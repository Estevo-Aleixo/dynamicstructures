#pragma once


#include "Main.h"  
#include "Cell.h"
#include "Canvas.h"

class CellSystem;

class CellFactory
{
public:
	//static void Create(Ogre::SceneManager* sceneMgr, Canvas* canvas); 
	//static void Destroy(); 
	static void createCellMeshes();

	 Cell* requestCellFromPool();
	 Cell* requestCell(CellSystem* cellSystem, CELLTYPE type);
	 Cell* requestCustomCell(std::vector<Ogre::Vector2> vertices, std::vector<unsigned int> indices);
	 
	 Cell* getCellByID(unsigned int id); 
	 Cell* getCellByName(std::string name); 

	 void removeCell(unsigned int id); 
	// unsigned int getBufferSize(CELLTYPE type);  

	 Ogre::Mesh* createCustomCellMesh(std::string& name, std::vector<Ogre::Vector2> vertex, std::vector<unsigned int> index);
     
	// static CellFactory& getSingleton(void);
    // static CellFactory* getSingletonPtr(void);
		
	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);
  
	CellFactory(std::string& name, Ogre::SceneManager* sceneMgr, Canvas* canvas);
	~CellFactory(void);

	
protected:
	std::string mName; 

	unsigned int cellBufferSize;
	

	Ogre::SceneManager* mSceneMgr;
	
	Canvas* mCanvas;


	//maybe later:
	
	//std::vector<Cell*> rectangularCells; 
	//std::vector<Cell*> hexagonalCells; 
	//std::vector<Cell*> circularCells; 
	//std::vector<Cell*> customCells; 
	void createPool(CellProperties* properties, int amount); 
	
	//void extendCellPool(CELLTYPE type, unsigned int amount); 

	std::vector<Cell*> mCells;
	std::vector<bool> inUse; 



	static CellFactory* instance;

};
