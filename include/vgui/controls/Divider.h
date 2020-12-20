/// @file
/// @brief Thin line used to divide sections in dialogs

#pragma once

#include "Panel.h"

namespace vgui2 // TODO: vgui/vgui3
{

class Divider : public Panel
{
	DECLARE_CLASS_SIMPLE(Divider, Panel);
public:
	Divider(Panel *apParent, const char *asName);
	~Divider();
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme) override;
};

}; // namespace vgui2