#pragma once

// CListenSocket ����Ŀ��
class CXiaoBiLiDlg;
class CListenSocket : public CSocket
{
	DECLARE_DYNAMIC(CListenSocket);
public:
	CListenSocket(CXiaoBiLiDlg* pDlg);
	virtual ~CListenSocket();
	CXiaoBiLiDlg *m_pDlg;
	virtual void OnAccept(int nErrorCode);
};


