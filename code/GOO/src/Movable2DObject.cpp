#include "Movable2DObject.h"

Movable2DObject::Movable2DObject(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position)
:mSceneMgr(sceneMgr),mName(name), mPos(position) 
{

}

Movable2DObject::~Movable2DObject(void)
{

}
