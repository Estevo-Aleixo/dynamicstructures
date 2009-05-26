#pragma once

#include "Movable2DObject.h"

class DebugShape: Movable2DObject 
{
public:
	DebugShape(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0));
	~DebugShape(void);


	void setColour(Ogre::ColourValue& colour);
	void verbose(bool on); 

	virtual bool update(Ogre::FrameEvent& evt);
	

	Ogre::Mesh* mMesh; 
	Ogre::ManualObject* mManualObject; 
	Ogre::ColourValue mColour; 
	bool mVerbose; 
};
