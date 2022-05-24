#include "Train.h"

#include "Database.h"

unsigned short Train::Count = 0;

Train::Train(unsigned short start_traffic_light_id)
{
	this->Number = ++Count;
	this->CurrentTLId = start_traffic_light_id;
	this->StationStatus = StationStopStatus::NotAtStation;
}

void Train::Move()
{
	if (this->StationStatus == StationStopStatus::ArrivingAtStation
		|| this->StationStatus == StationStopStatus::Stopped
		|| this->StationStatus == StationStopStatus::Boarding
		|| this->StationStatus == StationStopStatus::Disembarkation)
	{
		this->StationStatus = (StationStopStatus)(((int)(this->StationStatus)) + 1);
	}

	else if (this->StationStatus == StationStopStatus::Departure)
	{
		if ((*Database::GetTrafficLights())[this->CurrentTLId].GetLightColor() == LightColor::Green 
			|| (*Database::GetTrafficLights())[this->CurrentTLId].GetLightColor() == LightColor::MoonWhite)
		{
			this->StationStatus = StationStopStatus::NotAtStation;
			this->CurrentTLId++;
		}
	}

	else if (this->StationStatus == StationStopStatus::NotAtStation)
	{
		if ((*Database::GetTrafficLights())[this->CurrentTLId].GetLabel().find("C-") != std::string::npos) // Near station
		{
			this->StationStatus = StationStopStatus::ArrivingAtStation;
			this->CurrentTLId++;
		}

		else if ((*Database::GetTrafficLights())[this->CurrentTLId].GetLightColor() == LightColor::Green
			|| (*Database::GetTrafficLights())[this->CurrentTLId].GetLightColor() == LightColor::Yellow)
		{
			this->CurrentTLId++;
		}
	}

	if (this->CurrentTLId >= (*Database::GetTrafficLights()).size()) this->CurrentTLId -= (*Database::GetTrafficLights()).size();
	TrafficLight::UpdateTLColors(this->CurrentTLId);
}
