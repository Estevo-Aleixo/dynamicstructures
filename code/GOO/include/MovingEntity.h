#pragma once

#include "BaseEntity.h"


class MovingEntity:public BaseEntity
{
public:
	MovingEntity(Ogre::SceneNode* node,Ogre::Entity* entity);
	~MovingEntity(void);

	Ogre::Vector3& getVelocity(void); 
	Ogre::Vector3& getHeading(void); 


protected:


private:



};
