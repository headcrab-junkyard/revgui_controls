/// @file

#pragma once

#include <tier1/utlvector.h>

#include "Panel.h"

namespace vgui2
{

class MenuBar : public Panel
{
	DECLARE_CLASS_SIMPLE(MenuBar, Panel);
public:
	MenuBar(Panel *apParent, const char *asName);
	~MenuBar();
	
	/// Add button to end of menu list
	/*virtual*/ void AddButton(MenuButton *apButton);
	
	/*virtual*/ void AddMenu(const char *asButtonName, Menu *apMenu);
	
	/*virtual*/ void GetContentSize(int &anWidth, int &anHeight);
protected:
	/*virtual*/ void OnKeyCodeTyped(KeyCode aeCode);
	/*virtual*/ void OnKeyTyped(wchar_t anUniChar);
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void Paint();
	
	MESSAGE_FUNC(OnMenuClose, "MenuClose");
	MESSAGE_FUNC_INT(OnCursorEnteredMenuButton, "CursorEnteredMenuButton", VPanel);
private:
	CUtlVector<MenuButton*> mvMenuButtons;
	
	int mnRightEdge{0};
};

}; // namespace vgui2