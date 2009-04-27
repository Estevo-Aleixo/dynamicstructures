#include "ProceduralObject.h"


ProceduralObject::ProceduralObject(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, Ogre::SceneNode* parent)
:Movable2DObject(name, sceneMgr, position, parent)
{


}


ProceduralObject::~ProceduralObject(void)
{
}

void ProceduralObject::setBaseParameter(PROC_PARAMETER paramID, double value)
{

	switch(paramID)
	{
		case PROC_PARAMETER::simple_parameter:
			mSimpleParameter=value; 
		break; 	
	}
}

double  ProceduralObject::getBaseParameter(PROC_PARAMETER paramID)
{

	switch(paramID)
	{
		case PROC_PARAMETER::simple_parameter:
			return mSimpleParameter; 
		break; 	
	}

	return 0;
}

bool ProceduralObject::frameStarted(const Ogre::FrameEvent& evt)
{

return true;
}

bool ProceduralObject::frameEnded(const Ogre::FrameEvent& evt)
{

return true;
}