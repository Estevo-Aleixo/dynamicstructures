#include "Cell.h"
#include "CellSystem.h"

Cell::Cell(std::string name, unsigned int id, Ogre::SceneManager* sceneMgr, CellProperties* properties, Canvas* canvas, Ogre::Vector2 position, bool enabled):
Physical2DObject(name + std::string("_2DObject"), canvas, sceneMgr, (Object2DProperties)(*properties), position, enabled),
mName(name), 
mID(id), 
mPos(position), 
mSceneMgr(sceneMgr), 
mSystem(0)
{
	cellCount=0;
	mDirectionInterval= Math::TWO_PI /6;
	mDivideDirection= Radian(0);
	mCloneIntervalTime = 2.0;
	mTimePassed=0.0;
this->getBody()->SetLinearVelocity(b2Vec2(100.0,0)); 

//TODO: ELABORATE PROPERTIES!
//TODO: Replace with CellSystem->getProperties(); 

}



Cell::~Cell(void)
{

}

bool Cell::frameStarted(const FrameEvent &evt)
{
	if (this->isEnabled())
	{
		updatePhysics(evt); 

		mTimePassed+=evt.timeSinceLastFrame;
		//Ogre::LogManager::getSingletonPtr()->logMessage("timer: " +StringConverter::toString(mTimePassed));
		if (mTimePassed > mCloneIntervalTime && cellCount < 2){
			mTimePassed=0.0;
			//divide(); 
		}

	}
return true;
}

bool Cell::frameEnded(const FrameEvent &evt)
{

return true;
}

void Cell::divide()
{
	Cell* myClone;
	//spawn new cell
	cellCount++;
		Ogre::Vector2 position;

  // myClone= new Cell("testcel"+ StringConverter::toString(cellCount),0,mSceneMgr,this->mSystem,position);

	myClone= mSystem->requestCell(); 
		//initialize the new clone: 

	position.x = mPos.x + Math::Cos(mDivideDirection)* 18;
	position.y = mPos.y + Math::Sin(mDivideDirection)* 18;
	myClone->setPosition(position); 

	//set divide angle: 
	mDivideDirection+= mDirectionInterval;
}


CellProperties  Cell::retrieveProperties(CellSystem* system)
{
	CellProperties properties;
	
	return properties;
}

