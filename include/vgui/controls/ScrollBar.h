/// @file

#pragma once

#include "Panel.h"

namespace vgui2
{

class Button;

class ScrollBar : public Panel
{
	DECLARE_CLASS_SIMPLE(ScrollBar, Panel);
public:
	ScrollBar(Panel *apParent, const char *asName, bool abVertical);
protected:
private:
};

}; // namespace vgui2