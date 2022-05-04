#include <iostream>

#include "Menu.h"
#include "Database.h"

int main()
{
	Menu menu(Database::GetMenuItemLabels());
	menu.ActivateMenu();

	// TODO: Remove debug settings below
	system("pause");
	return 0;
}
