#include "ManualEvent.h"

ManualEvent::ManualEvent(Activator activatedBy, EventType reason, std::vector<TrafficLight> relatedTrafficLights)
	: Event(activatedBy, reason, relatedTrafficLights) {}