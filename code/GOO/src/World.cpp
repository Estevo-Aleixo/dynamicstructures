#include "World.h"
#include "Console.h"
#include "Pointer.h"
#include "CellSystem.h"
#include "CellFactory.h"
#include "ObjectDefinitions.h"

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
		
	ObjectDefinitions::Create(std::string("nothing")); 
	mObjectDefinitions= ObjectDefinitions::getSingletonPtr(); 

	CellFactory::createCellMeshes(); 

	mCanvas= new Canvas(std::string("myFirstCanvas"), CANVASTYPE::RECTANGULAR, mSceneMgr,40,1000,1000);
	mPointer= mCanvas->getPointer(); 	

	mCellFactory= new CellFactory(std::string("Triangle Cell Factory"),mSceneMgr, mCanvas); 

	mMainCam= mSceneMgr->getCamera("MainCam");
	camMode= CAMERAMODE::ATTACHED;
	
	camDirection=Vector3(0,0,0);
	camVelocity=Vector3(0,0,0);

	mSceneMgr->setAmbientLight(ColourValue()); 
	Ogre::LogManager::getSingletonPtr()->logMessage("World object instatiated");
	
	Ogre::OverlayManager::getSingletonPtr()->getByName("GUI/editor")->show(); 
	updateParameterOverlay(); 
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
	mCanvas->frameEnded(evt); 
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
		case OIS::KC_1:
			this->mPointer->setCreateType(1);
			updateParameterOverlay();
			break;
		case OIS::KC_2:
			this->mPointer->setCreateType(2);
			updateParameterOverlay();
			break;
		case OIS::KC_3:
			this->mPointer->setCreateType(3);
			updateParameterOverlay();
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

	//Set Cell Type;


	

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

	if (newPos.z < 10.0)
		newPos.z=10;

	if (newPos.z > 500)
		newPos.z= 500;

	mMainCam->setPosition(newPos); 	

	return true;
}


void  World::updateParameterOverlay(void)
	{

		std::string cellTypes; 
		
		std::vector<Object2DProperties>::iterator itr;
		std::vector<Object2DProperties> objects;
	    objects=  this->mObjectDefinitions->getAll2DObjects(); 
		int count=1;
		for (itr= objects.begin(); itr!= objects.end(); itr++)
		{
			cellTypes+= StringConverter::toString(count) +": " + (*itr).mName + "     "; 
			count++; 
		}

		OverlayElement* guiCellTypes = OverlayManager::getSingleton().getOverlayElement("GUI/cellTypes");
		guiCellTypes->setCaption(cellTypes); 
		OverlayElement* guiCellSelection = OverlayManager::getSingleton().getOverlayElement("GUI/currentCellSelection");
		guiCellSelection->setCaption("Current Selection: " + StringConverter::toString(this->mPointer->getCurrentCellModeID())); 


}