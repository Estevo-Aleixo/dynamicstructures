#pragma once

#include "Main.h"
#include "Object2DProperties.h"

class CellProperties: public Object2DProperties
{
public:
	CellProperties(void);
	~CellProperties(void);

//contact properties
	//what to do on collision?

	std::string eventHandler; 

};
