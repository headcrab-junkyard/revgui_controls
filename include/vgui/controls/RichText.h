/*
 * This file is part of revgui_controls
 * Copyright (C) 2020-2021, 2024 BlackPhrase
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
/// @brief Non-editable display of a rich text control

#pragma once

#include "Panel.h"

//#include <tier1/utlvector.h>

namespace vgui2
{

class ClickPanel;

class RichText : public Panel
{
	DECLARE_CLASS_SIMPLE(RichText, Panel);
public:
	RichText(Panel *apParent, const char *asPanelName);
	~RichText();
	
	// Text manipulation
	
	void SetText(const char *asText);
	void SetText(const wchar_t *asText);
	
	void GetText(int anOffset, char *asOutBuf, int anBufLenBytes);
	void GetText(int anOffset, wchar_t *asOutBuf, int anBufLenBytes);
	
	// Configuration
	void SetFont(HFont ahFont);
	
	// Inserts characters at the end of the stream
	void InsertChar(wchar_t aChar);
	void InsertString(const char *asText);
	void InsertString(const wchar_t *asText);
	
	// Selection
	
	void SelectNone();
	void SelectAllText();
	void SelectNoText();
	
	MESSAGE_FUNC(CutSelected, "DoCutSelected");
	MESSAGE_FUNC(CopySelected, "DoCopySelected");
	
	// Sets the RichText control interactive or not (meaning you can select/copy text in the window)
	void SetPanelInteractive(bool abInteractive){mbInteractive = abInteractive;}
	
	// Sets the RichText scroll bar invisible if it's not going to be used
	void SetUnusedScrollBarInvisible(bool abState){mbUnusedScrollBarInvis = abState;}
	
	// Cursor movement
	
	/// Go to start of text buffer
	void GotoTextStart();
	
	/// Go to end of text buffer
	void GotoTextEnd();
	
	// Configuration
	
	/// Sets visibility of the scroll bar
	void SetVerticalScrollBar(bool abState); // TODO: SetVerticalScrollBarActive? SetVerticalScrollBarEnabled?
	
	/// Sets the limit of number of characters insertable into field
	/// Set to -1 to remove maximum
	/// Only works if rich-edit is NOT enabled
	void SetMaximumCharCount(int anChars);
	
	// Rich edit commands
	void InsertColorChange(Color aColor);
	
	// IndentChange doesn't take effect until the next newline character
	void InsertIndentChange(int anIndentPixels);
	
	// Clickable text
	// Notification that text was clicked is through "TextClicked" message
	void InsertClickableTextStart(const char *asClickAction = nullptr);
	void InsertClickableTextEnd();
	
	/// Inserts and string that needs to be scanned for URLs/mailto commands to be made clickable
	void InsertPossibleURLString(const char *asText, Color aURLTextColor, Color aNormalTextColor);
	
	void InsertFade(float afSustain, float afLength);
	
	void ResetAllFades(bool abHold, bool abOnlyExpired = false, float afNewSustain = -1.0f);
	
	/// Sets the height of the window so all text is visible
	/// Used by the tooltips
	void SetToFullHeight();
	
	int GetNumLines() const;
	
	/* CUSTOM MESSAGE HANDLING
		"SetText"
			input: "text" - text is set to this string
	*/
	
	/* MESSAGE SENDING (to action signal targets)
		"TextChanged" - sent when the text is edited by the user
		
		"TextClicked" - send when clickable text has been clicked on
			"text" - the text that was clicked on
	*/
	
	/*virtual*/ bool RequestInfo(KeyValues *apOutputData);
	
	/* INFO HANDLING
		"GetText"
			returns:
				"text" - text contained in the box
	*/
	
	/*virtual*/ void SetFgColor(Color aColor);
	/*virtual*/ void SetDrawOffsets(int anOffsetX, int anOffsetY);
	
	bool IsScrollBarVisible() const;
	
	ScrollBar *GetScrollBar() const {return mpVertScrollBar;}
	
	void SetUnderlineFont(HFont ahFont);
	
	bool IsAllTextAlphaZero() const;
	bool HasText() const;
	
	void SetDrawTextOnly();
