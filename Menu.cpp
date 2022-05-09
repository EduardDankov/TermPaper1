#include "Menu.h"

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
	// TODO: Realize method
	std::cout << "Selected Menu Item \"" << Database::GetMenuItemLabels()[menu_item_id - 1] << "\" ID: " << menu_item_id << std::endl;
}
