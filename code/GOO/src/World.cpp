#include "World.h"
#include "Console.h"
#include "Pointer.h"
#include "CellSystem.h"
#include "CellFactory.h"


World::World(RenderWindow* win, Camera* cam, SceneManager *sceneMgr, CEGUI::OgreCEGUIRenderer *renderer, Root * root ): 
ExampleFrameListener(win, cam, true, true), mGUIRenderer(renderer), mSceneMgr(sceneMgr),mRoot(root)
{
	mMouse->setEventCallback(this);
	mKeyboard->setEventCallback(this);
	mContinue=true;
	mToggle=false; 
	moveButtonPressed=false;
	//testing: 
	coreNode= mSceneMgr->getRootSceneNode()->createChildSceneNode(); 
	coreEntity= mSceneMgr->createEntity("coreNode","sphere.mesh");
	coreNode->attachObject(coreEntity); 
	coreNode->scale(0.01,0.01,0.01); 
	 
	mCanvas= new Canvas(std::string("myFirstCanvas"), CANVASTYPE::RECTANGULAR, 1000,1000,4,mSceneMgr);
	mPointer= mCanvas->getPointer(); 	

	CellFactory::Create(mSceneMgr); 
	mCellFactory= CellFactory::getSingletonPtr(); 

	mMainCam= mSceneMgr->getCamera("MainCam");
	camMode= CAMERAMODE::ATTACHED;

	//TEST PURPOSE
	CellSystem* sys= new CellSystem(std::string("sysy"),Vector2(0,0),mSceneMgr,std::string(""),true,1);  
	Cell* temp; 
	
	for(int x=0;x < 100; x++){
		for(int y=0;y < 100 ; y++){
			testCells.push_back(new Cell(std::string("celll") + StringConverter::toString((x*100)+y),0,mSceneMgr,sys,Vector2(x*20,y*20))); 
		}
	}

	camDirection=Vector3(0,0,0);
	camVelocity=Vector3(0,0,0);

	mSceneMgr->setAmbientLight(ColourValue()); 
	Ogre::LogManager::getSingletonPtr()->logMessage("World object instatiated");

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

	mCanvas->frameStarted(evt);	

	std::vector<Cell*>::iterator itr;

	for(itr= this->testCells.begin(); itr!=testCells.end(); itr++)
	{
		(*itr)->frameStarted(evt);
	}


	switch(camMode)
	{
	case CAMERAMODE::FREEROAM:
		//this->frameRenderingQueued(evt);
		//processUnbufferedKeyInput(evt);
		//processUnbufferedMouseInput(evt);
		//moveCamera();
		break;
	case CAMERAMODE::ATTACHED:
		checkKeyboardInput(evt); 
		mPointer->frameStarted(evt); 
		updateCamera(evt); 
		break;

	}

	return mContinue;
}

bool World::frameEnded(const FrameEvent &evt)
{




return mContinue;
}
	
bool World::mouseMoved(const OIS::MouseEvent &e)
{

	mPointer->mouseMoved(e); 

	//scroll wheel: 
	
			mCamZoomSpeed += -1 * e.state.Z.rel;

			if (mCamZoomSpeed > MAX_ZOOM_SPEED)
				mCamZoomSpeed = MAX_ZOOM_SPEED;
			if (mCamZoomSpeed < MIN_ZOOM_SPEED)
				mCamZoomSpeed = MIN_ZOOM_SPEED;



return mContinue;
}
	
bool World::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	
	
	mPointer->mousePressed(e,id); 

	

	return mContinue;
}
	
bool World::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
	mPointer->mouseReleased(e,id); 


return mContinue;
}
	
bool World::handleMouseWheelEvent(const CEGUI::EventArgs& e)
{
		
	//alter camera distance:



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

		//CAMERA CONTROLS
	}

	//this->steerCamera(e); 	
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

	if (mKeyboard->isKeyDown(OIS::KC_W)== false && 
			mKeyboard->isKeyDown(OIS::KC_A)== false && 
			mKeyboard->isKeyDown(OIS::KC_S)== false && 
			mKeyboard->isKeyDown(OIS::KC_D)== false)
		{
			moveButtonPressed=false;
			camDirection.y = 0; 	
			camDirection.x = 0; 

		}

return mContinue;
}


void World::checkKeyboardInput(const FrameEvent &evt)
{

if (camMode == CAMERAMODE::ATTACHED)
	{

		if (mKeyboard->isKeyDown(OIS::KC_W))
				camDirection.y = -1.0; 	
		if (mKeyboard->isKeyDown(OIS::KC_A))
				camDirection.x = -1.0;
		if (mKeyboard->isKeyDown(OIS::KC_S))
				camDirection.y = 1.0;
		if (mKeyboard->isKeyDown(OIS::KC_D))
				camDirection.x = 1.0; 
	

	}


}


bool World::updateCamera(const FrameEvent &evt)
{
	
	//x,y
	Ogre::Vector3 newPos= mMainCam->getPosition(); 
	Ogre::Real camSpeed= 100.0;
	camVelocity= camDirection * camSpeed; 

	newPos.x+= camVelocity.x * evt.timeSinceLastFrame; 
	newPos.y-= camVelocity.y * evt.timeSinceLastFrame; 

	//z: zoom
	Ogre::Real camFriction= 100.0;
	double friction = evt.timeSinceLastFrame * camFriction;
		
		if (mCamZoomSpeed > 0.0) {
			mCamZoomSpeed= ((0.0 > (mCamZoomSpeed - friction)) ? 0.0 : (mCamZoomSpeed - friction)) ;
		}

		if (mCamZoomSpeed < 0.0) {
			mCamZoomSpeed= ((0.0 < (mCamZoomSpeed + friction)) ? 0.0 : (mCamZoomSpeed + friction)) ;
		}

	newPos.z+= mCamZoomSpeed*evt.timeSinceLastFrame; 

	if (newPos.z < 50.0)
		newPos.z=50;

	if (newPos.z > 1000)
		newPos.z= 1000;

	mMainCam->setPosition(newPos); 	

	return true;
}
