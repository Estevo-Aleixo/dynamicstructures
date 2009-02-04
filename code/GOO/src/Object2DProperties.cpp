#include "Object2DProperties.h"
#include "ObjectDefinitions.h"

Object2DProperties::Object2DProperties(void)
{
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


}

Object2DProperties::Object2DProperties(const char* name, std::string meshName, b2PolygonDef& shapeDef, double scale)
:mName(std::string(name)), mMeshName(meshName), mShapeDef(shapeDef), mScale(scale)
{


}



Object2DProperties::~Object2DProperties(void)
{
}
