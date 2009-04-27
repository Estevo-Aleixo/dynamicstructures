#pragma once
#include "GrowingSurface.h"
class Canvas;

class SystemFactory
{
public:
	SystemFactory(const Ogre::String& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~SystemFactory(void);

	DynamicSystem* spawnSystem(SystemProperties& properties, Vector2& position); 
	DynamicSystem* loadSystem(std::string& name, Vector2& position); 
	
	std::string& getSystemList(); 

	void registerSystemPropertySet(GrowingSurfaceProperties* propertySet);
private:

	std::vector<GrowingSurfaceProperties*> propertySetList;
	std::vector<DynamicSystem*> systemList;

	std::string mName;
	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;

};
