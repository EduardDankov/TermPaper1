#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Database.h"

class Menu
{
private:
	std::vector<std::string> ItemLabels;

public:
	Menu(std::vector<std::string>);

	void ActivateMenu();

	void ShowMenuItemLabels();
	void SelectMenuItem(unsigned short&);
	void InitMenuItem(unsigned short);
};
