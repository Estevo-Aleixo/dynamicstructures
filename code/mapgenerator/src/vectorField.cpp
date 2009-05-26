#include "vectorField.h"

vectorField::vectorField(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, Ogre::SceneNode* parent)
:Movable2DObject(name, sceneMgr, position,parent)
{

}

vectorField::~vectorField(void)
{

}
