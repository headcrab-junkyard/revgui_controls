/// @file
/// @brief Basic image control

#pragma once

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