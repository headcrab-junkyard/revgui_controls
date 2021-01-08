/// @file
/// @brief Windowed frame

#pragma once

#include "EditablePanel.h"

namespace vgui2
{

class Frame : public EditablePanel
{
	DECLARE_CLASS_SIMPLE(Frame, EditablePanel);
public:
	Frame(Panel *apParent, const char *asName, bool abShowTaskBarIcon = true, bool abPopUp = true);
	virtual ~Frame();
	
	/*virtual*/ void Activate();
	/*virtual*/ void ActivateMinimized();
	
	/// Move the dialog to the center of the screen
	/*virtual*/ void MoveToCenterOfScreen();
	
	/*virtual*/ void FlashWindow();
	/*virtual*/ void FlashWindowStop();
	
	/// Command handling
	/*virtual*/ void OnCommand(const char *asCmd);
	
	void PlaceUnderCursor();
	
	/// Set the moveability of the panel
	/// @param abState - whether or not the panel should be moveable
	/*virtual*/ void SetMoveable(bool abState);
	
	/// Check the moveability of the panel
	/// @return true if the panel is moveable, false otherwise
	/*virtual*/ bool IsMoveable() const;
	
	/// Set the resizability of the panel
	/// @param abState - whether or not the panel should be resizable
	/*virtual*/ void SetSizeable(bool abState); // TODO: SetResizable?
	
	/// Check the resizability of the panel
	/// @return true if the panel is resizable, false otherwise
	/*virtual*/ bool IsSizeable() const; // TODO: IsResizable?
	
	/*virtual*/ void SetMenuButtonVisible(bool abState);
	
	void SetMenuButtonResponsive(bool abState);
	
	/*virtual*/ void SetMinimizeButtonVisible(bool abState);
	/*virtual*/ void SetMaximizeButtonVisible(bool abState);
	/*virtual*/ void SetMinimeToSysTrayButtonVisible(bool abState);
	/*virtual*/ void SetCloseButtonVisible(bool abState);
	/*virtual*/ void SetTitleBarVisible(bool abState);
	
	/*virtual*/ bool IsMinimized() const;
	
	/*virtual*/ void SetSysMenu(Menu *apMenu);
	/*virtual*/ Menu *GetSysMenu() const;
protected:
	/// Respond to mouse presses
	/*virtual*/ void OnMousePressed(MouseCode aeCode);
	
	/// Respond to key typing
	/*virtual*/ void OnKeyCodeTyped(KeyCode aeCode);
	/*virtual*/ void OnKeyTyped(wchar_t anUnicodeChar);
	
	/// Respond to key releases
	/*virtual*/ void OnKeyCodeReleased(KeyCode aeCode);
	
	/*virtual*/ void OnKeyFocusTicked();
	/*virtual*/ void OnClose();
	/*virtual*/ void OnFinishedClose();
	/*virtual*/ void OnMinimize();
	/*virtual*/ void OnMinimizeToSysTray();
	/*virtual*/ void OnCloseFrameButtonPressed();
	/*virtual*/ void OnChildAdded(VPANEL anChild);
	
	/// Per-frame thinking, used for transition effects
	/*virtual*/ void OnThink();
	
	/*virtual*/ void OnScreenSizeChanged(int anOldWidth, int anOldHeight);
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void ApplySettings(KeyValues *apSettings);
	/*virtual*/ void GetSettings(KeyValues *apSettings);
	
	/*virtual*/ const char *GetDescription() const;
	
	/*virtual*/ bool GetDefaultScreenPosition(int &anX, int &anY, int &anWidth, int &anHeight);
	
	/// Painting
	/*virtual*/ void PaintBackground();
	
	/*virtual*/ void GetClientArea(int &anX, int &anY, int &anWidth, int &anHeight);
	
	/*virtual*/ void ApplyUserConfigSettings(KeyValues *apSettings);
	/*virtual*/ void GetUserConfigSettings(KeyValues *apSettings);
	
	/*virtual*/ bool HasUserConfigSettings() const;
private:
	void SetupResizeCursors();
	void LayoutProportional(FrameButton *apButton);
	void FinishClose();
	void OnFrameFocusChanged(bool abHasFocus);
private:
	Color mTitleBarBgColor{};
	Color mTitleBarDisabledBgColor{};
	
	Color mTitleBarFgColor{};
	Color mTitleBarDisabledFgColor{};
	
	Color mInFocusBgColor{};
	Color mOutOfFocusBgColor{};
	
	TextImage *mpTitle{nullptr};
	
	Panel *mpTopGrip{nullptr};
	Panel *mpBottomGrip{nullptr};
	
	Panel *mpLeftGrip{nullptr};
	Panel *mpRightGrip{nullptr};
	
	Panel *mpTopLeftGrip{nullptr};
	Panel *mpTopRightGrip{nullptr};
	
	Panel *mpBottomLeftGrip{nullptr};
	Panel *mpBottomRightGrip{nullptr};
	
	Panel *mpCaptionGrip{nullptr};
	
	FrameButton *mpMinimizeButton{nullptr};
	FrameButton *mpMaximizeButton{nullptr};
	FrameButton *mpMinimizeToSysTrayButton{nullptr};
	FrameButton *mpCloseButton{nullptr};
	
	FrameSystemButton *mpMenuButton{nullptr};
	
	Menu *mpSysMenu{nullptr};
	
	VPANEL mhPreviousModal{0};
	
	HFont mhCustomTitleFont{0};
	
	int mnClientInsetX{0};
	int mnClientInsetY{0};
	
	int mnTitleTextInsetX{0};
	
	int mnGripplerWidth{0};
};

}; // namespace vgui2