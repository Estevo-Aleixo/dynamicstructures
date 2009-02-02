#include "Physical2DObject.h"

Physical2DObject::Physical2DObject(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Object2DProperties& properties, Ogre::Vector2& position, bool enabled):
mSceneMgr(sceneMgr), mWorld(canvas->getPhysicsWorld()), mEnabled(enabled)
{
	//setup ogre things
	mNode= mSceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name + "_node"); 
	//mEntity= mSceneMgr->createEntity(name +"_entity", properties.mesh_name); 
	mEntity= mSceneMgr->createEntity(name +"_entity", TRIANGLE_MESH); 
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
		b2PolygonDef triangleDef;
		
		triangleDef.vertexCount = 3;
		triangleDef.vertices[0].Set(-1.0f, 0.0f);
		triangleDef.vertices[1].Set(1.0f, 0.0f);
		triangleDef.vertices[2].Set(0.0f, 2.0f);
		mShape = mBody->CreateShape(&triangleDef); 
		mBody->SetMassFromShapes();
		
		//if (mEnabled==false)
		//	mBody->PutToSleep(); 
		//other stuff: 

}

Physical2DObject::~Physical2DObject(void)
{

}


void Physical2DObject::updatePhysics(const Ogre::FrameEvent& evt)
{
//update pos:
	mBody->ApplyImpulse(b2Vec2(100,100),b2Vec2(0,0)); 
	mNode->setPosition(mBody->GetPosition().x,mBody->GetPosition().y,0); 
//update angle:

	Radian angle=Radian(0);
	mNode->roll(angle);  

}