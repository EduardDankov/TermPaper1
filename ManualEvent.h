#pragma once
#include "IEvent.h"

class ManualEvent 
	: public IEvent
{
public:
	ManualEvent(Activator, EventType, TrafficLight*);
};

