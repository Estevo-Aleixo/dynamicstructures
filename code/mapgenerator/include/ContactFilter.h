#pragma once

#include "main.h"

class ContactFilter: public b2ContactFilter
{
public:
	ContactFilter(void);
	~ContactFilter(void);

	bool ShouldCollide(b2Shape* shape1, b2Shape* shape2); 

};
