#include "CellSystem.h"
#include "CellFactory.h"
#include "Canvas.h"
#include "ObjectDefinitions.h"

CellSystem::CellSystem(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Ogre::Vector2& startPosition, const char* systemType, bool enabled, Ogre::Real speed)
: mName(name), mStartPos(startPosition), mSceneMgr(sceneMgr),mSystemType(systemType), mEnabled(enabled), mSpeed(speed), mCanvas(canvas) 
{
	
	//mStartEntity = mSceneMgr->createEntity(name+"_start_marker_entity",HEXAGON_LINE_MESH); 
	//mStartNode= mSceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name+ "_start_marker_node"); 
	//mStartNode->attachObject(mStartEntity); 
	//mStartNode->setScale(0.2,0.2,0.2);
	//mLabelNode= mStartNode->createChildSceneNode(Vector3(2,0,2)); 
	
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

	mObjectProps = new Object2DProperties(ObjectDefinitions::getSingletonPtr()->getObjectByName(systemType)); 

	this->mEnabled=true;
	this->initialize(); 
	mSkeleton= new Skeleton2D(name, startPosition,this,sceneMgr); 

	spawnTimeInterval=1;
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
		Cell* newCell=mCanvas->getCellFactory()->createCell(mObjectProps, mStartPos+ pos); 
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
	
	//update zhe system: iterate through cells: 
	int i=0; 
	//for(itr= mCells.begin(); itr!= mCells.end(); itr++)
	for(int i=0; i < mCells.size(); i++)
	{
		bool retvalue = mCells[i]->frameStarted(evt);	
		mCells[i]->setOrigin(mSkeleton->getPosition());
		if (retvalue==false)
			break;
	}
	mSkeleton->update(evt); 
	return true;
}

void CellSystem::processNewCells(const FrameEvent &evt)
{

}


bool CellSystem::frameEnded(const FrameEvent &evt)
{

	return true;
}

//repositions entire cell system
void CellSystem::setPosition(Ogre::Vector2& position)
{


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