protected:
	/*virtual*/ void OnThink();
	
	/// Layout the text in the window
	/*virtual*/ void PerformLayout();
	
	/*virtual*/ void ApplySchemeSettings(IScheme *apScheme);
	/*virtual*/ void Paint();
	
	/*virtual*/ void ApplySettings(KeyValues *apData);
	/*virtual*/ void GetSettings(KeyValues *apData) const;
	
	/*virtual*/ const char *GetDescription() const;
	
	MESSAGE_FUNC_WCHARPTR(OnSetText, "SetText", text);
	
	/// Respond to scroll bar events
	MESSAGE_FUNC(OnSliderMoved, "ScrollBarSliderMoved");
	
	/*virtual*/ void OnKillFocus();
	
	/// Respond to mouse wheel events
	/*virtual*/ void OnMouseWheeled(int anDelta);
	
	/// Respond to keyboard events
	/*virtual*/ void OnKeyCodeTyped(KeyCode aeCode);
	
	MESSAGE_FUNC_INT(OnClickPanel, "ClickPanel", nIndex);
	
	/// Respond to moving the cursor with mouse button down
	/*virtual*/ void OnCursorMoved(int anX, int anY);
	
	/// Respond to mouse down events
	/*virtual*/ void OnMousePressed(MouseCode aeCode);
	/*virtual*/ void OnMouseDoublePressed(MouseCode aeCode);
	
	/// Respond to mouse up events
	/*virtual*/ void OnMouseReleased(MouseCode aeCode);
	
	/// Do while window has mouse focus
	/*virtual*/ void OnMouseFocusTicked();
	
	/// Handle cursor entering window
	/*virtual*/ void OnCursorEntered();
	
	/// Handle cursor exiting window
	/*virtual*/ void OnCursorExited();
	
	/*virtual*/ void OnMouseCaptureLost();
	
	/*virtual*/ void OnSizeChanged(int anNewWidth, int anNewHeight);
	
	/*virtual*/ void OnSetFocus();
	
	// Clickable URL handling
	int ParseTextStringForURLs(const char *asText, int anStartPos, char *asURLText, int anURLText, char *asURL, int anURL, bool &abClickable);
	
	/*virtual*/ void OnTextClicked(const wchar_t *asText);
	
#ifdef DBGFLAG_VALIDATE
	/*virtual*/ void Validate(CValidator &aValidator, char *asName);
#endif
protected:
	ScrollBar *mpVertScrollBar{nullptr}; ///< The scroll bar used in the window
private:
	const wchar_t *ResolveLocalizedTextAndVariables(const char *asLookup, wchar_t *apOutBuf, size_t anOutBufSizeBytes);
	
	void CheckRecalcLineBreaks();
	
	/// Move cursor to start of next word
	void GotoWordRight();
	
	/// Move cursor to start of prev word
	void GotoWordLeft();
	
	void TruncateTextStream();
	
	bool GetSelectedRange(int &anCX0, int &anCX1) const;
	
	void CursorToPixelSpace(int anCursorPos, int &anCX, int &anCY) const;
	int PixelToCursorSpace(int anCX, int anCY) const;
	
	void AddAnotherLine(int &anCX, int &anCY);
	
	void RecalculateDefaultState(int anStartIndex);
	
	void LayoutVerticalScrollBarSlider();
	
	void OpenEditMenu();
	
	void FinishingURL(int anX, int anY);
	
	/// Returns the character index the drawing should start at
	int GetStartDrawIndex(int &anLineBreakIndex) const;
	
	int GetCursorLine() const;
	
	int GetClickableTextIndexStart(int anStartIndex) const;
	
	/// Create copy/cut/paste menu
	void CreateEditMenu();
	
	MESSAGE_FUNC_INT(MoveScrollBar, "MoveScrollBar", delta);
	MESSAGE_FUNC_INT(MoveScrollBarDirect, "MoveScrollBarDirect", delta);
	
	// Linebreak stream functions
	void InvalidateLineBreakStream();
	void RecalculateLineBreaks();
	
	/// Updates a render state based on the formatting and color streams
	/// Returns true if any state changed
	bool UpdateRenderState(int anTextStreamPos, TRenderState &aRenderState);
	
	void CalculateFade(TRenderState &aRenderState);
	
	void GenerateRenderStateForTextStreamIndex(int anTextStreamIndex, TRenderState &aRenderState);
	int FindFormatStreamIndexForTextStreamPos(int anTextStreamIndex) const;
	
	/// Draws a string of characters with the same formatting using the current render state
	int DrawString(int anFirst, int anLast, TRenderState &aRenderState, HFont ahFont);
