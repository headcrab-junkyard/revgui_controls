/*
 * This file is part of revgui_controls
 * Copyright (C) 2020-2021, 2024 BlackPhrase
 *
 * revgui_controls is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * revgui_controls is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with revgui_controls. If not, see <http://www.gnu.org/licenses/>.
 */

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
	ToggleButton(Panel *apParent, const char *asPanelName, const char *asText);
	
	/*virtal*/ void DoClick();
	
	/* Messages sent (get via AddActionSignalTarget() method):
		"ButtonToggled"
			int "state"
	*/
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