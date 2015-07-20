#pragma once
#include <Windows.h>

typedef int (WINAPI *ContexMenuEvent)(UINT menuid);

class CTboxConext
{
public:
	CTboxConext(void){};

	virtual UINT AddContextMenu(UINT menuid,TCHAR *menuname,ContexMenuEvent OnClickEvent) = 0;
	virtual void ShowHintWindow(TCHAR *text,int timelen) = 0;

};