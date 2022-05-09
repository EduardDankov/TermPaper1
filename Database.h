#pragma once
#include <string>
#include <vector>

#include "TrafficLight.h"

class Database
{
private:
	static const std::vector<std::string> MenuItemLabels;
	static std::vector<std::reference_wrapper<TrafficLight>> TrafficLights;

public:
	static std::vector<std::string> GetMenuItemLabels()	{ return Database::MenuItemLabels; }
	static std::vector<std::reference_wrapper<TrafficLight>> GetTrafficLights()	{ return Database::TrafficLights; }
};
