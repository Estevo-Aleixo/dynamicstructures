#pragma once

#include "Ogre.h"
#include "Movable2DObject.h" 


//first method for generating a suitable skeleton
#include "VoronoiDiagramGenerator.h"

//TODO: #include "SimpleSkeletonGenerator.h"


class GrowingSurface; 

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
	Skeleton2D(std::string& name, Ogre::Vector2& startpos, GrowingSurface* GrowingSurface, Ogre::SceneManager* sceneMgr);
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


	std::vector<Movable2DObject*> mJoints;
	std::vector<Ogre::SceneNode*> mLineNodes;
	std::vector<Ogre::ManualObject*> mLines;


protected:
	unsigned int maxJoints; 
	VoronoiDiagramGenerator vdg; 

	void expand(const Ogre::FrameEvent& evt); 
	void rigid(const Ogre::FrameEvent& evt); 
	void shrink(const Ogre::FrameEvent& evt); 
	void explode(const Ogre::FrameEvent& evt); 


	double mRadius;
	double mForce;

	Ogre::SceneManager* mSceneMgr;
	GrowingSurface* mGrowingSurface;

	void addPoint(Ogre::Vector2 point);
	void findNearestPoint(Ogre::Vector2 position); 

	std::vector<Skeleton2D*> children; 

	Ogre::SceneNode* node; 
	Ogre::Entity* entity; 

};
