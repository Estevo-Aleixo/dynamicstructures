#pragma once

#include "Main.h" 


class SystemProperties
{
public:
	SystemProperties(void);
	~SystemProperties(void);

	std::string mTexture;
	std::string mDescription; 
	double mMaxGrowthTime;
	
	Ogre::ColourValue mSurfaceColour;

	//surface properties that effect Surfaces
	
	SystemType type; 
	

	
};
