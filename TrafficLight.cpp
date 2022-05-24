#include "TrafficLight.h"
#include "Database.h"

TrafficLight::TrafficLight(std::string label, ControlType controlType)
{
	this->Label = label;
	this->Control = controlType;

	this->CurrentLightColor = LightColor::Green;
	this->CurrentMode = Mode::Auto;

	this->HCSensor = HousingConditionSensor();
	this->LCSensor = LightConditionSensor();
	this->PTSensor = PassingTrainSensor();
}

Mode TrafficLight::GetModeByIdFromCin()
{
	unsigned short modeId;

	do
	{
		std::cout << "0. Auto\n1. Manual\n2. Emergency\nChoose the mode: ";
		std::cin >> modeId;
		std::cin.clear();

		if (modeId >= 0 && modeId <= 2)
		{
			return (Mode)(modeId);
		}
	} while (true);
}

LightColor TrafficLight::GetLightByIdFromCin()
{
	unsigned short lightId;

	do
	{
		std::cout << "0. None\n1. Red\n2. Yellow\n3. Green\n4. Blue\n5. MoonWhite\nChoose the light: ";
		std::cin >> lightId;
		std::cin.clear();

		if (lightId >= 0 && lightId <= 5)
		{
			return (LightColor)(lightId);
		}
	} while (true);
}

void TrafficLight::UpdateTLColors(unsigned short train_position)
{
	std::vector<TrafficLight>* TrafficLights = Database::GetTrafficLights();
	int i;
	int count;

	for (i = train_position - 1, count = 0; count < 3; i--, count++)
	{
		if (i < 0) i += (*TrafficLights).size();
		(*TrafficLights)[i].SetLightColor(LightColor::Red);
	}
	for (i = train_position - 4, count = 0; count < 3; i--, count++)
	{
		if (i < 0) i += (*TrafficLights).size();
		(*TrafficLights)[i].SetLightColor(LightColor::Yellow);
	}
	i = train_position - 8;
	if (i < 0) i += (*TrafficLights).size();
	if ((*TrafficLights)[i].GetLightColor() != LightColor::Red) (*TrafficLights)[i].SetLightColor(LightColor::Green);
}

void TrafficLight::ShowLightInEmergencyLabels()
{
	std::vector<TrafficLight>* trafficLights = Database::GetTrafficLights();

	std::cout << "In emergency mode:" << std::endl;
	for (int i = 0; i < (*trafficLights).size(); i++)
	{
		if ((*trafficLights)[i].GetMode() == Mode::Emergency)
		{
			std::cout << (*trafficLights)[i].GetLabel() << std::endl;
		}
	}
}

void TrafficLight::ShowLightInManualLabels()
{
	std::vector<TrafficLight>* trafficLights = Database::GetTrafficLights();

	std::cout << "In manual mode:" << std::endl;
	for (int i = 0; i < (*trafficLights).size(); i++)
	{
		if ((*trafficLights)[i].GetMode() == Mode::Manual)
		{
			std::cout << (*trafficLights)[i].GetLabel() << std::endl;
		}
	}
}

void TrafficLight::ShowBrokenTrafficLights()
{
	std::vector<EmergencyEvent>* emergencyEvents = Database::GetEmergencyEvents();
	std::vector<ManualEvent>* manualEvents = Database::GetManualEvents();

	std::cout << "Emergency events:\n";
	for (int i = 0; i < (*emergencyEvents).size(); i++)
	{
		std::cout << (*emergencyEvents)[i].GetRelatedTrafficLight()->GetLabel() << " - " << (int)(*emergencyEvents)[i].GetReason() << " [" << (int)(*emergencyEvents)[i].GetStatus() << "]\n";
	}

	std::cout << "\nManual events:\n";
	for (int i = 0; i < (*manualEvents).size(); i++)
	{
		std::cout << (*manualEvents)[i].GetRelatedTrafficLight()->GetLabel() << " - " << (int)(*manualEvents)[i].GetReason() << " [" << (int)(*manualEvents)[i].GetStatus() << "]\n";
	}
}

