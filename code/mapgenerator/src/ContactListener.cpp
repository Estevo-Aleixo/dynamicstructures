#include "ContactListener.h"
#include "Cell.h"
#include "World.h"

ContactListener::ContactListener(World* world)
:EventHandler(world)
{
	//mEventHandler = world->getEventHandler(); 

}

ContactListener::~ContactListener()
{

}

void ContactListener::Add(const b2ContactPoint* point)
{

  
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

//build a max messages per second method!!!

      // handle results
	 Movable2DObject* object1=0;
	 Movable2DObject* object2=0;

	// handle add point
	object1 = static_cast<Movable2DObject*>(point->shape1->GetBody()->GetUserData());
	object2 = static_cast<Movable2DObject*>(point->shape2->GetBody()->GetUserData());

	//mTest.size();
	//mTest.push_back(1); 

	if (object1!=0 && object2!=0)
	{
		//create event 
		Event* newEvent=new Event(EVENTTYPE::COLLISION,object1,object2);
		//mEvents.push_back(newEvent);

		this->addEventToBuffer(newEvent);
		//mEventHandler->addEventToBuffer(new Event(EVENTTYPE::COLLISION,object1,object2)); 

	}


}

