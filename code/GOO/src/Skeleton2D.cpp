#include "Skeleton2D.h"
#include "CellSystem.h"

Skeleton2D::Skeleton2D(void)
{


}


Skeleton2D::Skeleton2D(std::string& name, Ogre::Vector2& startpos, CellSystem* cellSystem, Ogre::SceneManager* sceneMgr):
mCellSystem(cellSystem), mSceneMgr(sceneMgr)
{
	
	//create node
	node= mSceneMgr->getRootSceneNode()->createChildSceneNode(); 
	entity= mSceneMgr->createEntity(name + "skeleton2D","rectangular_cell"); 
	node->setPosition(startpos.x,startpos.y,0); 
	entity->setMaterialName("ambient_red");
	node->attachObject(entity);
	mPosition= startpos;
	mForce = 800.0;		//10 N/m?
}


Skeleton2D::~Skeleton2D(void)
{
	//delete the skeleton, notify the system.
	node->removeAndDestroyAllChildren(); 
	mSceneMgr->destroySceneNode(node); 
	mSceneMgr->destroyEntity(entity); 
}


void Skeleton2D::update(const Ogre::FrameEvent& evt)
{
	recalculate(); 
	//std::vector<Cell*> cells;
	std::vector<Cell*>::iterator itr;

	Ogre::Vector2 midPoint;

	b2Vec2 force; 
	midPoint.x=0;
	midPoint.y=0;
	
	for (itr = mCellSystem->mCells.begin(); itr!= mCellSystem->mCells.end(); itr++)
	{
		//calculate force
		double distance=((*itr)->getPosition()-mPosition).length();
		double magnitude= mForce - distance*3.0;
		Radian angle= Ogre::Math::ATan2(  (*itr)->getPosition().y- mPosition.y ,  (*itr)->getPosition().x-mPosition.x);
		force.x= Math::Cos(angle)*magnitude*evt.timeSinceLastFrame;
		force.y= Math::Sin(angle)*magnitude*evt.timeSinceLastFrame;

		midPoint += (*itr)->getPosition();  


		//temporary rule
		if (distance < 200)
			(*itr)->ApplyForce(force);
	} 

	midPoint /= (double)mCellSystem->mCells.size(); 
	setPosition(midPoint);

	//update children



}

void Skeleton2D::setPosition(Ogre::Vector2& position)
{
	mPosition = position;
	node->setPosition(position.x,position.y,0); 
}



void Skeleton2D::addPoint(Ogre::Vector2 point)
{


}

void Skeleton2D::findNearestPoint(Ogre::Vector2 position)
{


}

void Skeleton2D::recalculate()
{







} 

void Skeleton2D::show()
{
//show all nodes

}

void Skeleton2D::hide()
{


}


void Skeleton2D::addChild(Skeleton2D* child)
{


}

Skeleton2D* Skeleton2D::getClosestChild()
{

	return 0;
}

std::vector<Skeleton2D*>* Skeleton2D::getAllChildren()
{

	return 0; 
}

