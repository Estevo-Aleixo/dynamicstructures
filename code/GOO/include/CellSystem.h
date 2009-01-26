#pragma once

#include "Main.h"
#include "Cell.h"

class CellSystem
{
public:

	std::vector<Cell*> cells; 
	CellSystem(void);
	~CellSystem(void);
};
