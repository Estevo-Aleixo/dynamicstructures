#pragma once

#include "Main.h"

enum CANVASTYPE
{
	RECTANGULAR=0,
	HEXAGONAL=1,
	OCTOGONAL=2, 
	ELIPSOID=3
};


class Canvas
{
public:
	Canvas(void);
	Canvas( CANVASTYPE type, unsigned int width,unsigned int height, unsigned int rasterInterval=5);
	
	~Canvas(void);


	Ogre::Vector2& getDimensions(){return dimensions;}

	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);
	
protected: 
	Ogre::Vector2 dimensions;
	void createRaster();
	unsigned int mInterval;
	CANVASTYPE mType;

	Ogre::SceneNode* node; 
	Ogre::Entity* ent;
	Ogre::Mesh* rasterMesh;
};
