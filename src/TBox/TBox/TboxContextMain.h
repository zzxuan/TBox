#pragma once
#include "..\TBCommon\TBoxContext.h"
#include "..\TBCommon\TBoxComponent.h"
#include <vector>
#include "TBoxPlugLoader.h"


class CTboxContextMain :
	public CTboxConext
{
public:
	static CTboxContextMain &GetInstance();
private:
	static CTboxContextMain s_contextMain;
	std::vector<TBoxPlugLoader> m_tBoxPlugs;
	CRITICAL_SECTION m_tBoxPlugsSection;

	
public:
	CTboxContextMain(void);
	~CTboxContextMain(void);

	virtual void AddContextMenu(TCHAR * menuname,void *OnClickEvent);

	virtual void ShowHintWindow(TCHAR * text,int timelen);

	virtual void Init();

	virtual void Destory();

	void LoadTboxPlug(TCHAR *plugfolder);

};
