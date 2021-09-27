#pragma once

namespace vgui2
{
struct ISystem;
struct IVGui;
struct IPanel;
};

#include <vgui2/ISystem.h>
#include <vgui2/IVGUI.h>
#include <vgui2/IPanel.h>

class CVGUIProvider
{
public:
	//CVGUIProvider(vgui2::ISystem *apSystem, vgui2::IVGui *apVGUI, vgui2::IPanel *apPanelWrapper);
	
	static vgui2::ISystem *GetSystem() /*const*/ {return mpSystem;}
	
	static vgui2::IVGui *GetVGUI() /*const*/ {return mpVGUI;}
	
	static vgui2::IPanel *GetPanelWrapper() /*const*/ {return mpPanelWrapper;}
private:
	static constexpr vgui2::ISystem *mpSystem{nullptr};
	static constexpr vgui2::IVGui *mpVGUI{nullptr};
	static constexpr vgui2::IPanel *mpPanelWrapper{nullptr};
};