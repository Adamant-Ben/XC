// Cpage_cspz_yj_3.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Cpage_cspz_yj_3.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include "SessionSocket.h"
#include "Pag_Password.h"

// Cpage_cspz_yj_3 对话框

IMPLEMENT_DYNAMIC(Cpage_cspz_yj_3, CDialogEx)

Cpage_cspz_yj_3::Cpage_cspz_yj_3(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage_cspz_yj_3::IDD, pParent)
{
	m_pDlg=pDlg;
	m_rightrear_selftest_rudder_full_angle_lowrate = -150;
	m_left_rearrudder_stuck_diveangle = 10;
	m_right_rearrudder_stuck_diveangle = 10;
	m_lithium_alarm_limit_thrust_speed_limit = 7373;
	m_thrusr_high_temp_alarm = 16384;
	m_depth_sensor_calibrt_bias = 110;
	m_head_height_sensor_calibrt_bias = 1;
	m_rear_height_sensor_calibrt_bias = 1;
	m_acoustic_stop_vehicle_thrusr_speed_highbyte = 0;
	m_acoustic_stop_vehicle_thrusr_speed_lowbyte = 0;
	m_fixed_selftest_thrust_speed_highbyte_highrate = 4;
	m_fixed_selftest_thrusr_speed_highbyte_lowrate = 17;
	m_fixed_selftest_thrusr_speed_highbyte_mediumrate = 12;
	m_fixed_selftest_thrust_speed_lowbyte_lowrate = 17;
	m_fixed_selftest_thrust_speed_lowbyte_mediumrate = 205;
	m_fixed_selftest_thrust_speed_lowbyte_highrate = 68;
	m_fixed_thrust_speed_highbyte_highrate = 4;
	m_fixed_thrust_speed_highbyte_lowrate = 17;
	m_fixed_thrust_speed_highbyte_mediumrate = 12;
	m_fixed_thrust_speed_lowbyte_highrate = 68;
	m_fixed_thrust_speed_lowbyte_lowrate = 17;
	m_fixed_thrust_speed_lowbyte_mediumrate = 205;
	m_lithium_alarm_limit_thrust_speed_highbyte = 12;
	m_lithium_alarm_limit_thrust_speed_lowbyte = 205;
	m_low_battery_alarm_thrust_speed_highbyte = 12;
	m_low_battery_alarm_thrust_speed_lowbyte = 205;
	m_power_distribute_system_fault_thrust_speed_highbyte = 4;
	m_power_distribute_system_fault_thrust_speed_lowbyte = 68;
	m_stop_selftest_thrust_speed_highbyte = 0;
	m_stop_selftest_thrust_speed_lowbyte = 0;
	m_stop_thrust_speed_highbyte = 0;
	m_stop_thrust_speed_lowbyte = 0;
	m_thrusr_high_temp_alarm_speed_highbyte = 4;
	m_thrusr_high_temp_alarm_speed_lowbyte = 68;
	m_is_debug_emergency_line_enable = 1;
	m_is_debug_airbag_inflate_enable = 1;
	m_is_debug_airbag_oil_valve_enable = 1;
	m_depth_to_stop_emergency_thrust = 2;
	m_imagelist[0] = IDB_BITMAP_GRAY;
	m_imagelist[1] = IDB_BITMAP_GREEN;
	m_imagelist[2] = IDB_BITMAP_RED;


	m_depth_to_tell_uwmu_surface = 2.0;
	m_depth_to_release_emerline = 3.0;
	m_line_release_allowed_time = 2;
	m_orentation_rudder_surface_angle = 200;
}

Cpage_cspz_yj_3::~Cpage_cspz_yj_3()
{
}

