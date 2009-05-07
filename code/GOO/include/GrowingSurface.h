#pragma once

#include "Main.h"
#include "Cell.h"
#include "DynamicSystem.h"
#include "ProcForestPatch.h" 

#include "Skeleton2D.h"

class Canvas; 

class GrowingSurface: public DynamicSystem
{
public: 
	GrowingSurface(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr,Ogre::Vector2& position, GrowingSurfaceProperties& properties, bool enabled=true, Ogre::Real speed = 1.0);
	~GrowingSurface(void);

	void enable(bool on){mEnabled=on;}
	bool isEnabled(){return mEnabled;}

	void start();
	void halt();
	void stop();

	ProcForestPatch* createForestPatch(unsigned int density, TreeParameters& min,TreeParameters& max);
	void removeForestPatch(){delete mForestPatch;}
	ProcForestPatch* getForestPatch(){return mForestPatch;}


	Ogre::Real getSpeed(){return mSpeed;} 

	void setSpeed(Ogre::Real speed){mSpeed=speed;} 
	void setPosition(Ogre::Vector2& position); //repositions entire cell system 
	void setOrientation(Ogre::Radian& orientation); 


	Cell* requestCell(); 
	
	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);

	Canvas* getCanvas(){return mCanvas;} 
	GrowingSurfaceProperties& getProperties(){return mProperties;}
	GrowingSurfaceProperties* getLocalProperties(){return mLocalProperties;}

	std::vector<Cell*> mCells;
	std::vector<Cell*>::iterator mCellItr;

	inline void addCell(Cell* cell){mCells.push_back(cell);} 
	bool containsPoint(Ogre::Vector2& point); 
	
	void attachToCursor(){mAttachedToCursor = true;}
	void detachFromCursor(){mAttachedToCursor = false;}
	bool isAttachedToCursor(){return mAttachedToCursor;}
	
	void reduce(int percent);

	//MODE getMode(){return mMode;} 

	void showPolyLines(bool on);  

	void save(std::string& name);
	void load(std::string& name); 

	void notifyCellDeletion();
	void destroyCell(Cell* cell); 

	double mMaxGrowthVolume;
protected:

	//procedural objects:
	ProcForestPatch* mForestPatch; 
	
	
	
	//MODE mMode;
	void updatePolyLines(const Ogre::FrameEvent& evt);  
	bool mShowPolyLines;


	void initialize(); 
	bool mAttachedToCursor; 

	//Object2DProperties* mProperties;
	Skeleton2D* mSkeleton;

	Canvas* mCanvas;
	void processNewCells(const FrameEvent &evt);

	CELLTYPE mDefaultType;
	static std::vector<std::string> availableSystems;
	
	std::string mName;
	Ogre::SceneManager* mSceneMgr; 
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

	GrowingSurfaceProperties mProperties; 
	
	//local properties (can change per cell):
	GrowingSurfaceProperties* mLocalProperties; 

	Object2DProperties* mObjectProps;

	//temp: 
	float spawnTimeInterval;
	float TimePassed;
	
	
};
