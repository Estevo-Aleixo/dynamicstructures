#include "Physical2DObject.h"

Physical2DObject::Physical2DObject(std::string& name, Canvas* canvas, Ogre::SceneManager* sceneMgr, Object2DProperties* properties, Ogre::Vector2& position, bool enabled)
:Movable2DObject(name, sceneMgr, position), mWorld(canvas->getPhysicsWorld()), mCanvas(canvas)
{
	//setup ogre things
	mNode= mSceneMgr->getSceneNode("CanvasRootNode")->createChildSceneNode(name + "_node"); 
	mEntity= mSceneMgr->createEntity(name +"_entity", properties->mMeshName); 
	mNode->setVisible(true); 
	mNode->scale(Vector3(properties->mScale,properties->mScale,properties->mScale)); 
	//mNode->scale(Vector3(1.0,1.0,1.0)); 
	mNode->setPosition(position.x,position.y,0); 
	mNode->attachObject(mEntity); 

	//setup box2d things
	//create box2d physical body: 
	
		b2BodyDef bodyDef;
		mPos=position;
		bodyDef.position.Set(position.x, position.y);
		mBody= mWorld->CreateBody(&bodyDef); 
		//shape (just triangle for now)
		
		b2ShapeDef* shapeDef= properties->getShapeDef(); 
		mShape = mBody->CreateShape((b2PolygonDef*)shapeDef); 
		mBody->SetMassFromShapes();
		mBody->WakeUp(); 
		mScale=1.0;
		this->mProperties = properties; 
		 mActive=true;

		//b2FilterData lFilter; 
		//lFilter.groupIndex= mProperties->layer;
		//Ogre::LogManager::getSingletonPtr()->logMessage(name + "filter id: " + StringConverter::toString((int)mProperties->layer)); 
		//mShape->SetFilterData(mProperties->filterData); 
		//mWorld->Refilter(mShape); 
}

Physical2DObject::~Physical2DObject(void)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("deleting physical object " +mName); 
	
	//ogre:
	mNode->removeAndDestroyAllChildren(); 
	mSceneMgr->destroySceneNode(mNode); 
	mSceneMgr->destroyEntity(mEntity); 

	//physics: 
	mBody->DestroyShape(mShape); 
	mWorld->DestroyBody(mBody); 

}


void Physical2DObject::updatePhysics(const Ogre::FrameEvent& evt)
{

//update pos:
	mNode->setPosition(mBody->GetPosition().x,mBody->GetPosition().y,0); 
//update angle:
	mPos= Vector2(mBody->GetPosition().x, mBody->GetPosition().y); 

	if (mBody->GetAngularVelocity()>0.5)
		mBody->SetAngularVelocity(0.5);

	mNode->resetOrientation();
	Radian angle= Radian(mBody->GetAngle()); 
	mNode->roll(angle);  

}


void Physical2DObject::setScale(double& scale)
{

double newScale= scale / mScale;
//set node size:

mNode->scale(Vector3(newScale,newScale,newScale)); 
mScale = scale;
//CHANGE
		mBody->DestroyShape(mShape); 	
		b2ShapeDef* shapeDef= mProperties->getShapeDef(scale);
		mShape = mBody->CreateShape(shapeDef); 
		delete shapeDef;
		mBody->SetMassFromShapes();
		mBody->WakeUp(); 

}


void Physical2DObject::halt()
{
	mActive=false; 
	//store lin and angular speed
	mPrevAngVelocity= mBody->GetAngularVelocity(); 
	mPrevLinVelocity= mBody->GetLinearVelocity(); 
	mBody->SetLinearVelocity(b2Vec2(0,0)); 
	mBody->SetAngularVelocity(0.0); 
} 

void Physical2DObject::proceed()
{
	mActive=true;
	this->mBody->SetAngularVelocity(mPrevAngVelocity); 
	this->mBody->SetLinearVelocity(mPrevLinVelocity);  
} 
