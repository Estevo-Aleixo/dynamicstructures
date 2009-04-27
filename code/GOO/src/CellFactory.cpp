#include "CellFactory.h"


CellFactory::~CellFactory(void)
{
}


CellFactory::CellFactory(std::string& name, Ogre::SceneManager* sceneMgr, Canvas* canvas):
mName(name), mSceneMgr(sceneMgr), mCanvas(canvas)
{
	mCanvas->addCellFactory(this); 

	cellBufferSize=1000;

	//create triangle pool: 
	//CellProperties* triangleProperties= new CellProperties(); 
	//triangleProperties->mesh_name = TRIANGLE_MESH; 
	//triangleProperties->mFrictionConstant = 1.0; 
	//triangleProperties->mScale = 1.0;
	//triangleProperties->mMass = 1.0;
	
	//this->createPool(triangleProperties,100); 
}


void CellFactory::createCellMeshes()
{		
}

Ogre::Mesh* CellFactory::createCustomCellMesh(std::string& name, std::vector<Ogre::Vector2> vertex, std::vector<unsigned int> index)
{
	Ogre::Mesh* mesh;

	return mesh;
}



Cell* CellFactory::createCell(Object2DProperties* props,GrowingSurface* system, Vector2& position)
{
	//todo alter!
	Cell* newCell= new Cell("cell"+ Ogre::StringConverter::toString((int)mCells.size()),mCells.size(),system,mSceneMgr, props, mCanvas, position); 
	mCells.push_back(newCell); 
	return newCell; 
}


Cell* CellFactory::requestCellFromPool()
{
	//todo alter!
	for (int i = 0; i < mCells.size(); i++)
	{
		if (inUse[i]==false){
			inUse[i]=true;
			return mCells[i];
		}
	}

	return 0; 
}



Cell* CellFactory::requestCustomCell(std::vector<Ogre::Vector2> vertices, std::vector<unsigned int> indices)
{
	Cell* newCell; //= new Cell("cell"+ Ogre::StringConverter::toString((int)cells.size()),cells.size(), ); 
	mCells.push_back(newCell); 
	return newCell; 

}
	 
Cell* CellFactory::getCellByID(unsigned int id)
{
	return mCells.at(id); 
} 

Cell* CellFactory::getCellByName(std::string name)
{
	Cell* newCell;

	return newCell;
}

void  CellFactory::removeCell(unsigned int id)
{
	//delete 

}

bool  CellFactory::frameStarted(const FrameEvent &evt)
{
	return true;
}

bool  CellFactory::frameEnded(const FrameEvent &evt)
{

	return true;
}

void CellFactory::createPool(CellProperties* properties, int amount)
{

	//for(int i=0 ; i < amount; i++)
	//{
	//	//create new: 
//		mCells.push_back(new Cell(mName+std::string("_Cell_")+ StringConverter::toString(i),i,mSceneMgr,properties,mCanvas));  
//		inUse.push_back(false); 
//	}

}
	