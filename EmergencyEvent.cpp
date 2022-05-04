#include "EmergencyEvent.h"

EmergencyEvent::EmergencyEvent(Activator activatedBy, EventType reason, std::vector<TrafficLight> relatedTrafficLights)
	: Event(activatedBy, reason, relatedTrafficLights) {}