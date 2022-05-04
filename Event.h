#pragma once
#include <string>

#include "TrafficLight.h"
#include <vector>

class Event
{
protected:
	static unsigned int Counter;

	const static enum EventType
	{
		// Automatic, by sensor
		BrokenHousing,
		BrokenLight,
		TrainsTooClose,

		// Manual, by dispatcher
		HumanOnRails,
		BrokenTrain
	};

	const static enum Activator
	{
		Sensor,
		Dispatcher
	};

	const static enum Status
	{
		NotConsidered, // The event has just been initialized
		DispatcherControl, // The event is controlled manual by dispatcher
		SpecialService, // A special service has been sent to solve the problem
		Solved // The problem has been solved and the event can be deactivated
	};

	unsigned int ID;
	bool IsSolved;

	EventType Reason;
	Activator ActivatedBy;
	Status CurrentStatus;

	std::vector<TrafficLight> RelatedTrafficLights;

public:
	Event(Activator, EventType, std::vector<TrafficLight>);
};

