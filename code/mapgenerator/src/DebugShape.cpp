#include "DebugShape.h"

DebugShape::DebugShape(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position)
:Movable2DObject(name, sceneMgr, position)
{

	//create manual object and attach to node



}

DebugShape::~DebugShape(void)
{
}

void DebugShape::setColour(Ogre::ColourValue& colour)
{


}
/*
* verbose on:
*  -parameters are shown on screen with shape
* verbose off 
* - only shape representation
*/
void DebugShape::verbose(bool on)
{

}

bool DebugShape::update(Ogre::FrameEvent& evt)
{

return true;
}