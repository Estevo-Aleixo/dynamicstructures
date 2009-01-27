#pragma once

#include "Main.h"
#include "Cell.h"
#include "CellSystemProperties.h"

class CellSystem
{
public: 
	static void loadCellSystems(std::string& filename); //load with lua
	
	CellSystem(std::string& name, Ogre::Vector2& startPosition, Ogre::SceneManager* sceneMgr, std::string& systemType, bool enabled=true, Ogre::Real speed = 1.0);
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

	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);

protected: 
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
	Ogre::Entity* mStartEntity;  

	CellSystemProperties* mProperties; 
};
