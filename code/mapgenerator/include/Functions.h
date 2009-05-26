#pragma once

#include "Main.h"



class Functions
{

	static Ogre::Mesh* create2DPolygon(std::string name, std::vector<Ogre::Vector2> vertex, std::vector<unsigned int> index); 




public:
	Functions(void);
	~Functions(void);
};
