#pragma once

#include "Main.h"
#include "Object2DProperties.h"

//singleton
class ObjectDefinitions 
{
public:

	static void Create(std::string& filename); 
	static void Destroy();
	static ObjectDefinitions* getSingletonPtr(){return mInstance;}
	
	std::vector<Object2DProperties>& getAll2DObjects(); 

	Object2DProperties getObjectByName(const char* name); 
	Object2DProperties getObjectByID(unsigned int ID){return mObjects[ID];} 
private: 
	static ObjectDefinitions* mInstance;
	ObjectDefinitions(std::string& filename);
	~ObjectDefinitions(void);

	std::vector<Object2DProperties> mObjects;

	void loadDefaultObjects();
	void loadObjectDefinitions(std::string& filename); 
};
