#pragma once

#include "Main.h"
#include "CellProperties.h"
#include "CellSystemProperties.h"


#define SQUARE_MESH "rectangular_cell"
#define HEXAGON_LINE_MESH "hexagon_cell"
#define TRIANGLE_MESH "triangle_cell"
#define CIRCLE_LINE_MESH "NONE"


//cell types
/*
enum CELLTYPE{
	SQUARE=0,
	HEXAGON=1,
	CIRCLE=2,
	CUSTOM=3
};
*/

class CellSystem;

class Cell: public Physical2DObject; 
{
public:

	//GETTERS
	CELLTYPE getType(){return mType;}
	Ogre::Vector2& getPosition(){return mPos;}
	std::string getName(){return mName;} 

	//SETTERS
	void setType();
	void setPosition(Ogre::Vector2& p){mPos=p; node->setPosition(p.x,p.y,0);}

	Ogre::SceneNode* getNode(){return node;}

	Cell(std::string name, unsigned int id, Ogre::SceneManager* sceneMgr, CellSystem* cellSystem, Ogre::Vector2 position= Vector2(0,0));
	~Cell(void);

	void setDivideDirection(Ogre::Radian direction){mDivideDirection = direction;} 
	void divide(); 
	
	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);


protected: 
	int cellCount;
	Ogre::SceneManager* mSceneMgr;
	std::string mName; 
	unsigned int mID;
	CellProperties mProperties; //properties will be handled by means of scripting
	CELLTYPE mType;
	Ogre::Vector2 mPos;
	Ogre::Real mSize;
	Ogre::ColourValue colour;
	
	Ogre::SceneNode* node; 
	Ogre::Entity* outlineEntity; 

	CellSystem* mSystem;
	Ogre::Radian mDivideDirection; 
	Ogre::Radian mDirectionInterval;

	CellProperties retrieveProperties(CellSystem* system); 


	//TEMP: 
	Ogre::Real mTimePassed;
	Ogre::Real mCloneIntervalTime;
	
	MovableText* mLabel;
	Ogre::SceneNode* mLabelNode;


};

