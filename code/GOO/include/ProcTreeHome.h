#pragma once
#include "proceduralobject.h"

class ProcTreeHome :
	public ProceduralObject
{
public:
	ProcTreeHome(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0), Ogre::SceneNode* parent = 0);
	~ProcTreeHome(void);
};
