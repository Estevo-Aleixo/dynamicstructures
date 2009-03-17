#include "CellSystem.h"
#include "CellFactory.h"
#include "Canvas.h"
#include "ObjectDefinitions.h"

#include "PolygonAlgorithms.h"


typedef PolygonAlgorithms PA;

CellSystem::CellSystem(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, CellSystemProperties& properties, bool enabled, Ogre::Real speed)
:DynamicSystem(name, sceneMgr, position) , mProperties(properties), mEnabled(enabled), mSpeed(speed), mCanvas(canvas) 
{
	
	//create label:
	/*
	mLabel= new MovableText(name+ "_labelText",name); 
	mLabel->setFontName( "mainfont" );
	mLabel->setColor( ColourValue::Green );
	mLabel->setCharacterHeight(1.0);
    mLabel->showOnTop();
    mLabelNode->attachObject( mLabel);
	mLabelNode->pitch(Ogre::Radian(Math::PI/2));
	mLabelNode->setInheritScale(false); 
	mStartNode->setPosition(startPosition.x, startPosition.y,0); 
	*/

	
	
	mObjectProps = new Object2DProperties(ObjectDefinitions::getSingletonPtr()->getObjectByName(properties.mCellObjectName)); 

	this->mEnabled=true;
	this->initialize(); 
	mSkeleton= new Skeleton2D(name, position,this,sceneMgr); 
	//mSkeletonPoints= new std::vector<Point_2>();

	spawnTimeInterval=1;
	mShowPolyLines= true; 
	TimePassed=0;


}

CellSystem::~CellSystem(void)
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

void CellSystem::initialize()
{

//temp create surrounding array of cells: 
	unsigned int cells= 6; 
	Ogre::Radian angleInterval= Radian(Math::TWO_PI / cells); 
	Ogre::Vector2 pos;
	Cell* prevCell=0;
	for (int i = 0; i < cells; i++)
	{  
		pos.x = Math::Cos(angleInterval*i) * 2;
		pos.y = Math::Sin(angleInterval*i) * 2;
		Cell* newCell=mCanvas->getCellFactory()->createCell(mObjectProps, mPos+ pos); 
		if (prevCell!=0)
			prevCell->setCellBuddy(newCell);
		mCells.push_back(newCell);
		newCell->enable(true);
		newCell->setCellSystem(this); 
		double scale=5;
		newCell->setScale(scale); 
		prevCell= newCell;
	}
	prevCell->setCellBuddy(mCells[0]);
}


bool CellSystem::frameStarted(const FrameEvent &evt)
{
	std::vector<Cell*>::iterator itr;

    //std::vector<Point_2> result;
	//std::vector<Point_2> mVertices;
	
	if (mEnabled == true)
	{
		int i=0; 
		//mVertices.clear(); 
		for(int i=0; i < mCells.size(); i++)
		{
			bool retvalue = mCells[i]->frameStarted(evt);	
			mCells[i]->setOrigin(mSkeleton->getPosition());
			if (retvalue==false)
				break;

		
			//CREATE CGAL POLYGON 
			//mVertices.push_back(Point_2(mCells[i]->getPosition().x,mCells[i]->getPosition().y)); 		
	
		}
		mSkeleton->update(evt);
		
		//CGAL::convex_hull_2( mVertices.begin(),mVertices.end(), std::back_inserter(result) );
		 // Ogre::LogManager::getSingletonPtr()->logMessage(Ogre::StringConverter::toString(result.size()) + " points on the convex hull"); 



		//calculate skeleton from polygon
		  //PA::constructSkeleton(mVertices, result); 


	}
	return true;
}

void CellSystem::processNewCells(const FrameEvent &evt)
{

}


bool CellSystem::frameEnded(const FrameEvent &evt)
{

	return true;
}



//reorients entire cell system
void CellSystem::setOrientation(Ogre::Radian& orientation)
{



}

Cell*  CellSystem::requestCell()
{
	Cell* newCell;
	
	return newCell;
}	

void CellSystem::updateSkeleton()
{


}  

void CellSystem::recalculateSkeleton()
{


}

void CellSystem::start()
{
	mEnabled=true;
	//loop trough cells 
	
	for(mCellItr= mCells.begin(); mCellItr !=mCells.end(); mCellItr++)
	{
		(*mCellItr)->proceed(); 
	}

}

void CellSystem::halt()
{	
	mEnabled=false;
		//loop trough cells 	
	for(mCellItr= mCells.begin(); mCellItr!=mCells.end(); mCellItr++)
	{
		(*mCellItr)->halt(); 
	}


}
void CellSystem::stop()
{
	mEnabled=false; 
	mDone=true;
} 

bool CellSystem::containsPoint(Ogre::Vector2& point)
{
	//loop through skeleton and check wether the point lies closer 
	//the skeleton point than the furthest cell of the cell set.




	return true;
}

void CellSystem::reduce(int percent)
{


}

//the position that is given to setposition is taken as the main skeleton position
void CellSystem::setPosition(Ogre::Vector2& position)
{
	//translate skeleton: translation of the skeleton automatically translates the cells.  
	mSkeleton->setPosition(position); 
}


void CellSystem::showPolyLines(bool on)
{

}

void CellSystem::updatePolyLines(const Ogre::FrameEvent& evt)
{
	
	
}

void  CellSystem::save(std::string& name)
{
//hierarchy: 

	//open lua file for writing: 

		//write loadCellSystem with properties of system

			//add cell to system
			//add cell to system
			//...
			//spawnsystem


		


}
void  CellSystem::load(std::string& name)
{
	
}