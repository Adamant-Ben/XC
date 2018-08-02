#pragma once


// CPage_cspz_yj_2 对话框
class CXiaoBiLiDlg;
class CPage_cspz_yj_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CPage_cspz_yj_2)

public:
	CPage_cspz_yj_2(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage_cspz_yj_2();
	CXiaoBiLiDlg* m_pDlg;
// 对话框数据
	enum { IDD = IDD_DIALOG_CSPZ_YJ_2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCspzYj2();
	BYTE m_emu_micro;
	BYTE m_emu_schedule_number;
	float m_vehicle_headingspeed_highrate;
	float m_vehicle_headingspeed_mediumrate;
	short m_fairwater_rudder_stop_angle;
	short m_fairwater_rudder_full_angle_highrate;
	short m_fairwater_rudder_full_angle_lowrate;
	short m_fairwater_rudder_full_angle_mediumrate;
	short m_orentation_rudder_stop_angle;
	short m_orientation_rudder_full_angle_highrate;
	short m_orientation_rudder_full_angle_lowrate;
	short m_orientation_rudder_full_angle_mediumrate;
	short m_leftrear_rudder_stop_angle;
	short m_leftrear_rudder_full_angle_highrate;
	short m_leftrear_rudder_full_angle_lowrate;
	short m_leftrear_rudder_full_angle_mediumrate;
	short m_rightrear_rudder_stop_angle;
	short m_rightrear_rudder_full_angle_highrate;
	short m_rightrear_rudder_full_angle_lowrate;
	short m_rightrear_rudder_full_angle_mediumrate;
	short m_fairwater_rudder_stop_vehicle_acoustic;
	short m_leftrear_rudder_stop_vehicle_acoustic;
	short m_orientation_rudder_stop_vehicle_acoustic;
	short m_rightrear_rudder_stop_vehicle_acoustic;
	short m_fairwater_selftest_rudder_full_angle_highrate;
	short m_fairwater_selftest_rudder_full_angle_lowrate;
	short m_fairwater_selftest_rudder_full_angle_mediumrate;
	short m_fairwater_selftest_rudder_stop_angle;
	short m_orientation_selftest_rudder_rise_angle;
	short m_orientation_selftest_rudder_stop_angle;
	short m_rightrear_selftest_rudder_stop_angle;
	short m_rightrear_selftest_rudder_full_angle_highrate;
	short m_rightrear_selftest_rudder_full_angle_mediumrate;
	short m_leftrear_selftest_rudder_full_angle_highrate;
	short m_leftrear_selftest_rudder_full_angle_lowrate;
	short m_leftrear_selftest_rudder_full_angle_mediumrate;
	short m_leftrear_selftest_rudder_stop_angle;
	afx_msg void OnEnChangeEditRightrearRudderFullAngleLowrate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
