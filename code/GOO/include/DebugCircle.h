#pragma once

#include "DebugShape.h"

class DebugCircle: public DebugShape
{
public:
	DebugCircle(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0), double radius=1.0);
	~DebugCircle(void);

	virtual bool update(Ogre::FrameEvent& evt);

	void setRadius(double radius){mRadius  = radius;} 
	double mRadius; 
	 
};
