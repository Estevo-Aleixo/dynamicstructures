#pragma once
#include "ProceduralObject.h"

class ProcBridge :
	public ProceduralObject
{
public:
	ProcBridge(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0), Ogre::SceneNode* parent = 0);
	~ProcBridge(void);
};
