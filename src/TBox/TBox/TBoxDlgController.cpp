#include "StdAfx.h"
#include "TBoxDlgController.h"

TBoxDlgController TBoxDlgController::s_tboxController;

TBoxDlgController::TBoxDlgController(void)
{
	CTboxContextMain::GetInstance().m_AddContextMenuEvent = (pAddContextMenu)staitc_AddContextMenu;
}

TBoxDlgController::~TBoxDlgController(void)
{
}

void TBoxDlgController::Init(CTBoxDlg *ctboxdlg)
{
	m_ctboxdlg = ctboxdlg;

	CTboxContextMain::GetInstance().LoadTboxPlug(_T("tplug"));

	CTboxContextMain::GetInstance().Init();
}

void TBoxDlgController::Destory()
{
	CTboxContextMain::GetInstance().Destory();
}

UINT WINAPI TBoxDlgController::staitc_AddContextMenu(UINT menuid,TCHAR *menuname,ContexMenuEvent OnClickEvent)
{
	if (s_tboxController.m_ctboxdlg!=NULL)
	{
		return s_tboxController.m_ctboxdlg->m_viewNotify.AddPlugsMenu(menuid,menuname,OnClickEvent);
	}
	return ERROR_NO_ASSOCIATION;
}

TBoxDlgController &TBoxDlgController::GetInstance()
{
	return s_tboxController;
}