void TrafficLight::ShowStationsWithTrains()
{
	std::vector<Train>* trains = Database::GetTrains();

	std::cout << "Trains are at stations:" << std::endl;
	for (int i = 0; i < (*trains).size(); i++)
	{
		unsigned short stationNumber;
		std::string label = (*Database::GetTrafficLights())[(*trains)[i].GetCurrentTLId()].GetLabel();

		if (label.find("C-") != std::string::npos)
		{
			stationNumber = std::ceil((std::stoi(std::string(label.begin() + 2, label.end())) + 1) / 2);
			std::cout << "Station #" << stationNumber << std::endl;
		}
	}
}

void TrafficLight::ChangeTLMode()
{
	TrafficLight* trafficLight = Database::GetTrafficLightByLabelFromCin();
	std::cout << "TL found. Current mode: " << (int)((*trafficLight).GetMode()) << std::endl;
	Mode mode = GetModeByIdFromCin();

	if (mode == Mode::Emergency)
	{
		EventType reason = IEvent::GetReasonByIdFromCinUsingMode(mode);

		EmergencyEvent* event = Database::GetEmergencyEvent(Activator::Sensor, reason, trafficLight);
		if (event == nullptr) event = Database::GetEmergencyEvent(Activator::Dispatcher, reason, trafficLight);

		if (event == nullptr)
		{
			Database::AddEmergencyEvent(Activator::Dispatcher, reason, trafficLight);
			std::cout << "Done [code 1]." << std::endl;
			return;
		}
	}
	if (mode == Mode::Manual)
	{
		EventType reason = IEvent::GetReasonByIdFromCinUsingMode(mode);

		ManualEvent* event = Database::GetManualEvent(Activator::Sensor, reason, trafficLight);
		if (event == nullptr) event = Database::GetManualEvent(Activator::Dispatcher, reason, trafficLight);

		if (event == nullptr)
		{
			Database::AddManualEvent(Activator::Dispatcher, reason, trafficLight);
			std::cout << "Done [code 2]." << std::endl;
			return;
		}
	}

	trafficLight->SetMode(mode);
	std::cout << "Done [code 0]." << std::endl;
}

void TrafficLight::ChangeTLLight()
{
	TrafficLight* trafficLight = Database::GetTrafficLightByLabelFromCin();
	std::cout << "TL found. Current light: " << (int)((*trafficLight).GetLightColor()) << std::endl;
	LightColor light = GetLightByIdFromCin();

	(*trafficLight).SetLightColor(light);
	std::cout << "Done. Light changed to " << (int)((*trafficLight).GetLightColor()) << std::endl;
}

void TrafficLight::CheckTLCondition()
{
	Database::SH.Init();
	std::cout << "Done" << std::endl;
}

void TrafficLight::ShowLightNearTrainsLabels()
{
	std::vector<Train>* trains = Database::GetTrains();

	std::cout << "Trains are near:" << std::endl;
	for (int i = 0; i < (*trains).size(); i++)
	{
		std::cout << (*Database::GetTrafficLights())[(*trains)[i].GetCurrentTLId()].GetLabel() << std::endl;
	}
}

void TrafficLight::StopTheLine()
{
	std::vector<TrafficLight>* trafficLights = Database::GetTrafficLights();
	for (int i = 0; i < (*trafficLights).size(); i++)
	{
		(*trafficLights)[i].SetLightColor(LightColor::Red);
	}
	std::cout << "Done. All TL switched to red light." << std::endl;
}

void TrafficLight::ResyncWithEventsList()
{
	std::vector<TrafficLight>* trafficLights = Database::GetTrafficLights();
	for (int i = 0; i < (*trafficLights).size(); i++)
	{
		if (((*trafficLights)[i].GetMode() == Mode::Emergency && Database::GetEmergencyEventByTL(&(*trafficLights)[i]) == nullptr)
			|| ((*trafficLights)[i].GetMode() == Mode::Manual && Database::GetManualEventByTL(&(*trafficLights)[i]) == nullptr))
		{
			(*trafficLights)[i].SetMode(Mode::Auto);
			(*trafficLights)[i].SetLightColor(LightColor::Green);
		}
	}
	std::cout << "Done." << std::endl;
}
