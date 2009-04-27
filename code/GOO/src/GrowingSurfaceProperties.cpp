#include "GrowingSurfaceProperties.h"

GrowingSurfaceProperties::GrowingSurfaceProperties(void)
{
	mCellSize= 10.0;
	mType= CELLTYPE::HEXAGON;  
	this->mCellProperties= CellProperties(); 
}

GrowingSurfaceProperties::~GrowingSurfaceProperties(void)
{
}
