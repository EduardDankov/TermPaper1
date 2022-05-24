#include <iostream>

#include "Menu.h"
#include "Database.h"
#include "SensorHandler.h"

int main()
{
	std::cout << "Term Work by Eduard Ziablin (NUNG, IP-21-2, 2022)" << std::endl;

	Menu menu(Database::GetMenuItemLabels());

	while (true)
	{
		Database::TH.Init();
		Database::SH.Init();
		menu.ActivateMenu();
	}
}
