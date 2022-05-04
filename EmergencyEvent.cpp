#include "EmergencyEvent.h"

EmergencyEvent::EmergencyEvent(Event::Activator activatedBy, Event::EventType reason, std::vector<TrafficLight> relatedTrafficLights) 
	: Event(activatedBy, reason, relatedTrafficLights) {}