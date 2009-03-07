#include "Movable2DObject.h"

Movable2DObject::Movable2DObject(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position)
:mSceneMgr(sceneMgr),mName(name), mPos(position) 
{

}

Movable2DObject::~Movable2DObject(void)
{

}

void Movable2DObject::setPosition(Ogre::Vector2& position)
{
	mPos = position; 
	mNode->setPosition(position.x, position.y,0); 
}

bool Movable2DObject::update(Ogre::FrameEvent& evt)
{


return true;
}

void Movable2DObject::attach(Movable2DObject* object)
{

}
	
void Movable2DObject::detach()
{
} 