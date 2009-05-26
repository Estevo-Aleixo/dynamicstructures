#include "Object2DProperties.h"
#include "ObjectDefinitions.h"

Object2DProperties::Object2DProperties(void)
{

	/*
	this->mMeshName= TRIANGLE_MESH;
	mScale= 1.0;
	mDensity = 1.0;

	//TODO: change: make general  
	mShapeDef.vertexCount = 3;
	mShapeDef.vertices[0].Set(-1.0f, 0.0f);
	mShapeDef.vertices[1].Set(1.0f, 0.0f);
	mShapeDef.vertices[2].Set(0.0f, 2.0f);

	Ogre::Radian startAngle= Ogre::Radian(Math::PI/2); 
	Ogre::Radian intervalAngle= Ogre::Radian(Math::TWO_PI/3); 
	Ogre::Radian angle; 
	float32 x,y;
	for (int i=0; i < 3 ;i++)
	{
		angle= startAngle + (intervalAngle* i);
		x= Math::Cos(angle);
		y= Math::Sin(angle);
		mShapeDef.vertices[i].Set(x,y); 
	} 
	mShapeDef.density=20.0f;
	mShapeDef.friction= 8.0f;
*/

}

Object2DProperties::Object2DProperties(const char* name, std::string meshName, b2ShapeDef* shapeDef, double scale)
:mName(std::string(name)), mMeshName(meshName), mShapeDef(shapeDef), mScale(scale)
{

}

b2ShapeDef* Object2DProperties::getShapeDef(double scale)
{
	b2PolygonDef* lPolygonDef= ((b2PolygonDef*)mShapeDef); 

	if (mShapeDef->type == b2ShapeType::e_polygonShape){
			b2PolygonDef* scaledDef =new b2PolygonDef();
			scaledDef->vertexCount= lPolygonDef->vertexCount;
			scaledDef->density= lPolygonDef->density;
			scaledDef->friction= lPolygonDef->friction;
			
			for (unsigned int i=0 ; i < lPolygonDef->vertexCount; i++)
			{   
				scaledDef->vertices[i].x = lPolygonDef->vertices[i].x * scale; 
				scaledDef->vertices[i].y = lPolygonDef->vertices[i].y * scale; 
			}
			
			return (b2ShapeDef* )scaledDef;
	
	}else
	{
			b2CircleDef* scaledDef=new b2CircleDef();
			scaledDef->density= mShapeDef->density;
			scaledDef->friction= mShapeDef->friction;
			scaledDef->radius= ((b2CircleDef*)mShapeDef)->radius * scale; 
			return scaledDef;
	}
}


/*
b2ShapeDef Object2DProperties::getCircleDef(double scale)
{
}
*/


/*
Object2DProperties::Object2DProperties(Object2DProperties& p)
{
	this->mDensity = p.mDensity;
	this->mFrictionConstant= p.mFrictionConstant;
	this->mMeshName= p.mMeshName;
	this->mName= p.mName;
	this->mScale= p.mScale;
	this->mShapeDef= p.getShapeDef();
}
*/

Object2DProperties::~Object2DProperties(void)
{
}
