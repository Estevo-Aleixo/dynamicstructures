#pragma once
#include "Main.h"

class ContactListener: public b2ContactListener
{
public:

	void Add(const b2ContactPoint* point);
	void Persist(const b2ContactPoint* point);
	void Remove(const b2ContactPoint* point);
    void Result(const b2ContactResult* point);
};
