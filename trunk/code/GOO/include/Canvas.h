#pragma once

#include "Main.h"


enum CANVASTYPE
{
	RECTANGULAR=0,
	HEXAGONAL=1,
	OCTOGONAL=2, 
	ELIPSOID=3
};

class Pointer;
class CellSystem;

class Canvas
{
public:
	Canvas(void);
	Canvas(std::string& name, CANVASTYPE type, unsigned int width,unsigned int height, unsigned int lines, Ogre::SceneManager* sceneMgr);
	
	~Canvas(void);

	Ogre::Vector2& getDimensions(){return dimensions;}
	Ogre::SceneNode* getSceneNode(){return mRootCanvasNode;}
	
	bool addCellSystem(Ogre::Vector2& startPosition, std::string& systemType, bool enabled=true, Ogre::Real speed = 1.0); 

	Pointer* getPointer(){return mPointer;}

	CANVASTYPE getCanvasType(){return mType;}

	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);
	
protected: 
	Ogre::SceneManager* mSceneMgr;

	Ogre::Vector2 dimensions;
	Ogre::Vector2 lastCursorPos;

	std::vector<CellSystem*> mCellSystems; 

	Pointer* mPointer;

	void createRaster(CANVASTYPE type);
	unsigned int mLines;
	CANVASTYPE mType;

	Ogre::SceneNode* mRootCanvasNode;
	Ogre::SceneNode* mRasterNode; 
	Ogre::Entity* mRasterEntity;
	Ogre::Mesh* rasterMesh;
};