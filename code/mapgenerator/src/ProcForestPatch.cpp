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


	switch(method)
	{
		case SCATTERMETHOD::GRID:
			
					createRandomScatter(); 
							break;   
		case SCATTERMETHOD::THINNING:
		//premyslaw ecosystem thinning

			break;
	}
}
void ProcForestPatch::createRandomScatter()
{	
	ProcTree* newTree;
double averageTreeSpan= 10.0;
//averageTreeSpan = (mMin_Params.treeSpan + mMax_Params.treeSpan) / 2

//cols
int cols = (int) (mSurface->getWidth()  / (averageTreeSpan / mDensity));
//rows
int rows = (int) (mSurface->getHeight() / (averageTreeSpan / mDensity));


Ogre::Real xd= averageTreeSpan / mDensity; 
Ogre::Real yd= averageTreeSpan / mDensity; 

Vector2 pos;
Ogre::Real p= 0.4;


	for (int ix=0; ix < cols;ix++){
				for (int iy=0; iy < rows; iy++)
				{
					Ogre::LogManager::getSingletonPtr()->logMessage("method will create tree "+ mName+"_tree"+Ogre::StringConverter::toString((Real)(ix+1)*iy));
					
					pos.x= mSurface->getPosition().x + xd*ix+Ogre::Math::RangeRandom(-p,p)*ix;
					pos.y= mSurface->getPosition().y + yd*iy+Ogre::Math::RangeRandom(-p,p)*iy;
					newTree= new ProcTree(mName+"_tree"+Ogre::StringConverter::toString((Real)(ix*10)+iy),mSceneMgr,mMinParams,pos,0); 
					newTree->setScale(5.0); 
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






}