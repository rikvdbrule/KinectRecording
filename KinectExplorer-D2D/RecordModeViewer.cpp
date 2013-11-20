#include "resource.h" 
#include "RecordModeViewer.h"

RecordModeViewer::RecordModeViewer(const NuiViewer* pParent)
	: NuiViewer(pParent)
	, m_record(false)
	, m_fileName("C:/Desktop/skeldata_out_pp_1.data")
{
}

RecordModeViewer::~RecordModeViewer(void)
{
}

LRESULT RecordModeViewer::DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Pass the message to default dialog procedure
    return FALSE;
}

UINT RecordModeViewer::GetDlgId()
{
	return IDD_RECORD_MODE_VIEW;
}

void RecordModeViewer::SetRecordMode(bool record, char* fileName)
{
	//TODO
}