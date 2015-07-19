//插件配置文件读取

#pragma once
#include "..\TBCommon\TBoxComponent.h"

#define PLUGFILENAME _T("plugconfig.ini")

typedef struct _TBoxPlugInfo_
{
	TCHAR plugname[MAX_PATH];
	TCHAR plugDLL[MAX_PATH];
	_TBoxPlugInfo_()
	{
		memset(this,0,sizeof(_TBoxPlugInfo_));
	}
}TBoxPlugInfo;

typedef CTBoxComponent *(* pCreateComponent)();

class TBoxPlugLoader
{
private:
	CString m_plugFolder;
	TBoxPlugInfo m_plugInfo;
	HMODULE m_hmodule;
public:
	TBoxPlugLoader(CString plugFolder);
	~TBoxPlugLoader(void);

	BOOL LoadConfig();

	CTBoxComponent *LoadTBoxPlug();
	void RealsePlug();
public:
	CTBoxComponent *m_component;
};
