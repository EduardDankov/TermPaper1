#include "IEvent.h"

unsigned int IEvent::Counter = 0;

IEvent::IEvent(Activator activatedBy, EventType reason, TrafficLight* relatedTrafficLight)
{
	this->ID = ++IEvent::Counter;

	this->CurrentStatus = Status::NotConsidered;
	this->ActivatedBy = activatedBy;
	this->Reason = reason;
	this->RelatedTrafficLight = relatedTrafficLight;
}