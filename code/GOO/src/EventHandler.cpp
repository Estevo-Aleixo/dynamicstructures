#include "EventHandler.h"
#include "CellSystem.h"
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

	std::vector<Movable2DObject*>::iterator itr;
	bool actor1Deleted=false;
	bool actor2Deleted=false;

	while (!mEventBuffer.empty()) {
		
			Event* currentEvent= mEventBuffer.front(); 
			mEventBuffer.pop();

			//delete both cells if different cellsystems
			Cell* actor1= static_cast<Cell*>(currentEvent->mActor1);
			Cell* actor2= static_cast<Cell*>(currentEvent->mActor2);

			CellSystem* system1 = actor1->getCellSystem();
			CellSystem* system2 = actor2->getCellSystem();


			switch(currentEvent->mType){
				case EVENTTYPE::COLLISION:
					handleCollisionEvent(actor1, actor2);
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



			/*
			if (system1 != system2)
				{
					for(itr=mDeletedActors.begin(); itr!=mDeletedActors.end();itr++)
					{
						if ((*itr)==actor1)
							actor1Deleted=true;

						if ((*itr)==actor2)
							actor2Deleted=true;
					} 
			
					mDeletedActors.push_back(actor1);
					mDeletedActors.push_back(actor2);
					
					if (actor1Deleted==false)
						system1->destroyCell(actor1);
					if (actor2Deleted==false)
						system2->destroyCell(actor2);
				}*/
	
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


}
void EventHandler::handleScriptedEvent(int eventID, Movable2DObject* actor1, Movable2DObject* actor2)
{


}
	