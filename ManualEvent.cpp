#include "ManualEvent.h"

ManualEvent::ManualEvent(Event::Activator activatedBy, Event::EventType reason, std::vector<TrafficLight> relatedTrafficLights)
	: Event(activatedBy, reason, relatedTrafficLights) {}