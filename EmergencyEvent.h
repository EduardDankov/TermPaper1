#pragma once
#include "Event.h"

class EmergencyEvent 
	: public Event
{
public:
	EmergencyEvent(Activator, EventType, std::vector<TrafficLight>);
};

