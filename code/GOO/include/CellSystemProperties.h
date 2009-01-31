#pragma once
#include "Main.h"

enum CELLTYPE{
	SQUARE=0,
	HEXAGON=1,
	TRIANGLE=2,
	CIRCLE=3,
	CUSTOM=4
};

class CellSystemProperties
{
public:
	CellSystemProperties(void);
	~CellSystemProperties(void);

	Ogre::Real getCellSize(){return mCellSize;}
	CELLTYPE getCellType(){return mType;}
	
	void setCellSize(Ogre::Real cellSize){mCellSize= cellSize;}
	void setCellType(CELLTYPE type){mType=type;}


private: 
	Ogre::Real mCellSize;
	CELLTYPE mType;  

};
