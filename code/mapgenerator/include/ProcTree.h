#pragma once
#include "ProceduralObject.h"


typedef struct 
{
	unsigned int TreeLevels;
	float treeTrunkWidth; 
	float treeSpan;
} TreeParameters; 


class ProcTree :
	public ProceduralObject
{
public:
	ProcTree(std::string& name, Ogre::SceneManager* sceneMgr, TreeParameters& params, Ogre::Vector2& position = Ogre::Vector2(0,0), Ogre::SceneNode* parent = 0);
	~ProcTree(void);

protected: 
	double mRadius;
	double mHeight;
	std::vector<double>  mPlatformPositions;
private:





};
