#pragma once
#include "proceduralobject.h"

class ProcCaveEntrance :
	public ProceduralObject
{
public:
	ProcCaveEntrance(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0), Ogre::SceneNode* parent = 0);
	~ProcCaveEntrance(void);
};
