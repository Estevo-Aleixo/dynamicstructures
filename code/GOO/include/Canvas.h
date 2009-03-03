#pragma once

#include "Main.h"
#include "SurfaceProperties.h"

enum CANVASTYPE
{
	RECTANGULAR=0,
	HEXAGONAL=1,
	OCTOGONAL=2, 
	ELIPSOID=3
};

class Pointer;
class CellSystem;
class CellFactory;

class Canvas
{
public:
	Canvas(void);
	Canvas(std::string& name, CANVASTYPE type, SurfaceProperties* surfaceProperties,  Ogre::SceneManager* sceneMgr,unsigned int lines, unsigned int height, unsigned int width);
	
	~Canvas(void);

	Ogre::Vector2& getDimensions(){return dimensions;}
	b2AABB& getAABB(){return mAABB;}  
	Ogre::SceneNode* getSceneNode(){return mRootCanvasNode;}
	
	bool addCellSystem(Ogre::Vector2& startPosition, const char* systemType, bool enabled=true, Ogre::Real speed = 1.0); 

	Pointer* getPointer(){return mPointer;}

	CANVASTYPE getCanvasType(){return mType;}

	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);
	
	b2World* getPhysicsWorld(){return mb2World;} 

	void addCellFactory(CellFactory* cellFactory){cellFactories.push_back(cellFactory);}
	
	//temp func!!!
	inline CellFactory* getCellFactory(){return cellFactories[0];}

	//woot
	void clearCanvas(); 
	void removeSystem(CellSystem* cellSystem); 

	void pauseAllEntities(); 
	void startAllEntities(); 

	bool isRunning(){return mRunning;} 
	
	std::vector<CellSystem*> mCellSystems; 

	void setSurface(SurfaceProperties* properties); 
	SurfaceProperties* mSurfaceProperties;  
protected: 
	bool mRunning; 

	std::vector<CellFactory*> cellFactories;
	b2AABB mAABB;
	b2World* mb2World;
	float32 mTimeStep;

	Ogre::SceneManager* mSceneMgr;

	Ogre::Vector2 dimensions;
	Ogre::Vector2 lastCursorPos;

	//b2DefaultFilter

	Pointer* mPointer;

	void createRaster(CANVASTYPE type);
	unsigned int mLines;
	CANVASTYPE mType;

	Ogre::SceneNode* mRootCanvasNode;
	Ogre::SceneNode* mRasterNode; 
	Ogre::Entity* mRasterEntity;
	Ogre::Mesh* rasterMesh;

	Ogre::SceneNode* mSurfaceNode;
	Ogre::Entity* mSurfaceEntity;


	float mTimePassed;
	float mTimeInterval;

	CellSystem* mCurrentSelection;


};
