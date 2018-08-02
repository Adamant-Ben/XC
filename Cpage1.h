#pragma once
//#include "DLL.h"
class CXiaoBiLiDlg;
#include "packetProc.h"
// Cpage1 对话框

class Cpage1 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage1();
	void ShowData();
public:
	void drawpicture(int m_image_ID, int m_image_num);

// 对话框数据
	enum { IDD = IDD_DIALOG2 };
public:
	CXiaoBiLiDlg* m_pDlg1;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//float m_zqtj;
	//float m_zwddj;
	//float m_tjqzs;
	//float m_wkddj;
	//float m_ywddj;
	//float m_fxddj;
	char rwlx;
	float x11;
	float y11;
	float z11;
	float x12;
	float y12;
	float z12;
	float x21;
	float y21;
	float z21;
	float x22;
	float y22;
	float z22;
	float x31;
	float y31;
	float z31;
	float x32;
	float y32;
	float z32;
	UINT num_hc1;
	UINT num_hc2;
	UINT num_hc3;
	BYTE speed;
	CString str1;
	CString str2;
	CString str3;
	//CString str;
	char rwyz[20000];
	int m_imagelist[3];
	int m_showimage[50];
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonRwzj();
	afx_msg void OnBnClickedButtonRwxz();
	afx_msg void OnBnClickedButtonRwck();
	afx_msg void OnBnClickedButtonRwsc();
	afx_msg void OnBnClickedButtonRwjl();
public:
	void GuiHua_hc1();
	void GuiHua_hc2();
	void GuiHua_hc3();
public:
	Data_page1 *pdata_page1;
	afx_msg void OnBnClickedButtonTxztcx();
	void ShowData_R306();     //根据查询报文R_306，显示通信状态
	void ShowData_R30();     //开始调度后根据查询报文R_30，显示通信状态
	afx_msg void OnBnClickedCheckKsdd();
	BOOL m_ksdd_flag;
	afx_msg void OnBnClickedCheckDddlxt();
//	BOOL m_dddlxt;
	BOOL m_dsuEnable;
	BOOL m_emuEnable;
//	BOOL m_mpuEnable;
	BOOL m_nauEnable;
	BOOL m_prcuEnable;
	BOOL m_pocuEnable;
	afx_msg void OnBnClickedCheckPrcuEnable();
	afx_msg void OnBnClickedCheckNauEnable();
	afx_msg void OnBnClickedCheckEmuEnable();
	afx_msg void OnBnClickedCheckDsuEnable();
	afx_msg void OnBnClickedButtonTimeSet();
	afx_msg void OnBnClickedButtonUwmuWRecnet();
	afx_msg void OnBnClickedButtonEmuWRecnet();
	BOOL m_meuEnable;
	afx_msg void OnBnClickedCheckMeuEnable();
	afx_msg void OnBnClickedButton2();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonToWxd();
	void Fuzhi_Rwyz();
	BOOL m_wkd_ctr_enable;
	BOOL m_wd_ctr_enable;
	BOOL m_fxd_ctr_enable;
	BOOL m_speed_ctr_enable;
//	BOOL m_fxd_up;
	BOOL m_shuibeng_ctr_enable;
	BOOL m_shuibeng_start;
	BOOL m_shuibeng_command; //水泵控制指令
	BOOL m_wd_up;
	BOOL m_fxd_l;
	BOOL m_wkd_up;
	short m_wd_cmd_down;
	short m_wd_cmd_up;
	short m_wkd_cmd_down;
	short m_wkd_cmd_up;
	short m_fxd_cmd_l;
	short m_fxd_cmd_r;
	short p_wkd;
	short p_fxd;
	short p_zywd;
	void UpdateInf();
	short m_speed_cmd;
	afx_msg void OnBnClickedRadioWkdCmd();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedCheckWkdCtrEnable();
	afx_msg void OnBnClickedCheckFxdCtrEnable();
	afx_msg void OnBnClickedRadioFxdCmdL();
	afx_msg void OnBnClickedRadioFxdCmdR();
	afx_msg void OnBnClickedCheckWdCtrEnable();
	afx_msg void OnBnClickedRadioWdCmdUp();
	afx_msg void OnBnClickedRadioWdCmdDown();
	afx_msg void OnBnClickedButtonRudderConfirm();
	afx_msg void OnBnClickedCheckSpeedCmd();
	afx_msg void OnBnClickedButtonSpeedCmd();
	afx_msg void OnBnClickedCheckCtrShuibengEnable();
	afx_msg void OnBnClickedRadioStartShuibeng();
	afx_msg void OnBnClickedRadioStopShuibeng();
	
	long m_second_num;
};
