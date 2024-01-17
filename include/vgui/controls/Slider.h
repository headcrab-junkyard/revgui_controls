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
/// @brief Labeled horizontal slider

#pragma once

#include "Panel.h"

//#include <vgui/VGUI.h>

namespace vgui2 // TODO: vgui?
{

class TextImage;

class Slider : public Panel
{
	DECLARE_CLASS_SIMPLE(Slider, Panel);
public:
	Slider(Panel *apParent, const char *asPanelName);
	
	/*virtual*/ void SetValue(int anValue, bool abTriggerChangeMessage = true);
	/*virtual*/ int GetValue() const;
	
	/// Set to min and max range of rows to display
	/*virtual*/ void SetRange(int anMin, int anMax);
	
	/*virtual*/ void GetRange(int &anMin, int &anMax) const;
	
	/// Get current slider position
	/*virtual*/ void GetNobPos(int &anMin, int &anMax) const;
	
	/*virtual*/ void SetButtonOffset(int anOffset);
	
	/*virtual*/ void SetNumTicks(int anTicks);
	
	/*virtual*/ void SetThumbWidth(int anWidth);
	
	/*virtual*/ int EstimateValueAtPos(int anLocalMouseX, int anLocalMouseY);
	
	/*virtual*/ void SetInverted(bool abState);
	
	/*virtual*/ void SetTickCaptions(const wchar_t *asLeft, const wchar_t *asRight);
	/*virtual*/ void SetTickCaptions(const char *asLeft, const char *asRight);
	
	/// If you click on the slider outside of the nob, the nob jumps
	/// to the click position, and if this setting is enabled, the nob
	/// is then draggable from the new position until the mouse is released
	/*virtual*/ void SetDragOnRepositionNob(bool abState);
	/*virtual*/ bool IsDrawOnRepositionNob() const;
	
	/// Get if the slider nob is being dragged by user, usually the app
	/// should refure from forcefully setting slider value if it's being
	/// dragged by user since the next frame the nob will pop back to mouse pos
	/*virtual*/ bool IsDragged() const;
	
	/// This allows the slider to behave like it's larger than what's actually being drawn
	/*virtual*/ void SetSliderThumbSubRange(bool abEnable, int anMin = 0, int anMax = 100);
	
	/*virtual*/ void OnCursorMoved(int anPosX, int anPosY) override;
	
	/*virtual*/ void OnMousePressed(MouseCode aeCode) override;
	/*virtual*/ void OnMouseDoublePressed(MouseCode aeCode) override;
	/*virtual*/ void OnMouseReleased(MouseCode aeCode) override;
protected:
	/*virtual*/ void OnSizeChanged(int anNewWidth, int anNewHeight);
	
	/*virtual*/ void Paint();
	/*virtual*/ void PaintBackground();
	
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	/*virtual*/ void GetSettings(KeyValues *apSettings);
	/*virtual*/ void ApplySettings(KeyValues *apSettings);
	
	/*virtual*/ const char *GetDescription() const;
	
	/*virtual*/ void OnKeyCodeTyped(KeyCode aeCode);
	
	/*virtual*/ void DrawNob();
	/*virtual*/ void DrawTicks();
	/*virtual*/ void DrawTickLabels();
	
	/*virtual*/ void GetTrackRect(int &x, int &y, int &anWidth, int &anHeight);
	
	/*virtual*/ void RecomputeNobPosFromValue();
	/*virtual*/ void RecomputeValueFromNobPos();
	
	/*virtual*/ void SendSliderMovedMessage();
	
	/*virtual*/ void SendSliderDragStartMessage();
	/*virtual*/ void SendSliderDragEndMessage();
	
	void ClampRange(); // TODO: where from?
protected:
	Color mTickColor{};
	Color mTrackColor{};
	Color mDisabledTextColor1{};
	Color mDisabledTextColor2{};
	
	int mnNobPos[2]{};
	
	int mnDragStartPos[2]{};
	int mnNobDragStartPos[2]{};
	
	int mnRange[2]{};
	int mnSubRange[2]{};
	
	TextImage *mpLeftCaption{nullptr};
	TextImage *mpRightCaption{nullptr};
	
	IBorder *mpSliderBorder{nullptr};
	IBorder *mpInsetBorder{nullptr};
	
	float mfNobSize{0.0f};
	
	int mnTicks{0};
	int mnValue{0}; ///< The position of the slider, in coords as specified by SetRange/SetRangeWindow
	int mnButtonOffset{0};
	
	bool mbDragging{false};
	
	bool mbInverted : 1 {false};
	bool mbUseSubRange : 1 {false};
	bool mbDragOnRepositionNob : 1 {false};
};

}; // namespace vgui2