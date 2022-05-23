#include "IEvent.h"

unsigned int IEvent::Counter = 0;

IEvent::IEvent(Activator activatedBy, EventType reason, TrafficLight* relatedTrafficLight)
{
	this->ID = ++Counter;

	this->CurrentStatus = (activatedBy == Activator::Dispatcher) ? Status::DispatcherControl : Status::NotConsidered;
	this->ActivatedBy = activatedBy;
	this->Reason = reason;
	this->RelatedTrafficLight = relatedTrafficLight;
}

EventType IEvent::GetReasonByIdFromCinUsingMode(Mode mode)
{
	unsigned short eventId;

	do
	{
		std::cout << "Emergency events:\n1. Broken housing\n2. Broken light\nManual events:\n3. Human on rails\n4. Violence\nChoose the reason:\n";
		std::cin >> eventId;
		std::cin.clear();

		if (mode == Mode::Emergency && eventId >= 1 && eventId <= 2
			|| mode == Mode::Manual && eventId >= 3 && eventId <= 4)
		{
			return (EventType)(eventId);
		}
	} while (true);
}