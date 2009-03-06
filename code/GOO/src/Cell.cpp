#include "Cell.h"
#include "CellSystem.h"
#include "CellFactory.h"

Cell::Cell(std::string name, unsigned int id, Ogre::SceneManager* sceneMgr, Object2DProperties* properties, Canvas* canvas, Ogre::Vector2 position, bool enabled):
Physical2DObject(name + std::string("_2DObject"), canvas, sceneMgr, properties, position, enabled),
mName(name), 
mID(id), 
mSceneMgr(sceneMgr), 
mSystem(0)
{
	cellCount=0;
	mDirectionInterval= Math::TWO_PI /6;
	mDivideDirection= Radian(0);
	mCloneIntervalTime = 2.0;
	mTimePassed=0.0;
	mCellBuddy=0;

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
		if (mTimePassed > mCloneIntervalTime && cellCount < 2)
		{
			mTimePassed=0.0;
			//divide(); 
		}

		//create a brother
		if (mCellBuddy!=0)
		{
			if ((mCellBuddy->getPosition()- mPos).length() > (this->mScale*2)*1.5) 
			{
				//create new cell at midpoint:
				Ogre::Vector2 pos = mPos + (mCellBuddy->getPosition() - mPos)/2; 
				Cell* newCell= mCanvas->getCellFactory()->createCell(mProperties, pos); 
				mSystem->addCell(newCell);
				newCell->enable(true);
				newCell->setCellSystem(this->mSystem);
				
				double speed= mBody->GetLinearVelocity().Length();
				Radian angle= Math::ATan2(pos.y-mOrigin.y,pos.x- mOrigin.x); 
				b2Vec2 vel= b2Vec2(Math::Cos(angle)*speed, Math::Sin(angle)*speed);  
				newCell->setLinearVelocity(vel);
				double newScale= mScale + 2.0;
				this->setScale(newScale); 
				newCell->setScale(mScale);
				Cell* tempCell= mCellBuddy;
				setCellBuddy(newCell);
				newCell->setCellBuddy(tempCell); 
			
				
				//Ogre::LogManager::getSingletonPtr()->logMessage(mName + ": I spawned a buddy!!!"); 
			return false;
			}
		
		}else
		{
		
			
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

