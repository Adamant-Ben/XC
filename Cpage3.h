#pragma once


// Cpage3 对话框
class CXiaoBiLiDlg;
class Cpage3 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage3)

public:
	Cpage3(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage3();
	CXiaoBiLiDlg* m_pDlg;
// 对话框数据
	enum { IDD = IDD_DIALOG4 };
public:
	void drawpicture(int m_image_ID, int m_image_num);
	int m_imagelist[3];
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_djcssq;
	CString m_dk;
	CString m_fxdyxw;
	CString m_ip;
	CString m_lym;
	CString m_lymm;
	CString m_wdyxw;
	CString m_wkdyxw;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedCheck1();
	BOOL m_start;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonFsWkd();
	afx_msg void OnBnClickedButtonCcWkd();
	afx_msg void OnBnClickedButtonFsFxd();
	afx_msg void OnBnClickedButtonCcFxd();
	afx_msg void OnBnClickedButtonFsZwd();
	afx_msg void OnBnClickedButtonCcZwd();
	afx_msg void OnBnClickedButtonFsYwd();
	afx_msg void OnBnClickedButtonCcYwd();
	float m_kd_fxd;
	float m_kd_wkd;
	float m_kd_ywd;
	float m_kd_zwd;
	float m_ki_fxd;
	float m_ki_wkd;
	float m_ki_ywd;
	float m_ki_zwd;
	float m_kp_fxd;
	float m_kp_wkd;
	float m_kp_ywd;
	float m_kp_zwd;
	int m_sx_wkd;
	int m_sx_fxd;
	int m_sx_ywd;
	int m_sx_zwd;
	int m_xx_fxd;
	int m_xx_wkd;
	int m_xx_ywd;
	int m_xx_zwd;
//	BOOL m_cspzFlag;
	bool m_wkdcspzFlag;
	bool m_fxdcspzFlag;
	bool m_zwdcspzFlag;
	bool m_ywdcspzFlag;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
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
	CString m_emergencyunit;
//	CString m_errorthreshold;
	CString m_defaultmode;
	CString m_datastorageunit;
	CString m_clockrate;
	CString m_channelno_1;
	CString m_channelno_0;
	CString m_cardno;
	CString m_boardno_1;
	CString m_boardno_0;
	CString m_baudrate_1;
	CString m_baudrate_0;
	CString m_baudrate;
	CString m_abovewatermaster;
	CString m_abovewatermasterwifi;
	CString m_acceptancecode;
	CString m_acceptancemask;
	afx_msg void OnBnClickedButtonCspzSxzk();
	CString m_errorthreshhold;
	afx_msg void OnBnClickedCheckCspzSch();
	BOOL m_cspz_sch;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//afx_msg void OnBnClickedButtonSpeedLimit();
	//short m_speed_limit;
	//BOOL m_speed_limit_flag;
	//afx_msg void OnBnClickedCheckSpeedLimitEnable();
	//short m_speed_limit2;
	//afx_msg void OnBnClickedButtonRudderCtr();
	//short m_fairwater_rudder;
	//short m_direction_rudder;
	//short m_leftright_rudder;
	//BOOL m_rudder_ctr_flag;
	//afx_msg void OnBnClickedCheckRudderCtrEnable();
	//BOOL m_fx_rudder_ctr_flag;
	//BOOL m_zy_rudder_ctr_flag;
	//afx_msg void OnBnClickedCheckFxRudderCtrEnable();
	//afx_msg void OnBnClickedCheckZyRudderCtrEnable3();
	//BOOL m_speed_ctr_flag;
	//BOOL m_speed_awmu_cmd_flag;
	//short m_speed_tidu;
	//short m_awmu_speed_cmd;
	//afx_msg void OnBnClickedCheckSpeedCtr();
	//afx_msg void OnBnClickedCheckSpeedAwmuCmd();
	//afx_msg void OnBnClickedButtonSpeedTidu();
	//afx_msg void OnBnClickedButtonSpeedAwmuCmd();
	//CString m_djsszs2;
	//afx_msg void OnBnClickedRadioWk();
	//BOOL m_fxd;
	//BOOL m_wkd;
	//BOOL m_zywd;
	//short m_leftright_rudder2;
	//short m_direction_rudder2;
	//short m_fairwater_rudder2;
	//short p_wkd;
	//short p_fxd;
	//short p_zywd;

	//afx_msg void OnBnClickedRadio2();
	//afx_msg void OnBnClickedRadioFx();
	//afx_msg void OnBnClickedRadio4();
	//afx_msg void OnBnClickedRadioZywd();
	//afx_msg void OnBnClickedRadio6();
	//void UpdateInf();
	//float m_wkd_angle;
	//float m_fxd_angle;
	//float m_zywd_angle;
	//long m_second_num;
	//afx_msg void OnBnClickedCheckShuibengEnable();
	//BOOL m_shuibeng_ctr_flag;  //水上主控界面水泵控制使能
	//BOOL m_shuibeng;  //单选按钮序号
	//BOOL m_shuibeng_command; //水泵控制指令
	//BOOL m_shuibeng_state; //水泵状态反馈
	//afx_msg void OnBnClickedRadioShuibnengStart();
	//afx_msg void OnBnClickedRadioShuibengStop();
};

typedef struct 
{
	unsigned char pktHead1;
	char pktHead2;
	unsigned char rudderIndex;
	float kp;
	float ki;
	float kd;
	int upperLimit;
	int lowerLimit;
	unsigned short crcCheck;
	unsigned char pktEnd;
}RUDDER_PARAMETER;

typedef union
{
	float f;
	BYTE by[4];
}BAF;

typedef union
{
	int i;
	BYTE by[4];
}BAI;