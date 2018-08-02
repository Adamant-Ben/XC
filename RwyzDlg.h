#pragma once
class CXiaoBiLiDlg;
// CRwyzDlg 对话框

class CRwyzDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRwyzDlg)

public:
	CRwyzDlg(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRwyzDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_RWYZ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CXiaoBiLiDlg* m_pDlg;
	BYTE m_num_hc1;
	BYTE m_num_hc2;
	BYTE m_num_hc3;
	float m_z1;
	float m_z2;
	float m_z3;
	float m_z4;
//	int m_rwlx;
	float m_speed;
	CString m_x1;
	CString m_x2;
	CString m_x3;
	CString m_x4;
	CString m_y1;
	CString m_y2;
	CString m_y3;
	CString m_y4;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	int m_rwlx;
//	BOOL m_rwlx;
	int m_rwlx;
	afx_msg void OnBnClickedButtonTurn();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonReadIni();
	afx_msg void OnBnClickedButtonWriteIni();
	void ReadIni();
	CComboBox m_speed_ctr;
//	CString m_speed_kn;
	afx_msg void OnCbnSelchangeComboSpeed();
	CString m_speed_kn;
	virtual BOOL OnInitDialog();
	void SpeedTransform();
};
