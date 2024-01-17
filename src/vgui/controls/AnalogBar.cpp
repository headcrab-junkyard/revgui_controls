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

#include "AnalogBar.h"

namespace vgui2
{

constexpr auto ANALOG_BAR_HOME_SIZE{4};
constexpr auto ANALOG_BAR_HOME_GAP{2};
constexpr auto ANALOG_BAR_LESS_TALL{ANALOG_BAR_HOME_SIZE + ANALOG_BAR_HOME_GAP};

DECLARE_BUILD_FACTORY(AnalogBar);

AnalogBar::AnalogBar(Panel *apParent, const char *asName) : Panel(apParent, asName)
{
	SetSegmentInfo(2, 6);
	SetBarInset(0);
	
	mHomeColor = GetFgColor();
};

AnalogBar::~AnalogBar()
{
	delete [] msDialogVar;
};

void AnalogBar::SetAnalogValue(float afValue)
{
	if(mfAnalogValue != afValue)
	{
		// Clamp the value within the range
		if(afValue < 0.0f)
			afValue = 0.0f;
		else if(afValue > 1.0f)
			afValue = 1.0f;
		
		mfAnalogValue = afValue;
		
		Repaint();
	};
};

void AnalogBar::SetSegmentInfo(int anGap, int anWidth)
{
	mnSegmentGap = anGap;
	mnSegmentWidth = anWidth;
};

int AnalogBar::GetDrawnSegmentCount() const
{
	int nWidth, nHeight;
	GetSize(nWidth, nHeight);
	int nSegmentTotal{nWidth / (mnSegmentGap + mnSegmentWidth)};
	return (int)(mnSegmentCount * mfAnalogValue);
};

int AnalogBar::GetTotalSegmentCount() const
{
	int nWidth, nHeight;
	GetSize(nWidth, nHeight);
	int nSegmentTotal{nWidth / (mnSegmentGap + mnSegmentWidth)};
	return nSegmentTotal;
};

void AnalogBar::ApplySettings(const KeyValues *apSettings)
{
	mfAnalogValue = apSettings->GetFloat("analogValue", 0.0f);
	
	auto sDialogVar{apSettings->GetString("variable", "")};
	
	if(sDialogVar && *sDialogVar)
	{
		msDialogVar = new char[strlen(sDialogVar) + 1];
		strcpy(msDialogVar, sDialogVar);
	};
	
	BaseClass::ApplySettings(apSettings);
};

void AnalogBar::GetSettings(KeyValues *apSettings) const
{
	BaseClass::GetSettings(apSettings);
	
	apSettings->SetFloat("analogValue", mfAnalogValue);
	
	if(msDialogVar)
		apSettings->SetString("variable", msDialogVar);
};

const char *AnalogBar::GetDescription() const
{
	static char sBuf[1024]{};
	_snprintf(sBuf, sizeof(sBuf), "%s, string analogValue, string variable", BaseClass::GetDescription());
	return sBuf;
};

void AnalogBar::Paint()
{
	int nWidth, nHeight;
	GetSize(nWidth, nHeight);
	
	// Gaps
	int nSegmentTotal = 0, nSegmentsDrawn = 0;
	int nPosX = 0, nPosY = 0;
	
	switch(meAnalogValueDirection)
	{
	case AnalogValueDirection::East:
		nPosY = mnBarInset;
		break;
	case AnalogValueDirection::West:
		nPosX = nWidth;
		nPosY = mnBarInset;
		break;
	case AnalogValueDirection::North:
		nPosX = mnBarInset;
		nPosY = nHeight;
		break;
	case AnalogValueDirection::South:
		nPosX = mnBarInset;
		break;
	};
	
	auto nHomeIndex{(int)};
	
	if(nHomeIndex < 0)
		nHomeIndex = 0;
	
	for(int i = 0; i < nSegmentsDrawn; ++i)
		PaintSegment(nPosX, nPosY, nHeight, nWidth, GetFgColor(), i == nHomeIndex);
	
	for(int i = nSegmentsDrawn; i < nSegmentTotal; ++i)
		PaintSegment(nPosX, nPosY, nHeight, nWidth, GetBgColor(), i == nHomeIndex);
};

void AnalogBar::PaintSegment(int &anPosX, int &anPosY, int anHeight, int anWidth, Color aColor, bool abHome)
{
	switch(meAnalogValueDirection)
	{
	case AnalogValueDirection::East:
		anPosX += mnSegmentGap;
		
		if(abHome)
		{
			GetSurface()->DrawSetColor(GetHomeColor());
			GetSurface()->DrawFilledRect(anPosX, anPosY, anPosX + mnSegmentWidth, anPosY + ANALOG_BAR_HOME_SIZE);
			GetSurface()->DrawFilledRect(anPosX, anPosY + anHeight - (anPosY * 2) - ANALOG_BAR_HOME_SIZE, anPosX + mnSegmentWidth, anPosY + anHeight - (anPosY * 2));
		};
		
		GetSurface()->DrawSetColor(aColor);
		GetSurface()->DrawFilledRect(anPosX, anPosY + ANALOG_BAR_LESS_TALL, anPosX + mnSegmentWidth, anPosY + anHeight - (anPosY * 2) - ANALOG_BAR_LESS_TALL);
		
		anPosX += mnSegmentWidth;
		break;
	case AnalogValueDirection::West:
		anPosX -= mnSegmentGap + mnSegmentWidth;
		
		if(abHome)
		{
			GetSurface()->DrawSetColor(GetHomeColor());
			GetSurface()->DrawFilledRect(anPosX, anPosY, anPosX + mnSegmentWidth, anPosY + ANALOG_BAR_HOME_SIZE);
			GetSurface()->DrawFilledRect(anPosX, anPosY + anHeight - (anPosY * 2) - ANALOG_BAR_HOME_SIZE, anPosX + mnSegmentWidth, anPosY + anHeight - (anPosY * 2));
		};
		
		GetSurface()->DrawSetColor(aColor);
		GetSurface()->DrawFilledRect(anPosX, anPosY + ANALOG_BAR_LESS_TALL, anPosX + mnSegmentWidth, anPosY + anHeight - (anPosY * 2) - ANALOG_BAR_LESS_TALL);
		break;
	case AnalogValueDirection::North:
		anPosY -= mnSegmentGap + mnSegmentWidth;
		
		if(abHome)
		{
			GetSurface()->DrawSetColor(GetHomeColor());
			GetSurface()->DrawFilledRect(anPosX, anPosY, anPosX + ANALOG_BAR_HOME_SIZE, anPosY + mnSegmentWidth);
			GetSurface()->DrawFilledRect(anPosX + anWidth - (anPosX * 2) - ANALOG_BAR_HOME_SIZE, anPosY, anPosX + anWidth - (anPosX * 2), anPosY + mnSegmentWidth);
		};
		
		GetSurface()->DrawSetColor(aColor);
		GetSurface()->DrawFilledRect(anPosX + ANALOG_BAR_LESS_TALL, anPosY, anPosX + anWidth - (anPosX * 2) - ANALOG_BAR_LESS_TALL, anPosY + mnSegmentWidth);
		break;
	case AnalogValueDirection::South:
		anPosY += mnSegmentGap;
		
		if(abHome)
		{
			GetSurface()->DrawSetColor(GetHomeColor());
			GetSurface()->DrawFilledRect(anPosX, anPosY, anPosX + ANALOG_BAR_HOME_SIZE, anPosY + mnSegmentWidth);
			GetSurface()->DrawFilledRect(anPosX + anWidth - (anPosX * 2) - ANALOG_BAR_HOME_SIZE, anPosY, anPosX + anWidth - (anPosX * 2), anPosY + mnSegmentWidth);
		};
		
		GetSurface()->DrawSetColor(aColor);
		GetSurface()->DrawFilledRect(anPosX + ANALOG_BAR_LESS_TALL, anPosY, anPosX + anWidth - (anPosX * 2) - ANALOG_BAR_LESS_TALL, anPosY + mnSegmentWidth);
		
		anPosY += mnSegmentWidth;
		break;
	};
};

void AnalogBar::ApplySchemeSettings(IScheme *apScheme)
{
	Panel::ApplySchemeSettings(apScheme);
	
	SetBgColor(Color(255 - GetFgColor().r(), 255 - GetFgColor().g(), 255 - GetFgColor().b(), GetFgColor().a()));
};

void AnalogBar::OnDialogVariablesChanged(const KeyValues *apVariables)
{
	if(msDialogVar)
	{
		auto nValue{apVariables->GetInt(msDialogVar, -1)};
		if(nValue >= 0.0f)
			SetAnalogValue(nValue / 100.0f);
	};
};

DECLARE_BUILD_FACTORY(ContinuousAnalogBar);

ContinuousAnalogBar::ContinuousAnalogBar(Panel *apParent, const char *asName) : AnalogBar(apParent, asName){}

void ContinuousAnalogBar::Paint()
{
	int nWidth, nHeight;
	GetSize(nWidth, nHeight);
	
	GetSurface()->DrawSetColor(GetFgColor());
	
	int nPosX = 0, nPosY = 0;
	
	switch(meAnalogValueDirection)
	{
	case AnalogValueDirection::East:
		GetSurface()->DrawFilledRect(nPosX, nPosY, nPosX + (int)(nWidth * mfAnalogValue), nPosY + nHeight);
		break;
	case AnalogValueDirection::West:
		GetSurface()->DrawFilledRect(nPosX + (int)(nWidth * (1.0f - mfAnalogValue)), nPosY, nPosX + nWidth, nPosY + nHeight);
		break;
	case AnalogValueDirection::North:
		GetSurface()->DrawFilledRect(nPosX, nPosY + (int)(nHeight * (1.0f - mfAnalogValue)), nPosX + nWidth, nPosY + nHeight);
		break;
	case AnalogValueDirection::South:
		GetSurface()->DrawFilledRect(nPosX, nPosY, nPosX + nWidth, nPosY + (int)(nHeight * mfAnalogValue));
		break;
	};
};

}; // namespace vgui2