void Cpage_cspz_yj_3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE, m_rightrear_selftest_rudder_full_angle_lowrate);
	DDX_Text(pDX, IDC_EDIT_LEFT_REARRUDDER_STUCK_DIVEANGLE, m_left_rearrudder_stuck_diveangle);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REARRUDDER_STUCK_DIVEANGLE, m_right_rearrudder_stuck_diveangle);
	DDX_Text(pDX, IDC_EDIT_FIXED_SELFTEST_THRUST_SPEED_LOWBYTE_HIGHRATE, m_fixed_selftest_thrust_speed_lowbyte_highrate);
	DDX_Text(pDX, IDC_EDIT_LITHIUM_ALARM_LIMIT_THRUST_SPEED_LIMIT, m_lithium_alarm_limit_thrust_speed_limit);
	DDX_Text(pDX, IDC_EDIT_THRUSR_HIGH_TEMP_ALARM, m_thrusr_high_temp_alarm);
	DDX_Text(pDX, IDC_EDIT_DEPTH_SENSOR_CALIBRT_BIAS, m_depth_sensor_calibrt_bias);
	DDX_Text(pDX, IDC_EDIT_HEAD_HEIGHT_SENSOR_CALIBRT_BIAS, m_head_height_sensor_calibrt_bias);
	DDX_Text(pDX, IDC_EDIT_REAR_HEIGHT_SENSOR_CALIBRT_BIAS, m_rear_height_sensor_calibrt_bias);
	DDX_Text(pDX, IDC_EDIT_ACOUSTIC_STOP_VEHICLE_THRUSR_SPEED_HIGHBYTE, m_acoustic_stop_vehicle_thrusr_speed_highbyte);
	DDX_Text(pDX, IDC_EDIT_ACOUSTIC_STOP_VEHICLE_THRUSR_SPEED_LOWBYTE, m_acoustic_stop_vehicle_thrusr_speed_lowbyte);
	DDX_Text(pDX, IDC_EDIT_FIXED_SELFTEST_THRUST_SPEED_HIGHBYTE_HIGHRATE, m_fixed_selftest_thrust_speed_highbyte_highrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_SELFTEST_THRUST_SPEED_HIGHBYTE_LOWRATE, m_fixed_selftest_thrusr_speed_highbyte_lowrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_SELFTEST_THRUST_SPEED_HIGHBYTE_MEDIUMRATE, m_fixed_selftest_thrusr_speed_highbyte_mediumrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_SELFTEST_THRUST_SPEED_LOWBYTE_LOWRATE, m_fixed_selftest_thrust_speed_lowbyte_lowrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_SELFTEST_THRUST_SPEED_LOWBYTE_MEDIUMRATE, m_fixed_selftest_thrust_speed_lowbyte_mediumrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_THRUST_SPEED_HIGHBYTE_HIGHRATE, m_fixed_thrust_speed_highbyte_highrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_THRUST_SPEED_HIGHBYTE_LOWRATE, m_fixed_thrust_speed_highbyte_lowrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_THRUST_SPEED_HIGHBYTE_MEDIUMRATE, m_fixed_thrust_speed_highbyte_mediumrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_THRUST_SPEED_LOWBYTE_HIGHRATE, m_fixed_thrust_speed_lowbyte_highrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_THRUST_SPEED_LOWBYTE_LOWRATE, m_fixed_thrust_speed_lowbyte_lowrate);
	DDX_Text(pDX, IDC_EDIT_FIXED_THRUST_SPEED_LOWBYTE_MEDIUMRATE, m_fixed_thrust_speed_lowbyte_mediumrate);
	DDX_Text(pDX, IDC_EDIT_LITHIUM_ALARM_LIMIT_THRUST_SPEED_HIGHBYTE, m_lithium_alarm_limit_thrust_speed_highbyte);
	DDX_Text(pDX, IDC_EDIT_LITHIUM_ALARM_LIMIT_THRUST_SPEED_LOWBYTE, m_lithium_alarm_limit_thrust_speed_lowbyte);
	DDX_Text(pDX, IDC_EDIT_LOW_BATTERY_ALARM_THRUST_SPEED_HIGHBYTE, m_low_battery_alarm_thrust_speed_highbyte);
	DDX_Text(pDX, IDC_EDIT_LOW_BATTERY_ALARM_THRUST_SPEED_LOWBYTE, m_low_battery_alarm_thrust_speed_lowbyte);
	DDX_Text(pDX, IDC_EDIT_POWER_DISTRIBUTE_SYSTEM_FAULT_THRUST_SPEED_HIGHBYTE, m_power_distribute_system_fault_thrust_speed_highbyte);
	DDX_Text(pDX, IDC_EDIT_POWER_DISTRIBUTE_SYSTEM_FAULT_THRUST_SPEED_LOWBYTE, m_power_distribute_system_fault_thrust_speed_lowbyte);
	DDX_Text(pDX, IDC_EDIT_STOP_SELFTEST_THRUST_SPEED_HIGHBYTE, m_stop_selftest_thrust_speed_highbyte);
	DDX_Text(pDX, IDC_EDIT_STOP_SELFTEST_THRUST_SPEED_LOWBYTE, m_stop_selftest_thrust_speed_lowbyte);
	DDX_Text(pDX, IDC_EDIT_STOP_THRUST_SPEED_HIGHBYTE, m_stop_thrust_speed_highbyte);
	DDX_Text(pDX, IDC_EDIT_STOP_THRUST_SPEED_LOWBYTE, m_stop_thrust_speed_lowbyte);
	DDX_Text(pDX, IDC_EDIT_THRUSR_HIGH_TEMP_ALARM_SPEED_HIGHBYTE, m_thrusr_high_temp_alarm_speed_highbyte);
	DDX_Text(pDX, IDC_EDIT_THRUSR_HIGH_TEMP_ALARM_SPEED_LOWBYTE, m_thrusr_high_temp_alarm_speed_lowbyte);
	DDX_Text(pDX, IDC_EDIT_IS_DEBUG_EMERGENCY_LINE_ENABLE, m_is_debug_emergency_line_enable);
	DDX_Text(pDX, IDC_EDIT_IS_DEBUG_AIRBAG_INFLATE_ENABLE, m_is_debug_airbag_inflate_enable);
	DDX_Text(pDX, IDC_EDIT_IS_DEBUG_AIRBAG_OIL_VALVE_ENABLE, m_is_debug_airbag_oil_valve_enable);
	DDX_Text(pDX, IDC_EDIT_DEPTH_TO_STOP_EMERGENCY_THRUST, m_depth_to_stop_emergency_thrust);
	DDX_Text(pDX, IDC_EDIT_DEPTH_TO_TELL_UWMU_SURFACE, m_depth_to_tell_uwmu_surface);
	DDX_Text(pDX, IDC_EDIT_DEPTH_TO_RELEASE_EMERLINE, m_depth_to_release_emerline);
	DDX_Text(pDX, IDC_EDIT_LINE_RELEASE_ALLOWED_TIME, m_line_release_allowed_time);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_RUDDER_SURFACE_ANGLE, m_orentation_rudder_surface_angle);
}


