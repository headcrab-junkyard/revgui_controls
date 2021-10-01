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