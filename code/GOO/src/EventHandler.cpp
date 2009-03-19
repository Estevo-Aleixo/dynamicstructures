#include "EventHandler.h"

#include <deque>
#include <list>
#include <queue>



EventHandler::EventHandler(cLua* LuaManager)
:mLuaMgr(LuaManager)
{


}

EventHandler::~EventHandler(void)
{


}

void EventHandler::handleBufferedEvents()
{

	Event* currentEvent= mEventBuffer.front(); 
	mEventBuffer.pop();
	//handle it:
	mLuaMgr->RunScript(currentEvent->mActor1->getEventHandlerName()); 
	mLuaMgr->RunScript(currentEvent->mActor2->getEventHandlerName()); 

}

void EventHandler::addEventToBuffer(Event* newEvent)
{
	
	if (!mEventBuffer.empty()){
		if ( mEventBuffer.back()->compare(newEvent))
		{
			return;
		}
	}

		Ogre::LogManager::getSingletonPtr()->logMessage(newEvent->toString()); 
		mEventBuffer.push(newEvent); 
	

}

