#pragma once

#include "Main.h"


class Object2DProperties
{
public:
	Object2DProperties(void);
	Object2DProperties(const char* name, std::string meshName, b2ShapeDef* shapeDef, double scale= 1.0);
	//Object2DProperties(Object2DProperties& p);
	~Object2DProperties(void);

	std::string mName; 
	std::string mMeshName;
	std::string mMaterialName;
	unsigned int type; 
	double mDensity;
	double mScale;
	double mFrictionConstant;
	inline b2ShapeDef* getShapeDef(){return mShapeDef;}
	b2ShapeDef* getShapeDef(double scale);
	b2CircleDef getCircleDef(double scale);
	
	layerID layer;
	b2FilterData filterData; 
private: 
	//b2PolygonDef mShapeDef; 
	//b2CircleDef mCircleDef; 	
	b2ShapeDef* mShapeDef;
};
