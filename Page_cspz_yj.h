#pragma once


// CPage_cspz_yj 对话框
class CXiaoBiLiDlg;
class CPage_cspz_yj : public CDialogEx
{
	DECLARE_DYNAMIC(CPage_cspz_yj)

public:
	CPage_cspz_yj(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage_cspz_yj();
	CXiaoBiLiDlg* m_pDlg;
// 对话框数据
	enum { IDD = IDD_DIALOG_CSPZ_YJ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCspzYj1();
    BYTE m_is_debug_to_auto_emu_excute;
	BYTE m_is_debug_to_acoustic_emu_excute;
	BYTE m_depth_sensor_length;
//	BYTE m_is_debug_to_auto_emu_excute_either_mode;
	BYTE m_danger_depth_max;
	BYTE m_danger_depth_longtime;
	BYTE m_danger_height_head_max;
	BYTE m_danger_height_rear_max;
//	BYTE m_pitch_extremely_danger;
//	BYTE m_pitch_less_danger;
	BYTE m_pitch_less_danger_counttime_max;
	BYTE m_danger_depth_change_counttime_max;
	BYTE m_danger_left_sonar_distance;
	BYTE m_danger_straight_sonar_distance;
	BYTE m_dange_right_sonar_distance;
	BYTE m_rise_rudder_noeffect_to_airbag_maxperiod;
	BYTE m_rise_rudder_noeffect_to_airbag_maxcount;
	BYTE m_airbag_noeffect_to_emerg_line_maxperiod;
	BYTE m_airbag_inflate_time;
	BYTE m_airbag_inflate_finish_time;
	BYTE m_airbag_inflate_finish_time_remote;
	BYTE m_release_emergencyline_time;
	float m_danger_depth_change_per_period;
	float m_rise_rudder_depth_decrease_in_given_time;
	float m_airbag_depth_decrease_during_inflate;
	float m_airbag_depth_decrease_in_given_time;
	UINT m_uwmu_macro_auto;
	UINT m_uwmu_macro_remote;
	UINT m_uwmu_micro_auto;
	UINT m_uwmu_micro_remote;
	UINT m_awmu_selftest_remote;
	UINT m_acoustic_feedback_auto;
	UINT m_acoustic_feedback_emergency;
//	UINT m_remote_longtime_no_ang_msg;
//	UINT m_remote_depthSensorDangerToEmergency;
//	UINT m_remote_headheightSensorDangerToEmergency;
	BYTE m_remote_depthSensorDangerToEmergency;
	BYTE m_remote_headheightSensorDangerToEmergency;
	BYTE m_remote_rearheight_SensorDangerToEmergency;
	BYTE m_emu_macro;
	UINT m_remote_longtime_no_any_msg;
	
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	short m_pitch_less_danger;
	short m_pitch_extremely_danger;
};
