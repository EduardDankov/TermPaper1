#include "Event.h"

unsigned int Event::Counter = 0;

Event::Event(Activator activatedBy, EventType reason, std::vector<TrafficLight> relatedTrafficLights)
{
	this->ID = ++Event::Counter;
	this->IsSolved = false;

	this->ActivatedBy = activatedBy;
	this->Reason = reason;
	this->RelatedTrafficLights = relatedTrafficLights;
}