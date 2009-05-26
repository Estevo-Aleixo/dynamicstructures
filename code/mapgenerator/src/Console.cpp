#include "Console.h"

Console* Console::mConsole= NULL; 

Console::Console(void)
{
	consoleOverlay= Ogre::OverlayManager::getSingletonPtr()->getByName("UI/console");
	consoleOverlay->show(); 

	//historyPanel= Ogre::OverlayManager::getSingletonPtr()->getOverlayElement("UI/console/mainPanel");
	//inputPanel= Ogre::OverlayManager::getSingletonPtr()->getOverlayElement("UI/console/inputWindow");
	//historyPanel->show(); 

	Ogre::LogManager::getSingletonPtr()->logMessage("Console object instatiated");
}

Console* Console::getSingletonPtr()
{
	return mConsole;
}

void Console::create()
{
	if (!mConsole) 
		mConsole= new Console(); 
}

void Console::destroy()
{
	if (mConsole)
		delete mConsole; 
} 


Console::~Console(void)
{

}

void Console::frameStarted(Ogre::FrameEvent& evt)
{


}

void Console::frameEnded(Ogre::FrameEvent& evt)
{

}


bool Console::keyPressed(const OIS::KeyEvent &e)
{

return true;
}
	
bool Console::keyReleased(const OIS::KeyEvent &e)
{

return true;
}

void Console::show()
{
	enabled= true;
	consoleOverlay->show(); 
}

void Console::hide()
{
	enabled = false;
	consoleOverlay->hide(); 

}
