#pragma once
class CXiaoBiLiDlg;

// Cpage0 对话框

class Cpage0 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage0)

public:
	Cpage0(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage0();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };
public:
	CXiaoBiLiDlg* m_pDlg0;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCspzSxzk();
	CString m_abovewatermaster;
	CString m_abovewatermasterwifi;
	CString m_acceptancecode;
	CString m_acceptancemask;
	CString m_baudrate;
	CString m_baudrate_0;
	CString m_baudrate_1;
	CString m_boardno_0;
	CString m_boardno_1;
	CString m_cardno;
	CString m_channelno_0;
	CString m_channelno_1;
	CString m_clockrate;
	CString m_datastorageunit;
	CString m_defaultmode;
	CString m_emergencyunit;
	CString m_errorthreshhold;
	CString m_macroperiod;
	CString m_measureunit;
	CString m_microperiod;
	CString m_mode;
	CString m_motionplanningunit;
	CString m_navigationunit;
	CString m_numberofcontrolunit;
	CString m_numofslave;
	CString m_portno;
	CString m_primarycontrolunit;
	CString m_rcvlevel_0;
	CString m_rcvlevel_1;
	CString m_speedthreshhold;
	CString m_tcpserverportnumber;
	CString m_underwatermaster;
	CString m_workstage;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
