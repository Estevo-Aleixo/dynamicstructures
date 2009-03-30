#include "PolygonSurface.h"



PolygonSurface::PolygonSurface(std::string& name, Canvas* canvas, CellSystem* system)
:Movable2DObject(name, canvas->getSceneManager(),system->getPosition()), mCanvas(canvas)
{


}

PolygonSurface::PolygonSurface(std::string& name, Canvas* canvas, std::vector<Movable2DObject*>& vertexList, SystemProperties* props, Ogre::Vector2& pos)
:Movable2DObject(name, canvas->getSceneManager(),pos), mCanvas(canvas)
{




}


PolygonSurface::~PolygonSurface(void)
{
}


bool PolygonSurface::update(Ogre::FrameEvent& evt)
{





return true;
}










