#include "Canvas.h"

Canvas::Canvas(void)
{
}


Canvas::Canvas( CANVASTYPE type, unsigned int width, unsigned int height , unsigned int rasterInterval): 
mType(type), mInterval(rasterInterval)
{

this->dimensions.x= width;
this->dimensions.y= height;


//build raster:
	createRaster();
}
	
Canvas::~Canvas(void)
{
}

void Canvas::createRaster()
{


}
