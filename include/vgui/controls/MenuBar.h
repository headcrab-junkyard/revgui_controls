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

#pragma once

#include <tier1/utlvector.h>

#include "Panel.h"

namespace vgui2
{

class MenuBar : public Panel
{
	DECLARE_CLASS_SIMPLE(MenuBar, Panel);
public:
	MenuBar(Panel *apParent, const char *asName);
	~MenuBar();
	
	/// Add button to end of menu list
	/*virtual*/ void AddButton(MenuButton *apButton);
	
	/*virtual*/ void AddMenu(const char *asButtonName, Menu *apMenu);
	
	/*virtual*/ void GetContentSize(int &anWidth, int &anHeight);
protected:
	/*virtual*/ void OnKeyCodeTyped(KeyCode aeCode);
	/*virtual*/ void OnKeyTyped(wchar_t anUniChar);
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void Paint();
	
	MESSAGE_FUNC(OnMenuClose, "MenuClose");
	MESSAGE_FUNC_INT(OnCursorEnteredMenuButton, "CursorEnteredMenuButton", VPanel);
private:
	CUtlVector<MenuButton*> mvMenuButtons;
	
	int mnRightEdge{0};
};

}; // namespace vgui2