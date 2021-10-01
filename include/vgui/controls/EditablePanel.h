/*
 * This file is part of revgui_controls
 * Copyright (C) 2020-2021 BlackPhrase
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

#pragma once

#include "Panel.h"
#include "FocusNavGroup.h"

namespace vgui2
{

class EditablePanel : public Panel
{
	DECLARE_CLASS_SIMPLE(EditablePanel, Panel);
public:
	EditablePanel(Panel *apParent, const char *asName);
	EditablePanel(Panel *apParent, const char *asName, HScheme ahScheme);
	virtual ~EditablePanel();
	
	KeyValues *GetDialogVariables() const;
protected:
	/*virtual*/ void PaintBackground();
	
	/*virtual*/ FocusNavGroup &GetFocusNavGroup() const;
	
	// Overrides
	/*virtual*/ OnChildAdded(VPANEL anChild) override;
	/*virtual*/ OnSizeChanged(int anNewWidth, int anNewHeight) override;
	/*virtual*/ OnClose() override;
	
	/*virtual*/ void ApplyUserConfigSettings(KeyValues *apSettings);
	/*virtual*/ void GetUserConfigSettings(KeyValues *apSettings);
private:
	void ForceSubPanelsToUpdateWithNewDialogVariables(); // TODO: WeNeedEvenLongerMethodNameThanThisOnePlzFixValve
private:
	FocusNavGroup mNavGroup{};
	
	BuildGroup *mpBuildGroup{nullptr};
	KeyValues *mpDialogVariables{nullptr};
	
	char *msConfigName{nullptr};
	
	int mnConfigID{0};
	
	bool mbShouldSkipAutoResize{bool};
};

}; // namespace vgui2