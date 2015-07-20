#pragma once
#include "..\TBCommon\TBoxContext.h"
#include "..\TBCommon\TBoxComponent.h"
#include <vector>
#include "TBoxPlugLoader.h"

typedef UINT (WINAPI *pAddContextMenu)(UINT menuid,TCHAR *menuname,ContexMenuEvent OnClickEvent);

class CTboxContextMain :
	public CTboxConext
{
public:
	static CTboxContextMain &GetInstance();

	pAddContextMenu m_AddContextMenuEvent;
private:
	static CTboxContextMain s_contextMain;
	std::vector<TBoxPlugLoader> m_tBoxPlugs;
	CRITICAL_SECTION m_tBoxPlugsSection;

	
public:
	CTboxContextMain(void);
	~CTboxContextMain(void);

	virtual UINT AddContextMenu(UINT menuid,TCHAR *menuname,ContexMenuEvent OnClickEvent);

	virtual void ShowHintWindow(TCHAR * text,int timelen);

	virtual void Init();

	virtual void Destory();

	void LoadTboxPlug(TCHAR *plugfolder);

};
