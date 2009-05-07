#include "ProcTree.h"

ProcTree::ProcTree(std::string& name, Ogre::SceneManager* sceneMgr,TreeParameters& params, Ogre::Vector2& position, Ogre::SceneNode* parent)
:ProceduralObject(name,sceneMgr, position, parent)
{

	Ogre::LogManager::getSingletonPtr()->logMessage("creating tree " + name);
	parent= sceneMgr->getRootSceneNode(); 
	mNode= parent->createChildSceneNode(Ogre::Vector3(position.x,position.y,1)); 
	mEntity= sceneMgr->createEntity(name +"_entity", CIRCLE_POLYGON); 
	mNode->attachObject(mEntity);
	mPos = position;
}

ProcTree::~ProcTree(void)
{
}
