#pragma once
#include <string>
#include <vector>

#include "TrafficLight.h"
#include "EmergencyEvent.h"
#include "SensorHandler.h"

class Database
{
private:
	static const std::vector<std::string> MenuItemLabels;
	static std::vector<TrafficLight> TrafficLights;
	static std::vector<EmergencyEvent> EmergencyEvents;

public:
	static SensorHandler SH;

	static std::vector<std::string> GetMenuItemLabels()	{ return Database::MenuItemLabels; }
	static std::vector<TrafficLight>* GetTrafficLights() { return &Database::TrafficLights; }
	static std::vector<EmergencyEvent>* GetEmergencyEvents() { return &Database::EmergencyEvents; }

	static TrafficLight* GetTrafficLightByLabelFromCin();
};
