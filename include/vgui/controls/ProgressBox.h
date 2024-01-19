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

#include <vgui2/VGUI.h>

#include "Frame.h"

namespace vgui2
{

// Prevent Windows macros from messing with the class
//#ifdef ProgressBox
//#	undef ProgressBox
//#endif

class ProgressBox : public Frame
{
	DECLARE_CLASS_SIMPLE(ProgressBox, Frame);
public:
	/// asTitle - text to be displayed in the title bar of the window
	/// asText - text message in the message box
	/// apParent - parent panel of the message box, by default it has no parent
	ProgressBox(const char *asTitle, const char *asText, const char *asUnknownTimeString, Panel *apParent = nullptr);
	ProgressBox(const wchar_t *asTitle, const wchar_t *asText, const wchar_t *asUnknownTimeString, Panel *apParent = nullptr);
	
	~ProgressBox();
	
	/// Put the message box into a modal state
	/*virtual*/ void DoModal(Frame *apFrameOver = nullptr);
	
	/// Make the message box appear and in a modeless state
	/*virtual*/ void ShowWindow(Frame *apFrameOver = nullptr);
	
	/// Updates progress bar, range [0.0f, 1.0f]
	/*virtual*/ void SetProgress(float afProgress);
	
	/// Sets the info text
	/*virtual*/ void SetText(const char *asText);
	
	/// Toggle visibility of the close box
	/*virtual*/ void SetCancelButtonVisible(bool abState);
	
	/// Toggle the enabled state of the cancel button
	/// (in case it needs to be disabled partway through a process)
	/*virtual*/ void SetCancelButtonEnabled(bool abState);
	
	/* Custom messages:
	
		"ProgressBoxCancelled"
			sent if the user pressed the cancel button (must be enabled & visible for this to happen)
	*/
protected:
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void OnClose();
	/*virtual*/ void OnCloseFrameButtonPressed();
	/*virtual*/ void OnThink();
	/*virtual*/ void OnCommand(const char *asCmd);
	/*virtual*/ void OnTick();
	
	/// Called when the update has been cancelled
	/*virtual*/ void OnCancel();
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
private:
	MESSAGE_FUNC(OnShutdownRequest, "ShutdownRequest");
	
	void Init();
	void UpdateTitle();
private:
	wchar_t msTitleString[128]{};
	wchar_t msInfoString[128]{};
	wchar_t msUnknownTimeString[128]{};
	
	Label *mpMessageLabel{nullptr};
	ProgressBar *mpProgressBar{nullptr};
	Button *mpCancelButton{nullptr};
	
	float mfFirstProgressUpdate{0.0f};
	float mfLastProgressUpdate{0.0f};
	float mfCurrentProgress{0.0f};
};

}; // namespace vgui2