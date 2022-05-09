#pragma once
#include <string>
#include <vector>

#include "TrafficLight.h"

enum class EventType
{
	// Automatic, by sensor
	BrokenHousing,
	BrokenLight,
	TrainsTooClose,

	// Manual, by dispatcher
	HumanOnRails,
	BrokenTrain,
	TrainInDepot
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

	std::vector<std::reference_wrapper<TrafficLight>> RelatedTrafficLights;

	IEvent(Activator, EventType, std::vector<std::reference_wrapper<TrafficLight>>);

public:
	Status GetStatus() { return this->CurrentStatus; }
	EventType GetReason() { return this->Reason; }
	Activator GetActivator() { return this->ActivatedBy; }
	std::vector<std::reference_wrapper<TrafficLight>> GetRelatedTrafficLights() { return this->RelatedTrafficLights; }

	void SetStatus(Status status) { this->CurrentStatus = status; }
};

