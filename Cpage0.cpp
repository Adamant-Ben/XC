// Cpage0.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Cpage0.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include "Pag_Password.h"

// Cpage0 对话框

IMPLEMENT_DYNAMIC(Cpage0, CDialogEx)

Cpage0::Cpage0(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage0::IDD, pParent)
{
	m_pDlg0=pDlg;
	m_abovewatermaster = _T("");
	m_abovewatermasterwifi = _T("");
	m_acceptancecode = _T("");
	m_acceptancemask = _T("");
	m_baudrate = _T("");
	m_baudrate_0 = _T("");
	m_baudrate_1 = _T("");
	m_boardno_0 = _T("");
	m_boardno_1 = _T("");
	m_cardno = _T("");
	m_channelno_0 = _T("");
	m_channelno_1 = _T("");
	m_clockrate = _T("");
	m_datastorageunit = _T("");
	m_defaultmode = _T("");
	m_emergencyunit = _T("");
	m_errorthreshhold = _T("");
	m_macroperiod = _T("");
	m_measureunit = _T("");
	m_microperiod = _T("");
	m_mode = _T("");
	m_motionplanningunit = _T("");
	m_navigationunit = _T("");
	m_numberofcontrolunit = _T("");
	m_numofslave = _T("");
	m_portno = _T("");
	m_primarycontrolunit = _T("");
	m_rcvlevel_0 = _T("");
	m_rcvlevel_1 = _T("");
	m_speedthreshhold = _T("");
	m_tcpserverportnumber = _T("");
	m_underwatermaster = _T("");
	m_workstage = _T("");
}

Cpage0::~Cpage0()
{
	m_pDlg0=NULL;
}

void Cpage0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AboveWaterMaster, m_abovewatermaster);
	DDX_Text(pDX, IDC_EDIT_AboveWaterMasterWiFi, m_abovewatermasterwifi);
	DDX_Text(pDX, IDC_EDIT_AcceptanceCode, m_acceptancecode);
	DDX_Text(pDX, IDC_EDIT_AcceptanceMask, m_acceptancemask);
	DDX_Text(pDX, IDC_EDIT_BaudRate, m_baudrate);
	DDX_Text(pDX, IDC_EDIT_BaudRate_0, m_baudrate_0);
	DDX_Text(pDX, IDC_EDIT_BaudRate_1, m_baudrate_1);
	DDX_Text(pDX, IDC_EDIT_BoardNo_0, m_boardno_0);
	DDX_Text(pDX, IDC_EDIT_BoardNo_1, m_boardno_1);
	DDX_Text(pDX, IDC_EDIT_CardNo, m_cardno);
	DDX_Text(pDX, IDC_EDIT_ChannelNo_0, m_channelno_0);
	DDX_Text(pDX, IDC_EDIT_ChannelNo_1, m_channelno_1);
	DDX_Text(pDX, IDC_EDIT_ClockRate, m_clockrate);
	DDX_Text(pDX, IDC_EDIT_DataStorageUnit, m_datastorageunit);
	DDX_Text(pDX, IDC_EDIT_DefaultMode, m_defaultmode);
	DDX_Text(pDX, IDC_EDIT_EmergencyUnit, m_emergencyunit);
	DDX_Text(pDX, IDC_EDIT_ErrorThreshhold, m_errorthreshhold);
	DDX_Text(pDX, IDC_EDIT_MacroPeriod, m_macroperiod);
	DDX_Text(pDX, IDC_EDIT_MeasureUnit, m_measureunit);
	DDX_Text(pDX, IDC_EDIT_MicroPeriod, m_microperiod);
	DDX_Text(pDX, IDC_EDIT_Mode, m_mode);
	DDX_Text(pDX, IDC_EDIT_MotionPlanningUnit, m_motionplanningunit);
	DDX_Text(pDX, IDC_EDIT_NavigationUnit, m_navigationunit);
	DDX_Text(pDX, IDC_EDIT_NumberOfControlUnit, m_numberofcontrolunit);
	DDX_Text(pDX, IDC_EDIT_NumOfSlave, m_numofslave);
	DDX_Text(pDX, IDC_EDIT_PortNo, m_portno);
	DDX_Text(pDX, IDC_EDIT_PrimaryControlUnit, m_primarycontrolunit);
	DDX_Text(pDX, IDC_EDIT_RcvLevel_0, m_rcvlevel_0);
	DDX_Text(pDX, IDC_EDIT_RcvLevel_1, m_rcvlevel_1);
	DDX_Text(pDX, IDC_EDIT_SpeedThreshhold, m_speedthreshhold);
	DDX_Text(pDX, IDC_EDIT_TcpServerPortNumber, m_tcpserverportnumber);
	DDX_Text(pDX, IDC_EDIT_UnderWaterMaster, m_underwatermaster);
	DDX_Text(pDX, IDC_EDIT_WorkStage, m_workstage);
}


