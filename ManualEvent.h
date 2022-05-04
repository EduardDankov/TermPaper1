#pragma once
#include "Event.h"

class ManualEvent 
	: public Event
{
public:
	ManualEvent(Activator, EventType, std::vector<TrafficLight>);
};

