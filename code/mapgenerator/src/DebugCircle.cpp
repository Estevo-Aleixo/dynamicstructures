#include "DebugCircle.h"

DebugCircle::DebugCircle(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, double radius)
:DebugShape(name, sceneMgr, position), mRadius(radius)
{

}


DebugCircle::~DebugCircle(void)
{
}

bool DebugCircle::update(Ogre::FrameEvent& evt)
{

return true;
}
