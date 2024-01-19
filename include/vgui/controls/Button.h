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

#include <vgui2/VGUI.h>
#include <vgui2/MouseCode.h>

#include "Label.h"

namespace vgui2
{

class Button : public Label
{
	DECLARE_CLASS_SIMPLE(Button, Label);
public:
	Button(Panel *apParent, const char *asName, const char *asText, Panel *apActionSignalTarget = nullptr, const char *asCmd = nullptr);
	Button(Panel *apParent, const char *asName, const wchar_t *asText, Panel *apActionSignalTarget = nullptr, const char *asCmd = nullptr);
	~Button();
	
	/*virtual*/ void SetArmed(bool abState);
	/*virtual*/ bool IsArmed() const;
protected:
	/// Override this to draw different focus border
	/*virtual*/ void DrawFocusBorder(int anX0, int anY0, int anX1, int anY1);
	
	/// Paint button on screen
	/*virtual*/ void Paint();
	
	/// Get button border attributes
	/*virtual*/ IBorder *GetBorder(bool abDepressed, bool abArmed, bool abSelected, bool abKeyFocus) const;
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	MESSAGE_FUNC_INT(OnSetState, "SetState", state);
	
	/*virtual*/ void OnMousePressed(MouseCode aeCode);
	/*virtual*/ void OnMouseDoublePressed(MouseCode aeCode);
	/*virtual*/ void OnMouseReleased(MouseCode aeCode);
	/*virtual*/ void OnKeyCodePressed(KeyCode aeCode)
	/*virtual*/ void OnKeyCodeReleased(KeyCode aeCode);
	
	/// Get control setting for editing
	/*virtual*/ void GetSettings(KeyValues *apSettings);
	
	/*virtual*/ const char *GetDescription() const;
	
	KeyValues *GetActionMessage() const;
	
	void PlayButtonReleasedSound();
protected:
	CUtlFlags<unsigned short> mvFlags;
	
	KeyValues *mpActionMessage{nullptr};
	
	IBorder *mpDefaultBorder{nullptr};
	IBorder *mpDepressedBorder{nullptr};
	IBorder *mpKeyFocusBorder{nullptr};
	
	bool mbPaint{false};
	bool mbSelectionStateSaved{false};
	bool mbStaySelectedOnClick{false};
private:
	void Init();
};

}; // namespace vgui2