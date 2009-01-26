#include "CellFactory.h"

CellFactory* CellFactory::instance=0;

void CellFactory::Create()
{
if (!instance)
	instance= new CellFactory(); 

}

void CellFactory::Destroy()
{


}
CellFactory::~CellFactory(void)
{
}


CellFactory::CellFactory(void)
{
	createCellMeshes(); 
	

}


void CellFactory::createCellMeshes()
{
//create square

//create hexagon 

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