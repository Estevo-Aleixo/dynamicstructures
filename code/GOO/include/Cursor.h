#pragma once

#include "Main.h"
#include "Canvas.h"
#include "Movable2DObject.h"

class CellSystemProperties;
class Movable2DObject;

class Cursor :public Movable2DObject
{

public:
	Cursor(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~Cursor(void);

	bool update(const FrameEvent &evt); 

	bool mouseMoved(const OIS::MouseEvent &e);
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	unsigned int getCurrentCellModeID();
	void setCreateType(unsigned int type);

	Ogre::Vector2& getPosition(){return mPos;} 
	void setPosition(Ogre::Vector2& pos); 

	CURSORMODE getMode(){return mMode;}

	void attachObject(Movable2DObject* object); 

private:
	Movable2DObject* mAttachedObject;
	Movable2DObject* mCurrentSelection; 


	CURSORMODE mMode;
	unsigned int mSystemType; 
	unsigned int mCreateType; 

	std::vector<CellSystemProperties*> mCellSystemModes; 

	bool mPressed;
	std::vector<Ogre::Vector2> samples;

	Ogre::SceneNode* mCursorNode; 
	Ogre::Entity* mCursorEntity;


	Ogre::Vector2 mPos;
	Ogre::Vector2 acceleration;


	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;  


	
	
};
