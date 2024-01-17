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

#include "Image.h"

Image::Image()
{
};

Image::~Image()
{
};

bool Image::Evict()
{
	return true;
};

void Image::SetPos(int anX, int anY)
{
	mvPos[0] = anX;
	mvPos[1] = anY;
};

void Image::GetPos(int &anX, int &anY)
{
	anX = mvPos[0];
	anY = mvPos[1];
};

void Image::GetSize(int &anWidth, int &anHeight)
{
	anWidth = mvSize[0];
	anHeight = mvSize[1];
};

void Image::GetContextSize(int &anWidth, int &anHeight)
{
};

void Image::SetColor(Color aColor)
{
	mColor = aColor;
};

void Image::SetBgColor(Color aColor)
{
	mBgColor = aColor;
};

Color Image::GetColor() const
{
	return mColor;
};

HTexture Image::GetID() const
{
	return mhTextureID;
};

void Image::SetFrame(int anFrame)
{
};

int Image::GetNumFrames() const
{
};

void Image::SetRotation(int anRotation)
{
	mnRotation = anRotation;
};