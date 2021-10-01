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

#pragma once

#include <tier1/utlvector.h>

namespace vgui2
{

/// Tooltip for a panel - shows text when cursor hovers over a panel
class BaseTooltip
{
public:
	BaseTooltip(Panel *apParent, const char *asText = nullptr);
	
	/*virtual*/ void SetText(const char *asText);
	/*virtual*/ const char *GetText() const;
	
	/*virtual*/ void ShowTooltip(Panel *apCurrentPanel);
	/*virtual*/ void HideTooltip();
	
	bool ShouldLayout() const;
	virtual void PerformLayout(){}
	/*virtual*/ void PositionWindow(Panel *apTipPanel);
	
	void ResetDelay();
	
	void SetTooltipFormatToSingleLine();
	void SetTooltipFormatToMultiLine();
	
	void SetTooltipDelay(int anMillisecs);
	int GetTooltipDelay() const;
	
	void SetEnabled(bool abState);
protected:
	CUtlVector<char> msText;
	
	int mnDelay{0}; ///< Delay that counts down
	int mnTooltipDelay{0}; ///< Delay before tooltip comes up
	
	bool mbMakeVisible{false} : 1;
	bool mbDisplayOnOneLine{false} : 1;
	bool mbIsDirty{false} : 1;
	bool mbEnabled{false} : 1;
private:
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme){}
private:
	Panel *mpParent{nullptr};
};

class TextTooltip : public BaseTooltip
{
public:
	TextTooltip(Panel *apParent, const char *asText = nullptr);
	~TextTooltip();
	
	/*virtual*/ void SetText(const char *asText) override;
	
	/*virtual*/ void ShowTooltip(Panel *apCurrentPanel) override;
	/*virtual*/ void HideTooltip() override;
	
	/*virtual*/ void SizeTextWindow();
	
	/*virtual*/ void PerformLayout() override;
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme) override;
};

}; // namespace vgui2