#pragma once

#include "Main.h"
#include "CellProperties.h"

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
	CELLTYPE getType(){return type;}
	Ogre::Vector2& getPosition(){return pos;}
	
	//SETTERS
	void setType();
	void setPosition(Ogre::Vector2& p){pos=p;}

	Cell(void);
	~Cell(void);

protected: 
	std::string name; 
	unsigned int ID;
	CellProperties* properties; //properties will be handled by means of scripting
	CELLTYPE type;
	Ogre::Vector2 pos;

	Ogre::SceneNode* node; 
	Ogre::Entity* ent; 
	
};

