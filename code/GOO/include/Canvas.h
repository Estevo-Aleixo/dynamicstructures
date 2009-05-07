#pragma once

#include "Main.h"
//#include "SystemProperties.h"
#include "ContactFilter.h"
#include "ContactListener.h"



enum CANVASTYPE
{
	RECTANGULAR=0,
	HEXAGONAL=1,
	OCTOGONAL=2, 
	ELIPSOID=3
};

class Cursor;
class DynamicSystem;
class GrowingSurface;
class CellFactory;
class SystemFactory;
class SystemProperties; 
class World;

class Canvas
{
public:
	Canvas(void);
	Canvas(std::string& name, World* world,  CANVASTYPE type, SystemProperties* SystemProperties ,unsigned int lines, unsigned int height, unsigned int width);
	
	~Canvas(void);

	Ogre::Vector2& getDimensions(){return dimensions;}
	b2AABB& getAABB(){return mAABB;}  
	Ogre::SceneNode* getSceneNode(){return mRootCanvasNode;}
	
	bool addGrowingSurface(Ogre::Vector2& startPosition, const char* systemType, bool enabled=true, Ogre::Real speed = 1.0); 

	Cursor* getCursor(){return mCursor;}

	CANVASTYPE getCanvasType(){return mType;}

	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);
	
	b2World* getPhysicsWorld(){return mb2World;} 

	void addCellFactory(CellFactory* cellFactory){cellFactories.push_back(cellFactory);}
	
	//temp func!!!
	inline CellFactory* getCellFactory(){return cellFactories[0];}

	//woot
	void clearCanvas(); 
	void removeObject(Movable2DObject* object); 
	void notifyDestruction(Movable2DObject* object); 

	void pauseAllEntities(); 
	void startAllEntities(); 

	bool isRunning(){return mRunning;} 
	
	std::vector<GrowingSurface*>::iterator systemItr;
	std::vector<GrowingSurface*> mGrowingSurfaces; 

	void setSurface(SystemProperties* properties); 
	SystemProperties* mSystemProperties;  

	void setVisualizationStyle(VISUALIZATION vis); 
	
	void save(std::string& name); //save all to lua file 
	void load(std::string& name); //load all from lua file

	ContactListener* getContactListener(){return mContactListener;}

	DynamicSystem* getNearestSystem(Ogre::Vector2& pos, int filter); 
	Movable2DObject* getNearestObject(Ogre::Vector2& pos, int filter); 
	
	Ogre::SceneManager* getSceneManager(){return mSceneMgr;}


	//procedural objects function
	void deployForest(); 
protected: 
	bool mRunning; 

	SystemFactory* mSystemFactory;

	std::vector<CellFactory*> cellFactories;
	b2AABB mAABB;
	b2ContactFilter* mContactFilter;

	ContactListener* mContactListener; //this is also the collision event handler: ContactListener inherits from EventHandler
	
	b2World* mb2World;
	float32 mTimeStep;

	Ogre::SceneManager* mSceneMgr;

	Ogre::Vector2 dimensions;
	Ogre::Vector2 lastCursorPos;

	//b2DefaultFilter

	Cursor* mCursor;

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

	GrowingSurface* mCurrentSelection;


};
