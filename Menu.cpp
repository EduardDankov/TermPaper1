#include "Menu.h"
#include "SensorHandler.h"
#include "Database.h"

Menu::Menu(std::vector<std::string> item_labels)
{
	this->ItemLabels = item_labels;
}

void Menu::ActivateMenu()
{
	unsigned short selectedMenuItemId = 0;

	this->ShowMenuItemLabels();
	this->SelectMenuItem(selectedMenuItemId);
	this->InitMenuItem(selectedMenuItemId);
}

void Menu::ShowMenuItemLabels()
{
	unsigned short i = 0;
	std::cout << "\n";
	for each (std::string itemLabel in this->ItemLabels)
	{
		std::cout << ++i << ". " << itemLabel << std::endl;
	}
}

void Menu::SelectMenuItem(unsigned short &selected_menu_item)
{
	unsigned short itemLabelsCount = this->ItemLabels.size();

	while (true)
	{
		std::cout << "\nEnter valid menu item ID: ";
		std::cin >> selected_menu_item;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (selected_menu_item < 1 || selected_menu_item > itemLabelsCount)
		{
			std::cout << "The entered value is not in valid range." << std::endl;
			continue;
		}
		break;
	}
}

void Menu::InitMenuItem(unsigned short menu_item_id)
{
	std::cout << "\n";

	switch (menu_item_id)
	{
	case 1: TrafficLight::ShowLightInManualLabels(); break;
	case 2: TrafficLight::ShowLightInEmergencyLabels(); break;
	case 3: TrafficLight::ShowBrokenTrafficLights(); break;
	case 4: break;
	case 5: break;
	case 6: TrafficLight::ChangeTLMode(); break;
	case 7: TrafficLight::ChangeTLLight(); break;
	case 8: TrafficLight::CheckTLCondition(); break;
	case 9: break;
	case 10: TrafficLight::StopTheLine(); break;
	case 11: break;
	case 12: break;
	case 13: break;
	}
}
