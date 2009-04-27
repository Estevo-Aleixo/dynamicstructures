#include "ProcStairs.h"

ProcStairs::ProcStairs(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, Ogre::SceneNode* parent)
:ProceduralObject(name,sceneMgr, position, parent)
{

	mNode= parent->createChildSceneNode(Ogre::Vector3(position.x,position.y,1)); 
	mEntity= sceneMgr->createEntity(name +"_entity", CIRCLE_POLYGON); 
	mPos = position;
}

ProcStairs::~ProcStairs(void)
{



}
