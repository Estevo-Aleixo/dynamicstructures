#include "Skeleton2D.h"
#include "CellSystem.h"


#pragma warning( disable : 4482)

Skeleton2D::Skeleton2D(std::string& name, Ogre::Vector2& startpos, CellSystem* cellSystem, Ogre::SceneManager* sceneMgr):
Movable2DObject(name, sceneMgr, startpos), mCellSystem(cellSystem), mSceneMgr(sceneMgr)
{
	//create node
	mNode= mSceneMgr->getRootSceneNode()->createChildSceneNode(); 
	mEntity= mSceneMgr->createEntity(name + "skeleton2D","rectangular_cell"); 
	mNode->setPosition(startpos.x,startpos.y,0); 
	mEntity->setMaterialName("ambient_red");
	mNode->attachObject(mEntity);
	mForce = 800.0;		//10 N/m?
	mState= OBJECTSTATE::GROW;
}


Skeleton2D::~Skeleton2D(void)
{
	//delete the skeleton, notify the system.

}


void Skeleton2D::update(const Ogre::FrameEvent& evt)
{
	recalculate(); 
	//std::vector<Cell*> cells;
	



	switch((int)mState)
	{
		case OBJECTSTATE::GROW:
			this->expand(evt); 
			break;
		case OBJECTSTATE::RIGID:
			
			break;
		case OBJECTSTATE::EXPLODE:
		
			break;
		case OBJECTSTATE::FREE:
		default: 

			break; 
	}
	
	//update children



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


void Skeleton2D::expand(const Ogre::FrameEvent& evt)
{
	Ogre::Vector2 midPoint;

	b2Vec2 force; 
	midPoint.x=0;
	midPoint.y=0;

std::vector<Cell*>::iterator itr;

	for (itr = mCellSystem->mCells.begin(); itr!= mCellSystem->mCells.end(); itr++)
	{
		if ((*itr)!=0){
			//calculate force
			
			//if expanding: 

			double distance=((*itr)->getPosition()-mPos).length();
			double magnitude= mForce - distance*3.0;
			Radian angle= Ogre::Math::ATan2(  (*itr)->getPosition().y- mPos.y ,  (*itr)->getPosition().x-mPos.x);
			force.x= Math::Cos(angle)*magnitude*evt.timeSinceLastFrame;
			force.y= Math::Sin(angle)*magnitude*evt.timeSinceLastFrame;

			midPoint += (*itr)->getPosition();  

			//temporary rule
			if (distance < 200)
				(*itr)->ApplyForce(force);
		}
	} 

	midPoint /= (double)mCellSystem->mCells.size(); 
	setPosition(midPoint);

}

void Skeleton2D::rigid(const Ogre::FrameEvent& evt)
{


}

void Skeleton2D::shrink(const Ogre::FrameEvent& evt)
{


}

void Skeleton2D::explode(const Ogre::FrameEvent& evt)
{


} 

void Skeleton2D::setPosition(Ogre::Vector2& position)
{
	mPos= position; 
	mNode->setPosition(position.x,position.y,0);
}