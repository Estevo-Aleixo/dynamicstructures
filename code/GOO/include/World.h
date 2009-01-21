#pragma once

#include "Main.h"
#include "ExampleFrameListener.h"

using namespace Ogre;

class Console;
class InsectManager;

class World: public ExampleFrameListener, public OIS::MouseListener, public OIS::KeyListener
{

public:
	World(RenderWindow* win, Camera* cam, SceneManager *sceneMgr, CEGUI::OgreCEGUIRenderer *renderer, Root * root );
	~World(void);

	//! overloaded member function from ExampleFrameListener. updates all objects within the scene
	bool frameStarted(const FrameEvent &evt);

	//! overloaded member function from ExampleFrameListener. updates the ODE physics system and synchronizes the scene accordingly. 
	bool frameEnded(const FrameEvent &evt);
	
	//!overloaded member function from ExampleFrameListener. handles mouse input: x and y difference aswell as z (the scrollwheel) 
	bool mouseMoved(const OIS::MouseEvent &e);
	
	//!overloaded member function from ExampleFrameListener. handles all button presses for the mouse input device.
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	
	//!overloaded member function from ExampleFrameListener. handles all button releases from the mouse input device.
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	
	//! DEPRECATED. mouseMoved is used instead.
	bool handleMouseWheelEvent(const CEGUI::EventArgs& e);
	
	//!overloaded member function from ExampleFrameListener. buffered keyboard input key presses. 
	bool keyPressed(const OIS::KeyEvent &e);
	
	//!overloaded member function from ExampleFrameListener. buffered keyboard input key releases. 
	bool keyReleased(const OIS::KeyEvent &e);


private: 
	Ogre::SceneNode* coreNode; 
	Ogre::Entity* coreEntity;


	void createTestPolygon(); 
	void updateTestPolygon(const FrameEvent &evt); 

	Ogre::ManualObject* moTest; 

	std::vector<Ogre::Vector2> points; 
	
	bool mToggle;
	Root* mRoot;
	bool mContinue;
	Console* mConsole;
	InsectManager* mInsectManager;

	Radian angle;  
	double diameter;
	Radian wave;
	double counter;

protected: 
	CEGUI::OgreCEGUIRenderer* mGUIRenderer;     // CEGUI renderer
	Ogre::SceneManager* mSceneMgr;

	//void updateStats(void);
};
