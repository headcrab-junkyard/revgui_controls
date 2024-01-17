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
/// @brief Thin line used to divide sections, can be moved dragged!

#pragma once

#include "EditablePanel.h"

namespace vgui2
{

class SplitterHandle;
class SplitterChildPanel;

class Splitter : public EditablePanel
{
	DECLARE_CLASS_SIMPLE(Splitter, EditablePanel);
public:
	enum class Mode : int
	{
		Horizontal = 0,
		Vertical
	};
	
	/// anCount is the number of splitters to create
	/// NOTE: The constructor here will create (anCount + 1) EditablePanel chilren
	/// and name them child0...childN for .res file purposes
	Splitter(Panel *apParent, const char *asName, Mode aeMode, int anCount);
	
	~Splitter();
	
	/// Evenly respace all splitters
	void EvenlyRespaceSplitters();
	
	/// Respace splitters using given fractions (must sum to 1)
	void RespaceSplitters(float *afFractions);
public: // Inherited from Panel
	/*virtual*/ void ApplySettings(KeyValues *apSettings);
	/*virtual*/ void GetSettings(KeyValues *apSettings);
	
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void OnSizeChanged(int anNewWidth, int anNewHeight);
	
	/*virtual*/ void ApplyUserConfigSettings(KeyValues *apUserConfig);
	/*virtual*/ void GetUserConfigSettings(KeyValues *apUserConfig);
	/*virtual*/ bool HasUserConfigSettings() const {return true;}
public:
	// Sets the splitter color
	void SetSplitterColor(Color aColor);
	
	/// Enables borders on the splitters
	void EnableBorders(bool abEnable);
	
	/// Locks the size of a particular child in pixels
	void LockChildSize(int anChildIndex, int anSize);
	void UnlockChildSize(int anChildIndex);
private:
	void RecreateSplitters(int anCount);
	
	int GetPosRange() const;
	
	int GetSplitterCount() const;
	
	void SetSplitterPosition(int anIndex, int anPos);
	int GetSplitterPosition(int anIndex) const;
	
	int GetSubPanelCount() const;
	
	int ComputeLockedSize(int anStartingIndex);
private:
	struct SplitterInfo
	{
		SplitterChildPanel *mpPanel{nullptr}; ///< This panel is to the left or above the handle
		SplitterHandle *mpHandle{nullptr};
		
		float mfPos{0.0f};
		
		int mnLockedSize{0};
		
		bool mbLocked{false};
	};
	
	CUtlVector<SplitterInfo> mvSplitters;
	
	Mode meMode{};
	
	friend class SplitterHandle;
};

}; // namespace vgui2