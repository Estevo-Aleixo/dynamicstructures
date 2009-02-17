#include "Skeleton2D.h"

Skeleton2D::Skeleton2D(void)
{


}


Skeleton2D::Skeleton2D(Ogre::Vector2& startpos, CellSystem* cellSystem)
{
	

}


Skeleton2D::~Skeleton2D(void)
{
//delete the skeleton, notify the system.
}


void Skeleton2D::update(const Ogre::FrameEvent& evt)
{
	recalculate(); 

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

