#pragma once


#include "Canvas.h"

class God: public FrameListener
{
public:
	God(Ogre::String& name, Canvas* canvas);
	~God(void);

	void setActive(bool active);	
	bool isActive(){return mActive;}
protected:
	
	bool mActive; 

	Ogre::String mName; 
	Canvas* mCanvas; 

private: 



};
