/*
 * This file is part of revgui_controls
 * Copyright (C) 2020-2021, 2024 BlackPhrase
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

namespace vgui2
{

class Button;
class ScrollBarSlider;

class ScrollBar : public Panel
{
	DECLARE_CLASS_SIMPLE(ScrollBar, Panel);
public:
	ScrollBar(Panel *apParent, const char *asPanelName, bool abVertical);
	
	/// Set the value of the scroll bar slider
	/*virtual*/ void SetValue(int anValue);
	
	/// Get the value of the scroll bar slider
	/*virtual*/ int GetValue() const;
	
	/*virtual*/ void SetRange();
	
	/*virtual*/ void GetRange(int &anMin, int &anMax);
	
	/*virtual*/ void SetRangeWindow();
	
	/*virtual*/ int GetRangeWindow() const;
	
	/// Check if the scrollbar is vertical or horizontal
	/*virtual*/ bool IsVertical() const;
	
	/*virtual*/ bool HasFullRange() const;
protected:
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void SendSliderMoveMesssage(int anValue);
	/*virtual*/ void SendScrollBarSliderReleasedMessage(int anValue);
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	/*virtual*/ void OnSizeChanged(int anNewWidth, int anNewHeight);
	
	MESSAGE_FUNC_INT(OnSliderMoved, "ScrollBarSliderMoved", anPosition);
	MESSAGE_FUNC_INT(OnSliderReleased, "ScrollBarSliderReleased", anPosition);
	
	/*virtual*/ void RespondToScrollArrow(const int anDirection);
	
	/*virtual*/ void UpdateButtonsForImages();
	/*virtual*/ void UpdateSliderImages();
private:
	Button *mpButton[2]{nullptr};
	
	ScrollBarSlider *mpSlider{nullptr};
	
	int mnButtonPressedScrollValue{0};
	int mnScrollDelay{0}; ///< Used to control delays in scrolling
	
	bool mbRespond{false};
};

}; // namespace vgui2