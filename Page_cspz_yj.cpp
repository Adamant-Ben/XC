// Page_cspz_yj.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page_cspz_yj.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include "Pag_Password.h"

// CPage_cspz_yj 对话框

IMPLEMENT_DYNAMIC(CPage_cspz_yj, CDialogEx)

CPage_cspz_yj::CPage_cspz_yj(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage_cspz_yj::IDD, pParent)
{
	m_pDlg=pDlg;
	m_is_debug_to_auto_emu_excute = 1;
	m_is_debug_to_acoustic_emu_excute = 1;
	m_depth_sensor_length = 13;
	//m_is_debug_to_auto_emu_excute_either_mode = 1;
	m_danger_depth_max = 30;
	m_danger_depth_longtime = 20;
	m_danger_height_head_max = 10;
	m_danger_height_rear_max = 10;
	m_pitch_extremely_danger = -25;
	m_pitch_less_danger = -20;
	m_pitch_less_danger_counttime_max = 10;
	m_danger_depth_change_counttime_max = 5;
	m_danger_left_sonar_distance = 0;
	m_danger_straight_sonar_distance = 0;
	m_dange_right_sonar_distance = 0;
	m_rise_rudder_noeffect_to_airbag_maxperiod = 5;
	m_rise_rudder_noeffect_to_airbag_maxcount = 3;
	m_airbag_noeffect_to_emerg_line_maxperiod = 5;
	m_airbag_inflate_time = 40;
	m_airbag_inflate_finish_time = 38;
	m_airbag_inflate_finish_time_remote = 6;
	m_release_emergencyline_time = 30;
	m_danger_depth_change_per_period = 0.4f;
	m_rise_rudder_depth_decrease_in_given_time = 1.0f;
	m_airbag_depth_decrease_during_inflate = 5.0f;
	m_airbag_depth_decrease_in_given_time = 1.0f;
	m_uwmu_macro_auto = 1500;
	m_uwmu_macro_remote = 15000;
	m_uwmu_micro_auto = 100;
	m_uwmu_micro_remote = 1000;
	m_awmu_selftest_remote = 2000;
	m_acoustic_feedback_auto = 15000;
	m_acoustic_feedback_emergency = 15000;
	m_remote_depthSensorDangerToEmergency = 10;
	m_remote_headheightSensorDangerToEmergency = 10;
	m_remote_rearheight_SensorDangerToEmergency = 10;
	m_emu_macro = 110;
	m_remote_longtime_no_any_msg = 15000;

}

CPage_cspz_yj::~CPage_cspz_yj()
{
}

