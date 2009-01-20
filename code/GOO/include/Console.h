#pragma once
#include "World.h"

//console is a singleton 
class Console: public OIS::KeyListener
{
public:
	static Console* getSingletonPtr(); 
	
	static void create(); 
	static void destroy(); 

	//!overloaded member function from ExampleFrameListener. buffered keyboard input key presses. 
	bool keyPressed(const OIS::KeyEvent &e);
	//!overloaded member function from ExampleFrameListener. buffered keyboard input key releases. 
	bool keyReleased(const OIS::KeyEvent &e);

	void show(); 
	void hide(); 
	void frameStarted(Ogre::FrameEvent& evt);
	void frameEnded(Ogre::FrameEvent& evt);
	bool isEnabled(){return enabled;};
protected: 
	bool enabled;
	static Console* mConsole; 
	~Console(void);
	Console(void);

	std::vector<std::string> history;	

	Ogre::Overlay* consoleOverlay; 
	Ogre::OverlayElement* historyPanel; 
	Ogre::OverlayElement* inputPanel; 
};
