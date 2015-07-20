#include "StdAfx.h"
#include "TboxContextMain.h"
#include "TBoxPlugLoader.h"

CTboxContextMain CTboxContextMain::s_contextMain;

CTboxContextMain::CTboxContextMain(void)
{
	InitializeCriticalSection(&m_tBoxPlugsSection);
	m_AddContextMenuEvent = NULL;	
}

CTboxContextMain::~CTboxContextMain(void)
{
	DeleteCriticalSection(&m_tBoxPlugsSection);
}

UINT CTboxContextMain::AddContextMenu(UINT menuid,TCHAR *menuname,ContexMenuEvent OnClickEvent)
{
	if (m_AddContextMenuEvent != NULL)
	{
		UINT  n = m_AddContextMenuEvent(menuid,menuname,OnClickEvent);
		return n;
	}
	return ERROR_NO_ASSOCIATION;
}

void CTboxContextMain::ShowHintWindow(TCHAR * text,int timelen)
{
	//throw std::logic_error("The method or operation is not implemented.");
}

void CTboxContextMain::Init()
{
	EnterCriticalSection(&m_tBoxPlugsSection);
	int size = m_tBoxPlugs.size();
	for (int i=0 ;i < size;i++)
	{
		if (NULL != m_tBoxPlugs[i].m_component)
		{
			m_tBoxPlugs[i].m_component->OnInit(this);
		}
	}
	LeaveCriticalSection(&m_tBoxPlugsSection);
}

void CTboxContextMain::Destory()
{
	EnterCriticalSection(&m_tBoxPlugsSection);
	int size = m_tBoxPlugs.size();
	for (int i=0 ;i < size;i++)
	{
		if (NULL != m_tBoxPlugs[i].m_component)
		{
			m_tBoxPlugs[i].m_component->OnDestory();
		}
		m_tBoxPlugs[i].RealsePlug();
	}
	LeaveCriticalSection(&m_tBoxPlugsSection);
}

CTboxContextMain &CTboxContextMain::GetInstance()
{
	return s_contextMain;
}

void CTboxContextMain::LoadTboxPlug(TCHAR *plugfolder)
{
	TBoxPlugLoader loader(plugfolder);
	loader.LoadConfig();
	if (NULL != loader.LoadTBoxPlug())
	{
		EnterCriticalSection(&m_tBoxPlugsSection);
		m_tBoxPlugs.push_back(loader);
		LeaveCriticalSection(&m_tBoxPlugsSection);
	}
}