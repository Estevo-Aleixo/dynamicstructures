#pragma once

#include "Main.h"
#include "CellProperties.h"

#define SQUARE_NAME "rectangular_cell"
#define HEXAGON_NAME "hexagon_cell"
#define CIRCLE_NAME "NONE"



//cell types
enum CELLTYPE{
	SQUARE=0,
	HEXAGON=1,
	CIRCLE=2,
	CUSTOM=3
};

class Cell
{
public:

	//GETTERS
	CELLTYPE getType(){return mType;}
	Ogre::Vector2& getPosition(){return mPos;}
	
	//SETTERS
	void setType();
	void setPosition(Ogre::Vector2& p){mPos=p; node->setPosition(p.x,p.y,0);}

	Ogre::SceneNode* getNode(){return node;}

	Cell(std::string name, unsigned int id, Ogre::SceneManager* sceneMgr, CELLTYPE type, Ogre::Real size = 1.0, Ogre::Vector2 position= Vector2(0,0));
	~Cell(void);

protected: 
	Ogre::SceneManager* mSceneMgr;
	std::string mName; 
	unsigned int mID;
	CellProperties* properties; //properties will be handled by means of scripting
	CELLTYPE mType;
	Ogre::Vector2 mPos;
	Ogre::Real mSize;
	Ogre::ColourValue colour;
	
	Ogre::SceneNode* node; 
	Ogre::Entity* outlineEntity; 
	
};

