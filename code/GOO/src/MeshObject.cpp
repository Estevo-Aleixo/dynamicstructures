#include "MeshObject.h"

MeshObject::MeshObject(std::string& name, Canvas* canvas, PolygonSurface* surface)
:Movable2DObject(name, canvas->getSceneManager(),surface->getPosition())
{


}

MeshObject::~MeshObject(void)
{
}
