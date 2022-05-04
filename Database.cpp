#include "Database.h"

const std::vector<std::string> Database::MenuItemLabels = {
	"1. Get a list of traffic lights in Manual Mode.",
	"2. Get a list of traffic lights in Emergency Mode.",
	"3. Get a list of traffic lights fixed violation of the integrity of the housing and/or serviceability of the light.",
	"4. Get a list of traffic lights with solved problem (only for auto-initialized problems).",
	"5. Get a list of stations where trains are located.",
	"6. Change some traffic light's mode.",
	"7. Change some traffic light's light.",
	"8. Unscheduled check of serviceability of all traffic lights.",
	"9. Get a list of traffic lighs near which are located trains.",
	"10. Stop all trains (red light).",
	"11. Send information about emergency events to the special service.",
	"12. Update the events list.",
	"13. Re-syncronize traffic lights by events list."
};

std::vector<TrafficLight> Database::TrafficLights = {

};

std::vector<std::string> Database::GetMenuItemLabels()
{
	return Database::MenuItemLabels;
}

std::vector<TrafficLight> Database::GetTrafficLights()
{
	return Database::TrafficLights;
}
