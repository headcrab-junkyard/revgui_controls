/// @file

#pragma once

#include "Button.h"
#include "TextEntry.h"

namespace vgui2
{

/// Scroll bar button
class ComboBoxButton : public Button
{
public:
	ComboBoxButton();
private:
	Color mDisabledBgColor{};
};

/// Text entry with dropdown options list
class ComboBox : public TextEntry
{
	DECLARE_CLASS_SIMPLE(ComboBox, TextEntry);
public:
	ComboBox(Panel *apParent, const char *asName, int anLines, bool abAllowEdit);
	~ComboBox();
protected:
private:
	void DoMenuLayout();
private:
	Menu *mpDropDown{nullptr};
	ComboBoxButton *mpButton{nullptr};
	
	bool mbPreventTextChangeMessage{false};
};

}; // namespace vgui2