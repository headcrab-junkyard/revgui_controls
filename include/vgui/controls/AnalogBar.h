/// @file

#pragma once

#include <vgui2/VGUI.h>

#include "Panel.h"

namespace vgui2
{

class AnalogBar : public Panel
{
	DECLARE_CLASS_SIMPLE(AnalogBar, Panel);
public:
	AnalogBar(Panel *apParent, const char *asName);
	~AnalogBar();
protected:
	/*virtual*/ void Paint() override;
protected:
	int mnAnalogValueDirection{0};
	
	float mfAnalogValue{0.0f};
private:
	Color mHomeColor{};
	
	char *msDialogVar{nullptr};
	
	int mnSegmentCount{0};
	int mnSegmentGap{0};
	int mnSegmentWide{0};
	
	int mnBarInset{0};
	
	float mfHomeValue{0.0f};
};

/// Non-segmented analog bar
class ContinuousAnalogBar : public AnalogBar
{
	DECLARE_CLASS_SIMPLE(ContinuousAnalogBar, AnalogBar);
public:
	ContinuousAnalogBar(Panel *apParent, const char *asName);
	
	/*virtual*/ void Paint() override;
};

}; // namespace vgui2