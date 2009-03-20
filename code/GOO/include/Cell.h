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
	std::string getName(){return mName;} 

	//SETTERS
	void setType();


	Cell(std::string name, unsigned int id,CellSystem* system, Ogre::SceneManager* sceneMgr, Object2DProperties* properties, Canvas* canvas, Ogre::Vector2 position= Vector2(0,0), bool enabled=false);
	~Cell(void);

	
	void setCellSystem(CellSystem* cellSystem){mSystem = cellSystem;}
	void setProperties(CellProperties* properties){mProperties = properties;} 
	
	void setDivideDirection(Ogre::Radian direction){mDivideDirection = direction;} 
	void divide(); 
	
	bool frameStarted(const FrameEvent &evt); 
	bool frameEnded(const FrameEvent &evt);

	void setCellChild(Cell* cellBuddy)
	{
		mCellChild= cellBuddy; 
		
		if (cellBuddy!=0)
			mCellChild->setParent(this);
		//else
		//	this->mLineNode->setVisible(false);
	}
	void setOrigin(Ogre::Vector2& origin){mOrigin=origin;} 
	Cell* mCellChild; //TODO change to child
	Cell* mCellParent; 

	void showPolyLine(bool on){mShowPolyLine = on;mLineNode->setVisible(on);}
	void updatePolyLine();

	void setParent(Cell* parent){mCellParent=parent;} 
	CellSystem* getCellSystem(){return mSystem;} 
protected: 

	bool mShowPolyLine;

	Ogre::ManualObject* mPolyLine;
	Ogre::SceneNode* mLineNode;
	Ogre::SceneNode* mCenterNode;
	Ogre::Entity* mCenterEntity;

	Vector2 mOrigin;

	int cellCount;
	Ogre::SceneManager* mSceneMgr;
	std::string mName; 
	unsigned int mID;
	CellProperties* mCellProperties; //properties will be handled by means of scripting
	CELLTYPE mType;
	//Ogre::Vector2 mPos;
	Ogre::Real mSize;
	Ogre::ColourValue colour;
	
	//Ogre::SceneNode* node; 
	//Ogre::Entity* outlineEntity; 

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

