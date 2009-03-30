#pragma once

#include "Main.h"


enum OBJECTSTATE
{
GROW=0,
RIGID=1,
FREE=2,
EXPLODE=3
};

class Movable2DObject
{
public:
	Movable2DObject(std::string& name, Ogre::SceneManager* sceneMgr, Ogre::Vector2& position = Ogre::Vector2(0,0), Ogre::SceneNode* parent = 0);
	~Movable2DObject(void);

	Ogre::Vector3& getVelocity(void); 
	Ogre::Vector3& getHeading(void); 
	void setRootNode(Ogre::SceneNode* node){mNode=node;} 
	Ogre::SceneNode* getRootNode(){return mNode;} 
	void setEntity(Ogre::Entity* entity){mEntity=entity;} 
	Ogre::Entity* getEntity(){return mEntity;} 
	Object2DType type; //to allow casting

	virtual void attach(Movable2DObject* object); 
	virtual void detach(); 
	
	//virtual bool update(Ogre::FrameEvent& evt);
	virtual void setPosition(Ogre::Vector2& position);
	virtual Ogre::Vector2& getPosition(){return mPos;}
	virtual void save(std::string& name); //lua script filename
	virtual void load(std::string& name); //lua script filename

	OBJECTSTATE getState(){return mState;}

	void setState(OBJECTSTATE state){mState=state;}

	inline std::string& getName(){return mName;} 
	inline void setName(std::string& name){mName=name;}
 
	void handleCollisionWith(Movable2DObject* object);

	inline const char* getEventHandlerName(){return mEventHandlerName;} 

protected:
	bool mActive;
	OBJECTSTATE mState;

	std::string mName;
	Ogre::Vector2 mPos;
	double mScale; 

	Ogre::SceneManager* mSceneMgr;
	Ogre::SceneNode* mNode; 
	Ogre::Entity* mEntity;	

	const char* mEventHandlerName;

private:



};
