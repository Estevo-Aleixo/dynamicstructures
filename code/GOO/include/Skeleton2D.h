#pragma once

#include "Ogre.h"


class CellSystem; 

enum SKELETON_TYPE
{
CELLS=0,
PATH=1,
OBJECTS=2,
};


//Skeleton2D is basically a simple graph
class Skeleton2D
{
public:
	Skeleton2D(void);
	Skeleton2D(Ogre::Vector2& startpos, CellSystem* cellSystem);
	//Skeleton2D(Ogre::Vector2& startpos, ObjectSystem* objectSystem);
	//Skeleton2D(Ogre::Vector2& startpos, PathSystem* pathSystem);
	~Skeleton2D(void);

	void update(const Ogre::FrameEvent& evt);		

	void clear(); 
	void recalculate(); 
	void show();
	void hide(); 

	void addChild(Skeleton2D* child);
	Skeleton2D* getClosestChild();
	std::vector<Skeleton2D*>* getAllChildren();
	


protected:
	void addPoint(Ogre::Vector2 point);
	void findNearestPoint(Ogre::Vector2 position); 

	std::vector<Skeleton2D*> children; 

	Ogre::SceneNode* node; 
	Ogre::Entity* entity; 

};
