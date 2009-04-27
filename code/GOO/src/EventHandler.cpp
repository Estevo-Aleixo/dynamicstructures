#include "EventHandler.h"
#include "GrowingSurface.h"
#include <deque>
#include <list>
#include <queue>

#include "World.h"


EventHandler::EventHandler(World* mWorld)
:mLuaMgr(mWorld->getLuaMgr())
{


}

EventHandler::~EventHandler(void)
{


}

void EventHandler::handleBufferedEvents()
{

	


	while (!mEventBuffer.empty()) {
		
			Event* currentEvent= mEventBuffer.front(); 
			mEventBuffer.pop();
	

			switch(currentEvent->mType){
				case EVENTTYPE::COLLISION:
					//handleCollisionEvent(currentEvent->mActor1, currentEvent->mActor2);
					break;
				case EVENTTYPE::CONTAINS:
					
					break;
				case EVENTTYPE::DIE:
					
					break;
				case EVENTTYPE::SPAWN:
					
					break;
				case EVENTTYPE::MAXVOLUME:
					
					break;
			}



	
	}

	//handle it:
	//mLuaMgr->RunScript(currentEvent->mActor1->getEventHandlerName()); 
	//mLuaMgr->RunScript(currentEvent->mActor2->getEventHandlerName()); 
mDeletedActors.clear();
}

void EventHandler::addEventToBuffer(Event* newEvent)
{
	
	if (!mEventBuffer.empty()){
		if (mEventBuffer.back()->compare(newEvent))
		{
			return;
		}
	}

		//Ogre::LogManager::getSingletonPtr()->logMessage(newEvent->toString()); 
		mEventBuffer.push(newEvent); 
	

}

void EventHandler::notifyActorDestruction(Movable2DObject* actor)
{


}

void EventHandler::handleCollisionEvent(Movable2DObject* actor1,Movable2DObject* actor2)
{
	bool actor1Deleted=false;
	bool actor2Deleted=false;	
	
	std::vector<Movable2DObject*>::iterator itr;
			Cell* _actor1= static_cast<Cell*>(actor1);
			Cell* _actor2= static_cast<Cell*>(actor2);

			GrowingSurface* system1 = _actor1->getGrowingSurface();
			GrowingSurface* system2 = _actor2->getGrowingSurface();

			if (system1 != system2)
				{
					for(itr=mDeletedActors.begin(); itr!=mDeletedActors.end();itr++)
					{
						if ((*itr)==_actor1)
							actor1Deleted=true;

						if ((*itr)==_actor2)
							actor2Deleted=true;
					} 
			
					mDeletedActors.push_back(_actor1);
					mDeletedActors.push_back(_actor2);
					
					if (actor1Deleted==false)
						system1->destroyCell(_actor1);
					if (actor2Deleted==false)
						system2->destroyCell(_actor2);
				}

	
}
void EventHandler::handleScriptedEvent(int eventID, Movable2DObject* actor1, Movable2DObject* actor2)
{


}
	