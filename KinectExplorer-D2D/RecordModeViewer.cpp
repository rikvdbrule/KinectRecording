#include "stdafx.h"
#include "RecordModeViewer.h"
#include "resource.h" 

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
   switch (uMsg)
   {
   case WM_INITDIALOG:
	   OnInit(hWnd);
	   break;

   default:
	   break;
   }
   
   return FALSE;
}

UINT RecordModeViewer::GetDlgId()
{
	return IDD_RECORD_MODE_VIEW;
}

void RecordModeViewer::OnInit(HWND hWnd)
{
	HWND hWndButton = GetDlgItem(hWnd, IDC_RECORD_TOGGLE);
}

void RecordModeViewer::SetRecordMode(bool record, char* fileName)
{
	//TODO
}