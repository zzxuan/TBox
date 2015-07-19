#pragma once
#include <Windows.h>

class CTboxConext
{
public:
	CTboxConext(void){};

	virtual void AddContextMenu(TCHAR *menuname,void *OnClickEvent) = 0;
	virtual void ShowHintWindow(TCHAR *text,int timelen) = 0;

};