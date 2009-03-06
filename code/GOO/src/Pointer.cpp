#include "Pointer.h"
#include "CellSystemProperties.h"
Pointer::Pointer(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr): 
mCanvas(canvas), mSceneMgr(sceneMgr) 
{

	mPointerNode= mCanvas->getSceneNode()->createChildSceneNode(); 
	mPointerEntity= mSceneMgr->createEntity(name,HEXAGON_LINE_MESH); 
	mPointerNode->attachObject(mPointerEntity); 
	mPointerNode->scale(10,10,10);
	acceleration= Vector2(0,0);
	mPos= Vector2(0,0); 
	mPressed=false;
	mSystemType=1; 
}

Pointer::~Pointer(void)
{

}

bool Pointer::update(const FrameEvent &evt)
{
	mPointerNode->roll(Ogre::Radian(2)*evt.timeSinceLastFrame); 	
	return true;
} 


bool Pointer::mouseMoved(const OIS::MouseEvent &e)
{
	//samples
	acceleration.x= (Ogre::Real)e.state.X.rel;
	acceleration.y= (Ogre::Real)e.state.Y.rel;
	
	if (acceleration.length() > 100.0)
			acceleration= 100.0 * acceleration.normalisedCopy(); 

	mPos.x+= acceleration.x; 
	mPos.y-= acceleration.y;

	mPointerNode->setPosition(Vector3(mPos.x, mPos.y, 0)); 


	
	
	




return true;
}

bool Pointer::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	//plant  seed
	if (mPressed==false)
	{
		switch(mSystemType){
		
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
	}


	
	mPressed=true;
	return true;
}

bool Pointer::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	mPressed=false;

	return true;
}


unsigned int  Pointer::getCurrentCellModeID()
{
	return mSystemType; 
} 

void Pointer::setCreateType(unsigned int type)
{
	mSystemType = type;
}

void Pointer::setPosition(Ogre::Vector2& pos)
{
	mPos= pos;
	mPointerNode->setPosition(Vector3(mPos.x, mPos.y, 0)); 
}