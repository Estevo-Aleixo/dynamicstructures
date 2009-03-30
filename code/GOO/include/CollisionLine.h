#pragma once

#include "Physical2DObject.h"

class CollisionLine: public Physical2DObject
{
public:
	CollisionLine(std::string& name,Canvas* canvas, Physical2DObject* mother, Physical2DObject* father);
	~CollisionLine(void);
};
