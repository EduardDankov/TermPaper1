#include "Database.h"

const std::vector<std::string> Database::MenuItemLabels = {
	"Option 1",
	"Option 2",
	"Option 3"
};

std::vector<std::string> Database::GetMenuItemLabels()
{
	return Database::MenuItemLabels;
}
