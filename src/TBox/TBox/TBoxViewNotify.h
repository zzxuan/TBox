//ÍÐÅÌÍ¼±ê
#pragma once

#include <Windows.h>
#include <map>
#include "..\TBCommon\TBoxContext.h"

#define WM_USER_NOTIFYICON WM_USER+1  
#define WM_USER_MENUCLICK_SET WM_USER+101
#define WM_USER_MENUCLICK_ABOUT WM_USER+102
#define WM_USER_MENUCLICK_EXIT WM_USER+103

typedef struct _NotifyInfo_
{
	UINT menuid;
	TCHAR name[100];
	ContexMenuEvent clickEvent;

	_NotifyInfo_()
	{
		memset(this,0,sizeof(_NotifyInfo_));
	}

}NotifyInfo;

typedef std::map<UINT,NotifyInfo> NotifyMap;

class TBoxViewNotify
{
private:  
	NOTIFYICONDATA m_notify; 
	CDialog *m_pdlg;
	NotifyMap m_plugsNotifyMap;//±£´æ²å¼þÓÒ¼ü²Ëµ¥Map
	CRITICAL_SECTION m_plugsNotifyMapSection;
public:
	TBoxViewNotify(void);
	~TBoxViewNotify(void);
	void Init(CDialog &dlg);
	LRESULT NotifyProc(UINT message, WPARAM wParam, LPARAM lParam);

	void CreateNotifyMenu();

	void OnNotifyMenuClick(UINT menuid);
	UINT AddPlugsMenu(UINT menuid,TCHAR *menuname,ContexMenuEvent OnClickEvent);
};
