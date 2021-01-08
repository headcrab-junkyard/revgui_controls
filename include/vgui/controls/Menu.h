/// @file

#pragma once

#include "Panel.h"

namespace vgui2
{

class Menu : public Panel
{
	DECLARE_CLASS_SIMPLE(Menu, Panel);
public:
	Menu(Panel *apParent, const char *asName);
	~Menu();
protected:
private:
	MenuItem *GetParentMenuItem() const;
private:
};

}; // namespace vgui2