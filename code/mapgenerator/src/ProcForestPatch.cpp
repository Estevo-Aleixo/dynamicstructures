#include "ProcForestPatch.h"
#include "Surface.h"

ProcForestPatch::ProcForestPatch(std::string& name, Ogre::SceneManager* sceneMgr, Surface* surface, TreeParameters& min_params, TreeParameters& max_params, unsigned int density)
:mSceneMgr(sceneMgr),mSurface(surface), mName(name),mDensity(density), mMinParams(min_params) , mMaxParams(max_params)	
{
	scatter(SCATTERMETHOD::GRID);
}

ProcForestPatch::~ProcForestPatch(void)
{
}

void ProcForestPatch::scatter(SCATTERMETHOD method)
{

	ProcTree* newTree;
	switch(method)
	{
		case SCATTERMETHOD::GRID:
		
			for (int i=0; i < 10;i++){
				for (int j=0; j < 10;j++)
				{
					Ogre::LogManager::getSingletonPtr()->logMessage("method will create tree "+ mName+"_tree"+Ogre::StringConverter::toString((Real)(i+1)*j));
					newTree= new ProcTree(mName+"_tree"+Ogre::StringConverter::toString((Real)(i*10)+j),mSceneMgr,mMinParams,Vector2(i*20.0,j*20.0),0); 
					mTrees.push_back(newTree); 
				}
			}
			//gamasutra method:
		/*
			void CreateScatter(float x, float y, float w, float h, int rows, int cols)
			{
				float xd = w/cols;
				float yd = h/rows;
				for (int ix = 0;ix <(cols+1);ix++) {
				for (int iy = 0;iy<(rows+1);iy++) {
				float p = 0.4f;
				CreatePoint( Vector2(x+xd*ix+rndf(-p,p)*xd,y+yd*iy+rndf(-p,p)*yd));
			}
		*/
		break;   
		case SCATTERMETHOD::THINNING:
		//premyslaw ecosystem thinning

			break;
	}
}