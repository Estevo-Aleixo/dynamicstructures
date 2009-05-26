#pragma once
#include "Surface.h"
class Canvas;

class SystemFactory
{
public:
	SystemFactory(const Ogre::String& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~SystemFactory(void);

	DynamicSystem* spawnSystem(SystemProperties& properties, Vector2& position); 
	DynamicSystem* loadSystem(std::string& name, Vector2& position); 
	
	std::string& getSystemList(); 

	void registerSystemPropertySet(SurfaceProperties* propertySet);
private:

	std::vector<SurfaceProperties*> propertySetList;
	std::vector<DynamicSystem*> systemList;

	std::string mName;
	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;

};
