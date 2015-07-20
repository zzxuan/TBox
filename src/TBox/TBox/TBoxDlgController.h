#pragma once
#include "TboxContextMain.h"
#include "TBoxDlg.h"


class TBoxDlgController
{
private:
	static TBoxDlgController s_tboxController;
	CTBoxDlg *m_ctboxdlg;
public:
	TBoxDlgController(void);
	~TBoxDlgController(void);

	void Init(CTBoxDlg *ctboxdlg);

	void Destory();

	static UINT WINAPI staitc_AddContextMenu(UINT menuid,TCHAR *menuname,ContexMenuEvent OnClickEvent);

	static TBoxDlgController& GetInstance();
};
