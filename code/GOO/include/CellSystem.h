#pragma once

#include "Main.h"
#include "Cell.h"
//#include "CellSystemProperties.h"
#include "Skeleton2D.h"

class Canvas; 

class CellSystem
{
public: 
	static void loadCellSystems(std::string& filename); //load with lua
	
	CellSystem(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr,Ogre::Vector2& startPosition, const char* systemType, bool enabled=true, Ogre::Real speed = 1.0);
	~CellSystem(void);

	void enable(bool on){mEnabled=on;}
	bool isEnabled(){return mEnabled;}

	void start(){mEnabled=true;}
	void halt(){mEnabled=false;}
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

	//inline std::vector<Cell*>& getCellVector(){return mCells};
	std::vector<Cell*> mCells;

	inline void addCell(Cell* cell){mCells.push_back(cell);} 
protected:
	//Object2DProperties* mProperties;
	Skeleton2D* mSkeleton;

	Canvas* mCanvas;
	void processNewCells(const FrameEvent &evt);
	std::queue<Cell*> mCellBuffer;

	CELLTYPE mDefaultType;
	static std::vector<std::string> availableSystems;
	
	std::string mName;
	Ogre::SceneManager* mSceneMgr; 
	Ogre::Vector2 mStartPos;
	const char* mSystemType;
	bool mEnabled;
	bool mDone;
	Ogre::Real mSpeed;
	Ogre::Radian mOrientation;
	
	void updateSkeleton(); //just translate current spine positions 
	void recalculateSkeleton(); //recalculate entire skeleton


	
	Ogre::SceneNode* mStartNode; 
	Ogre::SceneNode* mLabelNode;
	Ogre::Entity* mStartEntity; 
	MovableText* mLabel;

	CellSystemProperties* mProperties; 
	
	//local properties (can change per cell):
	CellSystemProperties* mLocalProperties; 



	//temp: 
	float spawnTimeInterval;
	float TimePassed;
	
	
};
