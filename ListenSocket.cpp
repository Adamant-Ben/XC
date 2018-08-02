// ListenSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "ListenSocket.h"
#include "XiaoBiLiDlg.h"

// CListenSocket

CListenSocket::CListenSocket(CXiaoBiLiDlg* pDlg)
{
	m_pDlg=pDlg;
}

CListenSocket::~CListenSocket()
{
	m_pDlg=NULL;
}


// CListenSocket 成员函数


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CSocket::OnAccept(nErrorCode);
	m_pDlg->OnAccept();
}

IMPLEMENT_DYNAMIC(CListenSocket,CSocket)