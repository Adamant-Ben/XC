
// XiaoBiLi.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CXiaoBiLiApp:
// �йش����ʵ�֣������ XiaoBiLi.cpp
//

class CXiaoBiLiApp : public CWinApp
{
public:
	CXiaoBiLiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CXiaoBiLiApp theApp;