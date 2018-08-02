#pragma once


// CPage_nau_config 对话框
class CXiaoBiLiDlg;
class CPage_nau_config : public CDialogEx
{
	DECLARE_DYNAMIC(CPage_nau_config)

public:
	CPage_nau_config(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage_nau_config();
	CXiaoBiLiDlg* m_pDlg;

// 对话框数据
	enum { IDD = IDD_DIALOG_NAU_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNauParaCongirm();
	CString m_Altimeter1_BaudRate;
	CString m_Altimeter1_BoardNo;
	CString m_Altimeter1_ChannelNo;
	CString m_Altimeter1_RcvLevel;
	CString m_clientPortNumber;
	CString m_Depther_BaudRate;
	CString m_Depther_BoardNo;
	CString m_Depther_ChannelNo;
	CString m_Depther_RcvLevel;
	CString m_DVL_BaudRate;
	CString m_DVL_BoardNo;
	CString m_DVL_ChannelNo;
	CString m_DVL_RcvLevel;
	CString m_EMU_BaudRate;
	CString m_EMU_CpuSerialName;
	CString m_GPS_BaudRate;
	CString m_GPS_BoardNo;
	CString m_GPS_ChannelNo;
	CString m_GPS_RcvLevel;
	CString m_LRPA200_BaudRate;
	CString m_LRPA200_BoardNo;
	CString m_LRPA200_ChannelNo;
	CString m_LRPA200_RcvLevel;
	CString m_NavigationUnit;
	CString m_PHINS_BaudRate;
	CString m_PHINS_BoardNo;
	CString m_PHINS_ChannelNo;
	CString m_PHINS_RcvLevel;
	CString m_SeverPortNumber;
	CString m_UnderWaterMaster;
//	afx_msg void OnEnChangeEditGpsChannelno();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
