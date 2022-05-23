#pragma once
#include <string>
#include <vector>

#include "TrafficLight.h"
#include "EmergencyEvent.h"
#include "SensorHandler.h"
#include "ManualEvent.h"

class Database
{
private:
	static const std::vector<std::string> MenuItemLabels;
	static std::vector<TrafficLight> TrafficLights;
	static std::vector<EmergencyEvent> EmergencyEvents;
	static std::vector<ManualEvent> ManualEvents;

public:
	static SensorHandler SH;

	static std::vector<std::string> GetMenuItemLabels()	{ return Database::MenuItemLabels; }
	static std::vector<TrafficLight>* GetTrafficLights() { return &Database::TrafficLights; }
	static std::vector<EmergencyEvent>* GetEmergencyEvents() { return &Database::EmergencyEvents; }
	static std::vector<ManualEvent>* GetManualEvents() { return &Database::ManualEvents; }

	static void AddEmergencyEvent(Activator, EventType, TrafficLight*);
	static void RemoveEmergencyEvent(Activator, EventType, TrafficLight*);

	static TrafficLight* GetTrafficLightByLabelFromCin();
	static EmergencyEvent* GetEmergencyEvent(Activator, EventType, TrafficLight*);
};
