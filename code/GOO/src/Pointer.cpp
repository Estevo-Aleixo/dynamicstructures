#include "Pointer.h"

Pointer::Pointer(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr): 
mCanvas(canvas), mSceneMgr(sceneMgr) 
{

	mPointerNode= mCanvas->getSceneNode()->createChildSceneNode(); 
	mPointerEntity= mSceneMgr->createEntity(name,"sphere.mesh"); 
	mPointerNode->attachObject(mPointerEntity); 
	mPointerNode->scale(0.05,0.05,0.05);

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
	Ogre::Vector3 pos= mPointerNode->getPosition(); 

	pos.x+= e.state.X.rel;
	pos.y+= e.state.Y.rel;
	
	mPointerNode->setPosition(Vector3(pos.x, pos.y, 0)); 

return true;
}

bool Pointer::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	mPointerNode->scale(0.2,0.2,0.2);
	return true;
}

bool Pointer::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{


	return true;
}