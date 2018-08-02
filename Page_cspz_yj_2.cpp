// Page_cspz_yj_2.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page_cspz_yj_2.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include "Pag_Password.h"

// CPage_cspz_yj_2 对话框

IMPLEMENT_DYNAMIC(CPage_cspz_yj_2, CDialogEx)

CPage_cspz_yj_2::CPage_cspz_yj_2(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage_cspz_yj_2::IDD, pParent)
{
	m_pDlg=pDlg;
	m_emu_micro = 12;
	m_emu_schedule_number = 7;
	m_vehicle_headingspeed_highrate = 5.0f;
	m_vehicle_headingspeed_mediumrate = 2.5f;
	m_fairwater_rudder_stop_angle = 0;
	m_fairwater_rudder_full_angle_highrate = 20;
	m_fairwater_rudder_full_angle_lowrate = 200;
	m_fairwater_rudder_full_angle_mediumrate = 50;
	m_orentation_rudder_stop_angle = 0;
	m_orientation_rudder_full_angle_highrate = 0;
	m_orientation_rudder_full_angle_lowrate = 0;
	m_orientation_rudder_full_angle_mediumrate = 0;
	m_leftrear_rudder_stop_angle = 0;
	m_leftrear_rudder_full_angle_highrate = -20;
	m_leftrear_rudder_full_angle_lowrate = -150;
	m_leftrear_rudder_full_angle_mediumrate = -50;
	m_rightrear_rudder_stop_angle = 0;
	m_rightrear_rudder_full_angle_highrate = -20;
	m_rightrear_rudder_full_angle_lowrate = -150;
	m_rightrear_rudder_full_angle_mediumrate = -50;
	m_fairwater_rudder_stop_vehicle_acoustic = 0;
	m_leftrear_rudder_stop_vehicle_acoustic = 0;
	m_orientation_rudder_stop_vehicle_acoustic = 0;
	m_rightrear_rudder_stop_vehicle_acoustic = 0;
	m_fairwater_selftest_rudder_full_angle_highrate = 20;
	m_fairwater_selftest_rudder_full_angle_lowrate = 200;
	m_fairwater_selftest_rudder_full_angle_mediumrate = 50;
	m_fairwater_selftest_rudder_stop_angle = 0;
	m_orientation_selftest_rudder_rise_angle = 0;
	m_orientation_selftest_rudder_stop_angle = 0;
	m_rightrear_selftest_rudder_stop_angle = 0;
	m_rightrear_selftest_rudder_full_angle_highrate = -20;
	m_rightrear_selftest_rudder_full_angle_mediumrate = -50;
	m_leftrear_selftest_rudder_full_angle_highrate = -20;
	m_leftrear_selftest_rudder_full_angle_lowrate = -150;
	m_leftrear_selftest_rudder_full_angle_mediumrate = -50;
	m_leftrear_selftest_rudder_stop_angle = 0;
}

CPage_cspz_yj_2::~CPage_cspz_yj_2()
{
}

void CPage_cspz_yj_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_EMU_micro, m_emu_micro);
	DDX_Text(pDX, IDC_EDIT_EMU_SCHEDULE_NUMBER, m_emu_schedule_number);
	DDX_Text(pDX, IDC_EDIT_VEHICLE_HEADINGSPEED_HIGHRATE, m_vehicle_headingspeed_highrate);
	DDX_Text(pDX, IDC_EDIT_VEHICLE_HEADINGSPEED_MEDIUMRATE, m_vehicle_headingspeed_mediumrate);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_STOP_ANGLE, m_fairwater_rudder_stop_angle);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_FULL_ANGLE_HIGHRATE, m_fairwater_rudder_full_angle_highrate);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_FULL_ANGLE_LOWRATE, m_fairwater_rudder_full_angle_lowrate);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_FULL_ANGLE_MEDIUMRATE, m_fairwater_rudder_full_angle_mediumrate);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_RUDDER_STOP_ANGLE, m_orentation_rudder_stop_angle);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_RUDDER_FULL_ANGLE_HIGHRATE, m_orientation_rudder_full_angle_highrate);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_RUDDER_FULL_ANGLE_LOWRATE, m_orientation_rudder_full_angle_lowrate);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_RUDDER_FULL_ANGLE_MEDIUMRATE, m_orientation_rudder_full_angle_mediumrate);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_RUDDER_STOP_ANGLE, m_leftrear_rudder_stop_angle);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_RUDDER_FULL_ANGLE_HIGHRATE, m_leftrear_rudder_full_angle_highrate);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_RUDDER_FULL_ANGLE_LOWRATE, m_leftrear_rudder_full_angle_lowrate);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_RUDDER_FULL_ANGLE_MEDIUMRATE, m_leftrear_rudder_full_angle_mediumrate);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_RUDDER_STOP_ANGLE, m_rightrear_rudder_stop_angle);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_RUDDER_FULL_ANGLE_HIGHRATE, m_rightrear_rudder_full_angle_highrate);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_RUDDER_FULL_ANGLE_LOWRATE, m_rightrear_rudder_full_angle_lowrate);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_RUDDER_FULL_ANGLE_MEDIUMRATE, m_rightrear_rudder_full_angle_mediumrate);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_STOP_VEHICLE_ACOUSTIC, m_fairwater_rudder_stop_vehicle_acoustic);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_RUDDER_STOP_VEHICLE_ACOUSTIC, m_leftrear_rudder_stop_vehicle_acoustic);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_RUDDER_STOP_VEHICLE_ACOUSTIC, m_orientation_rudder_stop_vehicle_acoustic);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_RUDDER_STOP_VEHICLE_ACOUSTIC, m_rightrear_rudder_stop_vehicle_acoustic);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE, m_fairwater_selftest_rudder_full_angle_highrate);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE, m_fairwater_selftest_rudder_full_angle_lowrate);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE, m_fairwater_selftest_rudder_full_angle_mediumrate);
	DDX_Text(pDX, IDC_EDIT_FAIRWATER_SELFTEST_RUDDER_STOP_ANGLE, m_fairwater_selftest_rudder_stop_angle);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_SELFTEST_RUDDER_RISE_ANGLE, m_orientation_selftest_rudder_rise_angle);
	DDX_Text(pDX, IDC_EDIT_ORENTATION_SELFTEST_RUDDER_STOP_ANGLE, m_orientation_selftest_rudder_stop_angle);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_SELFTEST_RUDDER_STOP_ANGLE, m_rightrear_selftest_rudder_stop_angle);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE, m_rightrear_selftest_rudder_full_angle_highrate);
	DDX_Text(pDX, IDC_EDIT_RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE, m_rightrear_selftest_rudder_full_angle_mediumrate);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE, m_leftrear_selftest_rudder_full_angle_highrate);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE, m_leftrear_selftest_rudder_full_angle_lowrate);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE, m_leftrear_selftest_rudder_full_angle_mediumrate);
	DDX_Text(pDX, IDC_EDIT_LEFTREAR_SELFTEST_RUDDER_STOP_ANGLE, m_leftrear_selftest_rudder_stop_angle);
}


