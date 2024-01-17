/*
 * This file is part of revgui_controls
 * Copyright (C) 2019-2022 BlackPhrase
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

#include <vector>

#include <vgui2/IClientPanel.h>
#include <vgui2/IScheme.h>
#include <vgui2/MouseCode.h>

#include <Color.h>

//class CUtlVector;

template<typename T>
using CUtlVector = std::vector<T>; // TODO: temp

namespace vgui2
{

class BaseTooltip;

/*
	Panel(Panel *apParent, const char *asName, IScheme::Handle anScheme);
	
	virtual void SetParent(Panel *apParent);
	virtual Panel *GetParent() const;
	
	Panel *FindChildByName(const char *asName, bool abRecurseDown = false);
	
	// Scheme access
	virtual void SetScheme(IScheme::Handle anScheme);
	virtual IScheme::Handle GetScheme() const;
	
	// Input messages
	virtual void OnCursorEntered();
	virtual void OnCursorExited();
*/

class Panel : public IClientPanel
{
public:
	Panel();
	Panel(Panel *apParent);
	Panel(Panel *apParent, const char *asName);
	Panel(Panel *apParent, const char *asName, HScheme ahScheme);
	
	virtual ~Panel();
public: // IClientPanel interface implementation

	/// @return pointer to Panel's vgui VPanel interface handle
	VPANEL GetVPanel() override {return mnPanel;}
	
	void PaintTraverse(bool abForceRepaint, bool abAllowForce) override;
	
	void Repaint() override;
	
	void SetBuildModeEditable(bool abEditable);
	bool IsEditModeEditable() const;
	
	virtual VPANEL IsWithinTraverse(int x, int y, bool abTraversePopups) override;
	
	virtual void GetInset(int &top, int &left, int &right, int &bottom) override;
	virtual void GetClipRect(int &x0, int &y0, int &x1, int &y1) override;
	
	/// Called when a child has been added to this panel
	virtual void OnChildAdded(VPANEL anChild) override;
	
	/// Called after the size of a panel has been changed
	virtual void OnSizeChanged(int anNewWidth, int anNewHeight) override;
	
	void InternalFocusChanged(bool abLost) override;
	
	bool RequestInfo(KeyValues *apOutputData) override;
	
	virtual void RequestFocus(int anDirection = 0) override;
	virtual bool RequestFocusPrev(VPANEL anExistingPanel = 0) override;
	virtual bool RequestFocusNext(VPANEL anExistingPanel = 0) override;
	
	/// Called when panel receives message, must chain back
	virtual void OnMessage(const KeyValues *apParams, VPANEL anFromPanel) override;
	
	virtual VPANEL GetCurrentKeyFocus() override;
	
	virtual int GetTabPosition() override;
	
	/// @return the name of this panel (never returns a nullptr)
	const char *GetName() override;
	
	/// @return the class name of the panel (example: Panel, Label, Button, etc)
	const char *GetClassName() override;
	
	virtual HScheme GetScheme() override;
	
	virtual bool IsProportional() override; // TODO {return mFlags.IsFlagSet(IS_PROPORTIONAL);}
	virtual bool IsAutoDeleteSet() override;
	
	/// Deletes itself
	virtual void DeletePanel() override {delete this;}
	
	void *QueryInterface(EInterfaceID nId) override;
	
	/// @return the name of the module that this instance of panel was compiled into
	virtual const char *GetModuleName() override;
public: // Rest of the methods
	virtual void Init(int anPosX, int anPosY, int anWidth, int anHeight);
	
	/// Sets the name of the panel - used as an identifier
	void SetName(const char *asName){msName = asName;}
	
	// Drawing state
	virtual void SetEnabled(bool abState);
	virtual bool IsEnabled() const;
	
	/// Has a parent, but is in it's own space
	virtual bool IsPopup() const;
	
	virtual void MoveToFront();
	
	// Panel visibility
	// Invisible panels and their children won't be drawn, updated or receive input msgs
	virtual void SetVisible(bool abState);
	virtual bool IsVisible() const;
	
	virtual void SetProportional(bool abState);
	
	/// Object will free its memory next tick
	virtual void MarkForDeletion();
	
	/// If set to true, panel automatically frees itself when parent is deleted
	virtual void SetAutoDelete(bool abState);
	
	virtual void SetTabPosition(int anPos);
	
	/// Sets alpha modifier for panel and all child panels [0...255]
	void SetAlpha(int anAlpha);
	
	/// @return the current alpha
	int GetAlpha() const;
	
	// Scheme access methods
	virtual void SetScheme(const char *asTag);
	virtual void SetScheme(HScheme ahScheme){mhScheme = ahScheme;}
	
	virtual void SetCursor(HCursor ahCursor){mhCursor = ahCursor;} // TODO: HCursor -> CursorHandle_t?
	virtual HCursor GetCursor() const {return mhCursor;} // TODO: HCursor -> CursorHandle_t?
	
	/// Combination of SetPos/SetSize
	void SetBounds(int anPosX, int anPosY, int anWidth, int anHeight);
	
