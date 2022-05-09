#include "IEvent.h"

unsigned int IEvent::Counter = 0;

IEvent::IEvent(Activator activatedBy, EventType reason, std::vector<std::reference_wrapper<TrafficLight>> relatedTrafficLights)
{
	this->ID = ++IEvent::Counter;

	this->CurrentStatus = Status::NotConsidered;
	this->ActivatedBy = activatedBy;
	this->Reason = reason;
	this->RelatedTrafficLights = relatedTrafficLights;
}