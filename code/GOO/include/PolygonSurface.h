#pragma once

#include "Main.h" 
#include "Movable2DObject.h"
#include "Canvas.h"
#include "GrowingSurface.h" 


//a GrowingSurface is transformed into a polygon surface when it is done growing.
//a polygon surface can also be transformed back into GrowingSurface to apply changes


class PolygonSurface: public Movable2DObject 
{
public:
	PolygonSurface(std::string& name, Canvas* canvas, GrowingSurface* system); //may also be world
	PolygonSurface(std::string& name, Canvas* canvas, std::vector<Movable2DObject*>& vertexList, SystemProperties* props, Ogre::Vector2& pos); //may also be world
	~PolygonSurface(void);

	void constructFromGrowingSurface(GrowingSurface* system, double sampleFactor);
	
	//bool update(Ogre::FrameEvent& evt); 

	//store properties:

	std::vector<Movable2DObject*> vertices;

	bool update(Ogre::FrameEvent& evt); 
	
protected:
	Canvas* mCanvas; 

	

};
