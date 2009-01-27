#include "Cell.h"


Cell::Cell(std::string name, unsigned int id,Ogre::SceneManager* sceneMgr, CELLTYPE type, Ogre::Real size, Ogre::Vector2 position):
mName(name), mID(id), mType(type),mSize(size), mPos(position), mSceneMgr(sceneMgr)
{
	
	node= sceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name + "_node"); 
	
	switch(type)
	{
		case CELLTYPE::SQUARE:
			this->outlineEntity= mSceneMgr->createEntity(name +"_entity",SQUARE_NAME); 		
			break;
		case CELLTYPE::HEXAGON:
			this->outlineEntity= mSceneMgr->createEntity(name +"_entity",HEXAGON_NAME); 		
			break;
		case CELLTYPE::CIRCLE:
			this->outlineEntity= mSceneMgr->createEntity(name +"_entity",CIRCLE_NAME); 	
			break;
		default:
			break;
	}

	node->setVisible(true); 
	node->scale(Vector3(size,size,size)); 
	node->setPosition(position.x,position.y,0); 
	node->attachObject(outlineEntity); 


}



Cell::~Cell(void)
{

}
