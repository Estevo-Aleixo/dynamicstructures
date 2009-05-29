#pragma once
#include "ObjectPatch.h"
#include "ProcTree.h"

class Surface;

enum SCATTERMETHOD
{
	GRID = 0,
	THINNING = 1
};

struct
{
	double density; 
}typedef forestParams;



class ProcForestPatch :
	public ObjectPatch
{
public:
	ProcForestPatch(std::string& name, Ogre::SceneManager* sceneMgr, Surface* surface, TreeParameters& min_params, TreeParameters& max_params, unsigned int density = 1);
	~ProcForestPatch(void);

	void setTreeCount(unsigned int count){mTreeCount= count;}
	void setSurface(Surface* surface){mSurface = surface;} 
	void scatter(SCATTERMETHOD method);	
	void createRandomScatter();

	static forestParams loadParameters();
protected:
	std::vector<ProcTree*> mTrees;
	unsigned int mTreeCount;
	Surface* mSurface;
	Ogre::SceneManager* mSceneMgr; 
	
	Ogre::String mName;
	unsigned int mDensity;
	TreeParameters mMinParams;
	TreeParameters mMaxParams;
	
};
