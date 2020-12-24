/// @file
/// @brief Popup discardable message box

#pragma once

#include <vgui2/VGUI.h>

#include "Frame.h"

namespace vgui2
{

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