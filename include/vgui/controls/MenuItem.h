/// @file

#pragma once

#include "Button.h"

namespace vgui2
{

class Menu;
//class TextImage;

class MenuItem : public Button
{
	DECLARE_CLASS_SIMPLE(MenuItem, Button);
public:
	MenuItem(Panel *apParent, const char *asName, const char *asText, Menu *apCascadeMenu = nullptr, bool abCheckable = false);
	MenuItem(Panel *apParent, const char *asName, const wchar_t *asText, Menu *apCascadeMenu = nullptr, bool abCheckable = false);
	~MenuItem();
	
	/*virtual*/ void Paint() override;
protected:
	void OnKeyCodeReleased(KeyCode aeCode);
	void OnMenuClose();
	
	MESSAGE_FUNC(OnKeyModeSet, "KeyModeSet");
private:
	Menu *mpCascadeMenu{nullptr};
	TextImage *mpCascadeArrow{nullptr};
	Image *mpCheck{nullptr};
	TextImage *mpBlackCheck{nullptr};
	TextImage *mpCurrentKeyBinding{nullptr};
	KeyValues *mpUserData{nullptr};
	
	bool mbCheckable{false};
	bool mbChecked{false};
};

}; // namespace vgui2