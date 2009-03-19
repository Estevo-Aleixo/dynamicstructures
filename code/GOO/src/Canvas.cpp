#include "Canvas.h"
#include "Cursor.h"
#include "CellSystem.h"
#include "SystemFactory.h"
#include "World.h"

Canvas::Canvas(void)
{
}


Canvas::Canvas(std::string& name, World* world, CANVASTYPE type, SystemProperties* SystemProperties, unsigned int lines, unsigned int width, unsigned int height ): 
mType(type), mLines(lines), mSceneMgr(world->getSceneMgr())
{
	//physics:
	mAABB.lowerBound.Set(-1*(width/2.0)- 5.0, -1*(height/2.0) -5.0);
	mAABB.upperBound.Set((width/2)+5, (height/2)+5);

	mTimeStep = 1.0f / 20.0f;
	b2Vec2 gravity(0, 0.0);
	mb2World= new b2World(mAABB,gravity,false); 
	mContactFilter= new ContactFilter(); 
	mContactListener= new ContactListener(world); 
	mb2World->SetContactFilter(mContactFilter); 
	mb2World->SetContactListener(mContactListener); 

	this->dimensions.x= width;
	this->dimensions.y= height;
	
	//create system factory
	mSystemFactory= new SystemFactory(name + "_system_factory",this,mSceneMgr); 

//build raster:
mRootCanvasNode= mSceneMgr->getRootSceneNode()->createChildSceneNode("CanvasRootNode");
mRootCanvasNode->scale(1.0,1.0,1.0);

	createRaster(mType);
	mRasterEntity = mSceneMgr->createEntity("canvas_raster","Raster"); 
	mRasterNode= mRootCanvasNode->createChildSceneNode(); 
	mRasterNode->attachObject(mRasterEntity); 
	
	mCursor= new Cursor(name + "_Cursor", this, mSceneMgr); 
	mTimePassed = 0;
	mTimeInterval = 0.5;

//build surface
	/*
	mSurfaceEntity= mSceneMgr->createEntity("canvas_surface",SQUARE_MESH); 
	mSurfaceEntity->setMaterialName("basesurface"); 
	mSurfaceNode = mRootCanvasNode->createChildSceneNode(); 
	mSurfaceNode->attachObject(mSurfaceEntity); 
	mSurfaceNode->scale((double)width,(double)height,0.0);
	mSurfaceNode->translate(0.0,0.0,-1.0); 
*/

}
	
Canvas::~Canvas(void)
{
}

void Canvas::pauseAllEntities()
{
	mRunning= true;
	std::vector<CellSystem*>::iterator itr; 
	//loop through cell systems
	for (itr= mCellSystems.begin();itr != mCellSystems.end(); itr++)
	{
		(*itr)->halt(); 
	}
}

void Canvas::startAllEntities()
{
	mRunning = false;
	std::vector<CellSystem*>::iterator itr; 
	//loop through cell systems
	for (itr= mCellSystems.begin(); itr != mCellSystems.end(); itr++)
	{
		(*itr)->start(); 
	}
} 

void Canvas::createRaster(CANVASTYPE type)
{
	Ogre::ManualObject* raster;
	Ogre::ColourValue colour = Ogre::ColourValue(1.0,1.0,1.0,1.0); 

	double x,y;
	double vert_y, hor_x;
	double x_interval= dimensions.x/mLines;
	double y_interval= dimensions.y/mLines;

	raster= new Ogre::ManualObject("raster_manual"); 
	raster->begin("editorlines" ,RenderOperation::OT_LINE_LIST); 

	//create mesh raster on x,y plane 
	switch(type)
	{ 
	case CANVASTYPE::HEXAGONAL:
		break; 
	case CANVASTYPE::OCTOGONAL:
		break; 
	case CANVASTYPE::ELIPSOID:
		break;
	case CANVASTYPE::RECTANGULAR: //normal case 
	default: 
		
		//horizontal
		hor_x=   0 - dimensions.x/2.0;
		y =  0 - dimensions.y/2.0;
		
		//
		x=  0 - dimensions.x/2.0;
		vert_y=  0 - dimensions.y/2.0;
		
		for(int i=0; i <= mLines; i++)
		{
			//horizontal
			raster->position(hor_x,y,0);
			raster->colour(colour);
			raster->position(hor_x+dimensions.x ,y,0);
			raster->colour(colour);
			y+= y_interval;
		} 	


		for(int n=0; n <= mLines; n++)
		{
			//vertical
			raster->position(x,vert_y,0);
			raster->colour(colour);
			raster->position(x,vert_y+ dimensions.y,0);
			raster->colour(colour);
			x+= x_interval;

		}
		break;
	}
	
	raster->end(); 

	//todo check if not already excist
	raster->convertToMesh("Raster"); 

}


bool  Canvas::frameStarted(const FrameEvent &evt)
{
	//iterate through cell_systems
	std::vector<CellSystem*>::iterator itr;

	mCursor->update(evt); 

	//check cursor position:
	mTimePassed+=evt.timeSinceLastFrame;
	
	
	//check position relative to systems on the canvas (do this 2 times per second)
	if (mTimePassed > mTimeInterval)
	{
		mTimePassed =0;
		mCurrentSelection=0;
		for (itr= mCellSystems.begin(); itr!=mCellSystems.end(); itr++)
		{	
			if ((*itr)->containsPoint(mCursor->getPosition())==true)
			{
				mCurrentSelection= (*itr);
				break; 
			} 
		}
	
	}

	for (itr= mCellSystems.begin(); itr!=mCellSystems.end(); itr++)
	{	
		if ((*itr)->isEnabled())
			(*itr)->frameStarted(evt); 	
	}

	return true;
}

bool  Canvas::frameEnded(const FrameEvent &evt)
{
	mb2World->Step(mTimeStep, 10);
	return true;
}

bool  Canvas::addCellSystem(Ogre::Vector2& startPosition, const char* systemType, bool enabled, Ogre::Real speed)
{
	CellSystem* newCellSystem; 

	CellSystemProperties props;
	props.type= SystemType::CELLSYSTEM;
	props.mCellObjectName= systemType;

// properties


	newCellSystem= (CellSystem*)mSystemFactory->spawnSystem(props,startPosition); 
	mCellSystems.push_back(newCellSystem);
	//newCellSystem = new CellSystem("Cell_system_" +StringConverter::toString((Ogre::Real)mCellSystems.size()) +"_" +std::string(systemType),this,mSceneMgr, startPosition, systemType, enabled, speed); 



	//use system factory

	return true;
}

void Canvas::clearCanvas()
{
	std::vector<CellSystem*>::iterator itr; 

	for (itr = mCellSystems.begin(); itr!= mCellSystems.end();itr++)
	{
		delete (*itr);
		(*itr)=0;
	}

	mCellSystems.clear(); 
}

void Canvas::setSurface(SystemProperties* properties)
{
	mSystemProperties = properties;

	//set texture
	
}

void Canvas::save(std::string& name) //save all to lua file 
{
//use exception here


}

void Canvas::load(std::string& name) //load all from lua file
{
//use exception here

}