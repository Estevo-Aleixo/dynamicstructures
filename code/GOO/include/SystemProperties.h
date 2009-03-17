#pragma once

#include "Main.h" 


class SystemProperties
{
public:
	SystemProperties(void);
	~SystemProperties(void);

	std::string mTexture;
	std::string mDescription; 
	Ogre::ColourValue mSurfaceColour;

	//surface properties that effect cellsystems
	
	SystemType type; 
	


};
