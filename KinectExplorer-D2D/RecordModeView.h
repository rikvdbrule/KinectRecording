#pragma once
#include "NuiViewer.h"

class RecordModeView :
	public NuiViewer
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
    /// <param name="pParent">The pointer to parent window</param>
	RecordModeView(const NuiViewer* pParent);

	/// <summary>
	/// Destructor
	/// </summary>
	~RecordModeView();

private:
    /// <summary>
    /// Returns the ID of the dialog
    /// </summary>
    /// <returns>ID of dialog</returns>
    virtual UINT GetDlgId();

    /// <summary>
    /// Dispatch window message to message handlers.
    /// </summary>
    /// <param name="hWnd">Handle to window</param>
    /// <param name="uMsg">Message type</param>
    /// <param name="wParam">Extra message parameter</param>
    /// <param name="lParam">Extra message parameter</param>
    /// <returns>
    /// If message is handled, non-zero is returned. Otherwise FALSE is returned and message is passed to default dialog procedure
    /// </returns>
    virtual LRESULT DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

};

