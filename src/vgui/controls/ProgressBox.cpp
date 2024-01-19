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

#include "ProgressBox.h"

namespace vgui2
{

ProgressBox::~ProgressBox(const char *asTitle, const char *asText, const char *asUnknownTimeString, Panel *apParent)
{
};

ProgressBox::~ProgressBox(const wchar_t *asTitle, const wchar_t *asText, const wchar_t *asUnknownTimeString, Panel *apParent)
{
};

ProgressBox::~ProgressBox()
{
};

void ProgressBox::DoModal(Frame *apFrameOver)
{
};

void ProgressBox::ShowWindow(Frame *apFrameOver)
{
};

void ProgressBox::SetProgress(float afProgress)
{
};

void ProgressBox::SetText(const char *asText)
{
};

void ProgressBox::SetCancelButtonVisible(bool abState)
{
};

void ProgressBox::SetCancelButtonEnabled(bool abState)
{
};

void ProgressBox::PerformLayout()
{
};

void ProgressBox::OnClose()
{
};

void ProgressBox::OnCloseFrameButtonPressed()
{
};

void ProgressBox::OnThink()
{
};

void ProgressBox::OnCommand(const char *asCmd)
{
};

void ProgressBox::OnTick()
{
};

void ProgressBox::OnCancel()
{
};

void ProgressBox::ApplySchemeSettings(IScheme *apScheme)
{
};

void ProgressBox::Init()
{
};

void ProgressBox::UpdateTitle()
{
};

}; // namespace vgui2