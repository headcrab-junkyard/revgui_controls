/*
 * This file is part of revgui_controls
 * Copyright (C) 2021 BlackPhrase
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

#pragma once

namespace vgui2
{
struct ISystem;
struct IVGui;
struct IPanel;
};

#include <vgui2/ISystem.h>
#include <vgui2/IVGUI.h>
#include <vgui2/IPanel.h>

class CVGUIProvider
{
public:
	//CVGUIProvider(vgui2::ISystem *apSystem, vgui2::IVGui *apVGUI, vgui2::IPanel *apPanelWrapper);
	
	static vgui2::ISystem *GetSystem() /*const*/ {return mpSystem;}
	
	static vgui2::IVGui *GetVGUI() /*const*/ {return mpVGUI;}
	
	static vgui2::IPanel *GetPanelWrapper() /*const*/ {return mpPanelWrapper;}
private:
	static constexpr vgui2::ISystem *mpSystem{nullptr};
	static constexpr vgui2::IVGui *mpVGUI{nullptr};
	static constexpr vgui2::IPanel *mpPanelWrapper{nullptr};
};