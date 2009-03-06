#include "ContactFilter.h"

ContactFilter::ContactFilter(void)
{
}

ContactFilter::~ContactFilter(void)
{
}

bool ContactFilter::ShouldCollide(b2Shape* shape1, b2Shape* shape2)
{
	const b2FilterData& filter1 = shape1->GetFilterData();
	const b2FilterData& filter2 = shape2->GetFilterData();

	return filter1.groupIndex == filter2.groupIndex; 
	
	/*
	if (filter1.groupIndex == filter2.groupIndex && filter1.groupIndex != 0)
	{
		return filter1.groupIndex > 0;
	}
	bool collide = (filter1.maskBits & filter2.categoryBits) != 0 && (filter1.categoryBits & filter2.maskBits) != 0;	
	return collide;
	*/
}