void CPage_cspz_yj::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IS_DEBUG_TO_AUTO_EMU_EXCUTE, m_is_debug_to_auto_emu_excute);
	DDX_Text(pDX, IDC_EDIT_IS_DEBUG_TO_ACOUSTIC_EMU_EXCUTE, m_is_debug_to_acoustic_emu_excute);
	DDX_Text(pDX, IDC_EDIT_DEPTH_SENSOR_LENGTH, m_depth_sensor_length);
	//  DDX_Text(pDX, IDC_EDIT_IS_DEBUG_TO_AUTO_EMU_EXCUTE_EITHER_MODE, m_is_debug_to_auto_emu_excute_either_mode);
	DDX_Text(pDX, IDC_EDIT_DANGER_DEPTH_MAX, m_danger_depth_max);
	DDX_Text(pDX, IDC_EDIT_DANGER_DEPTH_LONGTIME, m_danger_depth_longtime);
	DDX_Text(pDX, IDC_EDIT_DANGER_HEIGHT_HEAD_MAX, m_danger_height_head_max);
	DDX_Text(pDX, IDC_EDIT_DANGER_HEIGHT_REAR_MAX, m_danger_height_rear_max);
	//  DDX_Text(pDX, IDC_EDIT_PITCH_EXTREMELY_DANGER, m_pitch_extremely_danger);
	//  DDX_Text(pDX, IDC_EDIT_PITCH_LESS_DANGER, m_pitch_less_danger);
	DDX_Text(pDX, IDC_EDIT_PITCH_LESS_DANGER_COUNTTIME_MAX, m_pitch_less_danger_counttime_max);
	DDX_Text(pDX, IDC_EDIT_DANGER_DEPTH_CHANGE_COUNTTIME_MAX, m_danger_depth_change_counttime_max);
	DDX_Text(pDX, IDC_EDIT_DANGER_LEFT_SONAR_DISTANCE, m_danger_left_sonar_distance);
	DDX_Text(pDX, IDC_EDIT_DANGER_STRAIGHT_SONAR_DISTANCE, m_danger_straight_sonar_distance);
	DDX_Text(pDX, IDC_EDIT_DANGE_RIGHT_SONAR_DISTANCE, m_dange_right_sonar_distance);
	DDX_Text(pDX, IDC_EDIT_RISE_RUDDER_NOEFFECT_TO_AIRBAG_MAXPERIOD, m_rise_rudder_noeffect_to_airbag_maxperiod);
	DDX_Text(pDX, IDC_EDIT_RISE_RUDDER_NOEFFECT_TO_AIRBAG_MAXCOUNT, m_rise_rudder_noeffect_to_airbag_maxcount);
	DDX_Text(pDX, IDC_EDIT_AIRBAG_NOEFFECT_TO_EMERG_LINE_MAXPERIOD, m_airbag_noeffect_to_emerg_line_maxperiod);
	DDX_Text(pDX, IDC_EDIT_AIRBAG_INFLATE_TIME, m_airbag_inflate_time);
	DDX_Text(pDX, IDC_EDIT_AIRBAG_INFLATE_FINISH_TIME, m_airbag_inflate_finish_time);
	DDX_Text(pDX, IDC_EDIT_AIRBAG_INFLATE_FINISH_TIME_REMOTE, m_airbag_inflate_finish_time_remote);
	DDX_Text(pDX, IDC_EDIT_RELEASE_EMERGENCYLINE_TIME, m_release_emergencyline_time);
	DDX_Text(pDX, IDC_EDIT_DANGER_DEPTH_CHANGE_PER_PERIOD, m_danger_depth_change_per_period);
	DDX_Text(pDX, IDC_EDIT_RISE_RUDDER_DEPTH_DECREASE_IN_GIVEN_TIME, m_rise_rudder_depth_decrease_in_given_time);
	DDX_Text(pDX, IDC_EDIT_AIRBAG_DEPTH_DECREASE_DURING_INFLATE, m_airbag_depth_decrease_during_inflate);
	DDX_Text(pDX, IDC_EDIT_AIRBAG_DEPTH_DECREASE_IN_GIVEN_TIME, m_airbag_depth_decrease_in_given_time);
	DDX_Text(pDX, IDC_EDIT_UWMU_macro_auto, m_uwmu_macro_auto);
	DDX_Text(pDX, IDC_EDIT_UWMU_macro_remote, m_uwmu_macro_remote);
	DDX_Text(pDX, IDC_EDIT_UWMU_micro_auto, m_uwmu_micro_auto);
	DDX_Text(pDX, IDC_EDIT_UWMU_micro_remote, m_uwmu_micro_remote);
	DDX_Text(pDX, IDC_EDIT_AWMU_selftest_remote, m_awmu_selftest_remote);
	DDX_Text(pDX, IDC_EDIT_acoustic_feedback_auto, m_acoustic_feedback_auto);
	DDX_Text(pDX, IDC_EDIT_acoustic_feedback_emergency, m_acoustic_feedback_emergency);
	//  DDX_Text(pDX, IDC_EDIT_REMOTE_LONGTIME_NO_ANY_MSG, m_remote_longtime_no_ang_msg);
	//  DDX_Text(pDX, IDC_EDIT_remote_depthSensorDangerToEmergency, m_remote_depthSensorDangerToEmergency);
	//  DDX_Text(pDX, IDC_EDIT_remote_headheightSensorDangerToEmergency, m_remote_headheightSensorDangerToEmergency);
	DDX_Text(pDX, IDC_EDIT_remote_depthSensorDangerToEmergency, m_remote_depthSensorDangerToEmergency);
	DDX_Text(pDX, IDC_EDIT_remote_headheightSensorDangerToEmergency, m_remote_headheightSensorDangerToEmergency);
	DDX_Text(pDX, IDC_EDIT_remote_rearheightSensorDangerToEmergency, m_remote_rearheight_SensorDangerToEmergency);
	DDX_Text(pDX, IDC_EDIT_EMU_macro, m_emu_macro);
	DDX_Text(pDX, IDC_EDIT_REMOTE_LONGTIME_NO_ANY_MSG, m_remote_longtime_no_any_msg);


	DDX_Text(pDX, IDC_EDIT_PITCH_LESS_DANGER, m_pitch_less_danger);
	DDX_Text(pDX, IDC_EDIT_PITCH_EXTREMELY_DANGER, m_pitch_extremely_danger);
}


BEGIN_MESSAGE_MAP(CPage_cspz_yj, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CSPZ_YJ_1, &CPage_cspz_yj::OnBnClickedButtonCspzYj1)
END_MESSAGE_MAP()


// CPage_cspz_yj 消息处理程序


