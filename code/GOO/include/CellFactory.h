#pragma once


#include "Main.h"  
#include "Cell.h"

class CellSystem;

class CellFactory
{
public:
	static void Create(Ogre::SceneManager* sceneMgr); 
	static void Destroy(); 

	 Cell* requestCell(CellSystem* cellSystem, CELLTYPE type);
	 Cell* requestCustomCell(std::vector<Ogre::Vector2> vertices, std::vector<unsigned int> indices);
	 
	 Cell* getCellByID(unsigned int id); 
	 Cell* getCellByName(std::string name); 

	 void removeCell(unsigned int id); 
	// unsigned int getBufferSize(CELLTYPE type);  

	 Ogre::Mesh* createCustomCellMesh(std::string& name, std::vector<Ogre::Vector2> vertex, std::vector<unsigned int> index);
     
	 static CellFactory& getSingleton(void);
     static CellFactory* getSingletonPtr(void);
	
	 
protected:
	Ogre::Real cellSize;	

	unsigned int cellBufferSize;
	

	Ogre::SceneManager* mSceneMgr;
	

	//maybe later:
	
	//std::vector<Cell*> rectangularCells; 
	//std::vector<Cell*> hexagonalCells; 
	//std::vector<Cell*> circularCells; 
	//std::vector<Cell*> customCells; 
	//void createPool(CELLTYPE type); 
	//void extendCellPool(CELLTYPE type, unsigned int amount); 

	std::vector<Cell*> cells;

	CellFactory(Ogre::SceneManager* sceneMgr);
	~CellFactory(void);

	void createWiredCellMeshes();
	static CellFactory* instance;

};
