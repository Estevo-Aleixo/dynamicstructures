#pragma once

#include "Movable2DObject.h"
#include "Canvas.h" 
#include "Object2DProperties.h"

class Physical2DObject: public Movable2DObject
{
public:
	Physical2DObject(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Object2DProperties* properties, Ogre::Vector2& position, bool enabled=true);
	~Physical2DObject(void);

	virtual void updatePhysics(const Ogre::FrameEvent& evt);
	inline b2Body* getBody(){return mBody;} 
	inline Ogre::SceneNode* getSceneNode(){return mNode;} 
	inline bool isEnabled(){return mActive;} 
	
	void enable(bool on)
	{
		if (on==true)
			mBody->WakeUp();
		else
			mBody->PutToSleep();
		
		mActive = on;
	}  

	void setPosition(Ogre::Vector2& p)
	{
		mPos = p;
		mNode->setPosition(p.x,p.y,0);
		mBody->SetXForm(b2Vec2((float)p.x,(float)p.y) ,0.0);
	}; 


	Ogre::Vector2& getPosition()
	{return mPos;}

	void setAngle(float& angle){mBody->SetXForm(mBody->GetPosition(),angle);}
	
	inline double getScale(){return mScale;}
	void setScale(double& scale);

	void ApplyForce(b2Vec2& force)
	{
		if (mActive == true) 
			mBody->ApplyForce(force, mBody->GetPosition()); 
	}
	
	void setLinearVelocity(b2Vec2& vel)
	{
		mBody->SetLinearVelocity(vel); 
	}

	void halt(); 
	void proceed(); 

	void moveTo(Ogre::Vector2& position); 

	b2Vec2 mPrevLinVelocity;
	float mPrevAngVelocity;
protected:

	//physics
	Canvas* mCanvas;
	Object2DProperties* mProperties;

	//body
	b2Body* mBody;	

	//world
	b2World* mWorld;
	b2Shape* mShape; 

	Ogre::Vector2 goalPosition;
	
};