BEGIN_MESSAGE_MAP(Cpage0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CSPZ_SXZK, &Cpage0::OnBnClickedButtonCspzSxzk)
END_MESSAGE_MAP()


// Cpage0 消息处理程序


void Cpage0::OnBnClickedButtonCspzSxzk()
{
		// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			CString PathStr;
			GetPrivateProfileString("IniFilePath","SXZK","默认路径",PathStr.GetBuffer(MAX_PATH),MAX_PATH,"D:\\SSZKConfig\\config.ini");
			WritePrivateProfileString("COM0","BoardNo",m_boardno_0,PathStr);
			WritePrivateProfileString("COM0","ChannelNo",m_channelno_0,PathStr);
			WritePrivateProfileString("COM0","BaudRate",m_baudrate_0,PathStr);
			WritePrivateProfileString("COM0","RcvLevel",m_rcvlevel_0,PathStr);
			WritePrivateProfileString("COM1","BoardNo",m_boardno_1,PathStr);
			WritePrivateProfileString("COM1","ChannelNo",m_channelno_1,PathStr);
			WritePrivateProfileString("COM1","BaudRate",m_baudrate_1,PathStr);
			WritePrivateProfileString("COM1","RcvLevel",m_rcvlevel_1,PathStr);
			WritePrivateProfileString("IP_ADDR","NumberOfControlUnit",m_numberofcontrolunit,PathStr);
			WritePrivateProfileString("IP_ADDR","TcpServerPortNumber",m_tcpserverportnumber,PathStr);
			WritePrivateProfileString("IP_ADDR","AboveWaterMaster",m_abovewatermaster,PathStr);
			WritePrivateProfileString("IP_ADDR","AboveWaterMasterWiFi",m_abovewatermasterwifi,PathStr);
			WritePrivateProfileString("IP_ADDR","UnderWaterMaster",m_underwatermaster,PathStr);
			WritePrivateProfileString("IP_ADDR","NavigationUnit",m_navigationunit,PathStr);
			WritePrivateProfileString("IP_ADDR","MotionPlanningUnit",m_motionplanningunit,PathStr);
			WritePrivateProfileString("IP_ADDR","PrimaryControlUnit",m_primarycontrolunit,PathStr);
			WritePrivateProfileString("IP_ADDR","EmergencyUnit",m_emergencyunit,PathStr);
			WritePrivateProfileString("IP_ADDR","DataStorageUnit",m_datastorageunit,PathStr);
			WritePrivateProfileString("IP_ADDR","MeasureUnit",m_measureunit,PathStr);
			WritePrivateProfileString("CAN","CardNo",m_cardno,PathStr);
			WritePrivateProfileString("CAN","PortNo",m_portno,PathStr);
			WritePrivateProfileString("CAN","BaudRate",m_baudrate,PathStr);
			WritePrivateProfileString("CAN","AcceptanceCode",m_acceptancecode,PathStr);
			WritePrivateProfileString("CAN","AcceptanceMask",m_acceptancemask,PathStr);
			WritePrivateProfileString("CAN","Mode",m_mode,PathStr);
			WritePrivateProfileString("SCHEDULE","ClockRate",m_clockrate,PathStr);
			WritePrivateProfileString("SCHEDULE","MicroPeriod",m_microperiod,PathStr);
			WritePrivateProfileString("SCHEDULE","MacroPeriod",m_macroperiod,PathStr);
			WritePrivateProfileString("SCHEDULE","NumOfSlave",m_numofslave,PathStr);
			WritePrivateProfileString("SCHEDULE","ErrorThreshhold",m_errorthreshhold,PathStr);
			WritePrivateProfileString("MISSION","SpeedThreshhold",m_speedthreshhold,PathStr);
			WritePrivateProfileString("MISSION","DefaultMode",m_defaultmode,PathStr);
			WritePrivateProfileString("MISSION","WorkStage",m_workstage,PathStr);
			MessageBox("发送成功");
		}
		else
		{
			MessageBox("密码错误");
		}

	}


}


BOOL Cpage0::PreTranslateMessage(MSG* pMsg)
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
