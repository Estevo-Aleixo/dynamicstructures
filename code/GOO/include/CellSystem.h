#pragma once

#include "Main.h"
#include "Cell.h"
//#include "CellSystemProperties.h"


class Canvas; 

class CellSystem
{
public: 
	static void loadCellSystems(std::string& filename); //load with lua
	
	CellSystem(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr,Ogre::Vector2& startPosition, std::string& systemType, bool enabled=true, Ogre::Real speed = 1.0);
	~CellSystem(void);

	void enable(bool on){mEnabled=on;}
	bool isEnabled(){return mEnabled;}

	void start(){mEnabled=true;}
	void pause(){mEnabled=false;}
	void stop(){mEnabled=false; mDone=true;} 

	Ogre::Real getSpeed(){return mSpeed;} 

	void setSpeed(Ogre::Real speed){mSpeed=speed;} 
	void setPosition(Ogre::Vector2& position); //repositions entire cell system 
	void setOrientation(Ogre::Radian& orientation); 
	Cell* requestCell(); 
	
	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);

	Canvas* getCanvas(){return mCanvas;} 
	CellSystemProperties* getProperties(){return mProperties;}
	CellSystemProperties* getLocalProperties(){return mLocalProperties;}

protected:
	Canvas* mCanvas;
	void processNewCells(const FrameEvent &evt);
	std::queue<Cell*> mCellBuffer;

	CELLTYPE mDefaultType;
	static std::vector<std::string> availableSystems;
	
	std::string mName;
	Ogre::SceneManager* mSceneMgr; 
	Ogre::Vector2 mStartPos;
	std::string mSystemType;
	bool mEnabled;
	bool mDone;
	Ogre::Real mSpeed;
	Ogre::Radian mOrientation;
	

	std::vector<Cell*> mCells;
	
	Ogre::SceneNode* mStartNode; 
	Ogre::SceneNode* mLabelNode;
	Ogre::Entity* mStartEntity; 
	MovableText* mLabel;

	CellSystemProperties* mProperties; 
	
	//local properties (can change per cell):
	CellSystemProperties* mLocalProperties; 
	
};
