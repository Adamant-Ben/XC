// ListenSocket.cpp : ʵ���ļ�
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


// CListenSocket ��Ա����


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CSocket::OnAccept(nErrorCode);
	m_pDlg->OnAccept();
}

IMPLEMENT_DYNAMIC(CListenSocket,CSocket)