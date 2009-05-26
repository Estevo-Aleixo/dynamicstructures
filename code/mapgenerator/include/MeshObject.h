#pragma once


/*
takes a polygonsurface:
	1. adds vertices on the inside of the polygon
	2. creates a delauney triangulation from all the points 
	3. adds height(z) information to the vertices
	4. add a nice surface texture
	5. voila: a 3d surface mesh

second step:
	- read properties -> create prop objects like trees, stone and stuff


*/
#include "Movable2DObject.h"
#include "Canvas.h"
//#include "PolygonSurface.h"

class MeshObject: public Movable2DObject
{
public:
	MeshObject(std::string& name, Canvas* canvas);
	~MeshObject(void);
};
