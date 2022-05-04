#pragma once
#include <string>

#include "TrafficLight.h"
#include <vector>

enum class EventType
{
	// Automatic, by sensor
	BrokenHousing,
	BrokenLight,
	TrainsTooClose,

	// Manual, by dispatcher
	HumanOnRails,
	BrokenTrain
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

class Event
{
protected:
	static unsigned int Counter;

	unsigned int ID;
	bool IsSolved;

	EventType Reason;
	Activator ActivatedBy;
	Status CurrentStatus;

	std::vector<TrafficLight> RelatedTrafficLights;

public:
	Event(Activator, EventType, std::vector<TrafficLight>);
};

