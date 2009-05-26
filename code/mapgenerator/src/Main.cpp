#include "Main.h"
#include "World.h"

//standard constructor
Main::Main()
    {
        mFrameListener = 0;
        mRoot = 0;
		// Provide a nice cross platform solution for locating the configuration files
		// On windows files are searched for in the current working directory, on OS X however
		// you must provide the full path, the helper function macBundlePath does this for us.
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
		mResourcePath = macBundlePath() + "/Contents/Resources/";
#else
		mResourcePath = "";
#endif
    }

/// Standard destructor
Main::~Main()
    {
        if (mFrameListener)
            delete mFrameListener;
        if (mRoot)
            delete mRoot;
    }

	void Main::go(void)
    {
        if (!setup())
            return;
        mRoot->startRendering();

        // clean up
        destroyScene();
    }

	bool Main::setup(void)
    {

		String pluginsPath;
		// only use plugins.cfg if not static
#ifndef OGRE_STATIC_LIB
		pluginsPath = mResourcePath + "plugins.cfg";
#endif

        mRoot = new Root(pluginsPath, mResourcePath + "ogre.cfg", mResourcePath + "Ogre.log");

        setupResources();

        bool carryOn = configure();
        if (!carryOn) return false;

        chooseSceneManager();
        createCamera();
        createViewports();

        // Set default mipmap level (NB some APIs ignore this)
        TextureManager::getSingleton().setDefaultNumMipmaps(5);

		// Create any resource listeners (for loading screens)
		createResourceListener();
		// Load resources
		loadResources();

		// Create the scene
        createScene();

        createFrameListener();

        return true;

    }


    /** Configures the application - returns false if the user chooses to abandon configuration. */
    bool Main::configure(void)
    {
        // Show the configuration dialog and initialise the system
        // You can skip this and use root.restoreConfig() to load configuration
        // settings if you were sure there are valid ones saved in ogre.cfg
        if(mRoot->showConfigDialog())
        {
            // If returned true, user clicked OK so initialise
            // Here we choose to let the system create a default rendering window by passing 'true'
            mWindow = mRoot->initialise(true,"GOO editor");
            return true;
        }
        else
        {
            return false;
        }
    }

    void Main::chooseSceneManager(void)
    {
        // Create the SceneManager, in this case a generic one
        mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "ExampleSMInstance");
    }

    void Main::createCamera(void)
    {
        // Create the camera
        mCamera = mSceneMgr->createCamera("MainCam");
        // Position it at 500 in Z direction
        mCamera->setPosition(Vector3(0,-150,300));
        // Look back along -Z
        mCamera->lookAt(Vector3(0,0,0));
        mCamera->setNearClipDistance(5);

    }
    void Main::createFrameListener(void)
    {
        mFrameListener= new World(mWindow, mCamera, mSceneMgr, mGUIRenderer, mRoot );
        mFrameListener->showDebugOverlay(true);
        mRoot->addFrameListener(mFrameListener);

    }

	void Main::createScene(void)
	{

	}

    void Main::destroyScene(void){}    // Optional to override this

    void Main::createViewports(void)
    {
        // Create one viewport, entire window
        Viewport* vp = mWindow->addViewport(mCamera);
		vp->setBackgroundColour(ColourValue(0.0,0.0,0.0,1.0));

        // Alter the camera aspect ratio to match the viewport
        mCamera->setAspectRatio(
            Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
    }

     /// Method which will define the source of resources (other than current folder)
	void Main::setupResources(void)
    {
        // Load resource paths from config file
        ConfigFile cf;
        cf.load("resources.cfg");

		// Go through all sections & settings in the file
        ConfigFile::SectionIterator seci = cf.getSectionIterator();

        String secName, typeName, archName;
        while (seci.hasMoreElements())
        {
            secName = seci.peekNextKey();
            ConfigFile::SettingsMultiMap *settings = seci.getNext();
            ConfigFile::SettingsMultiMap::iterator i;

			for (i = settings->begin(); i != settings->end(); ++i)
            {
                typeName = i->first;
                archName = i->second;
                ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
            }
        }
    }

	/// Optional override method where you can create resource listeners (e.g. for loading screens)
	void Main::createResourceListener(void)
	{

	}

	/// Optional override method where you can perform resource group loading
	/// Must at least do ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	void Main::loadResources(void)
{
		// Initialise, parse scripts etc
		ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

}



#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#ifdef __cplusplus
	extern "C" {
#endif

		INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
		{
			// Create application object
			Main app;
			try
			{
				app.go();
			}
			catch (Exception& e)
			{
				MessageBoxA(NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
			}
			return 0;
		}

#ifdef __cplusplus
	}
#endif
