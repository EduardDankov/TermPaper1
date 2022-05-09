#pragma once
#include "IEvent.h"

class ManualEvent 
	: public IEvent
{
public:
	ManualEvent(Activator, EventType, std::vector<std::reference_wrapper<TrafficLight>>);
};

