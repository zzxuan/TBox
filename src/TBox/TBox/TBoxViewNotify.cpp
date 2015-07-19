#include "StdAfx.h"
#include "TBoxViewNotify.h"
#include "Resource.h"


TBoxViewNotify::TBoxViewNotify(void)
{

}

TBoxViewNotify::~TBoxViewNotify(void)
{
	::Shell_NotifyIcon(NIM_DELETE,&m_notify);
}


void TBoxViewNotify::Init(CDialog &dlg)
{
	m_pdlg = &dlg;
	m_notify.cbSize=sizeof NOTIFYICONDATA;  
	m_notify.hWnd=dlg.m_hWnd;    
	m_notify.uID=IDR_MAINFRAME;  
	m_notify.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));  
	_tcscpy_s(m_notify.szTip,_T("Michael_Chen is a good man"));  
	m_notify.uCallbackMessage=WM_USER_NOTIFYICON;  
	m_notify.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP|NIF_INFO;  //OK,下面就是托盘产生了.

	_tcscpy_s(m_notify.szInfo,_T("XX"));
	_tcscpy_s(m_notify.szInfoTitle,_T("XXXX"));
	m_notify.dwInfoFlags=NIIF_INFO;  
	m_notify.uTimeout=2000;  


	Shell_NotifyIcon(NIM_ADD,&m_notify);  
	Shell_NotifyIcon(NIM_MODIFY,&m_notify); 
}

LRESULT TBoxViewNotify::NotifyProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class
	if (NULL == m_pdlg)
	{
		return NULL;
	}
	switch(message)
	{
	case WM_USER_NOTIFYICON:
		{
			if(lParam==WM_LBUTTONDBLCLK)

			{ 
				//鼠标双击时主窗口出现 
				if(AfxGetApp()->m_pMainWnd->IsWindowVisible()) //判断窗口当前状态
				{
					AfxGetApp()->m_pMainWnd->ShowWindow(SW_HIDE); //隐藏窗口
				}
				else
				{
					AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOW); //显示窗口
				}

			} 
			else if(lParam==WM_RBUTTONUP)
			{ //鼠标右键单击弹出选单 
				CPoint pos; 
				GetCursorPos(&pos); 
				//m_pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,pos.x,pos.y,m_pdlg);
				CMenu pPopMenu;
				pPopMenu.CreatePopupMenu();

				pPopMenu.AppendMenu(MF_POPUP,WM_USER + 101,_T("右键菜单"));
				pPopMenu.AppendMenu(MF_POPUP,WM_USER+102,_T("退出"));

				HMENU hTackMenu = GetSubMenu(pPopMenu.m_hMenu, 0); //取出目标菜单 

				CMenu cc;
				cc.CreatePopupMenu();
				cc.AppendMenu(MF_POPUP,WM_USER + 106,_T("右键菜单123123"));
				
				pPopMenu.AppendMenu(MF_POPUP,(UINT_PTR)cc.Detach(),_T("子菜单"));

				
				AfxGetMainWnd()->SetForegroundWindow(); //加上这一句就可以了
				pPopMenu.TrackPopupMenu(TPM_LEFTALIGN,pos.x,pos.y,AfxGetMainWnd());



				pPopMenu.DestroyMenu();
			} 
		}
		break;
	case WM_COMMAND:
		{
			//MessageBox(NULL,_T("231"),NULL,NULL);
			UINT uMsg=LOWORD(wParam);
			if(uMsg==1)
				MessageBox(NULL,_T("右键菜单"),NULL,NULL);
			else if (uMsg==WM_USER+102)
			{
				MessageBox(NULL,_T("退出"),NULL,NULL);
				/*AfxGetMainWnd()->CloseWindow();*/
				::Shell_NotifyIcon(NIM_DELETE,&m_notify);
				exit(0);
			}
			else if (WM_USER + 106 == uMsg)
			{
				MessageBox(NULL,_T("右键菜单123123"),NULL,NULL);
			}
		}
		break;
	default:
		break;
	}
	
	//else if (lParam == m_pMenu->GetMenuItemID(0))
	//{
	//	MessageBox(NULL,_T("2132"),NULL,NULL);
	//}
	return NULL;
}