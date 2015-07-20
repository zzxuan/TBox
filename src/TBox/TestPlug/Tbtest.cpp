#include "StdAfx.h"
#include "Tbtest.h"
#include <tchar.h>
#include <Windows.h>

typedef int (* testfun)();
testfun ptestfun;

CTbtest::CTbtest(void)
{
	/*HMODULE hm = ::LoadLibrary(_T("testDll.dll"));
	if (hm != NULL)
	{
		ptestfun = (testfun)GetProcAddress(hm,"fntestDll");
		
	}*/
}

CTbtest::~CTbtest(void)
{
}

void CTbtest::OnInit(CTboxConext *context)
{
	//throw std::logic_error("The method or operation is not implemented.");
	MessageBox(NULL,_T("TestInit"),NULL,0);
	/*if (ptestfun != NULL)
	{
		ptestfun();
	}*/

	context->AddContextMenu(WM_USER + 255,_T("≤‚ ‘"),(ContexMenuEvent)CTbtest::MenuClick);
}

void CTbtest::OnDestory()
{
	//throw std::logic_error("The method or operation is not implemented.");
}

int WINAPI CTbtest::MenuClick(UINT menuid)
{
	return 0;
}
