#include "Cell.h"
#include "CellSystem.h"
#include "CellFactory.h"

Cell::Cell(std::string name, unsigned int id,CellSystem* system, Ogre::SceneManager* sceneMgr, Object2DProperties* properties, Canvas* canvas, Ogre::Vector2 position, bool enabled):
Physical2DObject(name + std::string("_2DObject"), canvas, sceneMgr, properties, position, enabled),
mName(name), 
mID(id), 
mSceneMgr(sceneMgr), 
mSystem(system)
{
	cellCount=0;
	mDirectionInterval= Math::TWO_PI /6;
	mDivideDirection= Radian(0);
	mCloneIntervalTime = 2.0;
	mTimePassed=0.0;
	mCellChild=0;

	mBody->SetUserData(this); 
	mBody->GetShapeList()->SetUserData(this); 
	
	mShowPolyLine = false; 
	mPolyLine= new Ogre::ManualObject(name + "_polyline"); 

	mPolyLine->begin("polyline",RenderOperation::OT_LINE_LIST); 		
			mPolyLine->position(0,0,0); 
			mPolyLine->position(0,0,0); 
			mPolyLine->index(1);
			mPolyLine->index(0);
	mPolyLine->end(); 
	

	mLineNode= mNode->createChildSceneNode();
	mLineNode->attachObject(mPolyLine);
	mLineNode->setInheritOrientation(false);
	mLineNode->setInheritScale(false);

	//mCenterNode
		mCenterNode= mNode->createChildSceneNode();  
		mCenterEntity= mSceneMgr->createEntity(name +  "_center",SQUARE_MESH);
		mCenterEntity->setMaterialName("ambient_white"); 
		mCenterNode->attachObject(mCenterEntity); 
		mCenterNode->translate(0,0,0.001); 
		mCenterNode->scale(0.2,0.2,0.2); 
		
}



Cell::~Cell(void)
{

//notify parent
	mCellParent->setCellChild(0);

//connect parent to orphaned child of this
	//if (mCellChild!=0)
	//	mCellParent->setCellChild

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
		if (mCellChild!=0)
		{
			if ((mCellChild->getPosition()- mPos).length() > (mScale * (double)mNeighbourDistance) )
			{
				//create new cell at midpoint:
				Ogre::Vector2 pos = mPos + (mCellChild->getPosition() - mPos)/2; 
				Cell* newCell= mCanvas->getCellFactory()->createCell(mProperties,this->mSystem, pos); 
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
				Cell* tempCell= mCellChild;
				setCellChild(newCell);
				newCell->setCellChild(tempCell); 
			
			
				
				//Ogre::LogManager::getSingletonPtr()->logMessage(mName + ": I spawned a buddy!!!"); 
			return false;
			}
		
		//draw manual object line:
			updatePolyLine(); 
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

void Cell::updatePolyLine()
{


	Ogre::Vector2 pos;


	pos= mCellChild->getPosition()- mPos ;
	//pos = pos.normalisedCopy()* (pos.length()/3);
//refresh polyline
		//mPolyLine->clear(); 
		mPolyLine->beginUpdate(0); 		
			mPolyLine->position(0,0,0.001); 
			mPolyLine->position(pos.x,pos.y,0.001); 
			mPolyLine->index(1);
			mPolyLine->index(0);
		mPolyLine->end(); 
		
		//mPolyLine->convertToMesh(CIRCLE_POLYGON);  


}

void Cell::setCellSystem(CellSystem* cellSystem)
{
	mSystem = cellSystem;

	//set properties:
	mNeighbourDistance= mSystem->getProperties().vertexDistance;

}