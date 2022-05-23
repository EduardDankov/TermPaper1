#include <iostream>
#include <thread>
#include <future>

#include "Menu.h"
#include "Database.h"
#include "SensorHandler.h"

int main()
{
	std::cout << "Term Work by Eduard Ziablin (NUNG, IP-21-2, 2022)" << std::endl;

	Menu menu(Database::GetMenuItemLabels());

	while (true)
	{
		Database::SH.Init();
		menu.ActivateMenu();
	}

	// TODO: Remove debug settings below
	system("pause");
	return 0;
}
