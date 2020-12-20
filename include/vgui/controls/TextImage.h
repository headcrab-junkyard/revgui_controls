/// @file

#pragma once

#include "Image.h"

class KeyValues;

namespace vgui2
{

class TextImage : public Image
{
public:
	TextImage(const char *asText);
	TextImage(const wchar_t *asText);
	~TextImage();
	
	/*virtual*/ void SetText(const char *asText);
	/*virtual*/ void GetText(char *apBuffer, int anLength);
	
	/*virtual*/ void SetText(const wchar_t *asText, bool abClearUnlocalizedSymbol = false);
	/*virtual*/ void GetText(wchar_t *apBuffer, int anLength);
protected:
private:
	void RecalculateEllipsesPosition();
private:
	wchar_t *mpEllipsesPosition{nullptr};
	
	StringIndex_t mUnlocalizedTextSymbol{};
};

}; // namespace vgui2