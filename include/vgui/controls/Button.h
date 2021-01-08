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
	CUtlFlags<unsigned short> mvButtonFlags;
	
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