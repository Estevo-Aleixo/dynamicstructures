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

//moTest object here
	moTest= mSceneMgr->createManualObject("test_structure");

// Use identity view/projection matrices
moTest->setUseIdentityProjection(true);
moTest->setUseIdentityView(true);
moTest->setDynamic(true); 
angle=0;
wave=0;
diameter=0;
	
	int i; 
	double x,y; 
	int numVertices= 1200; 
	double interval= Ogre::Math::TWO_PI / numVertices;

moTest->begin("Examples/Rocky" , RenderOperation::OT_LINE_STRIP);
	

moTest->position(0,0, 0); 
	for(i=0; i < numVertices; i++)
	{
		x = (Ogre::Math::Cos(Radian(angle) + Radian(interval * i))) * diameter;
		y = (Ogre::Math::Sin(Radian(angle) + Radian(interval * i))) * diameter;
		moTest->position(x,y, 0); 	
		moTest->colour(Ogre::ColourValue(Math::Sin(angle + Radian(interval * i)),Math::Cos(angle + Radian(interval * i)),0.5,1.0)); 
	}
	
	for(i=0; i < numVertices-1; i++){
		moTest->index(i);
		moTest->index(i+1);
		moTest->index(0);
	}

		moTest->index(numVertices-1);
		moTest->index(1);
		moTest->index(0);
moTest->end();

// Use infinite AAB to always stay visible
AxisAlignedBox aabInf;
aabInf.setInfinite();
moTest->setBoundingBox(aabInf);

// Render just before overlays
moTest->setRenderQueueGroup(RENDER_QUEUE_OVERLAY - 1);
// Attach to scene
mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(moTest);

}



void World::updateTestPolygon(const FrameEvent &evt)
{


//we will do a test with rotating points: 

	int i; 
	//vertex position: 
	double x,y; 
	int numVertices= 1200; 
	counter+=20.0*evt.timeSinceLastFrame; 
	if (counter> 100000)
		counter=0;

	angle = angle + Ogre::Radian((1 * evt.timeSinceLastFrame)); 
	if (angle > Radian(Math::TWO_PI))
		angle = 0;

	//angle=0;
	
	//diameter= 0.5;
	double interval= Ogre::Math::TWO_PI / (numVertices-1);

	moTest->beginUpdate(0);
	moTest->position(0,0, 0); 
	for(i=0; i < numVertices; i++)
	{
		wave = Radian((interval*(i + counter*evt.timeSinceLastFrame))*13); 
		diameter= 0.5 + 0.4 * Ogre::Math::Cos(angle + 2 * Radian(interval * i)) + 0.5 * Ogre::Math::Sin(wave); 
		x = (Ogre::Math::Cos(angle + Radian(interval * i))) * diameter;
		y = (Ogre::Math::Sin(angle + Radian(interval * i))) * diameter;
	
		moTest->position(x,y, 0); 	
		moTest->colour(Ogre::ColourValue(Math::Sin(angle + Radian(interval * i)),Math::Cos(angle + Radian(interval * i)),0.5,1.0)); 
	}
	
	for(i=0; i < numVertices-1; i++){
		moTest->index(i);
		moTest->index(i+1);
		moTest->index(0);
	}

		moTest->index(numVertices-1);
		moTest->index(1);
		moTest->index(0);

	moTest->end();
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
	this->updateStats(); 

	//update test polygon
	updateTestPolygon(evt); 
	//updateStats(); 


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


/*
void World::updateStats(void)
	{
		static String currFps = "Current FPS: ";
		static String avgFps = "Average FPS: ";
		static String bestFps = "Best FPS: ";
		static String worstFps = "Worst FPS: ";
		static String tris = "Triangle Count: ";
		static String batches = "Batch Count: ";

		// update stats when necessary
		try {
			OverlayElement* guiAvg = OverlayManager::getSingleton().getOverlayElement("Core/AverageFps");
			OverlayElement* guiCurr = OverlayManager::getSingleton().getOverlayElement("Core/CurrFps");
			OverlayElement* guiBest = OverlayManager::getSingleton().getOverlayElement("Core/BestFps");
			OverlayElement* guiWorst = OverlayManager::getSingleton().getOverlayElement("Core/WorstFps");

			const RenderTarget::FrameStats& stats = mWindow->getStatistics();
			guiAvg->setCaption(avgFps + StringConverter::toString(stats.avgFPS));
			guiCurr->setCaption(currFps + StringConverter::toString(stats.lastFPS));
			guiBest->setCaption(bestFps + StringConverter::toString(stats.bestFPS)
				+" "+StringConverter::toString(stats.bestFrameTime)+" ms");
			guiWorst->setCaption(worstFps + StringConverter::toString(stats.worstFPS)
				+" "+StringConverter::toString(stats.worstFrameTime)+" ms");

			OverlayElement* guiTris = OverlayManager::getSingleton().getOverlayElement("Core/NumTris");
			guiTris->setCaption(tris + StringConverter::toString(stats.triangleCount));

			OverlayElement* guiBatches = OverlayManager::getSingleton().getOverlayElement("Core/NumBatches");
			guiBatches->setCaption(batches + StringConverter::toString(stats.batchCount));

			OverlayElement* guiDbg = OverlayManager::getSingleton().getOverlayElement("Core/DebugText");
			this->mDebugText= "blaat";
			guiDbg->setCaption(this->mDebugText);
		}*/
		//catch(...) { /* ignore */ }
//	}
	