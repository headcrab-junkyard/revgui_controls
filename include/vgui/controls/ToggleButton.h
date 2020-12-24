/// @file
/// @brief Type of button that when pressed stays selected & depressed until pressed again

#pragma once

#include <vgui2/VGUI.h>

#include "Button.h"

namespace vgui2
{

class ToggleButton : public Button
{
	DECLARE_CLASS_SIMPLE(ToggleButton, Button);
public:
	ToggleButton(Panel *apParent, const char *asName, const char *asText);
	
	/*virtal*/ void DoClick();
protected:
	// Overrides
	/*virtual*/ void OnMouseDoublePressed(MouseCode aeCode);
	
	/*virtual*/ Color GetButtonFgColor() const;
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	/*virtual*/ bool CanBeDefaultButton() const;
	
	/*virtual*/ void OnKeyCodePressed(KeyCode aeCode);
private:
	Color mSelectedColor{};
};

}; // namespace vgui2