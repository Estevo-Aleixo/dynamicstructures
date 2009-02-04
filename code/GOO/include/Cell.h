#pragma once

#include "Main.h"
#include "CellProperties.h"
#include "CellSystemProperties.h"
#include "Physical2DObject.h"




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

class Cell: public Physical2DObject
{
public:

	//GETTERS
	CELLTYPE getType(){return mType;}
	Ogre::Vector2& getPosition(){return mPos;}
	std::string getName(){return mName;} 

	//SETTERS
	void setType();

	Ogre::SceneNode* getNode(){return node;}

	Cell(std::string name, unsigned int id, Ogre::SceneManager* sceneMgr, Object2DProperties& properties, Canvas* canvas, Ogre::Vector2 position= Vector2(0,0), bool enabled=false);
	~Cell(void);

	
	void setCellSystem(CellSystem* cellSystem){mSystem = cellSystem;}
	void setProperties(CellProperties* properties){mProperties = properties;} 
	
	void setDivideDirection(Ogre::Radian direction){mDivideDirection = direction;} 
	void divide(); 
	
	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);


protected: 
	int cellCount;
	Ogre::SceneManager* mSceneMgr;
	std::string mName; 
	unsigned int mID;
	CellProperties* mProperties; //properties will be handled by means of scripting
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

