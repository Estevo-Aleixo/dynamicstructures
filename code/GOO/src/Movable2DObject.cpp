#include "Movable2DObject.h"

Movable2DObject::Movable2DObject(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, Ogre::SceneNode* parent)
:mSceneMgr(sceneMgr),mName(name), mPos(position) 
{
	mNode=0;
	mEntity=0;
}

Movable2DObject::~Movable2DObject(void)
{
	//delete the skeleton, notify the system.
	if (mNode!=0){
		mNode->removeAndDestroyAllChildren(); 
		mSceneMgr->destroySceneNode(mNode); 
	}
	
	if (mEntity!=0)
		mSceneMgr->destroyEntity(mEntity); 
}

void Movable2DObject::setPosition(Ogre::Vector2& position)
{
	mPos = position; 
	mNode->setPosition(position.x, position.y,0); 
}

/*bool Movable2DObject::update(Ogre::FrameEvent& evt)
{


return true;
}
*/
void Movable2DObject::attach(Movable2DObject* object)
{

}
	
void Movable2DObject::detach()
{
} 

void  Movable2DObject::save(std::string& name)
{

}
void  Movable2DObject::load(std::string& name)
{


}

void Movable2DObject::handleCollisionWith(Movable2DObject* object)
{


}
/*
bool Movable2DObject::update(Ogre::FrameEvent& evt)
{


}*/