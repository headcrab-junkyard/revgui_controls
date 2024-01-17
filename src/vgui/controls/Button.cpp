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

#include "Button.h"

using namespace vgui2;
//using namespace vgui3;

Button::Button()
{
	Init();
};

Button::Button()
{
	Init();
};

Button::~Button()
{
	if(mActionMessage)
		mActionMessage->deleteThis();
};

void Button::Init()
{
};

void Button::NavigateTo()
{
	BaseClass::NavigateTo();
	
	SetArmed(true);
	
	if(IsPC())
		RequestFocus(0);
};

void Button::NavigateFrom()
{
	BaseClass::NavigateFrom();
	
	SetArmed(false);
	
	OnKeyCodeReleased(KEY_XBUTTON_A);
};

void Button::Paint()
{
	if(!ShouldPaint())
		return;
	
	BaseClass::Paint();
	
	if(IsEnabled() && HasFocus() && IsDrawingFocusBox())
	{
		int nWidth, nHeight;
		GetSize(nWidth, nHeight);
		
		int x0 = 3, y0 = 3;
		int x1 = nWidth - 4, y1 = nHeight - 2;
		
		DrawFocusBorder(x0, y0, x1, y1);
	};
};

void Button::OnSetFocus()
{
	InvalidateLayout(false);
	BaseClass::OnSetFocus();
};

void Button::OnKillFocus()
{
	InvalidateLayout(false);
	BaseClass::OnKillFocus();
};

const char *Button::GetDescription()
{
	static char buf[1024]{};
	Q_snprintf(buf, sizeof(buf), "%s, string command, int default", BaseClass::GetDescription());
	return buf;
};

void Button::OnSetState(int anState)
{
	SetSelected(reinterpret_cast<bool>(anState));
	Repaint();
};

void Button::OnCursorEntered()
{
	if(IsEnabled() && !IsSelected())
		SetArmed(true);
};

void Button::OnCursorExited()
{
	if(!IsSelected() && !mvFlags.IsFlagSet(BUTTON_KEY_DOWN))
		SetArmed(false);
};

void Button::OnMousePressed(MouseCode aeCode)
{
	if(!IsEnabled())
		return;
	
	if(!IsMouseClickEnabled(aeCode))
		return;
	
	if(meActivationType == ACTIVATE_ONPRESSED)
	{
		if(IsKeyboardInputEnabled())
			RequestFocus();
		
		DoClick();
		return;
	};
	
	// Play activation sound
	if(msDepressedSoundName != UTL_INVAL_SYMBOL)
		GetSurface()->PlaySound(gButtonSoundNames.String(msDepressedSoundName));
	
	if(IsUseCaptureMouseEnabled() && meActivationType == ACTIVATE_ONPRESSEDANDRELEASED)
	{
		{
			if(IsKeyboardInputEnabled())
				RequestFocus();
			
			SetSelected(true);
			Repaint();
		};
		
		// Lock mouse input to going to this button
		GetInput()->SetMouseCapture(GetVPanel());
	};
};

void Button::OnMouseDoublePressed(MouseCode aeCode)
{
	OnMousePressed(aeCode);
};

void Button::OnMouseReleased(MouseCode aeCode)
{
	if(IsUseCaptureMouseEnabled())
		GetInput()->SetMouseCapture(nullptr);
};

void Button::OnKeyCodePressed(KeyCode aeCode)
{
	KeyCode aeLocalCode{GetBaseButtonCode(aeCode)};
	
	if(IsEnabled() && aeLocalCode == KEY_XBUTTON_A)
	{
		SetArmed(true);
		mvFlags.SetFlag(BUTTON_KEY_DOWN);
		
		if(meActivationType != ACTIVATE_ONRELEASED)
			DoClick();
	}
	else if(aeCode == KEY_SPACE || aeCode == KEY_ENTER)
	{
		SetArmed(true);
		mvFlags.SetFlag(BUTTON_KEY_DOWN);
		
		OnMousePressed(MOUSE_LEFT);
		
		// Undo the mouse capture since it's a fake mouse click
		if(IsUseCaptureMouseEnabled())
			GetInput()->SetMouseCapture(nullptr);
	}
	else
	{
		mvFlags.ClearFlag(BUTTON_KEY_DOWN);
		BaseClass::OnKeyCodePressed(aeCode);
	};
};

void Button::OnKeyCodeReleased(KeyCode aeCode)
{
	KeyCode eCode{GetBaseButtonCode(aeCode)}; // TODO
	
	if(mvFlags.IsFlagSet(BUTTON_KEY_DOWN) && (aeCode == KEY_XBUTTON_A || aeCode == KEY_XBUTTON_START))
	{
		SetArmed(true);
		
		if(meActivationType != ACTIVATE_ONPRESSED)
			DoClick();
	}
	else if(mvFlags.IsFlagSet(BUTTON_KEY_DOWN) && (aeCode == KEY_SPACE || aeCode == KEY_ENTER))
	{
		SetArmed(true);
		OnMouseReleased(MOUSE_LEFT);
	}
	else
		BaseClass::OnKeyCodeReleased(aeCode);
	
	mvFlags.ClearFlag(BUTTON_KEY_DOWN);
	
	if(!(aeCode == KEY_XSTICK1_UP || aeCode == KEY_XSTICK1_DOWN
	  || aeCode == KEY_XSTICK1_LEFT || aeCode == KEY_XSTICK1_RIGHT
	  || aeCode == KEY_XSTICK2_UP || aeCode == KEY_XSTICK2_DOWN
	  || aeCode == KEY_XSTICK2_LEFT || aeCode == KEY_XSTICK2_RIGHT
	  || aeCode == KEY_XBUTTON_UP || aeCode == KEY_XBUTTON_DOWN
	  || aeCode == KEY_XBUTTON_LEFT || aeCode == KEY_XBUTTON_RIGHT
	  || aeCode == KEY_UP || aeCode == KEY_DOWN
	  || aeCode == KEY_LEFT || aeCode == KEY_RIGHT))
		SetArmed(false);
};

void Button::DrawFocusBorder(int anPosX0, int anPosY0, int anPosX1, int anPosY1)
{
	GetSurface()->DrawSetColor();
	
	DrawDashedLine(anPosX0, anPosY0, anPosX1, anPosY1 + 1, 1, 1);
	DrawDashedLine(anPosX0, anPosY0, anPosX1 + 1, anPosY1, 1, 1);
	DrawDashedLine(anPosX0, anPosY0 - 1, anPosX1, anPosY1, 1, 1);
	DrawDashedLine(anPosX0 - 1, anPosY0, anPosX1, anPosY1, 1, 1);
};

void Button::SizeToContents()
{
	int nWidth, nHeight;
	GetContentSize(nWidth, nHeight);
	SetSize(nWidth + Label::Content, nHeight + Label::Content);
};