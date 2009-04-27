#pragma once
#include "ObjectPatch.h"
#include "GrowingSurface.h"
#include "ProcTree.h"

enum SCATTERMETHOD
{
	GRID =0
};

class ProcForestPatch :
	public ObjectPatch
{
public:
	ProcForestPatch(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position, Ogre::SceneNode* parent);
	~ProcForestPatch(void);

	void setTreeCount(unsigned int count){mTreeCount= count;}
	void setSurface(GrowingSurface* surface){mSurface = surface;} 
	void scatter(SCATTERMETHOD method);	
	
protected:
	std::vector<ProcTree*> mTrees;
	unsigned int mTreeCount;
	GrowingSurface* mSurface;


};
