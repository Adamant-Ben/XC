#pragma once


// Cpage_config_ydgh 对话框

class Cpage_config_ydgh : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_config_ydgh)

public:
	Cpage_config_ydgh(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage_config_ydgh();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_cyc1;
	CString m_cyc2;
	CString m_cyc3;
	CString m_cyc4;
	CString m_cyct;
	CString m_ssv_l;
	afx_msg void OnBnClickedButton1();
	CString m_k_e1;
	CString m_k_e2;
	CString m_k_e3;
	CString m_k_e4;
	CString m_k_e5;
	CString m_k_e6;
	CString m_k_h1;
	CString m_k_h2;
	CString m_k_h3;
	CString m_k_h4;
	CString m_k_h5;
	CString m_k_h6;
	CString m_kdu1;
	CString m_kdu2;
	CString m_kiu1;
	CString m_kiu2;
	CString m_kpu1;
	CString m_speed_a1;
	CString m_speed_a2;
	CString m_speed_a3;
	CString m_speed_a4;
	CString m_speed_a5;
	CString m_speed_a6;
	CString m_kpu2;
	CString m_deltar_a1;
	CString m_deltar_a2;
	CString m_deltar_a3;
	CString m_deltar_a4;
	CString m_deltar_a5;
	CString m_deltar_a6;
	CString m_kdr1;
	CString m_kdr2;
	CString m_kdr3;
	CString m_kir1;
	CString m_kir2;
	CString m_kir3;
	CString m_kpr1;
	CString m_kpr2;
	CString m_kpr3;
	CString m_ydr;
	CString m_ydb;
	CString m_kpb1;
	CString m_kpb2;
	CString m_kpb3;
	CString m_kib1;
	CString m_kib2;
	CString m_kib3;
	CString m_kdb1;
	CString m_kdb2;
	CString m_kdb3;
	CString m_deltab_a1;
	CString m_deltab_a2;
	CString m_deltab_a3;
	CString m_deltab_a4;
	CString m_deltab_a5;
	CString m_deltab_a6;
	CString m_deltas_a1;
	CString m_deltas_a2;
	CString m_deltas_a3;
	CString m_deltas_a4;
	CString m_deltas_a5;
	CString m_deltas_a6;
	CString m_kds1;
	CString m_kds2;
	CString m_kds3;
	CString m_kis1;
	CString m_kis2;
	CString m_kis3;
	CString m_kps1;
	CString m_kps2;
	CString m_yds;
	CString m_kps3;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
