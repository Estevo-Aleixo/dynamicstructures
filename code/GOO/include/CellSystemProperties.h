#pragma once
#include "Main.h"
#include "CellProperties.h"
#include "SystemProperties.h"

enum CELLTYPE{
	SQUARE=0,
	HEXAGON=1,
	TRIANGLE=2,
	CIRCLE=3,
	CUSTOM=4
};

class CellSystemProperties: public SystemProperties
{
public:
	CellSystemProperties(void);
	~CellSystemProperties(void);

	Ogre::Real getCellSize(){return mCellSize;}
	CELLTYPE getCellType(){return mType;}
	
	void setCellSize(Ogre::Real cellSize){mCellSize= cellSize;}
	void setCellType(CELLTYPE type){mType=type;}
	
	CellProperties& getCellProperties(){return mCellProperties;}

	std::string mName;
	std::string description; 
	std::string cellType; 
	
	std::map<const char*, int> mExtraParameters;
//, ltstr

	const char* mCellObjectName;
	unsigned int vertexDistance; 
private: 
	CellProperties mCellProperties;

	Ogre::Real mCellSize;
	CELLTYPE mType;  


};

//PROPERTIES

//SURFACE TYPE: controls much of the properties
	//-enumerate: water, ground, desert, jungle, mountains


//DENSITY
//AUTO EXPAND
//CELLTYPE
//MAX CELLS
//MAX VOLUME
//MAX CELL SIZE

//EVENT TYPES:

