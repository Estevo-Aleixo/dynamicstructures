#pragma once

#pragma warning( disable : 4267 44 82)
#pragma warning( disable : 4311)

#include "Main.h"
#include "cLua.h"

#include "Movable2DObject.h"

class World;

enum EVENTTYPE
{
	SPAWN=0,
	DIE=1,
	COLLISION=2,
	MAXVOLUME=3,
	CONTAINS=4,
	MAXCELLCOUNT=5
};

static const char* eventName[] = 
{"Creation", 
"Destruction",
"Collision",
"Maximal Volume",
"Object Contains Object",
"Maximal Cell Count"
};
 

class Event
{
public: 
	static std::string names[];

	Event(EVENTTYPE type, Movable2DObject* actor1, Movable2DObject* actor2)
	:mType(type),mActor1(actor1),mActor2(actor2)
	{
	}
	
	EVENTTYPE mType; 
	Movable2DObject* mActor1;
	Movable2DObject* mActor2;

	inline bool compare(Event* e)
	{
		return mType == e->mType && mActor1==e->mActor1 && mActor2 == e->mActor2; 
	}

	inline std::string Event::toString()
	{
		return Ogre::String("Event type: " + std::string(eventName[(int)mType]) + ", Actors: "+ mActor1->getName()+ " - " +  mActor2->getName());   
	}



}; 


class EventHandler
{
public:
	EventHandler(World* world);
	~EventHandler(void);

	void handleBufferedEvents();
	void addEventToBuffer(Event* newEvent); 
	void notifyActorDestruction(Movable2DObject* actor); 


	void clearDeletedActorsList(); 
protected:

	std::vector<Movable2DObject*> mDeletedActors; 

	World* mWorld;
	std::queue<Event*> mEventBuffer; 
	cLua* mLuaMgr; 

};
