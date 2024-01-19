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

#include <vgui2/VGUI.h>

#include "Panel.h"

namespace vgui2
{

/// Status bar that visually displays discrete progress in the form of a segmented strip
class ProgressBar : public Panel
{
	DECLARE_CLASS_SIMPLE(ProgressBar, Panel);
public:
	ProgressBar(Panel *apParent, const char *asPanelName);
	~ProgressBar();
	
	/// 'fProgress' is in the range [0.0f, 1.0f]
	MESSAGE_FUNC_FLOAT(SetProgress, "SetProgress", fProgress);
	
	float GetProgress() const;
	
	/*virtual*/ void SetSegmentInfo(int anGap, int anWidth);
	
	/// Utility function for calculating a time remaining string
	static bool ConstructTimeRemainingString(wchar_t *asOutBuf, int anOutBufSizeBytes, float afStartTime, float afCurrentTime, float afCurrentProgress, float afLastProgressUpdateTime, bool abAddRemainingSuffix);
	
	void SetBarInset(int anPixels);
	int GetBarInset() const;
	
	/*virtual*/ void ApplySettings(KeyValues *apSettings);
	/*virtual*/ void GetSettings(KeyValues *apSettings);
	
	/*virtual*/ const char *GetDescription() const;
	
	/// Returns the number of segment blocks drawn
	int GetDrawnSegmentCount() const;
	
	enum class ProgressDir : int
	{
		East,
		West,
		North,
		South
	};
	
	void SetProgressDirection(ProgressBar aeValue){meProgressDirection = aeValue;}
	ProgressBar GetProgressDirection() const {return meProgressDirection;}
protected:
	/*virtual*/ void Paint();
	
	void PaintSegment(int &anX, int &anY, int anHeight, int anWidth);
	
	/*virtual*/ void PaintBackground();
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	MESSAGE_FUNC_PARAMS(OnDialogVariablesChanged, "DialogVariables", dialogVariables);
	
	/* CUSTOM MESSAGE HANDLING
		"SetProgress"
			input: "progress" - float value of the progress to set
	*/
protected:
	int mnProgressDirection{0};
	
	float mfProgress{0.0f};
private:
	char *msDialogVar{nullptr};
	
	int mnSegmentCount{0};
	int mnSegmentGap{0};
	int mnSegmentWidth{0};
	
	int mnBarInset{0};
	//int mnBarMargin{0}; // TODO: where from?
};

//constexpr auto NUM_CONTINUOUS_PROGRESS_BAR_TEXTURES{2};

/// Non-segmented progress bar
class ContinuousProgressBar : public ProgressBar
{
	DECLARE_CLASS_SIMPLE(ContinuousProgressBar, ProgressBar);
public:
	ContinuousProgressBar(Panel *apParent, const char *asPanelName);
	
	/*virtual*/ void Paint();
	/*virtual*/ void PaintBackground();
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	
	enum class ProgressTextures : int
	{
		TextureFG,
		TextureBG,
		
		NUM_PROGRESS_TEXTURES
	};
	
	void SetImage(const char *asImageName, ProgressTextures aePos);
private:
	char *mvImageName[NUM_PROGRESS_TEXTURES]{nullptr};
	int mvImageNameLen[NUM_PROGRESS_TEXTURES]{0};
	
	int mvTextureID[NUM_PROGRESS_TEXTURES]{0};
};

}; // namespace vgui2