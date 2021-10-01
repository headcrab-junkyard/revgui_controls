/*
 * This file is part of revgui_controls
 * Copyright (C) 2020-2021 BlackPhrase
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
/// @brief A button without borders that shows a left-pointing/right-pointing arrow

#pragma once

#include "vgui2/VGUI.h"
#include "ToggleButton.h"

namespace vgui2
{

class ExpandButton : public ToggleButton
{
	DECLARE_CLASS_SIMPLE(ExpandButton, ToggleButton);
public:
	ExpandButton(Panel *apParent, const char *asName);
	~ExpandButton();
	
	/// Select/expand the button (selected == expanded)
	/*virtual*/ void SetSelected(bool abState);
	
	/// Sets whether or not the state of the check can be changed
	/// If set to false, then no input in the code or by the user can change its state
	void SetExpandable(bool abState);
	
	/*virtual*/ void Paint() override;
protected:
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	/* MESSAGES SENT
		"Expanded" - send when the expand button state is changed
			"state" - button state: 1 is expanded, 0 - unexpanded
	*/
	MESSAGE_FUNC_PTR(OnExpanded, "Expanded", panel);
	
	/*virtual*/ IBorder *GetBorder(bool abDepressed, bool abArmed, bool abSelected, bool abKeyFocus) const;
private:
	Color mColor{};
	
	HFont mhFont{0};
	
	bool mbExpandable{false};
};

}; // namespace vgui2