	/// Combination of GetPos/GetSize
	void GetBounds(int &anPosX, int &anPosY, int &anWidth, int &anHeight) const;
	
	virtual void SetBorder(IBorder *apBorder);
	virtual IBorder *GetBorder() const;
	
	virtual void SetPaintBorderEnabled(bool abState);
	virtual void SetPaintBackgroundEnabled(bool abState);
	virtual void SetPaintEnabled(bool abState);
	virtual void SetPostChildPaintEnabled(bool abState);
	
	/// 0 for normal (opaque), 1 for single texture from Texture1, and 2 for rounded box w/ four corner textures
	// TODO
	virtual void SetPaintBackgroundType(int anType);
	
	// Panel position & size
	// NOTE: all units are in pixels
	
	/// Sets position of the panel in local space (relative to parent's pos)
	void SetPos(int anPosX, int anPosY);
	
	/// Gets local position of the panel
	void GetPos(int &anPosX, int &anPosY) const;
	
	int GetXPos() const;
	int GetYPos() const;
	
	/// Sets Z-ordering - lower numbers are always behind higher Z's
	void SetZPos(int anPosZ);
	int GetZPos() const;
	
	void SetSize(int anWidth, int anHeight);
	void GetSize(int &anWidth, int &anHeight) const;
	
	void SetMinimumSize(int anWidth, int anHeight);
	void GetMinimumSize(int &anWidth, int &anHeight) const;
	
	void SetWidth(int anWidth);
	int GetWidth() const;
	
	void SetHeight(int anHeight);
	int GetHeight() const;
	
	//
	
	// Panel hierarchy
	virtual void SetParent(Panel *apParent);
	virtual void SetParent(VPANEL anParent);
	virtual Panel *GetParent() const {return mpParent;}
	virtual VPANEL GetVParent() const;
	virtual bool HasParent(VPANEL anPotentialParent) const;
	
	int GetChildCount() const;
	virtual CUtlVector<VPANEL> &GetChildren() const;
	Panel *GetChild(int anIndex) const;
	
	//
	
	virtual bool HasFocus() const;
	
	// Interface to build settings
	// Takes a group of settings and applies them to the control
	virtual void ApplySettings(const KeyValues *apSettings);
	
	// Records the settings into the resource data
	virtual void GetSettings(KeyValues *apSettings) const;
	
	void SetTooltip(BaseTooltip *apTooltip, const char *asText);
	
	/// @return a pointer to the tooltip object associated with the panel
	/// Creates a new one if none exists yet
	BaseTooltip *GetTooltip() const;
	
	// Message handlers
	
	/// Called every frame before painting, but only if panel is visible
	virtual void OnThink();
	
	// Message handlers that don't go through the msg pump
	virtual void PaintBackground();
	virtual void Paint();
	virtual void PaintBorder();
	virtual void PaintBuildOverlay();
	
	virtual void PostChildPaint();
	virtual void PerformLayout();
public: // Navigation public interface
	enum class NavDirection : int
	{
		Up,
		Down,
		Left,
		Right,
		Back,
		None
	};
public: // Drag & drop public interface
	virtual void SetDragEnabled(bool abEnabled);
	virtual bool IsDragEnabled() const;
	
	virtual void SetShowDragHelper(bool abEnabled);
	
	virtual void SetDropEnabled(bool abEnabled, float afHoverContextTime = 0.0f);
	virtual bool IsDropEnabled() const;
protected: // Drag & drop internal interface
	virtual void OnStartDragging();
	virtual void OnContinueDragging();
	virtual void OnFinishDragging(bool abMouseReleased, MouseCode aeCode, bool abAborted = false);
	
	virtual void DragDropStartDragging();
	
	virtual void CreateDragData();
	virtual void GetDragData(CUtlVector<KeyValues*> &avList) const;
protected:
	Panel *GetNavUpPanel() const;
	Panel *GetNavDownPanel() const;
	Panel *GetNavLeftPanel() const;
	Panel *GetNavRightPanel() const;
	Panel *GetNavToRelayPanel() const;
	Panel *GetNavActivatePanel() const;
	Panel *GetNavBackPanel() const;
protected:
	NavDirection meLastNavDir{};
	
	bool mbPassUnhandledInput{false};
private: // Private IClientPanel overrides
	/*virtual*/ Panel *GetPanel() override {return this;}
	
	void Think() override;
	
	void PerformApplySchemeSettings() override;
private: // Other private methods
	//void Init(int anX, int anY, int anWidth, int anHeight); // TODO: public?
	
	void InternalPerformLayout();
	void InternalSetCursor();
private:
	VPANEL mnPanel{};
	
	Panel *mpParent{nullptr};
	
	const char *msName{""};
	
	HScheme mhScheme{};
	HCursor mhCursor{};
	
	bool mbAutoDelete{false};
private:
	//IVGui *mpVGUI{nullptr};
	//IPanel *mpPanelManager{nullptr};
};

}; // namespace vgui2