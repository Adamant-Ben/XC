#pragma once


// Cpage_cspz_yj_3 对话框
class CXiaoBiLiDlg;
class Cpage_cspz_yj_3 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_cspz_yj_3)

public:
	Cpage_cspz_yj_3(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage_cspz_yj_3();
	CXiaoBiLiDlg* m_pDlg;
// 对话框数据
	enum { IDD = IDD_DIALOG_CSPZ_YJ_3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	short m_rightrear_selftest_rudder_full_angle_lowrate;
	BYTE m_left_rearrudder_stuck_diveangle;
	BYTE m_right_rearrudder_stuck_diveangle;
	BYTE m_fixed_selftest_thrust_speed_lowbyte_highrate;
	short m_lithium_alarm_limit_thrust_speed_limit;
	short m_thrusr_high_temp_alarm;
	short m_depth_sensor_calibrt_bias;
	short m_head_height_sensor_calibrt_bias;
	short m_rear_height_sensor_calibrt_bias;
	BYTE m_acoustic_stop_vehicle_thrusr_speed_highbyte;
	BYTE m_acoustic_stop_vehicle_thrusr_speed_lowbyte;
	BYTE m_fixed_selftest_thrust_speed_highbyte_highrate;
	BYTE m_fixed_selftest_thrusr_speed_highbyte_lowrate;
	BYTE m_fixed_selftest_thrusr_speed_highbyte_mediumrate;
	BYTE m_fixed_selftest_thrust_speed_lowbyte_lowrate;
	BYTE m_fixed_selftest_thrust_speed_lowbyte_mediumrate;
	BYTE m_fixed_thrust_speed_highbyte_highrate;
	BYTE m_fixed_thrust_speed_highbyte_lowrate;
	BYTE m_fixed_thrust_speed_highbyte_mediumrate;
	BYTE m_fixed_thrust_speed_lowbyte_highrate;
	BYTE m_fixed_thrust_speed_lowbyte_lowrate;
	BYTE m_fixed_thrust_speed_lowbyte_mediumrate;
	BYTE m_lithium_alarm_limit_thrust_speed_highbyte;
	BYTE m_lithium_alarm_limit_thrust_speed_lowbyte;
	BYTE m_low_battery_alarm_thrust_speed_highbyte;
	BYTE m_low_battery_alarm_thrust_speed_lowbyte;
	BYTE m_power_distribute_system_fault_thrust_speed_highbyte;
	BYTE m_power_distribute_system_fault_thrust_speed_lowbyte;
	BYTE m_stop_selftest_thrust_speed_highbyte;
	BYTE m_stop_selftest_thrust_speed_lowbyte;
	BYTE m_stop_thrust_speed_highbyte;
	BYTE m_stop_thrust_speed_lowbyte;
	BYTE m_thrusr_high_temp_alarm_speed_highbyte;
	BYTE m_thrusr_high_temp_alarm_speed_lowbyte;
	BYTE m_is_debug_emergency_line_enable;
	BYTE m_is_debug_airbag_inflate_enable;
	BYTE m_is_debug_airbag_oil_valve_enable;
	float m_depth_to_stop_emergency_thrust;
	afx_msg void OnBnClickedButtonConfirm();
	afx_msg void OnBnClickedButtonSend();
	virtual BOOL OnInitDialog();
	void drawpicture(int m_image_ID, int m_image_num);
	int m_imagelist[3];
	void Draw();

	
	float m_depth_to_tell_uwmu_surface;
	float m_depth_to_release_emerline;
	BYTE m_line_release_allowed_time;
	int m_orentation_rudder_surface_angle;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
