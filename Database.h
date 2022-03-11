#pragma once
#include <string>
#include <vector>

class Database
{
private:
	static const std::vector<std::string> MenuItemLabels;

public:
	static std::vector<std::string> GetMenuItemLabels();
};
