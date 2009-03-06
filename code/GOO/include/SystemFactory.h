#pragma once
#include "CellSystem.h"

class SystemFactory
{
public:
	SystemFactory(const Ogre::String& name, Canvas* canvas, Ogre::SceneManager* sceneMgr);
	~SystemFactory(void);

	CellSystem* getSystem(int id, Vector2& position); 
	std::string& getSystemList(); 

	void registerSystemPropertySet(CellSystemProperties* propertySet);
private:

	std::vector<CellSystemProperties*> propertySetList;
	std::vector<CellSystem*> systemList;

	std::string mName;
	Canvas* mCanvas;
	Ogre::SceneManager* mSceneMgr;

};
