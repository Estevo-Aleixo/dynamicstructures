#include "Canvas.h"
#include "Pointer.h"
#include "CellSystem.h"

Canvas::Canvas(void)
{
}


Canvas::Canvas(std::string& name, CANVASTYPE type, unsigned int width, unsigned int height , unsigned int lines, Ogre::SceneManager* sceneMgr): 
mType(type), mLines(lines), mSceneMgr(sceneMgr)
{
	//physics:
	b2AABB worldAABB;
	worldAABB.lowerBound.Set((float32)(width/-2), (float32)(height/-2));
	worldAABB.upperBound.Set((float32)(width/2), (float32)(height/2));

	mTimeStep = 1.0f / 60.0f;
	b2Vec2 gravity(0,0);
	mb2World= new b2World(worldAABB,gravity,true); 

	this->dimensions.x= width;
	this->dimensions.y= height;
	
//build raster:
	createRaster(mType);
	mRasterEntity = sceneMgr->createEntity("canvas_raster","Raster"); 
	mRootCanvasNode= sceneMgr->getRootSceneNode()->createChildSceneNode("CanvasRootNode");
	mRasterNode= mRootCanvasNode->createChildSceneNode(); 
	mRasterNode->attachObject(mRasterEntity); 
	mRootCanvasNode->scale(1.0,1.0,1.0);
	mPointer= new Pointer(name + "_pointer", this, mSceneMgr); 

}
	
Canvas::~Canvas(void)
{
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

bool  Canvas::addCellSystem(Ogre::Vector2& startPosition, std::string& systemType, bool enabled, Ogre::Real speed)
{
	CellSystem* newCellSystem; 

	newCellSystem = new CellSystem("Cell_system_" +StringConverter::toString((Ogre::Real)mCellSystems.size()) +"_" +systemType, startPosition, mSceneMgr, systemType, enabled, speed); 
	mCellSystems.push_back(newCellSystem); 

	return true;
}