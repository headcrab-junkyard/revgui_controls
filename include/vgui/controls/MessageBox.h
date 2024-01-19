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
/// @brief Popup discardable message box

#pragma once

//#include <vgui/VGUI.h>
#include "Frame.h"

namespace vgui2
{

// Prevent Window macros from messing with the class
#ifdef MessageBox
#	undef MessageBox
#endif

class MessageBox : public Frame
{
	DECLARE_CLASS_SIMPLE(MessageBox, Frame);
public:
	/// @param asTitle Text to be displayed in the title bar of the window
	/// @param asText Text message in the message box
	/// @param apParent Parent panel of the message box, by default it has no parent. This will keep the box visible until the OK button is pressed
	MessageBox(const char *asTitle, const char *asText, Panel *apParent = nullptr
	MessageBox(const wchar_t *asTitle, const wchar_t *asText, Panel *apParent = nullptr);
	~MessageBox();
	
	/// Put the message box into a modal state
	/*virtual*/ void DoModel(Frame *apFrameOver = nullptr);
	
	/// Make the message box appear and in a modeless state
	/*virtual*/ void ShowWindow(Frame *apFrameOver = nullptr);
	
	/// Set a string command to be sent when the OK button is pressed
	/// Use AddActionSignalTarget() to mark yourself as a recipient of the command
	/*virtual*/ void SetCommand(const char *asCmd);
	/*virtual*/ void SetCommand(KeyValues *apCmd);
	
	/// Set the visibility of the OK button
	/*virtual*/ void SetOKButtonVisible(bool abState);
	
	/// Set the text on the OK button
	/*virtual*/ void SetOKButtonText(const char *asText);
	/*virtual*/ void SetOKButtonText(const wchar_t *asText);
	
	/// Cancel button (disabled by default)
	
	void SetCancelButtonVisible(bool abState);
	
	void SetCancelButtonText(const char *asText);
	void SetCancelButtonText(const wchar_t *asText);
	
	void SetCancelCommand(KeyValues *apCmd);
	
	/// Toggle visibility of the close button
	/*virtual*/ void DisableCloseButton(bool abState);
	
	/*virtual*/ void OnCommand(const char *asCmd);
	
	/// Shows the message box over the cursor
	void ShowMessageBoxOverCursor(bool abEnable);
protected:
	/*virtual*/ void PerformLayout();
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
protected:
	Button *mpOkButton{nullptr};
	Button *mpCancelButton{nullptr};
	
	Label *mpMessageLabel{nullptr};
private:
	void Init();
	
	MESSAGE_FUNC(OnShutdownRequest, "ShutdownRequest");
private:
	KeyValues *mpOkCommand{nullptr};
	KeyValues *mpCancelCommand{nullptr};
	
	vgui::Frame *mpFrameOver{nullptr};
	
	bool mbNoAutoClose{false} : 1;
	bool mbShowMessageBoxOverCursor{false} : 1;
};

}; // namespace vgui2