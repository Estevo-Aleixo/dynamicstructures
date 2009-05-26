#include "ElevatedArea.h"

ElevatedArea::ElevatedArea(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, Ogre::SceneNode* parent)
:ProceduralObject(name,sceneMgr, position, parent)
{
}

ElevatedArea::~ElevatedArea(void)
{
}
