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

#include "Panel.h"

namespace vgui2
{

class MenuItem;

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