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
LuaGlue SetSurfaceProperties(lua_State* l); 

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

void PrintTable(lua_State *L);
std::string	getStringGlobal(lua_State *L, const char* varname);
double getNumGlobal(lua_State *L, const char* varname); 

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
pLua->AddFunction("SetSurfaceProperties",SetSurfaceProperties);
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
	int argNum=1; 
	//get scriptname
	const char* scriptName = pLua->GetStringArgument(argNum++); 

	Ogre::LogManager::getSingletonPtr()->logMessage("c++: loading system class: " + std::string(scriptName));
	//load system
	
	if (pLua->RunScript(scriptName))
	{
		//create property set:
		SurfaceProperties* newSet= new SurfaceProperties(); 
		newSet->mName =getStringGlobal(pLua->GetScriptContext(),"name");
		newSet->description =getStringGlobal(pLua->GetScriptContext(),"description");
		newSet->cellType =getStringGlobal(pLua->GetScriptContext(),"cellType"); 
		
		//extra properties:
		lua_getglobal(pLua->GetScriptContext(), "extraParameters");
		lua_pushnil(pLua->GetScriptContext());

		while(lua_next(pLua->GetScriptContext(), -2) != 0)
		{
				const char* key = lua_tostring(pLua->GetScriptContext(), -2);
				double var = lua_tonumber(pLua->GetScriptContext(), -1); 
				newSet->mExtraParameters[key]= var;
				lua_pop(pLua->GetScriptContext(), 1);
		}
	
		pWorld->mSystemFactory->registerSystemPropertySet(newSet); 


	} 


  


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

LuaGlue SetSurfaceProperties(lua_State* l)
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
pWorld->mCanvas->clearCanvas();

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

void PrintTable(lua_State *L)
{
    lua_pushnil(L);

    while(lua_next(L, -2) != 0)
    {
		if(lua_isstring(L, -1)){
          printf("%s = %s\n", lua_tostring(L, -2), lua_tostring(L, -1));
		Ogre::LogManager::getSingletonPtr()->logMessage( std::string(lua_tostring(L, -2)) + " = " + std::string(lua_tostring(L, -1)) ) ;     
		}
		else if(lua_isnumber(L, -1)){
          printf("%s = %d\n", lua_tostring(L, -2), lua_tonumber(L, -1));
		Ogre::LogManager::getSingletonPtr()->logMessage( StringConverter::toString((Ogre::Real)lua_tonumber(L, -2)) + " = " + StringConverter::toString((Ogre::Real)lua_tonumber(L, -1)) ) ;     
		}
		else if(lua_istable(L, -1))
		{
          PrintTable(L);
		}
        lua_pop(L, 1);
    }
}

std::string	getStringGlobal(lua_State *L, const char* varname)
{
	lua_getglobal(L, varname);
	return std::string(lua_tostring(L, -1));
}

double getNumGlobal(lua_State *L, const char* varname)
{
	lua_getglobal(L, varname);
	return lua_tonumber(L, -1);
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



