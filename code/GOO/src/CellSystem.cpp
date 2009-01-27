#include "CellSystem.h"

CellSystem::CellSystem(std::string& name, Ogre::Vector2& startPosition, Ogre::SceneManager* sceneMgr, std::string& systemType, bool enabled, Ogre::Real speed)
: mName(name), mStartPos(startPosition), mSceneMgr(sceneMgr),mSystemType(systemType), mEnabled(enabled),mSpeed(speed)
{
	
	mStartEntity = mSceneMgr->createEntity(name+"_start_marker_entity","sphere.mesh"); 
	mStartNode= mSceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name+ "_start_marker_node"); 
	mStartNode->attachObject(mStartEntity); 

	mStartNode->setPosition(startPosition.x, startPosition.y,0); 
	mStartNode->scale(0.06,0.06,0.06);
	//load properties:

}

CellSystem::~CellSystem(void)
{

}

bool CellSystem::frameStarted(const FrameEvent &evt)
{
	
	return true;
}

bool CellSystem::frameEnded(const FrameEvent &evt)
{

	return true;
}

//repositions entire cell system
void CellSystem::setPosition(Ogre::Vector2& position)
{


} 

//reorients entire cell system
void CellSystem::setOrientation(Ogre::Radian& orientation)
{



}

