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
	for each (std::string itemLabel in this->ItemLabels)
	{
		std::cout << ++i << ". " << itemLabel << std::endl;
	}	
}

void Menu::SelectMenuItem(unsigned short &selected_menu_item)
{
	unsigned short itemLabelsCount = this->ItemLabels.size();

	do 
	{
		std::cout << "Enter valid menu item ID: ";
		std::cin >> selected_menu_item;
	} while (selected_menu_item < 1 || selected_menu_item > itemLabelsCount);
}

void Menu::InitMenuItem(unsigned short menu_item_id)
{
	// TODO: Realize method
	std::cout << "Selected Menu Item ID: " << menu_item_id << std::endl;
}
