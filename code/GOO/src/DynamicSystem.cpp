#include "DynamicSystem.h"

DynamicSystem::DynamicSystem(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position)
:Movable2DObject(name, sceneMgr,position)
{

}

DynamicSystem::~DynamicSystem(void)
{
}
