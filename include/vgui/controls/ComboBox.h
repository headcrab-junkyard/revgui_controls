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

#include "Button.h"
#include "TextEntry.h"

namespace vgui2
{

/// Scroll bar button
class ComboBoxButton : public Button
{
public:
	ComboBoxButton();
private:
	Color mDisabledBgColor{};
};

/// Text entry with dropdown options list
class ComboBox : public TextEntry
{
	DECLARE_CLASS_SIMPLE(ComboBox, TextEntry);
public:
	ComboBox(Panel *apParent, const char *asName, int anLines, bool abAllowEdit);
	~ComboBox();
protected:
private:
	void DoMenuLayout();
private:
	Menu *mpDropDown{nullptr};
	ComboBoxButton *mpButton{nullptr};
	
	bool mbPreventTextChangeMessage{false};
};

}; // namespace vgui2