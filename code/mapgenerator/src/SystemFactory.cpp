#include "SystemFactory.h"
#include  "Canvas.h"

SystemFactory::SystemFactory(const Ogre::String& name, Canvas* canvas, Ogre::SceneManager* sceneMgr)
: mName(name), mCanvas(canvas), mSceneMgr(sceneMgr)
{

}

SystemFactory::~SystemFactory(void)
{

}

DynamicSystem* SystemFactory::spawnSystem(SystemProperties& properties, Vector2& position)
{
	DynamicSystem* system;

	switch(properties.type){
		case SystemType::BLAAT:
			system= new Surface("Surface"  + StringConverter::toString((int)systemList.size()),mCanvas,mSceneMgr, position, (SurfaceProperties&)properties,true); 
			break;
		
		case SystemType::CUSTOMSYSTEM:
			//system= new Surface(mName + StringConverter::toString((int)systemList.size()),mCanvas,mSceneMgr, position, "bullshit",true); 
			break;
		
		case SystemType::PATHSYSTEM:
			//system= new Surface(mName + StringConverter::toString((int)systemList.size()),mCanvas,mSceneMgr, position, "bullshit",true); 
			break;
		default:
			//throw exception 
			break;
	}
	
	systemList.push_back(system); 
	return system;
} 

DynamicSystem* SystemFactory::loadSystem(std::string& name, Vector2& position)
{
	DynamicSystem* system;
	
	return system;
}




std::string& SystemFactory::getSystemList()
{
	std::vector<SurfaceProperties*>::iterator itr; 
	std::map<const char*, int>::iterator mapitr; 
	for (itr = propertySetList.begin(); itr != propertySetList.end(); itr++)
	{
		Ogre::LogManager::getSingletonPtr()->logMessage((*itr)->mName);
		Ogre::LogManager::getSingletonPtr()->logMessage("description: "+ (*itr)->description);
		Ogre::LogManager::getSingletonPtr()->logMessage("extra parameters: ");
	
		for(mapitr= (*itr)->mExtraParameters.begin(); mapitr != (*itr)->mExtraParameters.end(); mapitr++)
		{
			Ogre::LogManager::getSingletonPtr()->logMessage(std::string((*mapitr).first) +": " + StringConverter::toString( (*mapitr).second ) );
		}

	}

	return std::string();
}

void SystemFactory::registerSystemPropertySet(SurfaceProperties* propertySet)
{	
	propertySetList.push_back(propertySet);
}