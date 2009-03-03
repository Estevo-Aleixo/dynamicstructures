#pragma once

#include "Main.h" 


class SurfaceProperties
{
public:
	SurfaceProperties(void);
	~SurfaceProperties(void);

	std::string mTexture;
	std::string mDescription; 
	Ogre::ColourValue mSurfaceColour;

	//surface properties that effect cellsystems


};
