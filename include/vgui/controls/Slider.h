/// @file

#pragma once

#include "Panel.h"

namespace vgui2
{

class Slider : public Panel
{
	DECLARE_CLASS_SIMPLE(Slider, Panel);
public:
	Slider(Panel *apParent, const char *asName);
	
	/*virtual*/ void SetValue(int anValue, bool abTriggerChangeMessage = true);
	/*virtual*/ int GetValue() const;
	
	/*virtual*/ void SetRange(int anMin, int anMax);
	/*virtual*/ void GetRange(int &anMin, int &anMax) const;
	
	/// Get current slider position
	/*virtual*/ void GetNobPos(int &anMin, int &anMax) const;
	
	/*virtual*/ void SetButtonOffset(int anOffset);
	
	/*virtual*/ void SetNumTicks(int anTicks);
	
	/*virtual*/ void SetThumbWidth(int anWidth);
	
	/*virtual*/ int EstimateValueAtPos(int anLocalMouseX, int anLocalMouseY);
	
	/*virtual*/ void SetInverted(bool abState);
	
	/*virtual*/ bool IsDragged() const;
	
	/*virtual*/ void SetSliderThumbSubRange(bool abEnable, int anMin = 0, int anMax = 100);
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
	
	void ClampRange();
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
	
	int mnTicks{0};
	int mnValue{0};
	int mnButtonOffset{0};
	
	bool mbDragging{false};
	
	bool mbInverted{false} : 1;
};

}; // namespace vgui2