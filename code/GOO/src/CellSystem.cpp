#include "CellSystem.h"
#include "CellFactory.h"
#include "Canvas.h"

CellSystem::CellSystem(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Ogre::Vector2& startPosition, std::string& systemType, bool enabled, Ogre::Real speed)
: mName(name), mStartPos(startPosition), mSceneMgr(sceneMgr),mSystemType(systemType), mEnabled(enabled), mSpeed(speed), mCanvas(canvas) 
{
	
	mStartEntity = mSceneMgr->createEntity(name+"_start_marker_entity",HEXAGON_LINE_MESH); 
	mStartNode= mSceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name+ "_start_marker_node"); 
	mStartNode->attachObject(mStartEntity); 
	mLabelNode= mStartNode->createChildSceneNode(Vector3(20,0,20)); 
	
	//create label:
	mLabel= new MovableText(name+ "_labelText",name); 
	mLabel->setFontName( "mainfont" );
	mLabel->setColor( ColourValue::Green );
	mLabel->setCharacterHeight(20.0);
    mLabel->showOnTop();
    mLabelNode->attachObject( mLabel);
	mLabelNode->pitch(Ogre::Radian(Math::PI/2));
	mLabelNode->setInheritScale(false); 
	mStartNode->setPosition(startPosition.x, startPosition.y,0); 
	
	//load properties:
	mProperties= new CellSystemProperties(); 
	mLocalProperties= new CellSystemProperties(); 
	mDefaultType=CELLTYPE::HEXAGON; 

	//create Start Cell:
	Cell* firstCell= requestCell();
	firstCell->setPosition(mStartPos); 
	this->mEnabled=true;
}

CellSystem::~CellSystem(void)
{

}

bool CellSystem::frameStarted(const FrameEvent &evt)
{
	std::vector<Cell*>::iterator itr;
	
	//update zhe system: iterate through cells: 
	int i=0; 
	//for(itr= mCells.begin(); itr!= mCells.end(); itr++)
	for(int i=0; i < mCells.size(); i++)
	{
		mCells[i]->frameStarted(evt); 
	}

	//remember to call this function:
	//processNewCells(evt);

	return true;
}

void CellSystem::processNewCells(const FrameEvent &evt)
{
	//while(mCellBuffer.empty()==false)
	//{
	//	mCells.push_back(mCellBuffer.front());
	//	mCellBuffer.pop(); 
	//}
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
	//load settings here	

	//mutated variables:
	mLocalProperties->setCellSize(10.0);
	newCell= CellFactory::getSingletonPtr()->requestCell(this, mDefaultType); 
	//mCellBuffer.push(newCell); 
	mCells.push_back(newCell); 
	return newCell;
}