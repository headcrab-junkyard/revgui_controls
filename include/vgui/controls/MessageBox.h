/// @file
/// @brief Popup discardable message box

#pragma once

#include "Frame.h"

namespace vgui2
{

class MessageBox : public Frame
{
	DECLARE_CLASS_SIMPLE(MessageBox, Frame);
public:
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
	
	Frame *mpFrameOver{nullptr};
	
	bool mbNoAutoClose{false} : 1;
	bool mbShowMessageBoxOverCursor{false} : 1;
};

}; // namespace vgui2