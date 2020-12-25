/// @file

#pragma once

#include <vgui2/VGUI.h>

#include "Panel.h"

namespace vgui2
{

class Label : public Panel
{
	DECLARE_CLASS_SIMPLE(Label, Panel);
public:
	Label(Panel *apParent, const char *asName, const char *asText);
	Label(Panel *apParent, const char *asName, const wchar_t *asText);
	~Label();
protected:
private:
	void Init();
private:
	struct TImageInfo
	{
	};
	
	CUtlVector<TImageInfo> mvImageDar;
	
	TextImage *mpTextImage{nullptr};
	
	Alignment meContentAlignment{};
};

}; // namespace vgui2