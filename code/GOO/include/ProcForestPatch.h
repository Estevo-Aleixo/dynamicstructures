#pragma once
#include "ObjectPatch.h"
#include "ProcTree.h"

class GrowingSurface;

enum SCATTERMETHOD
{
	GRID = 0,
	THINNING = 1
};

class ProcForestPatch :
	public ObjectPatch
{
public:
	ProcForestPatch(std::string& name, Ogre::SceneManager* sceneMgr, GrowingSurface* surface, TreeParameters& min_params, TreeParameters& max_params, unsigned int density = 1);
	~ProcForestPatch(void);

	void setTreeCount(unsigned int count){mTreeCount= count;}
	void setSurface(GrowingSurface* surface){mSurface = surface;} 
	void scatter(SCATTERMETHOD method);	
	
protected:
	std::vector<ProcTree*> mTrees;
	unsigned int mTreeCount;
	GrowingSurface* mSurface;
	Ogre::SceneManager* mSceneMgr; 
	
	Ogre::String mName;
	unsigned int mDensity;
	TreeParameters mMinParams;
	TreeParameters mMaxParams;
	
};
