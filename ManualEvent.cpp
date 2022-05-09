#include "ManualEvent.h"

ManualEvent::ManualEvent(Activator activatedBy, EventType reason, std::vector<std::reference_wrapper<TrafficLight>> relatedTrafficLights)
	: IEvent(activatedBy, reason, relatedTrafficLights) {}