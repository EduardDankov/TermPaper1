#include "Database.h"

const std::vector<std::string> Database::MenuItemLabels = {
	"1. Get traffic lights in Manual Mode.",
	"2. Get traffic lights in Emergency Mode.",
	"3. "
};

std::vector<std::string> Database::GetMenuItemLabels()
{
	return Database::MenuItemLabels;
}

std::vector<TrafficLight> Database::GetTrafficLights()
{
	return Database::TrafficLights;
}
