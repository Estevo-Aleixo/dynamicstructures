#include "World.h"
#include "Console.h"



World::World(RenderWindow* win, Camera* cam, SceneManager *sceneMgr, CEGUI::OgreCEGUIRenderer *renderer, Root * root ): 
ExampleFrameListener(win, cam, true, true), mGUIRenderer(renderer), mSceneMgr(sceneMgr),mRoot(root)
{
	mMouse->setEventCallback(this);
	mKeyboard->setEventCallback(this);
	mContinue=true;
	mToggle=false; 

	//testing: 
	coreNode= mSceneMgr->getRootSceneNode()->createChildSceneNode(); 
	coreEntity= mSceneMgr->createEntity("coreNode","sphere.mesh");
	coreNode->attachObject(coreEntity); 
	coreNode->scale(0.3,0.3,0.3); 
	 
	createTestPolygon();	

	mSceneMgr->setAmbientLight(ColourValue()); 
	Ogre::LogManager::getSingletonPtr()->logMessage("World object instatiated");

}

void World::createTestPolygon()
{

//manual object here

}



void World::updateTestPolygon()
{


}
	

World::~World(void)
{
//delete all


}

bool World::frameStarted(const FrameEvent &evt)
{
	if(mMouse)
		mMouse->capture();
	if(mKeyboard)
		mKeyboard->capture();


	//update test polygon
	updateTestPolygon(); 


	return mContinue;
}

bool World::frameEnded(const FrameEvent &evt)
{




return mContinue;
}
	
bool World::mouseMoved(const OIS::MouseEvent &e)
{




return mContinue;
}
	
bool World::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{




return mContinue;
}
	
bool World::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{



return mContinue;
}
	
bool World::handleMouseWheelEvent(const CEGUI::EventArgs& e)
{


return mContinue;
}
	
bool World::keyPressed(const OIS::KeyEvent &e)
{


	switch (e.key)
	{
		case OIS::KC_ESCAPE:
			mRoot->shutdown(); 
			exit(0);
			break;
		case OIS::KC_GRAVE:
		case OIS::KC_BACK:
			if (mToggle==true)
				mConsole->isEnabled() ? mConsole->hide() : mConsole->show(); 
			break;
	}
	return mContinue;
}
	
bool World::keyReleased(const OIS::KeyEvent &e)
{

	switch (e.key)
	{

		case OIS::KC_GRAVE:
		case OIS::KC_BACK:
			mToggle=false;
			break;
	}
return mContinue;
}

