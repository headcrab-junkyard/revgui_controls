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