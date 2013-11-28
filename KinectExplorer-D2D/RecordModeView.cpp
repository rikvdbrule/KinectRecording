#include "RecordModeView.h"
#include "resource.h"

RecordModeView::RecordModeView(const NuiViewer* pParent)
	: NuiViewer(pParent)
{
}


RecordModeView::~RecordModeView(void)
{
}

LRESULT RecordModeView::DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_RECORD_TOGGLE_BUTTON:
			EnableWindow(GetDlgItem(hWnd, IDC_RECORD_FILE_NAME), FALSE);
			//do record stuff
			break;
		case IDC_RECORD_FILE_NAME:
			switch(HIWORD(wParam))
			{
			case EN_CHANGE:
				TCHAR buf[100];
				GetDlgItemText(hWnd, IDC_RECORD_FILE_NAME, buf, 100);
				MessageBox(hWnd, buf, NULL, NULL);
				break;
			}
		}
		break;
	default:
		return FALSE;
	}
	// Pass the message to default dialog procedure
    return TRUE;
}

/// <summary>
/// Returns the ID of the dialog
/// </summary>
UINT RecordModeView::GetDlgId()
{
    return IDD_RECORD_VIEW;
}