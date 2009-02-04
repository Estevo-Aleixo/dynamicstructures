#include "Physical2DObject.h"

Physical2DObject::Physical2DObject(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Object2DProperties& properties, Ogre::Vector2& position, bool enabled):
mSceneMgr(sceneMgr), mWorld(canvas->getPhysicsWorld()),mCanvas(canvas), mEnabled(enabled)
{
	//setup ogre things
	mNode= mSceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name + "_node"); 
	//mEntity= mSceneMgr->createEntity(name +"_entity", properties.mesh_name); 
	mEntity= mSceneMgr->createEntity(name +"_entity", properties.mMeshName); 
	mNode->setVisible(true); 
	mNode->scale(Vector3(1.0,1.0,1.0)); 
	//mNode->scale(Vector3(properties.mScale,properties.mScale,properties.mScale)); 
	mNode->setPosition(position.x,position.y,0); 
	mNode->attachObject(mEntity); 

	//setup box2d things
		
		//create box2d physical body: 
	
		b2BodyDef bodyDef;
		bodyDef.position.Set(position.x, position.y);
		mBody= mWorld->CreateBody(&bodyDef); 
		//shape (just triangle for now)
		
		b2PolygonDef shapeDef= properties.getShapeDef(); 
		mShape = mBody->CreateShape(&shapeDef); 
		mBody->SetMassFromShapes();
		mBody->WakeUp(); 
		

}

Physical2DObject::~Physical2DObject(void)
{

}


void Physical2DObject::updatePhysics(const Ogre::FrameEvent& evt)
{
/*
	if (mBody->GetPosition().x < mCanvas->getAABB().lowerBound.x || mBody->GetPosition().x > mCanvas->getAABB().upperBound.x)
	{
		float32 offset= mBody->GetPosition().x - mCanvas->getAABB().lowerBound.x;  
		b2Vec2 position= mBody->GetPosition();
		position.x +=offset*1.1;	
		mBody->SetXForm(position,mBody->GetAngle());
		b2Vec2 velocity= mBody->GetLinearVelocity(); 
		velocity.x*=-1.0;
		mBody->SetLinearVelocity(velocity); 
	}
*/

//update pos:
	mNode->setPosition(mBody->GetPosition().x,mBody->GetPosition().y,0); 
//update angle:
	Ogre::LogManager::getSingletonPtr()->logMessage("x: " + StringConverter::toString(mBody->GetPosition().x));

	if (mBody->GetAngularVelocity()>0.5)
		mBody->SetAngularVelocity(0.5);

	mNode->resetOrientation();
	Radian angle= Radian(mBody->GetAngle()); 
	mNode->roll(angle);  

}