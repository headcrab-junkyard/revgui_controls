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

#include "TextImage.h"
#include "ToggleButton.h"

namespace vgui2
{

/// Radio button image
class RadioImage : public TextImage
{
public:
	RadioImage(RadioButton *apButton);
	
	/*virtual*/ void Paint() override;
	
	/*virtual*/ void SetColor(Color aColor);
	
	Color mBorderColor1{};
	Color mBorderColor2{};
	
	Color mCheckColor{};
	
	Color mBgColor{};
private:
	RadioButton *mpButton{nullptr};
};

class RadioButton : public ToggleButton
{
	DECLARE_CLASS_SIMPLE(RadioButton, ToggleButton);
public:
	RadioButton(Panel *apParent, const char *asName, const char *asText);
	~RadioButton();
	
	/*virtual*/void SetSelected(int abState);
	
	/*virtual*/ void SetSubTabPosition(int anPosition);
	/*virtual*/int GetSubTabPosition() const;
	
	/*virtual*/ int GetRadioTabPosition() const;
	
	/*virtual*/ void SilentSetSelected(bool abState);
protected:
	/*virtual*/ void DoClick();
	
	/*virtual*/ void Paint() override;
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	/*virtual*/ void OnKeyCodeTyped(KeyCode aeCode);
	
	/*virtual*/ IBorder *GetBorder(bool abDepressed, bool abArmed, bool abSelected, bool abKeyFocus) const;
	
	/*virtual*/ void ApplySettings(KeyValues *apSettings);
	/*virtual*/ void GetSettings(KeyValues *apSettings);
	
	/*virtual*/ const char *GetDescription() const;
	
	/*virtual*/ void PerformLayout();
	
	RadioButton *FindBestRadioButton(int anDirection) const;
private:
	void InternalSetSelected(bool abState, bool abFireEvents);
private:
	Color mSelectedFgColor{};
	
	RadioImage *mpRadioBoxImage{nullptr};
	
	int mnOldTabPosition{0};
	int mnSubTabPosition{0}; ///< Tab position with the radio button list
};

}; // namespace vgui2