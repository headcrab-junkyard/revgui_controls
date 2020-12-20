/// @file

#pragma once

#include "Panel.h"
#include "FocusNavGroup.h"

namespace vgui2
{

class EditablePanel : public Panel
{
	DECLARE_CLASS_SIMPLE(EditablePanel, Panel);
public:
	EditablePanel(Panel *apParent, const char *asName);
	EditablePanel(Panel *apParent, const char *asName, HScheme ahScheme);
	virtual ~EditablePanel();
	
	KeyValues *GetDialogVariables() const;
protected:
	/*virtual*/ void PaintBackground();
	
	/*virtual*/ FocusNavGroup &GetFocusNavGroup() const;
	
	// Overrides
	/*virtual*/ OnChildAdded(VPANEL anChild) override;
	/*virtual*/ OnSizeChanged(int anNewWidth, int anNewHeight) override;
	/*virtual*/ OnClose() override;
	
	/*virtual*/ void ApplyUserConfigSettings(KeyValues *apSettings);
	/*virtual*/ void GetUserConfigSettings(KeyValues *apSettings);
private:
	void ForceSubPanelsToUpdateWithNewDialogVariables(); // TODO: WeNeedEvenLongerMethodNameThanThisOnePlzFixValve
private:
	FocusNavGroup mNavGroup{};
	
	BuildGroup *mpBuildGroup{nullptr};
	KeyValues *mpDialogVariables{nullptr};
	
	char *msConfigName{nullptr};
	
	int mnConfigID{0};
	
	bool mbShouldSkipAutoResize{bool};
};

}; // namespace vgui2