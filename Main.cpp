#include <Windows.h>
#include <iostream>
#include "Menu.h"
#include "Database.h"

int main()
{
	Menu menu(Database::GetMenuItemLabels());
	menu.ActivateMenu();

	system("pause");
	return 0;
}
