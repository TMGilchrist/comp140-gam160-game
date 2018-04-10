#pragma once
#include "Event.h"
#include "Object.h"

class Observer
{
public:
	virtual ~Observer() {};

	//What do do when recieveing an event notification.
	virtual void onNotify(const Object& object, Event event) = 0;
};