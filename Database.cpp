#include "Database.h"

const std::vector<std::string> Database::MenuItemLabels = {
	"Get a list of traffic lights in Manual Mode.",
	"Get a list of traffic lights in Emergency Mode.",
	"Get a list of traffic lights fixed violation of the integrity of the housing and/or serviceability of the light.",
	"Get a list of traffic lights with solved problem.",
	"Get a list of stations where trains are located.",
	"Change some traffic light's mode.",
	"Change some traffic light's light.",
	"Unscheduled check of serviceability of all traffic lights.",
	"Get a list of traffic lights near which are located trains.",
	"Stop all trains (red light).",
	"Send information about emergency events to the special service.",
	"Update the events list.", // TODO: remove events with Solved status
	"Re-synchronize traffic lights by events list." // TODO: change traffic lights light and mode, if there are no events in vectors
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

std::vector<ManualEvent> Database::ManualEvents = {

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

void Database::ShowSolvedEvents()
{
	std::cout << "Solved emergency events:\n";
	for (int i = 0; i < EmergencyEvents.size(); i++)
	{
		if (EmergencyEvents[i].GetStatus() == Status::Solved)
			std::cout << EmergencyEvents[i].GetRelatedTrafficLight()->GetLabel() << " - " << (int)EmergencyEvents[i].GetReason();
	}

	std::cout << "\nSolved manual events:\n";
	for (int i = 0; i < ManualEvents.size(); i++)
	{
		if (ManualEvents[i].GetStatus() == Status::Solved)
			std::cout << ManualEvents[i].GetRelatedTrafficLight()->GetLabel() << " - " << (int)ManualEvents[i].GetReason();
	}
}

void Database::SendReportToSpecialService()
{
	for (int i = 0; i < EmergencyEvents.size(); i++)
	{
		if (EmergencyEvents[i].GetStatus() == Status::NotConsidered || EmergencyEvents[i].GetStatus() == Status::DispatcherControl)
		{
			EmergencyEvents[i].SetStatus(Status::SpecialService);
			std::cout << "Emergency event #" << i << " has been reported to special service." << std::endl;
		}
	}
	
	for (int i = 0; i < ManualEvents.size(); i++)
	{
		if (ManualEvents[i].GetStatus() == Status::NotConsidered || ManualEvents[i].GetStatus() == Status::DispatcherControl)
		{
			ManualEvents[i].SetStatus(Status::SpecialService);
			std::cout << "Manual event #" << i << " has been reported to special service." << std::endl;
		}
	}

	std::cout << "Done." << std::endl;
}

void Database::AddEmergencyEvent(Activator activator, EventType event_type, TrafficLight* traffic_light)
{
	EmergencyEvents.push_back(EmergencyEvent(activator, event_type, traffic_light));

	(*traffic_light).SetLightColor(LightColor::None);
	(*traffic_light).SetMode(Mode::Emergency);
}

void Database::RemoveEmergencyEvent(Activator activator, EventType event_type, TrafficLight* traffic_light)
{
	for (int i = 0; i < EmergencyEvents.size(); i++)
	{
		if (EmergencyEvents[i].GetActivator() == activator
			&& EmergencyEvents[i].GetReason() == event_type
			&& EmergencyEvents[i].GetRelatedTrafficLight() == traffic_light)
		{
			EmergencyEvents.erase(EmergencyEvents.begin() + i);
			break;
		}
	}
}

void Database::AddManualEvent(Activator activator, EventType event_type, TrafficLight* traffic_light)
{
	ManualEvents.push_back(ManualEvent(activator, event_type, traffic_light));

	(*traffic_light).SetLightColor(LightColor::None);
	(*traffic_light).SetMode(Mode::Manual);
}

void Database::RemoveManualEvent(Activator activator, EventType event_type, TrafficLight* traffic_light)
{
	for (int i = 0; i < ManualEvents.size(); i++)
	{
		if (ManualEvents[i].GetActivator() == activator
			&& ManualEvents[i].GetReason() == event_type
			&& ManualEvents[i].GetRelatedTrafficLight() == traffic_light)
		{
			ManualEvents.erase(ManualEvents.begin() + i);
			break;
		}
	}
}

EmergencyEvent* Database::GetEmergencyEvent(Activator activator, EventType event_type, TrafficLight* traffic_light)
{
	for (int i = 0; i < EmergencyEvents.size(); i++)
	{
		if (EmergencyEvents[i].GetRelatedTrafficLight() == traffic_light
			&& EmergencyEvents[i].GetActivator() == activator
			&& EmergencyEvents[i].GetReason() == event_type) return &EmergencyEvents[i];
	}
	return nullptr;
}

ManualEvent* Database::GetManualEvent(Activator activator, EventType event_type, TrafficLight* traffic_light)
{
	for (int i = 0; i < ManualEvents.size(); i++)
	{
		if (ManualEvents[i].GetRelatedTrafficLight() == traffic_light
			&& ManualEvents[i].GetActivator() == activator
			&& ManualEvents[i].GetReason() == event_type) return &ManualEvents[i];
	}
	return nullptr;
}

SensorHandler Database::SH(GetTrafficLights());