#pragma once

#include "Ogre.h"
#include "Movable2DObject.h" 

class CellSystem; 

enum SKELETON_TYPE
{
CELLS=0,
PATH=1,
OBJECTS=2,
};



enum GROW_TYPE
{
EXPAND_CIRCULAR,
EXPAND_MEDIAL_AXIS
};





//Skeleton2D is basically a simple graph
class Skeleton2D: public Movable2DObject
{
public:
	Skeleton2D(std::string& name, Ogre::Vector2& startpos, CellSystem* cellSystem, Ogre::SceneManager* sceneMgr);
	~Skeleton2D(void);

	void update(const Ogre::FrameEvent& evt);		

	void clear(); 
	void recalculate(); 
	void show();
	void hide(); 

	void addChild(Skeleton2D* child);
	Skeleton2D* getClosestChild();
	std::vector<Skeleton2D*>* getAllChildren();
	
	inline void setEffectRadius(double& radius){mRadius=radius;} 
	inline void setPushForce(double& force){mForce=force;}  

	void setPosition(Ogre::Vector2& position);
protected:

	void expand(const Ogre::FrameEvent& evt); 
	void rigid(const Ogre::FrameEvent& evt); 
	void shrink(const Ogre::FrameEvent& evt); 
	void explode(const Ogre::FrameEvent& evt); 


	double mRadius;
	double mForce;

	Ogre::SceneManager* mSceneMgr;
	CellSystem* mCellSystem;

	void addPoint(Ogre::Vector2 point);
	void findNearestPoint(Ogre::Vector2 position); 

	std::vector<Skeleton2D*> children; 

	Ogre::SceneNode* node; 
	Ogre::Entity* entity; 

};
