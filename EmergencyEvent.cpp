#include "EmergencyEvent.h"

EmergencyEvent::EmergencyEvent(Activator activatedBy, EventType reason, TrafficLight* relatedTrafficLight)
	: IEvent(activatedBy, reason, relatedTrafficLight) {}