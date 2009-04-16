#include "Cursor.h"
#include "CellSystemProperties.h"
#include "Movable2DObject.h"



const char * const Cursor::cursorModeLabels[NUMMODES] = 
{"Place System", 
"Move System", 
"Edit System"}; 


Cursor::Cursor(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr): 
Movable2DObject(name,sceneMgr,Ogre::Vector2(0,0)),mCanvas(canvas), mSceneMgr(sceneMgr) 
{

	mNode= mCanvas->getSceneNode()->createChildSceneNode(); 
	mEntity= mSceneMgr->createEntity(name,HEXAGON_LINE_MESH); 
	mNode->attachObject(mEntity); 
	mNode->scale(10,10,10);
	acceleration= Vector2(0,0); 
	mPressed=false;
	mSystemType=1; 

	mPos= Vector2(0,0); 
	mCurrentSelection=0;

	mMode=1; 
}

Cursor::~Cursor(void)
{

}

bool Cursor::update(const FrameEvent &evt)
{
	mNode->roll(Ogre::Radian(2)*evt.timeSinceLastFrame); 	

	//refresh current selection (SIMPLE), ALTER THIS

	mCurrentSelection= (Movable2DObject*)mCanvas->getNearestSystem(mPos); 


	return true;
} 


bool Cursor::mouseMoved(const OIS::MouseEvent &e)
{
	//samples
	acceleration.x= (Ogre::Real)e.state.X.rel;
	acceleration.y= (Ogre::Real)e.state.Y.rel;
	
	if (acceleration.length() > 100.0)
			acceleration= 100.0 * acceleration.normalisedCopy(); 

	mPos.x+= acceleration.x; 
	mPos.y-= acceleration.y;

	mNode->setPosition(Vector3(mPos.x, mPos.y, 0)); 


	
	
	




return true;
}

bool Cursor::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	//plant  seed

	switch(id){
		case OIS::MouseButtonID::MB_Left:
			//create

			if (mPressed==false)
				performAction();  

			mPressed=true;
		break;
		case OIS::MouseButtonID::MB_Right:
			//delete
			mCanvas->removeObject(mCurrentSelection); 
		break;
	}
	
	
	return true;
}

bool Cursor::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	mPressed=false;

	return true;
}


unsigned int  Cursor::getCurrentCellModeID()
{
	return mSystemType; 
} 

void Cursor::setCreateType(unsigned int type)
{
	mSystemType = type;
}

void Cursor::setPosition(Ogre::Vector2& pos)
{
	mPos= pos;
	mCursorNode->setPosition(Vector3(mPos.x, mPos.y, 0)); 
}

void Cursor::attachObject(Movable2DObject* object)
{
	mAttachedObject= object; 
}

void Cursor::performAction()
{
		
	switch(mMode)
	{
	case CURSORMODE::PLACE_SYSTEM: 
			switch(mSystemType)
				{
					case 1:
						mCanvas->addCellSystem(mPos,"Square",true,1.0); 
						break;
					case 2:
						mCanvas->addCellSystem(mPos,"Hexagon",true,1.0); 
						break;
					case 3:
						mCanvas->addCellSystem(mPos,"Triangle",true,1.0); 
						break;
					case 4:
						mCanvas->addCellSystem(mPos,"Circle",true,1.0); 
						break;
				}
			break; 
	case CURSORMODE::MOVE_SYSTEM: 
		//do something
		break;
	case CURSORMODE::EDIT_SYSTEM: 
		//do something
		break; 
	}
}