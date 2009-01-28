#include "CellFactory.h"

CellFactory* CellFactory::instance=0;

void CellFactory::Create(Ogre::SceneManager* sceneMgr)
{
	
if (!instance)
	instance= new CellFactory(sceneMgr); 

}

void CellFactory::Destroy()
{


}
CellFactory::~CellFactory(void)
{
}


CellFactory::CellFactory(Ogre::SceneManager* sceneMgr)
{
	mSceneMgr= sceneMgr;
	cellSize=1.0;
	cellBufferSize=1000;
	createWiredCellMeshes();

	//create rectangular cells 
	//createPool(CELLTYPE::SQUARE); 
	//create hexagonal cells
	//createPool(CELLTYPE::HEXAGON); 

}


void CellFactory::createWiredCellMeshes()
{		
	Ogre::ManualObject* cell; 
	Ogre::ColourValue colour=  Ogre::ColourValue(); 

	cell= new Ogre::ManualObject("wireCell"); 
//create square mesh
	cell->begin("square_cell",RenderOperation::OT_LINE_LIST); 
	cell->position(Vector3(-0.5*cellSize,0.5*cellSize,0));
	cell->colour(colour); 
	cell->position(Vector3(0.5*cellSize,0.5*cellSize,0));
	cell->colour(colour); 
	cell->position(Vector3(0.5*cellSize,-0.5*cellSize,0));
	cell->colour(colour); 
	cell->position(Vector3(-0.5*cellSize,-0.5*cellSize,0));
	cell->colour(colour); 

	cell->index(0);
	cell->index(3);
	cell->index(3);
	cell->index(2);
	cell->index(2);
	cell->index(1);
	cell->index(1);
	cell->index(0);
	cell->end(); 
	cell->convertToMesh(SQUARE_LINE_MESH);  

//create hexagon mesh 
	Ogre::Radian angle= Ogre::Radian(Math::TWO_PI /6); 
	Ogre::Real x,y; 
	cell->clear(); 
	cell->begin("hexagon_cell",RenderOperation::OT_LINE_LIST); 

	for (int i=0; i < 6 ;i++)
	{
		x= Math::Cos(angle * i);
		y= Math::Sin(angle * i);
		cell->position(x,y,0); 
		cell->colour(colour); 
	} 
	for (int i=1; i < 6 ;i++){
		cell->index(i-1);	
		cell->index(i);	
	}
	cell->index(5);
	cell->index(0);
	cell->end(); 

	cell->convertToMesh(HEXAGON_LINE_MESH);  

//create circle (fake: create sprite)


}

Ogre::Mesh* CellFactory::createCustomCellMesh(std::string& name, std::vector<Ogre::Vector2> vertex, std::vector<unsigned int> index)
{
	Ogre::Mesh* mesh;

	return mesh;
}



CellFactory& CellFactory::getSingleton(void)
{
	return *instance;
}
CellFactory* CellFactory::getSingletonPtr(void)
{
	return instance;
}


Cell* CellFactory::requestCell(CellSystem* cellSystem, CELLTYPE type)
{
	//todo alter!
	Cell* newCell= new Cell("cell"+ Ogre::StringConverter::toString((int)cells.size()),cells.size(),mSceneMgr, cellSystem); 
	cells.push_back(newCell); 
	return newCell; 
}

Cell* CellFactory::requestCustomCell(std::vector<Ogre::Vector2> vertices, std::vector<unsigned int> indices)
{
	Cell* newCell; //= new Cell("cell"+ Ogre::StringConverter::toString((int)cells.size()),cells.size(), ); 
	cells.push_back(newCell); 
	return newCell; 

}
	 
Cell* CellFactory::getCellByID(unsigned int id)
{
	return cells.at(id); 
} 

Cell* CellFactory::getCellByName(std::string name)
{
	Cell* newCell;

	return newCell;
}

void removeCell(unsigned int id)
{
	//delete 

}