#pragma once
#include "Movable2DObject.h"

enum PROC_PARAMETER
{
simple_parameter = 0
};


class ProceduralObject:
	public Movable2DObject, public Ogre::FrameListener
{
public:
	ProceduralObject(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0), Ogre::SceneNode* parent = 0);
	~ProceduralObject(void);

	Ogre::Mesh* buildFinalMesh(); 
	void setBaseParameter(PROC_PARAMETER paramID, double value); 
	double getBaseParameter(PROC_PARAMETER paramID); 	

	virtual bool frameStarted(const Ogre::FrameEvent& evt);
	virtual bool frameEnded(const Ogre::FrameEvent& evt);
protected:
	Ogre::ManualObject* mManualObject;  
	double mSimpleParameter; 
};
