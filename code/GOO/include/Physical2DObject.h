#pragma once
#include "Main.h"
#include "Canvas.h" 
#include "Object2DProperties.h"


class Physical2DObject
{
public:
	Physical2DObject(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Object2DProperties* properties, Ogre::Vector2& position, bool enabled=true);
	~Physical2DObject(void);

	virtual void updatePhysics(const Ogre::FrameEvent& evt);
	inline b2Body* getBody(){return mBody;} 
	inline Ogre::SceneNode* getSceneNode(){return mNode;} 
	inline bool isEnabled(){return mEnabled;} 
	void enable(bool on)
	{
		if (on==true)
			mBody->WakeUp();
		else
			mBody->PutToSleep();
		
		mEnabled = on;
	}  

	void setPosition(Ogre::Vector2& p)
	{
		mNode->setPosition(p.x,p.y,0);
		mBody->SetXForm(b2Vec2((float)p.x,(float)p.y) ,0.0);
	}; 
	void setAngle(float& angle){mBody->SetXForm(mBody->GetPosition(),angle);}
	
	inline double getScale(){return mScale;}
	void setScale(double& scale);

private: 
	double mScale; 

	Canvas* mCanvas;
	bool mEnabled; 
//ogre 
	Ogre::SceneManager* mSceneMgr;
	Ogre::SceneNode* mNode; 
	Ogre::Entity* mEntity;	

//physics

	//body
	Object2DProperties* mProperties;
	b2Body* mBody;	
	//world
	b2World* mWorld;
	b2Shape* mShape; 


//shape

//blaat

};
