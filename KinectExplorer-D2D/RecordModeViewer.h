#pragma once

#include "Utility.h"
#include "NuiViewer.h"

class KinectWindow;

class RecordModeViewer :
	public NuiViewer
{
public:
	RecordModeViewer(const NuiViewer* pParent);

	~RecordModeViewer(void);

	void SetRecordMode(bool record, char* fileName);

private:

	virtual UINT GetDlgId();

    virtual LRESULT DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void OnInit(HWND hWnd);

private:
	bool m_record;
	char * m_fileName;

};

