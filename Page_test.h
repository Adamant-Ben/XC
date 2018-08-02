#pragma once


// CPage_test 对话框
class CXiaoBiLiDlg;
class CPage_test : public CDialogEx
{
	DECLARE_DYNAMIC(CPage_test)

public:
	CPage_test(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage_test();
	CXiaoBiLiDlg* m_pDlg;
// 对话框数据
	enum { IDD = IDD_DIALOG9 };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_gps_data;
	void ShowData();
	CString m_usbl_data;
	int m_gongkuang;
	int m_moshi;
	afx_msg void OnBnClickedButton();
	int m_binpinqi_reset;
//	BOOL m_bianpinqi_start;
	int m_bianpinqi_start;
	int m_cable;
	int m_camera1;
	int m_camera2;
	int m_camera3;
	int m_chaoshen;
	int m_float;
	int m_gasbag;
	int m_jueyuan;
	int m_loushui;
	int m_motor1;
	int m_motor2;
//	CButton m_motor3;
	int m_motor3;
	int m_motor4;
	int m_power1;
//	int m_power;
	int m_power2;
	int m_power3;
	int m_power4;
	int m_power5;
	int m_qiangao;
	int m_stop;
	int m_yingjiganyu;
	int m_bianpinqi_jiting;
public:
	afx_msg void OnBnClickedCheckSchTest();
	void FUZHI_SCH_SO1_TEST();

	CString m_wxd_data;
	afx_msg void OnBnClickedButtonSendWxd();
//	BOOL m_wxdrecv_flag;
	afx_msg void OnBnClickedCheckRecv();
	BOOL m_recvwxd_flag;
	BOOL m_wxd_detect;
	afx_msg void OnBnClickedCheckWxdDetect();
	double JINGWEIDU_TO_XY(double jingdu,double weidu,double start_jingdu,double start_weidu); //经纬度转化为大地坐标系X Y
	double Angle(double jingdu,double weidu,double start_jingdu,double start_weidu); //计算方位角
	afx_msg void OnBnClickedCheckTxDistance();
	BOOL m_distance_flag;
	CString m_angle;
	CString m_distance;
	double s_jingdu;   //水上GPS经度
	double s_weidu;    //水上GPS纬度
	double jingdu;     //自航模经纬度
	double weidu;
//	afx_msg void OnTimeChange();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEdit5();
//	CEdit m_show_weidu;
//	double m_show_weidu;
	CString m_show_jingdu;
	CString m_show_weidu;
	double m_weidu_set;
	double m_jingdu_set;
	CString m_real_distance;
//	float m_x;
//	float m_y;
	CString m_y;
	CString m_x;
	CString m_fangwei;
	afx_msg void OnBnClickedButtonSet();
	CString m_distance_jizhan;
	float distance_sum;
	float jingdu_now;
	float weidu_now;
	float jingdu_last;
	float weidu_last;


	afx_msg void OnBnClickedButtonReset();
	double m_m_weidu_set2;
	double m_jingdu_set2;
	afx_msg void OnBnClickedButtonQingling();
	afx_msg void OnBnClickedButtonSet2();
//	CEdit m_distance_base2;
	CString m_diastance_base2;
	afx_msg void OnBnClickedButtonSet3();
	afx_msg void OnBnClickedButtonSet4();
	double m_base_lat;
	double m_base_lon;
	BOOL m_speed_limit_flag;
	BOOL m_speed_ctr_flag;
	short m_speed_limit_n;
	short m_speed_limit_p;
	short m_speed_gradient;
	afx_msg void OnBnClickedCheckSpeedLimit();
	afx_msg void OnBnClickedCheckSpeedGradientCtr();
	afx_msg void OnBnClickedButtonSpeedLimitComfirm();
	afx_msg void OnBnClickedButtonSpeedGradientConfirm();
};
