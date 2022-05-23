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

std::vector<TrafficLight> Database::TrafficLights = {
	TrafficLight("C-1", ControlType::Semiautomatic),
	TrafficLight("C-2", ControlType::Semiautomatic),
	TrafficLight("M-1", ControlType::Semiautomatic),
	TrafficLight("M-2", ControlType::Automatic),
	TrafficLight("M-3", ControlType::Automatic),
	TrafficLight("MK-1", ControlType::Semiautomatic),
	TrafficLight("M-4", ControlType::Semiautomatic),
	TrafficLight("M-5", ControlType::Automatic),
	TrafficLight("M-6", ControlType::Automatic),
	TrafficLight("MK-2", ControlType::Semiautomatic),
	TrafficLight("M-7", ControlType::Semiautomatic),
	TrafficLight("M-8", ControlType::Automatic),
	TrafficLight("M-9", ControlType::Automatic),
	TrafficLight("MK-3", ControlType::Semiautomatic),
	TrafficLight("M-10", ControlType::Semiautomatic),
	TrafficLight("M-11", ControlType::Automatic),
	TrafficLight("M-12", ControlType::Automatic),
	TrafficLight("MK-4", ControlType::Semiautomatic),
	TrafficLight("M-13", ControlType::Semiautomatic),
	TrafficLight("M-14", ControlType::Automatic),
	TrafficLight("M-15", ControlType::Automatic),
	TrafficLight("MK-5", ControlType::Semiautomatic),
	TrafficLight("M-16", ControlType::Semiautomatic),
	TrafficLight("M-17", ControlType::Automatic),
	TrafficLight("M-18", ControlType::Automatic),
	TrafficLight("C-3", ControlType::Semiautomatic),
	TrafficLight("C-4", ControlType::Semiautomatic),
	TrafficLight("M-19", ControlType::Semiautomatic),
	TrafficLight("MK-6", ControlType::Semiautomatic),
	TrafficLight("M-20", ControlType::Semiautomatic),
	TrafficLight("C-5", ControlType::Semiautomatic),
	TrafficLight("C-6", ControlType::Semiautomatic),
	TrafficLight("M-21", ControlType::Semiautomatic),
	TrafficLight("M-22", ControlType::Automatic),
	TrafficLight("M-23", ControlType::Automatic),
	TrafficLight("MK-7", ControlType::Semiautomatic),
	TrafficLight("M-24", ControlType::Semiautomatic),
	TrafficLight("M-25", ControlType::Automatic),
	TrafficLight("M-26", ControlType::Automatic),
	TrafficLight("MK-8", ControlType::Semiautomatic),
	TrafficLight("M-27", ControlType::Semiautomatic),
	TrafficLight("M-28", ControlType::Automatic),
	TrafficLight("M-29", ControlType::Automatic),
	TrafficLight("MK-9", ControlType::Semiautomatic),
	TrafficLight("M-30", ControlType::Semiautomatic),
	TrafficLight("M-31", ControlType::Automatic),
	TrafficLight("M-32", ControlType::Automatic),
	TrafficLight("MK-10", ControlType::Semiautomatic),
	TrafficLight("M-33", ControlType::Semiautomatic),
	TrafficLight("M-34", ControlType::Automatic),
	TrafficLight("M-35", ControlType::Automatic),
	TrafficLight("MK-11", ControlType::Semiautomatic),
	TrafficLight("M-36", ControlType::Semiautomatic),
	TrafficLight("M-37", ControlType::Automatic),
	TrafficLight("M-38", ControlType::Automatic),
	TrafficLight("C-7", ControlType::Semiautomatic),
	TrafficLight("C-8", ControlType::Semiautomatic),
	TrafficLight("M-39", ControlType::Semiautomatic),
	TrafficLight("MK-12", ControlType::Semiautomatic),
	TrafficLight("M-40", ControlType::Semiautomatic)
};

std::vector<EmergencyEvent> Database::EmergencyEvents = {

};

TrafficLight* Database::GetTrafficLightByLabelFromCin()
{
	std::string label;

	do
	{
		std::cout << "Please, enter the traffic light label: ";
		std::cin >> label;
		std::cin.clear();

		for (int i = 0; i < TrafficLights.size(); i++)
		{
			if (TrafficLights[i].GetLabel() == label)
			{
				return &TrafficLights[i];
			}
		}
	} while (true);
}

SensorHandler Database::SH(Database::GetTrafficLights());