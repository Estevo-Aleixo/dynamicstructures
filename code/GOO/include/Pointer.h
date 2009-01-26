#pragma once

#include "Main.h"
#include "Canvas.h"

class Pointer 
{

public:
	Pointer(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~Pointer(void);

	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);

	bool mouseMoved(const OIS::MouseEvent &e);
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);

private:
	Ogre::SceneNode* mPointerNode; 
	Ogre::Entity* mPointerEntity;

	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;  
	
};
