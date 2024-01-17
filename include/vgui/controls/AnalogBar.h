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

/// Status bar that visually displays discrete analogValue in the form of a segmented strip
class AnalogBar : public Panel
{
	DECLARE_CLASS_SIMPLE(AnalogBar, Panel);
public:
	AnalogBar(Panel *apParent, const char *asName);
	~AnalogBar();
	
	// 'analogValue' is in the range [0.0f, 1.0f]
	MESSAGE_FUNC_FLOAT(SetAnalogValue, "SetAnalogValue", analogValue);
	
	float GetAnalogValue() const {return mfAnalogValue;}
	
	enum class AnalogValueDirection : int
	{
		East,
		West,
		North,
		South
	};
	
	void SetAnalogValueDirection(AnalogValueDirection aeDir){meAnalogValueDirection = aeDir;}
	AnalogValueDirection GetAnalogValueDirection() const {return meAnalogValueDirection;}
	
	virtual void SetSegmentInfo(int anGap, int anWidth);
	
	void SetBarInset(int anPixels){mnBarInset = anPixels;}
	int GetBarInset() const {return mnBarInset;}
	
	void SetHomeValue(float afValue){mfHomeValue = afValue;}
	
	void SetHomeColor(const Color &aColor){mHomeColor = aColor;}
	const Color &GetHomeColor() const {return mHomeColor;}
	
	/// @return the number of segment blocks drawn
	int GetDrawnSegmentCount() const;
	
	/// @return the total number of segment blocks drawn (both active and inactive)
	int GetTotalSegmentCount() const;
	
	virtual void ApplySettings(const KeyValues *apSettings) override;
	virtual void GetSettings(KeyValues *apSettings) const override;
	
	/// @return a string description of the panel fields for use in the UI
	virtual const char *GetDescription() const override;
public:
	// Util func for calculating a time remaining string
	static bool ConstructTimeRemainingString(OUT_Z_BYTECAP(anOutputSize) wchar_t *asOutput, int anOutputSize, float afStartTime, float afCurrentTime, float afCurrentAnalogValue, float afLastAnalogValueUpdateTime, bool abAddRemainingSuffix);
protected:
	/*virtual*/ void Paint() override;
	
	void PaintSegment(int &anPosX, int &anPosY, int anHeight, int anWidth, Color aColor, bool abHome);
	
	virtual void PaintBackground() override {} // Don't draw a background
	virtual void ApplySchemeSettings(IScheme *apScheme) override;
	
	/// Updates analogValue bar based on values
	MESSAGE_FUNC_PARAMS(OnDialogVariablesChanged, "DialogVariables", dialogVariables);
protected:
	AnalogValueDirection meAnalogValueDirection{AnalogValueDirection::East};
	
	float mfAnalogValue{0.0f};
private:
	Color mHomeColor{GetFgColor()};
	
	char *msDialogVar{nullptr};
	
	int mnSegmentCount{0};
	int mnSegmentGap{0};
	int mnSegmentWidth{0};
	
	int mnBarInset{0};
	
	float mfHomeValue{2.0f};
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