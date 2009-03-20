#pragma once
#include "Main.h"

#include "EventHandler.h" 
class World;


class ContactListener: public b2ContactListener, public EventHandler
{
public:
	ContactListener(World* world);
	~ContactListener();

	void Add(const b2ContactPoint* point);
	void Persist(const b2ContactPoint* point);
	void Remove(const b2ContactPoint* point);
    void Result(const b2ContactResult* point);

protected: 
};
