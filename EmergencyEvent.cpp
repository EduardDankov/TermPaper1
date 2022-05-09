#include "EmergencyEvent.h"

EmergencyEvent::EmergencyEvent(Activator activatedBy, EventType reason, std::vector<std::reference_wrapper<TrafficLight>> relatedTrafficLights)
	: IEvent(activatedBy, reason, relatedTrafficLights) {}