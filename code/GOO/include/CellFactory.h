#pragma once


#include "Main.h"  
#include "Cell.h"

class CellFactory
{
	static void Create(); 
	static void Destroy(); 

	 Cell* createNewCell(); 
	 Ogre::Mesh* createCustomCellMesh(std::string& name, std::vector<Ogre::Vector2> vertex, std::vector<unsigned int> index);
     
	 static CellFactory& getSingleton(void);
     static CellFactory* getSingletonPtr(void);
protected:
	
	std::vector<Cell*> Cells; 
	
	CellFactory(void);
	~CellFactory(void);

	void createCellMeshes();
	static CellFactory* instance;

};
