#pragma once
#include <string>
#include <vector>

#include "TrafficLight.h"
#include "EmergencyEvent.h"
#include "SensorHandler.h"
#include "ManualEvent.h"
#include "Train.h"
#include "TrainHandler.h"

class Database
{
private:
	static const std::vector<std::string> MenuItemLabels;
	static std::vector<TrafficLight> TrafficLights;
	static std::vector<Train> Trains;
	static std::vector<EmergencyEvent> EmergencyEvents;
	static std::vector<ManualEvent> ManualEvents;

public:
	static SensorHandler SH;
	static TrainHandler TH;

	// Task 4: Get a list of traffic lights with solved problem
	static void ShowSolvedEvents();
	// Task 11: Send information about emergency events to the special service
	static void SendReportToSpecialService();
	// Task 12: Update the events list
	static void UpdateEventsLists();

	static std::vector<std::string> GetMenuItemLabels()	{ return MenuItemLabels; }
	static std::vector<TrafficLight>* GetTrafficLights() { return &Database::TrafficLights; }
	static std::vector<Train>* GetTrains() { return &Database::Trains; }
	static std::vector<EmergencyEvent>* GetEmergencyEvents() { return &Database::EmergencyEvents; }
	static std::vector<ManualEvent>* GetManualEvents() { return &Database::ManualEvents; }

	static void AddEmergencyEvent(Activator, EventType, TrafficLight*);
	static void RemoveEmergencyEvent(Activator, EventType, TrafficLight*);
	static void AddManualEvent(Activator, EventType, TrafficLight*);
	static void RemoveManualEvent(Activator, EventType, TrafficLight*);

	static TrafficLight* GetTrafficLightByLabelFromCin();
	static EmergencyEvent* GetEmergencyEvent(Activator, EventType, TrafficLight*);
	static ManualEvent* GetManualEvent(Activator, EventType, TrafficLight*);
	static EmergencyEvent* GetEmergencyEventByTL(TrafficLight*);
	static ManualEvent* GetManualEventByTL(TrafficLight*);
};