BEGIN_MESSAGE_MAP(CPage_cspz_yj_2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CSPZ_YJ_2, &CPage_cspz_yj_2::OnBnClickedButtonCspzYj2)
END_MESSAGE_MAP()


// CPage_cspz_yj_2 消息处理程序


void CPage_cspz_yj_2::OnBnClickedButtonCspzYj2()
{
	// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			/*m_pDlg->pdata_0701->EMU_micro=m_emu_micro;
			m_pDlg->pdata_0701->EMU_SCHEDULE_NUMBER=m_emu_schedule_number;
			m_pDlg->pdata_0701->VEHICLE_HEADINGSPEED_HIGHRATE=m_vehicle_headingspeed_highrate;
			m_pDlg->pdata_0701->VEHICLE_HEADINGSPEED_MEDIUMRATE=m_vehicle_headingspeed_mediumrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_STOP_ANGLE=m_fairwater_rudder_stop_angle;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_FULL_ANGLE_HIGHRATE=m_fairwater_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_FULL_ANGLE_MEDIUMRATE=m_fairwater_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_FULL_ANGLE_LOWRATE=m_fairwater_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_STOP_ANGLE=m_orentation_rudder_stop_angle;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_FULL_ANGLE_HIGHRATE=m_orientation_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_FULL_ANGLE_MEDIUMRATE=m_orientation_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_FULL_ANGLE_LOWRATE=m_orientation_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_STOP_ANGLE=m_leftrear_rudder_stop_angle;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_FULL_ANGLE_HIGHRATE=m_leftrear_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_FULL_ANGLE_MEDIUMRATE=m_leftrear_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_FULL_ANGLE_LOWRATE=m_leftrear_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_STOP_ANGLE=m_rightrear_rudder_stop_angle;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_FULL_ANGLE_HIGHRATE=m_rightrear_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_FULL_ANGLE_MEDIUMRATE=m_rightrear_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_FULL_ANGLE_LOWRATE=m_rightrear_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->FAIRWATER_RUDDER_STOP_VEHICLE_ACOUSTIC=m_fairwater_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->ORENTATION_RUDDER_STOP_VEHICLE_ACOUSTIC=m_orientation_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->LEFTREAR_RUDDER_STOP_VEHICLE_ACOUSTIC=m_leftrear_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->RIGHTREAR_RUDDER_STOP_VEHICLE_ACOUSTIC=m_rightrear_rudder_stop_vehicle_acoustic;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE=m_fairwater_selftest_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE=m_fairwater_selftest_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE=m_fairwater_selftest_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->FAIRWATER_SELFTEST_RUDDER_STOP_ANGLE=m_fairwater_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->ORENTATION_SELFTEST_RUDDER_RISE_ANGLE=m_orientation_selftest_rudder_rise_angle;
			m_pDlg->pdata_0701->ORENTATION_SELFTEST_RUDDER_STOP_ANGLE=m_orientation_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE=m_leftrear_selftest_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_LOWRATE=m_leftrear_selftest_rudder_full_angle_lowrate;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE=m_leftrear_selftest_rudder_full_angle_mediumrate;
			m_pDlg->pdata_0701->LEFTREAR_SELFTEST_RUDDER_STOP_ANGLE=m_leftrear_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->RIGHTREAR_SELFTEST_RUDDER_STOP_ANGLE=m_rightrear_selftest_rudder_stop_angle;
			m_pDlg->pdata_0701->RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_HIGHRATE=m_rightrear_selftest_rudder_full_angle_highrate;
			m_pDlg->pdata_0701->RIGHTREAR_SELFTEST_RUDDER_FULL_ANGLE_MEDIUMRATE=m_rightrear_selftest_rudder_full_angle_mediumrate;*/
			MessageBox("参数确认成功");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}

}



BOOL CPage_cspz_yj_2::PreTranslateMessage(MSG* pMsg)
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
