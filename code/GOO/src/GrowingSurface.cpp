#include "GrowingSurface.h"
#include "CellFactory.h"
#include "Canvas.h"
#include "ObjectDefinitions.h"

#include "PolygonAlgorithms.h"


typedef PolygonAlgorithms PA;

GrowingSurface::GrowingSurface(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, GrowingSurfaceProperties& properties, bool enabled, Ogre::Real speed)
:DynamicSystem(name, sceneMgr, position) , mProperties(properties), mEnabled(enabled), mSpeed(speed), mCanvas(canvas)
{
type= Object2DType::GrowingSurfaceType; 

	mObjectProps = new Object2DProperties(ObjectDefinitions::getSingletonPtr()->getObjectByName(properties.mCellObjectName)); 

	this->mEnabled=true;
	this->initialize(); 
	mSkeleton= new Skeleton2D(name, position,this,sceneMgr); 
	mForestPatch=0; 

	spawnTimeInterval=1;
	mShowPolyLines= true; 
	TimePassed=0;
	mSceneMgr= sceneMgr;
}

GrowingSurface::~GrowingSurface(void)
{

//delete cells:
	for (mCellItr= mCells.begin(); mCellItr!= mCells.end(); mCellItr++)
	{
		delete (*mCellItr);
		(*mCellItr)=0;
	}

//delete skeleton: 
	delete mSkeleton;
	mSkeleton=0;

}

void GrowingSurface::initialize()
{

	mProperties.vertexDistance=3.5; 



//temp create surrounding array of cells: 
	unsigned int cells= 6; 
	Ogre::Radian angleInterval= Radian(Math::TWO_PI / cells); 
	Ogre::Vector2 pos;
	Cell* prevCell=0;
	for (int i = 0; i < cells; i++)
	{  
		pos.x = Math::Cos(angleInterval*i) * 2;
		pos.y = Math::Sin(angleInterval*i) * 2;
		Cell* newCell=mCanvas->getCellFactory()->createCell(mObjectProps,this, mPos+ pos); 
		if (prevCell!=0)
			prevCell->setCellChild(newCell);
		mCells.push_back(newCell);
		newCell->enable(true);
		newCell->setGrowingSurface(this); 
		double scale=5;
		newCell->setScale(scale); 
		newCell->setNeighourDistanceInterval(mProperties.vertexDistance); 
		prevCell= newCell;
	}
	prevCell->setCellChild(mCells[0]);
}


bool GrowingSurface::frameStarted(const FrameEvent &evt)
{
	std::vector<Cell*>::iterator itr;

	if (mEnabled == true)
	{
		int i=0; 
		for(int i=0; i < mCells.size(); i++)
		{
			if (mCells[i]!=0)
			{
				bool retvalue = mCells[i]->frameStarted(evt);	
				mCells[i]->setOrigin(mSkeleton->getPosition());
				if (retvalue==false)
					break;
			}
		
			//CREATE CGAL POLYGON 
			//mVertices.push_back(Point_2(mCells[i]->getPosition().x,mCells[i]->getPosition().y)); 		
	
		}
		mSkeleton->update(evt);
		mPos= mSkeleton->getPosition(); 

		//CGAL::convex_hull_2( mVertices.begin(),mVertices.end(), std::back_inserter(result) );
		 // Ogre::LogManager::getSingletonPtr()->logMessage(Ogre::StringConverter::toString(result.size()) + " points on the convex hull"); 



		//calculate skeleton from polygon
		  //PA::constructSkeleton(mVertices, result); 


	}
	return true;
}

void GrowingSurface::processNewCells(const FrameEvent &evt)
{

}


bool GrowingSurface::frameEnded(const FrameEvent &evt)
{

	return true;
}



//reorients entire cell system
void GrowingSurface::setOrientation(Ogre::Radian& orientation)
{



}

Cell*  GrowingSurface::requestCell()
{
	Cell* newCell;
	
	return newCell;
}	

void GrowingSurface::updateSkeleton()
{


}  

void GrowingSurface::recalculateSkeleton()
{


}

void GrowingSurface::start()
{
	mEnabled=true;
	//loop trough cells 
	
	for(mCellItr= mCells.begin(); mCellItr !=mCells.end(); mCellItr++)
	{
		(*mCellItr)->proceed(); 
	}

}

void GrowingSurface::halt()
{	
	mEnabled=false;
		//loop trough cells 	
	for(mCellItr= mCells.begin(); mCellItr!=mCells.end(); mCellItr++)
	{
		(*mCellItr)->halt(); 
	}


}
void GrowingSurface::stop()
{
	mEnabled=false; 
	mDone=true;
} 

bool GrowingSurface::containsPoint(Ogre::Vector2& point)
{
	//loop through skeleton and check wether the point lies closer 
	//the skeleton point than the furthest cell of the cell set.




	return true;
}

void GrowingSurface::reduce(int percent)
{


}

//the position that is given to setposition is taken as the main skeleton position
void GrowingSurface::setPosition(Ogre::Vector2& position)
{
	//translate skeleton: translation of the skeleton automatically translates the cells.  
	mSkeleton->setPosition(position); 
}


void GrowingSurface::showPolyLines(bool on)
{

}

void GrowingSurface::updatePolyLines(const Ogre::FrameEvent& evt)
{
	
	
}

void  GrowingSurface::save(std::string& name)
{
//hierarchy: 

	//open lua file for writing: 

		//write loadGrowingSurface with properties of system

			//add cell to system
			//add cell to system
			//...
			//spawnsystem


		


}
void  GrowingSurface::load(std::string& name)
{
	
}

void GrowingSurface::destroyCell(Cell* cell)
{
	/*Cell* temp;
	std::vector<Cell*>::iterator result;
	result = find(mCells.begin(), mCells.end(), cell);
	temp = (*result);
	delete (*result);
	(*result)=0;
	*/
	//mCells.erase(result); 
	//delete temp;
}

ProcForestPatch* GrowingSurface::createForestPatch(unsigned int density, TreeParameters& min,TreeParameters& max)
{
	return mForestPatch = new ProcForestPatch(mName+"_forest",mSceneMgr,this,min,max,density); 
}