void CPage_cspz_yj::OnBnClickedButtonCspzYj1()
{
	// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	/*dlg.DoModal();
	dlg.SetFocus(dlg.gethw);*/
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			/*m_pDlg->pdata_0701->IS_DEBUG_TO_AUTO_EMU_EXCUTE=m_is_debug_to_auto_emu_excute;
			m_pDlg->pdata_0701->IS_DEBUG_TO_ACOUSTIC_EMU_EXCUTE=m_is_debug_to_acoustic_emu_excute;
			m_pDlg->pdata_0701->DEPTH_SENSOR_LENGTH=m_depth_sensor_length;
			m_pDlg->pdata_0701->DANGER_DEPTH_MAX=m_danger_depth_max;
			m_pDlg->pdata_0701->DANGER_DEPTH_LONGTIME=m_danger_depth_longtime;
			m_pDlg->pdata_0701->DANGER_HEIGHT_HEAD_MAX=m_danger_height_head_max;
			m_pDlg->pdata_0701->DANGER_HEIGHT_REAR_MAX=m_danger_height_rear_max;
			m_pDlg->pdata_0701->PITCH_LESS_DANGER=m_pitch_less_danger;
			m_pDlg->pdata_0701->PITCH_LESS_DANGER_COUNTTIME_MAX=m_pitch_less_danger_counttime_max;
			m_pDlg->pdata_0701->PITCH_EXTREMELY_DANGER=m_pitch_extremely_danger;
			m_pDlg->pdata_0701->DANGER_DEPTH_CHANGE_COUNTTIME_MAX=m_danger_depth_change_counttime_max;
			m_pDlg->pdata_0701->DANGER_LEFT_SONAR_DISTANCE=m_danger_left_sonar_distance;
			m_pDlg->pdata_0701->DANGE_RIGHT_SONAR_DISTANCE=m_dange_right_sonar_distance;
			m_pDlg->pdata_0701->DANGER_STRAIGHT_SONAR_DISTANCE=m_danger_straight_sonar_distance;
			m_pDlg->pdata_0701->RISE_RUDDER_NOEFFECT_TO_AIRBAG_MAXPERIOD=m_rise_rudder_noeffect_to_airbag_maxperiod;
			m_pDlg->pdata_0701->RISE_RUDDER_NOEFFECT_TO_AIRBAG_MAXCOUNT=m_rise_rudder_noeffect_to_airbag_maxcount;
			m_pDlg->pdata_0701->AIRBAG_NOEFFECT_TO_EMERG_LINE_MAXPERIOD=m_airbag_noeffect_to_emerg_line_maxperiod;
			m_pDlg->pdata_0701->AIRBAG_INFLATE_FINISH_TIME_REMOTE=m_airbag_inflate_finish_time_remote;
			m_pDlg->pdata_0701->AIRBAG_INFLATE_FINISH_TIME=m_airbag_inflate_finish_time;
			m_pDlg->pdata_0701->AIRBAG_INFLATE_TIME=m_airbag_inflate_time;
			m_pDlg->pdata_0701->RELEASE_EMERGENCYLINE_TIME=m_release_emergencyline_time;
			m_pDlg->pdata_0701->DANGER_DEPTH_CHANGE_PER_PERIOD=m_danger_depth_change_per_period;
			m_pDlg->pdata_0701->RISE_RUDDER_DEPTH_DECREASE_IN_GIVEN_TIME=m_rise_rudder_depth_decrease_in_given_time;
			m_pDlg->pdata_0701->AIRBAG_DEPTH_DECREASE_DURING_INFLATE=m_airbag_depth_decrease_during_inflate;
			m_pDlg->pdata_0701->AIRBAG_DEPTH_DECREASE_IN_GIVEN_TIME=m_airbag_depth_decrease_in_given_time;
			m_pDlg->pdata_0701->UWMU_macro_remote=m_uwmu_macro_remote;
			m_pDlg->pdata_0701->UWMU_micro_remote=m_uwmu_micro_remote;
			m_pDlg->pdata_0701->UWMU_macro_auto=m_uwmu_macro_auto;
			m_pDlg->pdata_0701->UWMU_micro_auto=m_uwmu_micro_auto;
			m_pDlg->pdata_0701->AWMU_selftest_remote=m_awmu_selftest_remote;
			m_pDlg->pdata_0701->acoustic_feedback_auto=m_acoustic_feedback_auto;
			m_pDlg->pdata_0701->acoustic_feedback_emergency=m_acoustic_feedback_emergency;
			m_pDlg->pdata_0701->REMOTE_LONGTIME_NO_ANY_MSG=m_remote_longtime_no_any_msg;
			m_pDlg->pdata_0701->remote_depthSensorDangerToEmergency=m_remote_depthSensorDangerToEmergency;
			m_pDlg->pdata_0701->remote_headheightSensorDangerToEmergency=m_remote_headheightSensorDangerToEmergency;
			m_pDlg->pdata_0701->remote_rearheightSensorDangerToEmergency=m_remote_rearheight_SensorDangerToEmergency;
			m_pDlg->pdata_0701->EMU_macro=m_emu_macro;*/
			MessageBox("参数确认成功");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}
}


BOOL CPage_cspz_yj::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
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

	return CDialogEx::PreTranslateMessage(pMsg);
}
