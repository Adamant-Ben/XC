#pragma once

// CSessionSocket ÃüÁîÄ¿±ê
class CXiaoBiLiDlg;
class CSessionSocket : public CSocket
{
	DECLARE_DYNAMIC(CSessionSocket);
public:
	CSessionSocket(CXiaoBiLiDlg* pDlg);
	CSessionSocket();
	virtual ~CSessionSocket();
	CXiaoBiLiDlg *m_pDlg;
	virtual void OnReceive(int nErrorCode);
	int num_fs_rw[4];
};


