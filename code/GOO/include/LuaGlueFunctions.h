#include "cLua.h"
#include "World.h"

cLua* pLua;

World* pWorld;
Canvas* pCanvas;

#define LUA_DIR "..\\..\\media\\Lua\\"; 

LuaGlue HelloWorld(lua_State* l); 

//first priority functions
LuaGlue RunScript(lua_State* l); 
LuaGlue LogMessage(lua_State* l); 
LuaGlue Initialize(lua_State* l);
LuaGlue ConstructCanvas(lua_State* l);
LuaGlue SetCamera(lua_State* l);
LuaGlue LoadCellClass(lua_State* l);
LuaGlue LoadSystemClass(lua_State* l);

LuaGlue SpawnSystem(lua_State* l); 
LuaGlue MergeSystems(lua_State* l); 
LuaGlue HaltSystem(lua_State* l); 
LuaGlue StartSystem(lua_State* l); 
LuaGlue LinkPathToSystems(lua_State* l); 

LuaGlue DeleteSystem(lua_State* l); 
LuaGlue SetCellSystemProperties(lua_State* l); 

LuaGlue SpawnCell(lua_State* l);
LuaGlue DeleteCell(lua_State* l); 
LuaGlue SetCellProperties(lua_State* l); 

LuaGlue SpawnObject(lua_State* l); 
LuaGlue SpawnObjectSystem(lua_State* l); 
//second fase of my project
LuaGlue BakeSystem(lua_State* l); 
LuaGlue BakeAllSystems(lua_State* l); 
LuaGlue InitiateFase2(lua_State* l); 

LuaGlue ClearCanvas(lua_State* l);

//misc
LuaGlue LoadSoundLibrary(lua_State* l);
LuaGlue LoadSound(lua_State* l);
LuaGlue PlaySound(lua_State* l); 
LuaGlue PlayEffect(lua_State* l); 
LuaGlue Save(lua_State* l); 
LuaGlue Quit(lua_State* l); 

LuaGlue RegisterEventHandler(lua_State* l); 


LuaGlue PauseAll(lua_State* l); 

LuaGlue LoadCanvasSurface(lua_State* l); 


//http://lua-users.org/lists/lua-l/2004-04/msg00201.html

void RegisterFunctions()
{

pLua->AddFunction("HelloWorld", HelloWorld); 
pLua->AddFunction("RunScript", RunScript); 
pLua->AddFunction("LogMessage",LogMessage); 
pLua->AddFunction("Initialize",Initialize);
pLua->AddFunction("ConstructCanvas",ConstructCanvas);
pLua->AddFunction("SetCamera",SetCamera);
pLua->AddFunction("LoadCellClass",LoadCellClass);
pLua->AddFunction("LoadSystemClass", LoadSystemClass);
pLua->AddFunction("SpawnSystem",SpawnSystem);
pLua->AddFunction("MergeSystems",MergeSystems);
pLua->AddFunction("HaltSystem",HaltSystem);
pLua->AddFunction("StartSystem",StartSystem);
pLua->AddFunction("LinkPathToSystems",LinkPathToSystems);
pLua->AddFunction("DeleteSystem",DeleteSystem);
pLua->AddFunction("SetCellSystemProperties",SetCellSystemProperties);
pLua->AddFunction("SpawnCell",SpawnCell);
pLua->AddFunction("DeleteCell",DeleteCell);
pLua->AddFunction("SetCellProperties",SetCellProperties);
pLua->AddFunction("SpawnObject",SpawnObject);
pLua->AddFunction("SpawnObjectSystem", SpawnObjectSystem);
//second fase of my project
pLua->AddFunction("BakeSystem",BakeSystem);
pLua->AddFunction("BakeAllSystems",BakeAllSystems);
pLua->AddFunction("InitiateFase2",InitiateFase2);
pLua->AddFunction("ClearCanvas",ClearCanvas);

//misc
pLua->AddFunction("LoadSoundLibrary",LoadSoundLibrary);
pLua->AddFunction("LoadSound",LoadSound);
pLua->AddFunction("PlaySound",PlaySound);
pLua->AddFunction("PlayEffect",PlayEffect); 
pLua->AddFunction("Save",Save);
pLua->AddFunction("Quit",Quit);

pLua->AddFunction("PauseAll",PauseAll);
pLua->AddFunction("LoadCanvasSurface",LoadCanvasSurface);

}

