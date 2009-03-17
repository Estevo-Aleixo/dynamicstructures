#pragma once
#include "CellSystem.h"
class Canvas;

class SystemFactory
{
public:
	SystemFactory(const Ogre::String& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~SystemFactory(void);

	DynamicSystem* spawnSystem(SystemProperties& properties, Vector2& position); 
	DynamicSystem* loadSystem(std::string& name, Vector2& position); 
	
	std::string& getSystemList(); 

	void registerSystemPropertySet(CellSystemProperties* propertySet);
private:

	std::vector<CellSystemProperties*> propertySetList;
	std::vector<DynamicSystem*> systemList;

	std::string mName;
	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;

};
