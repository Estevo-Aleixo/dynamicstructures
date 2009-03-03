#pragma once

#include "Main.h"


class Object2DProperties
{
public:
	Object2DProperties(void);
	Object2DProperties(const char* name, std::string meshName, b2PolygonDef& shapeDef, double scale= 1.0);
	//Object2DProperties(Object2DProperties& p);
	~Object2DProperties(void);

	std::string mName; 
	std::string mMeshName;
	unsigned int type; 
	double mDensity;
	double mScale;
	double mFrictionConstant;
	inline b2PolygonDef getShapeDef(){return mShapeDef;}
	b2PolygonDef getShapeDef(double scale);
	
	layerID layer;
	b2FilterData filterData; 
private: 
	b2PolygonDef mShapeDef; 

	

};
