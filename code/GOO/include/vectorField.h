#pragma once

#include "Movable2DObject.h"


class vectorField: public Movable2DObject
{
public:
	vectorField(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0), Ogre::SceneNode* parent = 0);
	~vectorField(void);







};
