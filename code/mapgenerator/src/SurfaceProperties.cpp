#include "SurfaceProperties.h"

SurfaceProperties::SurfaceProperties(void)
{
	mCellSize= 10.0;
	mType= CELLTYPE::HEXAGON;  
	this->mCellProperties= CellProperties(); 
}

SurfaceProperties::~SurfaceProperties(void)
{
}
