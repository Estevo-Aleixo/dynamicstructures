#include "World.h"
#include "Console.h"
#include "Pointer.h"
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
	 
	mCanvas= new Canvas(std::string("myFirstCanvas"), CANVASTYPE::RECTANGULAR, 1000,1000,100,mSceneMgr);
	mPointer= mCanvas->getPointer(); 	

	CellFactory::Create(mSceneMgr); 
	mCellFactory= CellFactory::getSingletonPtr(); 

	mMainCam= mSceneMgr->getCamera("MainCam");
	camMode= CAMERAMODE::ATTACHED;

	//test: 
	/*
	Cell* testCell;
	testCell= mCellFactory->requestCell(CELLTYPE::HEXAGON); 
	testCell->getNode()->scale(100.0,100.0,100.0);

	Cell* testCell2;
	testCell2= mCellFactory->requestCell(CELLTYPE::SQUARE); 
	testCell2->getNode()->scale(105.0,105.0,105.0);
	testCell2->getNode()->translate(Vector3(0,0,10)); 
	*/
	camDirection=Vector3(0,0,0);
	camVelocity=Vector3(0,0,0);

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

moTest->begin("editorlines" , RenderOperation::OT_LINE_STRIP);
	
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

	
	mCanvas->frameStarted(evt);	

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
