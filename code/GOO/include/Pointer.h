#pragma once

#include "Main.h"
#include "Canvas.h"

class CellSystemProperties;

class Pointer 
{

public:
	Pointer(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~Pointer(void);

	bool update(const FrameEvent &evt); 

	bool mouseMoved(const OIS::MouseEvent &e);
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	unsigned int getCurrentCellModeID();
	void setCreateType(unsigned int type);

	Ogre::Vector2& getPosition(){return mPos;} 
	void setPosition(Ogre::Vector2& pos); 

	CURSORMODE getMode(){return mMode;}
private:
	CURSORMODE mMode;
	unsigned int mSystemType; 
	unsigned int mCreateType; 

	std::vector<CellSystemProperties*> mCellSystemModes; 

	bool mPressed;
	std::vector<Ogre::Vector2> samples;

	Ogre::SceneNode* mPointerNode; 
	Ogre::Entity* mPointerEntity;


	Ogre::Vector2 mPos;
	Ogre::Vector2 acceleration;


	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;  


	
	
};
