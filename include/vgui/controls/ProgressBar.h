/// @file

#pragma once

#include <vgui2/VGUI.h>

#include "Panel.h"

namespace vgui2
{

/// Status bar that visually displays discrete progress in the form of a segmented strip
class ProgressBar : public Panel
{
	DECLARE_CLASS_SIMPLE(ProgressBar, Panel);
public:
	ProgressBar(Panel *apParent, const char *asName);
	~ProgressBar();
protected:
	/*virtual*/ void Paint();
	
	void PaintSegment(int &anX, int &anY, int anHeight, int anWidth);
	
	/*virtual*/ void PaintBackground();
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
protected:
	int mnProgressDirection{0};
	
	float mfProgress{0.0f};
private:
	char *msDialogVar{nullptr};
	
	int mnSegmentCount{0};
	int mnSegmentGap{0};
	int mnSegmentWidth{0};
	
	int mnBarInset{0};
	int mnBarMargin{0};
};

/// Non-segmented progress bar
class ContinuousProgressBar : public ProgressBar
{
	DECLARE_CLASS_SIMPLE(ContinuousProgressBar, ProgressBar);
public:
	ContinuousProgressBar(Panel *apParent, const char *asName);
	
	/*virtual*/ void Paint();
};

}; // namespace vgui2