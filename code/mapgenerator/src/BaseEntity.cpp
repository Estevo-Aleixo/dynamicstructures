#include "BaseEntity.h"

BaseEntity::BaseEntity(Ogre::SceneNode* node,Ogre::Entity* entity)
{
	m_node = node; 
	m_entity = entity;
}

BaseEntity::~BaseEntity(void)
{

}

void BaseEntity::update(const Ogre::FrameEvent& evt)
{

//update state machine: 

//update animations:


}