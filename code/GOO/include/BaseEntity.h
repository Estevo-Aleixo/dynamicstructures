#pragma once

#include "Main.h"

class BaseEntity
{
public:
	BaseEntity(Ogre::SceneNode* node,Ogre::Entity* entity);
	~BaseEntity(void);
	
	void update(const Ogre::FrameEvent& evt); 

	//GET 

	//
	unsigned int getID(){return ID_num;}
	//
	std::string getName(){return m_name;} 
	//
	unsigned int getPrice(){return m_price;}
	//
	const Ogre::Vector3& getPosition(void){return m_node->getPosition();}
	//
	Ogre::Vector3& getFacingDirection(void){return m_facingDirection;}
	//
	Ogre::SceneNode* getNode(){return m_node;}

	
	//set
	void setPrice(int amount){m_price = amount;}
	void setPosition(Ogre::Vector3& pos){m_node->setPosition(pos);}
	void setFacingDirection(Ogre::Vector3& direction){m_facingDirection= direction ;}

protected: 

	unsigned int ID_num;
	std::string m_name;

	unsigned int m_price; 

	//positioning stuff
	Ogre::Vector3 m_facingDirection; 

	//ogre scenenode stuff
	Ogre::SceneNode* m_node;
	Ogre::Entity* m_entity;

	//AI stuff


	//physics stuff

	//sound stuff




};	