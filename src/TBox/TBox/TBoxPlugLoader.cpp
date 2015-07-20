#include "StdAfx.h"
#include "TBoxPlugLoader.h"
#include <shlwapi.h>

TBoxPlugLoader::TBoxPlugLoader(CString plugFolder)
{
	//判断是否存在
	if(!PathFileExists(plugFolder))
	{
		TCHAR chpath[MAX_PATH] = {NULL};  
		GetModuleFileName(NULL,chpath,MAX_PATH);
		TCHAR * tt= _tcsrchr(chpath, _T('\\'));
		if (tt != NULL)
		{
			tt[0] = '\0';
		}
		m_plugFolder.Format(_T("%s\\%s"),chpath,plugFolder.GetBuffer());
	}
	else
	{
		m_plugFolder = plugFolder;
	}
	
}

TBoxPlugLoader::~TBoxPlugLoader(void)
{
}

BOOL TBoxPlugLoader::LoadConfig()
{

	CString path = m_plugFolder + _T("\\") + PLUGFILENAME;
	//判断是否存在
	if(!PathFileExists(path))
	{
		TCHAR chpath[MAX_PATH] = {NULL};  
		GetModuleFileName(NULL,chpath,MAX_PATH);
		TCHAR * tt= _tcsrchr(chpath, _T('\\'));
		if (tt != NULL)
		{
			tt[0] = '\0';
		}
		path.Format(_T("%s\\%s\\%s"),chpath,m_plugFolder,PLUGFILENAME);
	}
	

	GetPrivateProfileString(_T("TBOX"),_T("PLUGNAME"),_T("ERROR")
		,m_plugInfo.plugname,sizeof(m_plugInfo.plugname),path);

	GetPrivateProfileString(_T("TBOX"),_T("DLLNAME"),_T("ERROR")
		,m_plugInfo.plugDLL,sizeof(m_plugInfo.plugDLL),path);
	
	if (_tcscmp(_T("ERROR"),m_plugInfo.plugname) == 0 
		|| _tcscmp(_T("ERROR"),m_plugInfo.plugDLL) == 0 )
	{
		CString info;
		info.Format(_T("插件配置文件读取失败\n%s"),m_plugFolder);
		MessageBox(NULL,info,_T("ERROR"),0);
		return FALSE;
	}
	return TRUE;
}

//加载插件
CTBoxComponent *TBoxPlugLoader::LoadTBoxPlug()
{
	SetDllDirectory(m_plugFolder);
	HMODULE hm = ::LoadLibrary(m_plugInfo.plugDLL);
	if (hm != NULL)
	{
		pCreateComponent pcreate = (pCreateComponent)GetProcAddress(hm,"CreateComponent");
		if (NULL == pcreate)
		{
			return NULL;
		}
		m_component = pcreate();
		return m_component;
	}
	return NULL;
}

void TBoxPlugLoader::RealsePlug()
{
	if (NULL != m_component)
	{
		delete m_component;
		m_component = NULL;
	}
	if (NULL != m_hmodule)
	{
		FreeLibrary(m_hmodule);
		m_hmodule = NULL;
	}
}