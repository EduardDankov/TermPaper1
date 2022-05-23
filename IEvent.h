#pragma once
#include <string>
#include <vector>

#include "TrafficLight.h"

enum class EventType
{
	None,

	// Automatic, by sensor
	BrokenHousing,
	BrokenLight,

	// Manual, by dispatcher
	HumanOnRails,
	Violence
};

enum class Activator
{
	Sensor,
	Dispatcher
};

enum class Status
{
	NotConsidered, // The event has just been initialized
	DispatcherControl, // The event is controlled manual by dispatcher
	SpecialService, // A special service has been sent to solve the problem
	Solved // The problem has been solved and the event can be deactivated
};

class IEvent
{
private:
	static unsigned int Counter;

protected:
	unsigned int ID;

	Status CurrentStatus;
	EventType Reason;
	Activator ActivatedBy;
	TrafficLight* RelatedTrafficLight;

	IEvent(Activator, EventType, TrafficLight*);

public:
	Status GetStatus() { return this->CurrentStatus; }
	EventType GetReason() { return this->Reason; }
	Activator GetActivator() { return this->ActivatedBy; }
	TrafficLight* GetRelatedTrafficLight() { return this->RelatedTrafficLight; }

	void SetStatus(Status status) { this->CurrentStatus = status; }

	static EventType GetReasonByIdFromCinUsingMode(Mode);
};
