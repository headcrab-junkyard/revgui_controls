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
	
	/*virtual*/ void SetMoveable(bool abState);
	/*virtual*/ bool IsMoveable() const;
	
	/*virtual*/ void SetSizeable(bool abState);
	/*virtual*/ bool IsSizeable() const;
protected:
private:
};

}; // namespace vgui2