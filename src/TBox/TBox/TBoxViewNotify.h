//Õ–≈ÃÕº±Í
#pragma once

#include <Windows.h>

#define WM_USER_NOTIFYICON WM_USER+1  
#define WM_USER_MENUCLICK_ZERO WM_USER+100

class TBoxViewNotify
{
private:  
	NOTIFYICONDATA m_notify; 
	CDialog *m_pdlg;
public:
	TBoxViewNotify(void);
	~TBoxViewNotify(void);
	void Init(CDialog &dlg);
	LRESULT NotifyProc(UINT message, WPARAM wParam, LPARAM lParam);
};