BEGIN_MESSAGE_MAP(Cpage_cspz_yj_3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRM, &Cpage_cspz_yj_3::OnBnClickedButtonConfirm)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &Cpage_cspz_yj_3::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// Cpage_cspz_yj_3 消息处理程序


void Cpage_cspz_yj_3::OnBnClickedButtonConfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			//参数配置页面1
			m_pDlg->pdata_0701->IS_DEBUG_TO_AUTO_EMU_EXCUTE=m_pDlg->page_cspz_yj->m_is_debug_to_auto_emu_excute;
			m_pDlg->pdata_0701->IS_DEBUG_TO_ACOUSTIC_EMU_EXCUTE=m_pDlg->page_cspz_yj->m_is_debug_to_acoustic_emu_excute;
			m_pDlg->pdata_0701->DEPTH_SENSOR_LENGTH=m_pDlg->page_cspz_yj->m_depth_sensor_length;
			m_pDlg->pdata_0701->DANGER_DEPTH_MAX=m_pDlg->page_cspz_yj->m_danger_depth_max;
			m_pDlg->pdata_0701->DANGER_DEPTH_LONGTIME=m_pDlg->page_cspz_yj->m_danger_depth_longtime;
			m_pDlg->pdata_0701->DANGER_HEIGHT_HEAD_MAX=m_pDlg->page_cspz_yj->m_danger_height_head_max;
			m_pDlg->pdata_0701->DANGER_HEIGHT_REAR_MAX=m_pDlg->page_cspz_yj->m_danger_height_rear_max;
			m_pDlg->pdata_0701->PITCH_LESS_DANGER=m_pDlg->page_cspz_yj->m_pitch_less_danger;
			m_pDlg->pdata_0701->PITCH_LESS_DANGER_COUNTTIME_MAX=m_pDlg->page_cspz_yj->m_pitch_less_danger_counttime_max;
			m_pDlg->pdata_0701->PITCH_EXTREMELY_DANGER=m_pDlg->page_cspz_yj->m_pitch_extremely_danger;
			m_pDlg->pdata_0701->DANGER_DEPTH_CHANGE_COUNTTIME_MAX=m_pDlg->page_cspz_yj->m_danger_depth_change_counttime_max;
			m_pDlg->pdata_0701->DANGER_LEFT_SONAR_DISTANCE=m_pDlg->page_cspz_yj->m_danger_left_sonar_distance;
			m_pDlg->pdata_0701->DANGE_RIGHT_SONAR_DISTANCE=m_pDlg->page_cspz_yj->m_dange_right_sonar_distance;
			m_pDlg->pdata_0701->DANGER_STRAIGHT_SONAR_DISTANCE=m_pDlg->page_cspz_yj->m_danger_straight_sonar_distance;
			m_pDlg->pdata_0701->RISE_RUDDER_NOEFFECT_TO_AIRBAG_MAXPERIOD=m_pDlg->page_cspz_yj->m_rise_rudder_noeffect_to_airbag_maxperiod;
			m_pDlg->pdata_0701->RISE_RUDDER_NOEFFECT_TO_AIRBAG_MAXCOUNT=m_pDlg->page_cspz_yj->m_rise_rudder_noeffect_to_airbag_maxcount;
			m_pDlg->pdata_0701->AIRBAG_NOEFFECT_TO_EMERG_LINE_MAXPERIOD=m_pDlg->page_cspz_yj->m_airbag_noeffect_to_emerg_line_maxperiod;
			m_pDlg->pdata_0701->AIRBAG_INFLATE_FINISH_TIME_REMOTE=m_pDlg->page_cspz_yj->m_airbag_inflate_finish_time_remote;
			m_pDlg->pdata_0701->AIRBAG_INFLATE_FINISH_TIME=m_pDlg->page_cspz_yj->m_airbag_inflate_finish_time;
			m_pDlg->pdata_0701->AIRBAG_INFLATE_TIME=m_pDlg->page_cspz_yj->m_airbag_inflate_time;
			m_pDlg->pdata_0701->RELEASE_EMERGENCYLINE_TIME=m_pDlg->page_cspz_yj->m_release_emergencyline_time;
			m_pDlg->pdata_0701->DANGER_DEPTH_CHANGE_PER_PERIOD=m_pDlg->page_cspz_yj->m_danger_depth_change_per_period;
			m_pDlg->pdata_0701->RISE_RUDDER_DEPTH_DECREASE_IN_GIVEN_TIME=m_pDlg->page_cspz_yj->m_rise_rudder_depth_decrease_in_given_time;
			m_pDlg->pdata_0701->AIRBAG_DEPTH_DECREASE_DURING_INFLATE=m_pDlg->page_cspz_yj->m_airbag_depth_decrease_during_inflate;
			m_pDlg->pdata_0701->AIRBAG_DEPTH_DECREASE_IN_GIVEN_TIME=m_pDlg->page_cspz_yj->m_airbag_depth_decrease_in_given_time;
			m_pDlg->pdata_0701->UWMU_macro_remote=m_pDlg->page_cspz_yj->m_uwmu_macro_remote;
			m_pDlg->pdata_0701->UWMU_micro_remote=m_pDlg->page_cspz_yj->m_uwmu_micro_remote;
			m_pDlg->pdata_0701->UWMU_macro_auto=m_pDlg->page_cspz_yj->m_uwmu_macro_auto;
			m_pDlg->pdata_0701->UWMU_micro_auto=m_pDlg->page_cspz_yj->m_uwmu_micro_auto;
			m_pDlg->pdata_0701->AWMU_selftest_remote=m_pDlg->page_cspz_yj->m_awmu_selftest_remote;
			m_pDlg->pdata_0701->acoustic_feedback_auto=m_pDlg->page_cspz_yj->m_acoustic_feedback_auto;
			m_pDlg->pdata_0701->acoustic_feedback_emergency=m_pDlg->page_cspz_yj->m_acoustic_feedback_emergency;
			m_pDlg->pdata_0701->REMOTE_LONGTIME_NO_ANY_MSG=m_pDlg->page_cspz_yj->m_remote_longtime_no_any_msg;
			m_pDlg->pdata_0701->remote_depthSensorDangerToEmergency=m_pDlg->page_cspz_yj->m_remote_depthSensorDangerToEmergency;
			m_pDlg->pdata_0701->remote_headheightSensorDangerToEmergency=m_pDlg->page_cspz_yj->m_remote_headheightSensorDangerToEmergency;
			m_pDlg->pdata_0701->remote_rearheightSensorDangerToEmergency=m_pDlg->page_cspz_yj->m_remote_rearheight_SensorDangerToEmergency;
			m_pDlg->pdata_0701->EMU_macro=m_pDlg->page_cspz_yj->m_emu_macro;
			//参数配置页面2
			m_pDlg->pdata_0701->EMU_micro=m_pDlg->page_cspz_yj_2->m_emu_micro;
			m_pDlg->pdata_0701->EMU_SCHEDULE_NUMBER=m_pDlg->page_cspz_yj_2->m_emu_schedule_number;
			m_pDlg->pdata_0701->VEHICLE_HEADINGSPEED_HIGHRATE=m_pDlg->page_cspz_yj_2->m_vehicle_headingspeed_highrate;
			m_pDlg->pdata_0701->VEHICLE_HEADINGSPEED_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_vehicle_headingspeed_mediumrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_fairwater_rudder_stop_angle;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_FULL_ANGLE_HIGHRATE=m_pDlg->page_cspz_yj_2->m_fairwater_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_FULL_ANGLE_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_fairwater_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_FULL_ANGLE_LOWRATE=m_pDlg->page_cspz_yj_2->m_fairwater_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_orentation_rudder_stop_angle;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_FULL_ANGLE_HIGHRATE=m_pDlg->page_cspz_yj_2->m_orientation_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_FULL_ANGLE_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_orientation_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_FULL_ANGLE_LOWRATE=m_pDlg->page_cspz_yj_2->m_orientation_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_leftrear_rudder_stop_angle;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_FULL_ANGLE_HIGHRATE=m_pDlg->page_cspz_yj_2->m_leftrear_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_FULL_ANGLE_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_leftrear_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_FULL_ANGLE_LOWRATE=m_pDlg->page_cspz_yj_2->m_leftrear_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_rightrear_rudder_stop_angle;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_FULL_ANGLE_HIGHRATE=m_pDlg->page_cspz_yj_2->m_rightrear_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_FULL_ANGLE_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_rightrear_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_FULL_ANGLE_LOWRATE=m_pDlg->page_cspz_yj_2->m_rightrear_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_STOP_VEHICLE_ACOUSTIC=m_pDlg->page_cspz_yj_2->m_fairwater_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_STOP_VEHICLE_ACOUSTIC=m_pDlg->page_cspz_yj_2->m_orientation_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_STOP_VEHICLE_ACOUSTIC=m_pDlg->page_cspz_yj_2->m_leftrear_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_STOP_VEHICLE_ACOUSTIC=m_pDlg->page_cspz_yj_2->m_rightrear_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE=m_pDlg->page_cspz_yj_2->m_fairwater_selftest_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE=m_pDlg->page_cspz_yj_2->m_fairwater_selftest_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_fairwater_selftest_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_fairwater_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->ORENTATION_SELFTEST_RUDDER_RISE_ANGLE=m_pDlg->page_cspz_yj_2->m_orientation_selftest_rudder_rise_angle;
			m_pDlg->pdata_0701->ORENTATION_SELFTEST_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_orientation_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE=m_pDlg->page_cspz_yj_2->m_leftrear_selftest_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE=m_pDlg->page_cspz_yj_2->m_leftrear_selftest_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_leftrear_selftest_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_leftrear_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->RIGHTREAR_SELFTEST_RUDDER_STOP_ANGLE=m_pDlg->page_cspz_yj_2->m_rightrear_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE=m_pDlg->page_cspz_yj_2->m_rightrear_selftest_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE=m_pDlg->page_cspz_yj_2->m_rightrear_selftest_rudder_full_angle_mediumrate;
			//参数配置页面3
			m_pDlg->pdata_0701->RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE=m_rightrear_selftest_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->LEFT_REARRUDDER_STUCK_DIVEANGLE=m_left_rearrudder_stuck_diveangle;
			m_pDlg->pdata_0701->RIGHT_REARRUDDER_STUCK_DIVEANGLE=m_right_rearrudder_stuck_diveangle;
			m_pDlg->pdata_0701->FIXED_THRUST_SPEED_HIGHBYTE_HIGHRATE=m_fixed_thrust_speed_highbyte_highrate;
			m_pDlg->pdata_0701->FIXED_THRUST_SPEED_HIGHBYTE_LOWRATE=m_fixed_thrust_speed_highbyte_lowrate;
			m_pDlg->pdata_0701->FIXED_THRUST_SPEED_HIGHBYTE_MEDIUMRATE=m_fixed_thrust_speed_highbyte_mediumrate;
			m_pDlg->pdata_0701->FIXED_THRUST_SPEED_LOWBYTE_HIGHRATE=m_fixed_thrust_speed_lowbyte_highrate;
			m_pDlg->pdata_0701->FIXED_THRUST_SPEED_LOWBYTE_LOWRATE=m_fixed_thrust_speed_lowbyte_lowrate;
			m_pDlg->pdata_0701->FIXED_THRUST_SPEED_LOWBYTE_MEDIUMRATE=m_fixed_thrust_speed_lowbyte_mediumrate;
			m_pDlg->pdata_0701->STOP_THRUST_SPEED_HIGHBYTE=m_stop_thrust_speed_highbyte;
			m_pDlg->pdata_0701->STOP_THRUST_SPEED_LOWBYTE=m_stop_thrust_speed_lowbyte;
			m_pDlg->pdata_0701->POWER_DISTRIBUTE_SYSTEM_FAULT_THRUST_SPEED_HIGHBYTE=m_power_distribute_system_fault_thrust_speed_highbyte;
			m_pDlg->pdata_0701->POWER_DISTRIBUTE_SYSTEM_FAULT_THRUST_SPEED_LOWBYTE=m_power_distribute_system_fault_thrust_speed_lowbyte;
			m_pDlg->pdata_0701->LOW_BATTERY_ALARM_THRUST_SPEED_HIGHBYTE=m_low_battery_alarm_thrust_speed_highbyte;
			m_pDlg->pdata_0701->LOW_BATTERY_ALARM_THRUST_SPEED_LOWBYTE=m_low_battery_alarm_thrust_speed_lowbyte;
			m_pDlg->pdata_0701->LITHIUM_ALARM_LIMIT_THRUST_SPEED_HIGHBYTE=m_lithium_alarm_limit_thrust_speed_highbyte;
			m_pDlg->pdata_0701->LITHIUM_ALARM_LIMIT_THRUST_SPEED_LOWBYTE=m_lithium_alarm_limit_thrust_speed_lowbyte;
			m_pDlg->pdata_0701->THRUSR_HIGH_TEMP_ALARM_SPEED_HIGHBYTE=m_thrusr_high_temp_alarm_speed_highbyte;
			m_pDlg->pdata_0701->THRUSR_HIGH_TEMP_ALARM_SPEED_LOWBYTE=m_thrusr_high_temp_alarm_speed_lowbyte;
			m_pDlg->pdata_0701->LITHIUM_ALARM_LIMIT_THRUST_SPEED_LIMIT=m_lithium_alarm_limit_thrust_speed_limit;
			m_pDlg->pdata_0701->THRUSR_HIGH_TEMP_ALARM=m_thrusr_high_temp_alarm;
			m_pDlg->pdata_0701->FIXED_SELFTEST_THRUST_SPEED_HIGHBYTE_HIGHRATE=m_fixed_selftest_thrust_speed_highbyte_highrate;
			m_pDlg->pdata_0701->FIXED_SELFTEST_THRUST_SPEED_HIGHBYTE_MEDIUMRATE=m_fixed_selftest_thrusr_speed_highbyte_mediumrate;
			m_pDlg->pdata_0701->FIXED_SELFTEST_THRUST_SPEED_HIGHBYTE_LOWRATE=m_fixed_selftest_thrusr_speed_highbyte_lowrate;
			m_pDlg->pdata_0701->FIXED_SELFTEST_THRUST_SPEED_LOWBYTE_HIGHRATE=m_fixed_selftest_thrust_speed_lowbyte_highrate;
			m_pDlg->pdata_0701->FIXED_SELFTEST_THRUST_SPEED_LOWBYTE_MEDIUMRATE=m_fixed_selftest_thrust_speed_lowbyte_mediumrate;
			m_pDlg->pdata_0701->FIXED_SELFTEST_THRUST_SPEED_LOWBYTE_LOWRATE=m_fixed_selftest_thrust_speed_lowbyte_lowrate;
			m_pDlg->pdata_0701->STOP_SELFTEST_THRUST_SPEED_HIGHBYTE=m_stop_selftest_thrust_speed_highbyte;
			m_pDlg->pdata_0701->STOP_SELFTEST_THRUST_SPEED_LOWBYTE=m_stop_selftest_thrust_speed_lowbyte;
			m_pDlg->pdata_0701->ACOUSTIC_STOP_VEHICLE_THRUSR_SPEED_HIGHBYTE=m_acoustic_stop_vehicle_thrusr_speed_highbyte;
			m_pDlg->pdata_0701->ACOUSTIC_STOP_VEHICLE_THRUSR_SPEED_LOWBYTE=m_acoustic_stop_vehicle_thrusr_speed_lowbyte;
			m_pDlg->pdata_0701->DEPTH_SENSOR_CALIBRT_BIAS=m_depth_sensor_calibrt_bias;
			m_pDlg->pdata_0701->HEAD_HEIGHT_SENSOR_CALIBRT_BIAS=m_head_height_sensor_calibrt_bias;
			m_pDlg->pdata_0701->REAR_HEIGHT_SENSOR_CALIBRT_BIAS=m_rear_height_sensor_calibrt_bias;
			m_pDlg->pdata_0701->IS_DEBUG_AIRBAG_INFLATE_ENABLE=m_is_debug_airbag_inflate_enable;
			m_pDlg->pdata_0701->IS_DEBUG_EMERGENCY_LINE_ENABLE=m_is_debug_emergency_line_enable;
			m_pDlg->pdata_0701->IS_DEBUG_AIRBAG_OIL_VALVE_ENABLE=m_is_debug_airbag_oil_valve_enable;
			m_pDlg->pdata_0701->DEPTH_TO_STOP_EMERGENCY_THRUST=m_depth_to_stop_emergency_thrust;
			m_pDlg->pdata_0701->DEPTH_TO_TELL_UWMU_SURFACE=m_depth_to_tell_uwmu_surface;
			m_pDlg->pdata_0701->DEPTH_TO_RELEASE_EMERLINE=m_depth_to_release_emerline;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_SURFACE_ANGLE=m_orentation_rudder_surface_angle;
			m_pDlg->pdata_0701->LINE_RELEASE_ALLOWED_TIME=m_line_release_allowed_time;
			GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
			drawpicture(IDC_EMU_CONFIG_LIGHT,0);
			MessageBox("参数确认成功");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}
}


