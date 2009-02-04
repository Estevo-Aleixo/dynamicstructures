#include "CellSystem.h"
#include "CellFactory.h"
#include "Canvas.h"
#include "ObjectDefinitions.h"

CellSystem::CellSystem(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Ogre::Vector2& startPosition, const char* systemType, bool enabled, Ogre::Real speed)
: mName(name), mStartPos(startPosition), mSceneMgr(sceneMgr),mSystemType(systemType), mEnabled(enabled), mSpeed(speed), mCanvas(canvas) 
{
	
	mStartEntity = mSceneMgr->createEntity(name+"_start_marker_entity",HEXAGON_LINE_MESH); 
	mStartNode= mSceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name+ "_start_marker_node"); 
	mStartNode->attachObject(mStartEntity); 
	mStartNode->setScale(0.2,0.2,0.2);
	mLabelNode= mStartNode->createChildSceneNode(Vector3(2,0,2)); 
	
	//create label:
	
	mLabel= new MovableText(name+ "_labelText",name); 
	mLabel->setFontName( "mainfont" );
	mLabel->setColor( ColourValue::Green );
	mLabel->setCharacterHeight(1.0);
    mLabel->showOnTop();
    mLabelNode->attachObject( mLabel);
	mLabelNode->pitch(Ogre::Radian(Math::PI/2));
	mLabelNode->setInheritScale(false); 
	mStartNode->setPosition(startPosition.x, startPosition.y,0); 
	
	Object2DProperties props= ObjectDefinitions::getSingletonPtr()->getObjectByName(systemType); 
	Cell* firstCell= mCanvas->getCellFactory()->createCell(props, mStartPos); 

	firstCell->enable(true); 
	this->mEnabled=true;
	mCells.push_back(firstCell);

	//temp create surrounding array of cells: 
	unsigned int cells= 6; 
	Ogre::Radian angleInterval= Radian(Math::TWO_PI / cells); 
	Ogre::Vector2 pos;
	for (int i = 0; i < cells; i++)
	{  
		pos.x = Math::Cos(angleInterval*i) * 2;
		pos.y = Math::Sin(angleInterval*i) * 2;
		Cell* newCell=mCanvas->getCellFactory()->createCell(props, mStartPos+ pos); 
		mCells.push_back(newCell);
		newCell->enable(true); 
	}

	spawnTimeInterval=1;
	TimePassed=0;

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

	//spawn a cell from any random cell
	TimePassed+=evt.timeSinceLastFrame;

	if (TimePassed > this->spawnTimeInterval)
	{
		TimePassed=0;
		int chosen= (int)Ogre::Math::RangeRandom(0,mCells.size());
		//vector from core
		Ogre::Vector2 offset;
		offset.x=Ogre::Math::RangeRandom(-1,1);
		offset.y=Ogre::Math::RangeRandom(-1,1);
		Ogre::Vector2 pos= mCells[chosen]->getPosition() + offset.normalisedCopy() * 2; 
	
		Object2DProperties props= ObjectDefinitions::getSingletonPtr()->getObjectByName(mSystemType); 
		Cell* newCell= mCanvas->getCellFactory()->createCell(props, pos);
		mCells.push_back(newCell);
		offset*=1;
		newCell->enable(true); 
		newCell->getBody()->ApplyImpulse(b2Vec2((float32)offset.x,(float32)offset.y),b2Vec2(0,0)); 
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