#pragma once

enum class StationStopStatus
{
	NotAtStation,
	ArrivingAtStation,
	Stopped,
	Disembarkation,
	Boarding,
	Departure
};

class Train
{
private:
	static unsigned short Count;

	unsigned short Number;
	unsigned short CurrentTLId;
	StationStopStatus StationStatus;

public:
	Train(unsigned short);

	unsigned short GetNumber() { return this->Number; }
	unsigned short GetCurrentTLId() { return this->CurrentTLId; }
	StationStopStatus GetStationStatus() { return this->StationStatus; }

	void Move();
};

