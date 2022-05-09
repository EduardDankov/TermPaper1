#include <iostream>

#include "Menu.h"
#include "Database.h"

int main()
{
	std::cout << "Term Work by Eduard Ziablin (NUNG, IP-21-2, 2022)" << std::endl;

	Menu menu(Database::GetMenuItemLabels());

	while (true)
	{
		menu.ActivateMenu();
	}

	// TODO: Remove debug settings below
	system("pause");
	return 0;
}
