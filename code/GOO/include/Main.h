#pragma once


/*
-----------------------------------$(OGRE_HOME)\------------------------------------------
Filename:    Main.h
-----------------------------------------------------------------------------
*/

#include <iostream>
#include <assert.h>
#include "Box2D.h"

#include "Ogre.h"
#include "OgreConfigFile.h"
#include <OIS/OIS.h>

#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUISchemeManager.h>
#include <OgreCEGUIRenderer.h>

#define SQUARE_MESH "rectangular_cell"
#define HEXAGON_LINE_MESH "hexagon_cell"
#define TRIANGLE_MESH "triangle_cell"
#define CIRCLE_LINE_MESH "NONE"


#include "MovableText.h"

/*
extern "C"
{
    #include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include <luabind/luabind.hpp>
*/


class ExampleFrameListener;

using namespace Ogre;

/** Base class which manages the standard startup of an Ogre application.
    Designed to be subclassed for specific examples if required.
*/
class Main
{
public:
    /// Standard constructor
	Main(); 
	~Main();
   
	void go();
	/// Start the example
   

protected:
    Root *mRoot;
    Camera* mCamera;
    SceneManager* mSceneMgr;
    ExampleFrameListener* mFrameListener;
    RenderWindow* mWindow;
	Ogre::String mResourcePath;

	CEGUI::OgreCEGUIRenderer *mGUIRenderer;
    CEGUI::System *mGUISystem;         // CEGUI system

    // These internal methods package up the stages in the startup process
    /** Sets up the application - returns false if the user chooses to abandon configuration. */
    bool setup(void);

    /** Configures the application - returns false if the user chooses to abandon configuration. */
    bool configure(void);

    void chooseSceneManager(void);

    void createCamera(void);

	void createFrameListener(void);

    void createScene(void);   //create zha scene

    void destroyScene(void);    // Optional to override this

    void createViewports(void);

    /// Method which will define the source of resources (other than current folder)
    void setupResources(void);

	/// Optional override method where you can create resource listeners (e.g. for loading screens)
	void createResourceListener(void);

	/// Optional override method where you can perform resource group loading
	/// Must at least do ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	void loadResources(void);

};