void Cpage_cspz_yj_3::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDlg->FuZhi_EMU_0701();
	m_pDlg->SSYJSocket->Send(m_pDlg->sendata_0701,sizeof(AWMU_2_EMU_EA_PARAM_CONFIG)+3,0);
		/* CString str,strtemp;
	for(int i=0;i<sizeof(AWMU_2_EMU_EA_PARAM_CONFIG)+3;i++)
	{strtemp.Format("%02x ",m_pDlg->sendata_0701[i]);str+=strtemp;}
	MessageBox(str);*/
}


BOOL Cpage_cspz_yj_3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
	drawpicture(IDC_EMU_CONFIG_LIGHT,0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Cpage_cspz_yj_3::drawpicture(int m_image_ID, int m_image_num)
{
    CBitmap   bmp;  
	HBITMAP   hbmpold;
	bmp.LoadBitmap(m_imagelist[m_image_num]); 
	hbmpold=((CStatic *)GetDlgItem(m_image_ID))->SetBitmap((HBITMAP)bmp); 
	bmp.Detach();
    if(hbmpold!=NULL)
	{
		DeleteObject(hbmpold);
	}
	CRect rc;
	GetDlgItem(m_image_ID)->GetClientRect(&rc);
	InvalidateRect(&rc,false);
}

void Cpage_cspz_yj_3::Draw()
{
	drawpicture(IDC_EMU_CONFIG_LIGHT,1);
}

BOOL Cpage_cspz_yj_3::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
    {
        // 如果消息是键盘按下事件，且是Esc键，执行以下代码（什么都不做，你可以自己添加想要的代码）
        return TRUE;
    }
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        // 如果消息是键盘按下事件，且是Entert键，执行以下代码（什么都不做，你可以自己添加想要的代码）
        return TRUE;
    }

	return CDialogEx::PreTranslateMessage(pMsg);
}
