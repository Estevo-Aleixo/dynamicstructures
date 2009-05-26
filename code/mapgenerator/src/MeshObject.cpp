#include "MeshObject.h"

MeshObject::MeshObject(std::string& name, Canvas* canvas)
:Movable2DObject(name, canvas->getSceneManager(),Vector2(0,0))
{


}

MeshObject::~MeshObject(void)
{
}
