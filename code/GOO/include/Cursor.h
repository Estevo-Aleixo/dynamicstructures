#pragma once

#include "Main.h"
#include "Canvas.h"
#include "Movable2DObject.h"

class GrowingSurfaceProperties;
class Movable2DObject;

#define NUMMODES 3
enum CURSORMODE
{
	PLACE_SYSTEM = 1,
	MOVE_SYSTEM  = 2, 
	EDIT_SYSTEM  = 3
};

static const char* toolModeNames[] = 
{"place new system", 
"edit current system",
"edit current vertex",
"delete current system",
"select object"
};



class Cursor :public Movable2DObject
{

public:
	Cursor(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~Cursor(void);



static const char* const cursorModeLabels[NUMMODES];

	bool update(const FrameEvent &evt); 

	bool mouseMoved(const OIS::MouseEvent &e);
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	unsigned int getCurrentCellModeID();
	void setCreateType(unsigned int type);

	Ogre::Vector2& getPosition(){return mPos;} 
	void setPosition(Ogre::Vector2& pos); 

	void setMode(unsigned int mode)
	{
		if (mode > NUMMODES)
			mMode = 1;
		else if(mode < 1)
			mMode = NUMMODES; 
		else
			mMode = mode;
	}
	unsigned int getMode(){return mMode;}

	void attachObject(Movable2DObject* object); 



private:
	Movable2DObject* mAttachedObject;
	Movable2DObject* mCurrentSelection; 
	int mFilter;


	unsigned int mMode;
	unsigned int mSystemType; 
	unsigned int mCreateType; 


	void addNewSystem(); 
	void editCurrentSystem(); 
	void moveCurrentSystem(); 
	void deleteCurrentSystem(); 

	std::vector<GrowingSurfaceProperties*> mGrowingSurfaceModes; 

	bool mPressed;
	std::vector<Ogre::Vector2> samples;

	Ogre::SceneNode* mCursorNode; 
	Ogre::Entity* mCursorEntity;


	Ogre::Vector2 mPos;
	Ogre::Vector2 acceleration;


	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;  
	void performAction();
	
};