LuaGlue HelloWorld(lua_State* l)
{
	int argNum =1; 
	
	Ogre::LogManager::getSingletonPtr()->logMessage("LUA CALLED: Hello World!"); 
	const char* name= pLua->GetStringArgument(argNum++); 
	Ogre::LogManager::getSingletonPtr()->logMessage("He also said: " + std::string(name)); 
	pWorld->sayHello(); 
return 0;
}

LuaGlue RegisterEventHandler(lua_State* l)
{

return 0;
}


//first priority functions
LuaGlue Initialize(lua_State* l)
{




return 0;
}

LuaGlue RunScript(lua_State* l)
{
	int argNum =1; 
	const char* filename= pLua->GetStringArgument(argNum++); 
	//todo concatenate filename with LUA DIR 
	pLua->RunScript(filename);

	return 0;
}


LuaGlue ConstructCanvas(lua_State* l)
{
	//create canvas with settings

	return 0;
}

LuaGlue SetCamera(lua_State* l)
{
return 0;
}

LuaGlue LoadCellClass(lua_State* l)
{
return 0;
}



LuaGlue LoadSystemClass(lua_State* l)
{

	//load system


return 0;
}



LuaGlue SpawnSystem(lua_State* l)
{
return 0;
}

LuaGlue MergeSystems(lua_State* l)
{
return 0;
}

LuaGlue HaltSystem(lua_State* l)
{
return 0;
}

LuaGlue StartSystem(lua_State* l)
{
return 0;
}

LuaGlue LinkPathToSystems(lua_State* l)
{
return 0;
}

LuaGlue DeleteSystem(lua_State* l)
{
return 0;
}

LuaGlue SetCellSystemProperties(lua_State* l)
{
return 0;
}

LuaGlue SpawnCell(lua_State* l)
{
return 0;
}

LuaGlue DeleteCell(lua_State* l)
{
return 0;
}

LuaGlue SetCellProperties(lua_State* l)
{
return 0;
}

LuaGlue SpawnObject(lua_State* l) 
{
return 0;
}

LuaGlue SpawnObjectSystem(lua_State* l)
{
return 0;
}

//second fase of my project
LuaGlue BakeSystem(lua_State* l)
{
return 0;
}

LuaGlue BakeAllSystems(lua_State* l)
{
return 0;
}

LuaGlue InitiateFase2(lua_State* l)
{
return 0;
}

LuaGlue ClearCanvas(lua_State* l)
{
return 0;
}


//misc
LuaGlue LoadSoundLibrary(lua_State* l)
{
return 0;
}

LuaGlue LoadSound(lua_State* l)
{
return 0;
}

LuaGlue PlaySound(lua_State* l) 
{
return 0;
}

LuaGlue PlayEffect(lua_State* l) 
{
return 0;
}

LuaGlue Save(lua_State* l) 
{
return 0;
}

LuaGlue Quit(lua_State* l)
{
return 0;
}

LuaGlue LogMessage(lua_State* l)
{
	int argNum =1; 
	const char* message = pLua->GetStringArgument(argNum++); 
	Ogre::LogManager::getSingletonPtr()->logMessage("Lua: " + std::string(message)); 

return 0;
}

LuaGlue PauseAll(lua_State* l)
{
	pWorld->PauseAll(); 

	return 0;
}

LuaGlue LoadCanvasSurface(lua_State* l)
{
	int argNum =1; 
	const char* filename= pLua->GetStringArgument(argNum++); 
	//todo concatenate filename with LUA DIR 
	pLua->RunScript(filename);

	//load globals






	return 0;
}



