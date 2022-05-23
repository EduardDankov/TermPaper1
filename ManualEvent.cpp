#include "ManualEvent.h"

ManualEvent::ManualEvent(Activator activatedBy, EventType reason, TrafficLight* relatedTrafficLight)
	: IEvent(activatedBy, reason, relatedTrafficLight) {}