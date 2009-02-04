#include "CellSystemProperties.h"

CellSystemProperties::CellSystemProperties(void)
{
	mCellSize= 10.0;
	mType= CELLTYPE::HEXAGON;  
	this->mCellProperties= CellProperties(); 
}

CellSystemProperties::~CellSystemProperties(void)
{
}
