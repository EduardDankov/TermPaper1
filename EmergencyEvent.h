#pragma once
#include "IEvent.h"

class EmergencyEvent 
	: public IEvent
{
public:
	EmergencyEvent(Activator, EventType, std::vector<std::reference_wrapper<TrafficLight>>);
};

