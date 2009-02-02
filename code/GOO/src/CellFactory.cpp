#include "CellFactory.h"

//CellFactory* CellFactory::instance=0;

/*
void CellFactory::Create(Ogre::SceneManager* sceneMgr, Canvas* canvas)
{
	
if (!instance)
	instance= new CellFactory(sceneMgr, canvas); 

}

void CellFactory::Destroy()
{


}

*/
CellFactory::~CellFactory(void)
{
}


CellFactory::CellFactory(std::string& name, Ogre::SceneManager* sceneMgr, Canvas* canvas):
mName(name), mSceneMgr(sceneMgr), mCanvas(canvas)
{
	mCanvas->addCellFactory(this); 

	cellBufferSize=1000;

	//create triangle pool: 
	CellProperties* triangleProperties= new CellProperties(); 
	triangleProperties->mesh_name = TRIANGLE_MESH; 
	triangleProperties->mFrictionConstant = 1.0; 
	triangleProperties->mScale = 1.0;
	triangleProperties->mMass = 1.0;
	
	this->createPool(triangleProperties,50); 
}


void CellFactory::createCellMeshes()
{		
	Real cellSize= 1.0;
	Ogre::ColourValue colour=  Ogre::ColourValue(); 
	Ogre::ManualObject* cellHex; 
	Ogre::ManualObject* cellSquare; 
	Ogre::ManualObject* cellTriangle; 

//create square mesh
	cellSquare= new Ogre::ManualObject("wireCellSquare"); 
	cellSquare->begin("square_cell",RenderOperation::OT_TRIANGLE_LIST); 
	
	cellSquare->position(Vector3(-0.5*cellSize,-0.5*cellSize,0));
	cellSquare->position(Vector3(0.5*cellSize,-0.5*cellSize,0));
	cellSquare->position(Vector3(0.5*cellSize,0.5*cellSize,0));
	cellSquare->position(Vector3(-0.5*cellSize,0.5*cellSize,0));

	cellSquare->quad(0,1,2,3); 


	cellSquare->end(); 
	cellSquare->convertToMesh(SQUARE_MESH);  


//create hexagon mesh 
	Ogre::Radian angle= Ogre::Radian(Math::TWO_PI /6); 
	Ogre::Real x,y; 
	cellHex= new Ogre::ManualObject("wireCellHex"); 
	cellHex->clear(); 
	cellHex->begin("hexagon_cell",RenderOperation::OT_LINE_LIST); 

	for (int i=0; i < 6 ;i++)
	{
		x= Math::Cos(angle * i);
		y= Math::Sin(angle * i);
		cellHex->position(x,y,0); 
		cellHex->colour(colour); 
	} 
	for (int i=1; i < 6 ;i++){
		cellHex->index(i-1);	
		cellHex->index(i);	
	}
	cellHex->index(5);
	cellHex->index(0);
	cellHex->end(); 

	cellHex->convertToMesh(HEXAGON_LINE_MESH);  

//create triangle
	cellTriangle= new Ogre::ManualObject("cellTriangle"); 
	cellTriangle->clear(); 
	cellTriangle->begin("hexagon_cell",RenderOperation::OT_TRIANGLE_LIST); 

	cellTriangle->position(0,1,0); 
	cellTriangle->position(-0.8,-0.4,0); 
	cellTriangle->position(0.8,-0.4,0); 

	cellTriangle->colour(colour); 	
	cellTriangle->triangle(0,1,2);

	cellTriangle->end(); 

	cellTriangle->convertToMesh(TRIANGLE_MESH);  


//create circle (fake: create sprite)


}

Ogre::Mesh* CellFactory::createCustomCellMesh(std::string& name, std::vector<Ogre::Vector2> vertex, std::vector<unsigned int> index)
{
	Ogre::Mesh* mesh;

	return mesh;
}



Cell* CellFactory::requestCell(CellSystem* cellSystem, CELLTYPE type)
{
	//todo alter!
	CellProperties* tempProperties = new CellProperties(); 
	Cell* newCell= new Cell("cell"+ Ogre::StringConverter::toString((int)mCells.size()),mCells.size(),mSceneMgr, tempProperties, mCanvas); 
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

	for(int i=0 ; i < amount; i++)
	{
		//create new: 
		mCells.push_back(new Cell(mName+std::string("_Cell_")+ StringConverter::toString(i),i,mSceneMgr,properties,mCanvas));  
		inUse.push_back(false); 
	}

}
	