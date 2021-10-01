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
/// @brief Basic image control

#pragma once

#include <Color.h>

#include "vgui2/IImage.h"

namespace vgui2
{

class Panel;

class Image : public IImage
{
public:
	Image();
	virtual ~Image();
	
	/*virtual*/ bool Evict();
	
	/*virtual*/ void SetPos(int anX, int anY);
	/*virtual*/ void GetPos(int &anX, int &anY);
	
	/*virtual*/ void GetSize(int &anWidth, int &anHeight);
	/*virtual*/ void GetContextSize(int &anWidth, int &anHeight);
	
	/*virtual*/ void SetColor(Color aColor);
	/*virtual*/ void SetBgColor(Color aColor);
	/*virtual*/ Color GetColor() const;
	
	/*virtual*/ HTexture GetID() const;
	
	/*virtual*/ void SetFrame(int anFrame);
	
	/*virtual*/ int GetNumFrames() const;
	
	/*virtual*/ void SetRotation(int anRotation);
protected:
	virtual void Paint() = 0;
private:
	Color mColor{};
	
	int mvPos[2]{};
	int mvSize[2]{};
};

}; // namespace vgui2