private:
	struct TFade
	{
		float mfFadeStartTime{0.0f};
		float mfFadeLength{0.0f};
		float mfFadeSustain{0.0f};
		
		int mnOriginalAlpha{0};
	};
	
	/// Describes changes in formatting for the text stream
	struct TFormatStream
	{
		TFade mFade{};
		
		// Render state
		Color mColor{};
		
		CUtlSymbol mClickableTextAction;
		
		int mnPixelsIndent{0};
		
		/// Position in text stream that these changes take effect
		int mnTextStreamIndex{0};
		
		bool mbTextClickable{false};
	};
	
	struct TRenderState
	{
		/// Rendering positions
		int x, y;
		
		/// Basic state
		Color mTextColor{};
		
		int mnPixelsIndent{0};
		
		/// Index into our current position in the formatting stream
		int mnFormatStreamIndex{0};
		
		bool mbTextClickable{false};
	};
	
	// Data
	CUtlVector<wchar_t> mvTextStream; ///< The text in the text window is started in this buffer
	CUtlVector<int> mvLineBreaks; ///< An array that holds the index in the buffer to wrap lines at
	CUtlVector<TFormatStream> mvFormatStream; ///< List of format changes
	
	CUtlVector<ClickPanel*> mvClickableTextPanels;
	
	TRenderState mCachedRenderState{}; ///< Cached render state for the beginning of painting
	
	Color mSelectionColor{};
	
	Color mDefaultTextColor{};
	Color mSelectionTextColor{}; ///< Color of the highlighted text
	
	int mnSelect[2]{0}; ///< mnSelect[0] is the offset to where the cursor was dragged to or -1 if no drag
						///< mnSelect[1] is the offset in the text to where the cursor is currently
	
	Panel *mpInterior{nullptr};
	
	// Sub-controls
	Menu *mpEditMenu{nullptr}; ///< Cut/copy/paste popup
	
	char *msInitialText{nullptr}; ///< Initial text
	
	HFont mhFont{}; ///< Font of chars in the text buffer
	HFont mhFontUnderline{};
	
	int mnRecalculateBreaksIndex{0}; ///< Tells next line break index to start recalculating line breaks
	
	int mnCursorPos{0}; ///< The position in the text buffer of the blinking cursor
	
	int mnPixelsIndent{0};
	int mnMaxCharCount{0}; ///< Max number of chars that can be in the text buffer
	
	int mnClickableTextIndex{0};
	
	int mnDrawOffsetX{0};
	int mnDrawOffsetY{0};
	
	bool mbRecalcLineBreaks{false};
	
	bool mbInvalidateVerticalScrollBarSlider{false};
	
	bool mbMouseSelection{false}; ///< Whether we are highlighting text or not (selecting text)
	bool mbMouseDragSelection{false}; ///< Tells whether mouse is outside the window and button is down so we select text
	
	bool mbCurrentTextClickable{false};
	
	bool mbResetFades{false};
	bool mbInteractive{false};
	bool mbUnusedScrollBarInvis{false};
	bool mbAllTextAlphaIsZero{false};
	
	/// Saved state
	bool mbRecalcSavedRenderState{false};
};

}; // namespace vgui2