#include "CollisionLine.h"

CollisionLine::CollisionLine(std::string& name,Canvas* canvas, Physical2DObject* mother, Physical2DObject* father)
:Physical2DObject(name,canvas,canvas->getSceneManager(),0,Ogre::Vector2(0,0),false)
{

}

CollisionLine::~CollisionLine(void)
{
}
