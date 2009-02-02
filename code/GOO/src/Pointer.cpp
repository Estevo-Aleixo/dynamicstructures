#include "Pointer.h"

Pointer::Pointer(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr): 
mCanvas(canvas), mSceneMgr(sceneMgr) 
{

	mPointerNode= mCanvas->getSceneNode()->createChildSceneNode(); 
	mPointerEntity= mSceneMgr->createEntity(name,"sphere.mesh"); 
	mPointerNode->attachObject(mPointerEntity); 
	mPointerNode->scale(0.01,0.01,0.01);
	acceleration= Vector2(0,0);
	mPos= Vector2(0,0); 
	mPressed=false;
}

Pointer::~Pointer(void)
{

}

bool Pointer::frameStarted(const FrameEvent &evt)
{

	return true;
} 
bool Pointer::frameEnded(const FrameEvent &evt)
{

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
		mCanvas->addCellSystem(mPos,std::string("land"),true,1.0); 
	}


	
	mPressed=true;
	return true;
}

bool Pointer::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	mPressed=false;

	return true;
}