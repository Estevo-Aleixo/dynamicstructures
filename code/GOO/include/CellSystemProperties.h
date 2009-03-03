#pragma once
#include "Main.h"
#include "CellProperties.h"
#include "SurfaceProperties.h"

enum CELLTYPE{
	SQUARE=0,
	HEXAGON=1,
	TRIANGLE=2,
	CIRCLE=3,
	CUSTOM=4
};

class CellSystemProperties: public SurfaceProperties
{
public:
	CellSystemProperties(void);
	~CellSystemProperties(void);

	Ogre::Real getCellSize(){return mCellSize;}
	CELLTYPE getCellType(){return mType;}
	
	void setCellSize(Ogre::Real cellSize){mCellSize= cellSize;}
	void setCellType(CELLTYPE type){mType=type;}
	
	CellProperties& getCellProperties(){return mCellProperties;}

private: 
	CellProperties mCellProperties;

	Ogre::Real mCellSize;
	CELLTYPE mType;  

};
