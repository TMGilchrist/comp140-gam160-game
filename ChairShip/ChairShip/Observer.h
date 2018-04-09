#pragma once
#include "Event.h"
#include "Object.h"

class Observer
{
public:
	virtual ~Observer() {};
	virtual void onNotify(const Object& object, Event event) = 0;
};