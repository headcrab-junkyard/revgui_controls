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

#include "EditablePanel.h"

namespace vgui2
{

class SplitterHandle;
class SplitterChildPanel;

class Splitter : public EditablePanel
{
	DECLARE_CLASS_SIMPLE(Splitter, EditablePanel);
public:
	Splitter(Panel *apParent, const char *asName, SplitterMode_t aeMode, int anCount);
	~Splitter();
	
	void EvenlyRespaceSplitters();
	
	void RespaceSplitters(float *afFractions);
private:
	void RecreateSplitter(int anCount);
	
	int GetPosRange() const;
	
	int GetSplitterCount() const;
	
	void SetSplitterPosition(int anIndex, int anPos);
	int GetSplitterPosition(int anIndex) const;
	
	int GetSubPanelCount() const;
	
	int ComputeLockedSize(int anStartingIndex);
private:
	CUtlVector<SplitterInfo_t> mvSplitters;
	
	SplitterMode_t meMode{};
};

}; // namespace vgui2