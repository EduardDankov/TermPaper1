#include "Database.h"

const std::vector<std::string> Database::MenuItemLabels = {
	"Get a list of traffic lights in Manual Mode.",
	"Get a list of traffic lights in Emergency Mode.",
	"Get a list of traffic lights fixed violation of the integrity of the housing and/or serviceability of the light.",
	"Get a list of traffic lights with solved problem (only for auto-initialized problems).",
	"Get a list of stations where trains are located.",
	"Change some traffic light's mode.",
	"Change some traffic light's light.",
	"Unscheduled check of serviceability of all traffic lights.",
	"Get a list of traffic lighs near which are located trains.",
	"Stop all trains (red light).",
	"Send information about emergency events to the special service.",
	"Update the events list.",
	"Re-syncronize traffic lights by events list."
};

std::vector<std::reference_wrapper<TrafficLight>> Database::TrafficLights = {

};
