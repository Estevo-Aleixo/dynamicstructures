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

	maxJoints=200;
	
	Ogre::SceneNode* lineNode;  
	for (int i=0; i < maxJoints; i++)
	{ 
		Movable2DObject* newJoint= new Movable2DObject(this->mName + "_joint_" + StringConverter::toString(i),mSceneMgr,Vector2(0,0),0);
		newJoint->setRootNode(mSceneMgr->getRootSceneNode()->createChildSceneNode());
		newJoint->setEntity(mSceneMgr->createEntity(newJoint->getName(),CIRCLE_POLYGON)); 
		newJoint->getRootNode()->attachObject(newJoint->getEntity());
		newJoint->getRootNode()->setVisible(false); 
		mJoints.push_back(newJoint);

		//create lines: 
		Ogre::ManualObject* line= new Ogre::ManualObject("vor_line" + StringConverter::toString((Real)i)); 
		line->begin("skeleton",RenderOperation::OT_LINE_LIST); 
		line->position(0,0,1);
		line->position(1,1,1);
		line->index(0); 
		line->index(1);
		line->end(); 
		mLines.push_back(line);
		lineNode= newJoint->getRootNode()->createChildSceneNode() ; 
		lineNode->attachObject(line); 
		lineNode->setInheritOrientation(false); 
		lineNode->setInheritScale(false); 
		mLineNodes.push_back(lineNode); 
	}
}


Skeleton2D::~Skeleton2D(void)
{

	Ogre::LogManager::getSingletonPtr()->logMessage("deleting Cell " + this->mName);

	//delete the skeleton, notify the system.
	/*
	std::vector<Movable2DObject*>::iterator itr; 

	for (itr= mJoints.begin(); itr!=mJoints.end(); itr++)
	{
		delete (*itr);
	}
	mJoints.clear();
*/

}


void Skeleton2D::update(const Ogre::FrameEvent& evt)
{
	recalculate(); 
	//std::vector<Cell*> cells;
	
	//try voronoi
	
vdg.generateVoronoi((mCellSystem->mCells));
vdg.resetIterator();

	float x1,y1,x2,y2;
	std::stringstream ss; 
	
for (int i=0; i < maxJoints;i++)
	mJoints[i]->getRootNode()->setVisible(false);

int counter=0;
while(vdg.getNext(x1,y1,x2,y2))
	{

		//checkbounds
	if ((x1 > -900 && x1 < 900) &&
		(x2 > -900 && x2 < 900) &&
		(y1 > -900 && y1 < 900) &&
		(y2 > -900 && y2 < 900)) {


		//create new movable object with position and mesh
		if (counter < this->maxJoints){
			mJoints[counter]->getRootNode()->setVisible(true);
			mJoints[counter]->setPosition(Vector2(x1,y1));
			counter++;
		}

		//teken line tussen deze twee: 
		double xDist=  x2-x1; 
		double yDist=  y2-y1;
	
		if (counter < this->maxJoints){
			mJoints[counter]->getRootNode()->setVisible(true);
			mJoints[counter]->setPosition(Vector2(x2,y2));
		
			mLines[counter-1]->beginUpdate(0);
				mLines[counter-1]->position(0,0,1); 
				mLines[counter-1]->position(xDist,yDist,1); 
				mLines[counter-1]->index(0); 
				mLines[counter-1]->index(1);
			mLines[counter-1]->end(); 
			
			counter++;
		}
	}
	}

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
