#include "ContactListener.h"
#include "Cell.h"

void ContactListener::Add(const b2ContactPoint* point)
{
     Physical2DObject* object1=0;
	 Physical2DObject* object2=0;

	// handle add point
	object1 = static_cast<Physical2DObject*>(point->shape1->GetBody()->GetUserData());
	object2 = static_cast<Physical2DObject*>(point->shape2->GetBody()->GetUserData());

	if (object1!=0 && object2!=0)
		Ogre::LogManager::getSingletonPtr()->logMessage(object1->getName() + " has collided with " + object2->getName() );

}
void ContactListener::Persist(const b2ContactPoint* point)
{
        // handle persist point
}

void ContactListener::Remove(const b2ContactPoint* point)
{
        // handle remove point
}
    
void ContactListener::Result(const b2ContactResult* point)
{
        // handle results
}