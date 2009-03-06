#include "SystemFactory.h"

SystemFactory::SystemFactory(const Ogre::String& name, Canvas* canvas, Ogre::SceneManager* sceneMgr)
: mName(name), mCanvas(canvas), mSceneMgr(sceneMgr)
{

}

SystemFactory::~SystemFactory(void)
{

}

CellSystem* SystemFactory::getSystem(int id, Vector2& position)
{
	CellSystem* system= new CellSystem(mName + StringConverter::toString((int)systemList.size()),mCanvas,mSceneMgr, position, "bullshit",true); 
	systemList.push_back(system); 
	return system;
}


std::string& SystemFactory::getSystemList()
{
	std::vector<CellSystemProperties*>::iterator itr; 
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

void SystemFactory::registerSystemPropertySet(CellSystemProperties* propertySet)
{	
	propertySetList.push_back(propertySet);
}