// Cpage3.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Cpage3.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include "Pag_Password.h"
#include <math.h>
// Cpage3 对话框
CByteArray arraySend1;
IMPLEMENT_DYNAMIC(Cpage3, CDialogEx)

Cpage3::Cpage3(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage3::IDD, pParent)
{
	m_pDlg=pDlg;
	m_imagelist[0]=IDB_BITMAP_GRAY;
	m_imagelist[1]=IDB_BITMAP_GREEN;
	m_imagelist[2] = IDB_BITMAP_RED;
	m_djcssq = _T("");
	m_dk = _T("");
	m_fxdyxw = _T("");
	m_ip = _T("");
	m_lym = _T("");
	m_lymm = _T("");
	m_wdyxw = _T("");
	m_wkdyxw = _T("");
	m_kd_fxd = 4.0f;
	m_kd_wkd = 4.0f;
	m_kd_ywd = 20.0f;
	m_kd_zwd = 20.0f;
	m_ki_fxd = 1.0f;
	m_ki_wkd = 1.0f;
	m_ki_ywd = 1.8f;
	m_ki_zwd = 1.8f;
	m_kp_fxd = 3.0f;
	m_kp_wkd = 3.0f;
	m_kp_ywd = 3.0f;
	m_kp_zwd = 3.0f;
	m_sx_wkd = 3999;
	m_sx_fxd = 3999;
	m_sx_ywd = 3999;
	m_sx_zwd = 3999;
	m_xx_fxd = 0;
	m_xx_wkd = 0;
	m_xx_ywd = 0;
	m_xx_zwd = 0;
	m_wkdcspzFlag=false;
	m_fxdcspzFlag=false;
	m_zwdcspzFlag=false;
	m_ywdcspzFlag=false;
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
	m_emergencyunit = _T("");
	m_defaultmode = _T("");
	m_datastorageunit = _T("");
	m_clockrate = _T("");
	m_channelno_1 = _T("");
	m_channelno_0 = _T("");
	m_cardno = _T("");
	m_boardno_1 = _T("");
	m_boardno_0 = _T("");
	m_baudrate_1 = _T("");
	m_baudrate_0 = _T("");
	m_baudrate = _T("");
	m_abovewatermaster = _T("");
	m_abovewatermasterwifi = _T("");
	m_acceptancecode = _T("");
	m_acceptancemask = _T("");
	m_errorthreshhold = _T("");
	//m_speed_limit = 1500;
	//m_speed_limit_flag=false;
	//m_speed_limit2 = -1500;
	//m_fairwater_rudder = 0;
	//m_direction_rudder = 0;
	//m_leftright_rudder = 0;
	//m_speed_ctr_flag=true;
	//m_speed_tidu = 100;
	//m_awmu_speed_cmd = 0;
	//m_djsszs2 = _T("");
	//m_leftright_rudder2 = 0;
	//m_direction_rudder2 = 0;
	//m_fairwater_rudder2 = 0;
	//p_wkd=0;
	//p_fxd=0;
	//p_zywd=0;
	//m_wkd_angle = 0.0f;
	//m_fxd_angle = 0.0f;
	//m_zywd_angle = 0.0f;
	//m_second_num = 0;
	//m_shuibeng_command=false;
	//m_shuibeng_state=false;
	//m_shuibeng=0;
}

Cpage3::~Cpage3()
{
}

void Cpage3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DJCSSQ, m_djcssq);
	DDX_Text(pDX, IDC_EDIT_DK, m_dk);
	DDX_Text(pDX, IDC_EDIT_FXDYXW, m_fxdyxw);
	DDX_Text(pDX, IDC_EDIT_IP, m_ip);
	DDX_Text(pDX, IDC_EDIT_LYM, m_lym);
	DDX_Text(pDX, IDC_EDIT_LYMM, m_lymm);
	DDX_Text(pDX, IDC_EDIT_WDYXW, m_wdyxw);
	DDX_Text(pDX, IDC_EDIT_WKDYXW, m_wkdyxw);
	DDX_Check(pDX, IDC_CHECK1, m_start);
	DDX_Text(pDX, IDC_EDIT_KD_FXD, m_kd_fxd);
	DDX_Text(pDX, IDC_EDIT_KD_WKD, m_kd_wkd);
	DDX_Text(pDX, IDC_EDIT_KD_YWD, m_kd_ywd);
	DDX_Text(pDX, IDC_EDIT_KD_ZWD, m_kd_zwd);
	DDX_Text(pDX, IDC_EDIT_KI_FXD, m_ki_fxd);
	DDX_Text(pDX, IDC_EDIT_KI_WKD, m_ki_wkd);
	DDX_Text(pDX, IDC_EDIT_KI_YWD, m_ki_ywd);
	DDX_Text(pDX, IDC_EDIT_KI_ZWD, m_ki_zwd);
	DDX_Text(pDX, IDC_EDIT_KP_FXD, m_kp_fxd);
	DDX_Text(pDX, IDC_EDIT_KP_WKD, m_kp_wkd);
	DDX_Text(pDX, IDC_EDIT_KP_YWD, m_kp_ywd);
	DDX_Text(pDX, IDC_EDIT_KP_ZWD, m_kp_zwd);
	DDX_Text(pDX, IDC_EDIT_SX_WKD, m_sx_wkd);
	DDX_Text(pDX, IDC_EDIT_SX_FXD, m_sx_fxd);
	DDX_Text(pDX, IDC_EDIT_SX_YWD, m_sx_ywd);
	DDX_Text(pDX, IDC_EDIT_SX_ZWD, m_sx_zwd);
	DDX_Text(pDX, IDC_EDIT_XX_FXD, m_xx_fxd);
	DDX_Text(pDX, IDC_EDIT_XX_WKD, m_xx_wkd);
	DDX_Text(pDX, IDC_EDIT_XX_YWD, m_xx_ywd);
	DDX_Text(pDX, IDC_EDIT_XX_ZWD, m_xx_zwd);
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
	DDX_Text(pDX, IDC_EDIT_EmergencyUnit, m_emergencyunit);
	DDX_Text(pDX, IDC_EDIT_DefaultMode, m_defaultmode);
	DDX_Text(pDX, IDC_EDIT_DataStorageUnit, m_datastorageunit);
	DDX_Text(pDX, IDC_EDIT_ClockRate, m_clockrate);
	DDX_Text(pDX, IDC_EDIT_ChannelNo_1, m_channelno_1);
	DDX_Text(pDX, IDC_EDIT_ChannelNo_0, m_channelno_0);
	DDX_Text(pDX, IDC_EDIT_CardNo, m_cardno);
	DDX_Text(pDX, IDC_EDIT_BoardNo_1, m_boardno_1);
	DDX_Text(pDX, IDC_EDIT_BoardNo_0, m_boardno_0);
	DDX_Text(pDX, IDC_EDIT_BaudRate_1, m_baudrate_1);
	DDX_Text(pDX, IDC_EDIT_BaudRate_0, m_baudrate_0);
	DDX_Text(pDX, IDC_EDIT_BaudRate, m_baudrate);
	DDX_Text(pDX, IDC_EDIT_AboveWaterMaster, m_abovewatermaster);
	DDX_Text(pDX, IDC_EDIT_AboveWaterMasterWiFi, m_abovewatermasterwifi);
	DDX_Text(pDX, IDC_EDIT_AcceptanceCode, m_acceptancecode);
	DDX_Text(pDX, IDC_EDIT_AcceptanceMask, m_acceptancemask);
	DDX_Text(pDX, IDC_EDIT_ErrorThreshhold, m_errorthreshhold);
	DDX_Check(pDX, IDC_CHECK_CSPZ_SCH, m_cspz_sch);
	//DDX_Text(pDX, IDC_EDIT_SPEED_LIMIT, m_speed_limit);
	//DDV_MinMaxShort(pDX, m_speed_limit, 0, 1500);
	//DDX_Check(pDX, IDC_CHECK_SPEED_LIMIT_ENABLE, m_speed_limit_flag);
	//DDX_Text(pDX, IDC_EDIT_SPEED_LIMIT2, m_speed_limit2);
	//DDV_MinMaxShort(pDX, m_speed_limit2, -1500, 0);
	//DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_CTR, m_fairwater_rudder);
	//DDX_Text(pDX, IDC_EDIT_DIRECTION_RUDDER_CTR, m_direction_rudder);
	//DDX_Text(pDX, IDC_EDIT_LEFTRIGHT_RUDDER_CTR, m_leftright_rudder);
	//DDX_Check(pDX, IDC_CHECK_RUDDER_CTR_ENABLE, m_rudder_ctr_flag);
	//DDX_Check(pDX, IDC_CHECK_FX_RUDDER_CTR_ENABLE, m_fx_rudder_ctr_flag);
	//DDX_Check(pDX, IDC_CHECK_ZY_RUDDER_CTR_ENABLE3, m_zy_rudder_ctr_flag);
	//DDX_Check(pDX, IDC_CHECK_SPEED_CTR, m_speed_ctr_flag);
	//DDX_Check(pDX, IDC_CHECK_SPEED_AWMU_CMD, m_speed_awmu_cmd_flag);
	//DDX_Text(pDX, IDC_EDIT_SPEED_TIDU, m_speed_tidu);
	//DDV_MinMaxShort(pDX, m_speed_tidu, 0, 200);
	//DDX_Text(pDX, IDC_EDIT_SPEED_AWMU_CMD, m_awmu_speed_cmd);
	//DDV_MinMaxShort(pDX, m_awmu_speed_cmd, -1500, 1500);
	//DDX_Text(pDX, IDC_EDIT_DJSSZS2, m_djsszs2);
	//DDX_Radio(pDX, IDC_RADIO_FX, m_fxd);
	//DDX_Radio(pDX, IDC_RADIO_WK, m_wkd);
	//DDX_Radio(pDX, IDC_RADIO_ZYWD, m_zywd);
	//DDX_Text(pDX, IDC_EDIT_LEFTRIGHT_RUDDER_CTR2, m_leftright_rudder2);
	//DDX_Text(pDX, IDC_EDIT_DIRECTION_RUDDER_CTR2, m_direction_rudder2);
	//DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_CTR2, m_fairwater_rudder2);
	//DDX_Text(pDX, IDC_EDIT_FAIRWATER_RUDDER_ANGLE, m_wkd_angle);
	//DDX_Text(pDX, IDC_EDIT_FX_RUDDER_ANGLE, m_fxd_angle);
	//DDX_Text(pDX, IDC_EDIT_ZYW_RUDDER_ANGLE, m_zywd_angle);
	//DDX_Text(pDX, IDC_EDIT_AUTO_TIME, m_second_num);
	//DDX_Check(pDX, IDC_CHECK_SHUIBENG_ENABLE, m_shuibeng_ctr_flag);
	//DDX_Radio(pDX, IDC_RADIO_SHUIBNENG_START, m_shuibeng);

}


BEGIN_MESSAGE_MAP(Cpage3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cpage3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cpage3::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cpage3::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Cpage3::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cpage3::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cpage3::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cpage3::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_CHECK1, &Cpage3::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON_FS_WKD, &Cpage3::OnBnClickedButtonFsWkd)
	ON_BN_CLICKED(IDC_BUTTON_CC_WKD, &Cpage3::OnBnClickedButtonCcWkd)
	ON_BN_CLICKED(IDC_BUTTON_FS_FXD, &Cpage3::OnBnClickedButtonFsFxd)
	ON_BN_CLICKED(IDC_BUTTON_CC_FXD, &Cpage3::OnBnClickedButtonCcFxd)
	ON_BN_CLICKED(IDC_BUTTON_FS_ZWD, &Cpage3::OnBnClickedButtonFsZwd)
	ON_BN_CLICKED(IDC_BUTTON_CC_ZWD, &Cpage3::OnBnClickedButtonCcZwd)
	ON_BN_CLICKED(IDC_BUTTON_FS_YWD, &Cpage3::OnBnClickedButtonFsYwd)
	ON_BN_CLICKED(IDC_BUTTON_CC_YWD, &Cpage3::OnBnClickedButtonCcYwd)
	ON_WM_TIMER()
//	ON_BN_CLICKED(IDC_BUTTON_SCPZWJ_YJ, &Cpage3::OnBnClickedButtonScpzwjYj)
ON_BN_CLICKED(IDC_BUTTON_CSPZ_SXZK, &Cpage3::OnBnClickedButtonCspzSxzk)
ON_BN_CLICKED(IDC_CHECK_CSPZ_SCH, &Cpage3::OnBnClickedCheckCspzSch)
//ON_BN_CLICKED(IDC_BUTTON_SPEED_LIMIT, &Cpage3::OnBnClickedButtonSpeedLimit)
//ON_BN_CLICKED(IDC_CHECK_SPEED_LIMIT_ENABLE, &Cpage3::OnBnClickedCheckSpeedLimitEnable)
//ON_BN_CLICKED(IDC_BUTTON_RUDDER_CTR, &Cpage3::OnBnClickedButtonRudderCtr)
//ON_BN_CLICKED(IDC_CHECK_RUDDER_CTR_ENABLE, &Cpage3::OnBnClickedCheckRudderCtrEnable)
//ON_BN_CLICKED(IDC_CHECK_FX_RUDDER_CTR_ENABLE, &Cpage3::OnBnClickedCheckFxRudderCtrEnable)
//ON_BN_CLICKED(IDC_CHECK_ZY_RUDDER_CTR_ENABLE3, &Cpage3::OnBnClickedCheckZyRudderCtrEnable3)
//ON_BN_CLICKED(IDC_CHECK_SPEED_CTR, &Cpage3::OnBnClickedCheckSpeedCtr)
//ON_BN_CLICKED(IDC_CHECK_SPEED_AWMU_CMD, &Cpage3::OnBnClickedCheckSpeedAwmuCmd)
//ON_BN_CLICKED(IDC_BUTTON_SPEED_TIDU, &Cpage3::OnBnClickedButtonSpeedTidu)
//ON_BN_CLICKED(IDC_BUTTON_SPEED_AWMU_CMD, &Cpage3::OnBnClickedButtonSpeedAwmuCmd)
//ON_BN_CLICKED(IDC_RADIO_WK, &Cpage3::OnBnClickedRadioWk)
//ON_BN_CLICKED(IDC_RADIO2, &Cpage3::OnBnClickedRadio2)
//ON_BN_CLICKED(IDC_RADIO_FX, &Cpage3::OnBnClickedRadioFx)
//ON_BN_CLICKED(IDC_RADIO4, &Cpage3::OnBnClickedRadio4)
//ON_BN_CLICKED(IDC_RADIO_ZYWD, &Cpage3::OnBnClickedRadioZywd)
//ON_BN_CLICKED(IDC_RADIO6, &Cpage3::OnBnClickedRadio6)
//ON_BN_CLICKED(IDC_CHECK_SHUIBENG_ENABLE, &Cpage3::OnBnClickedCheckShuibengEnable)
//ON_BN_CLICKED(IDC_RADIO_SHUIBNENG_START, &Cpage3::OnBnClickedRadioShuibnengStart)
//ON_BN_CLICKED(IDC_RADIO_SHUIBENG_STOP, &Cpage3::OnBnClickedRadioShuibengStop)
END_MESSAGE_MAP()


// Cpage3 消息处理程序


void Cpage3::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *ch=NULL;
	CString str;
	str="$SSID=";
	str+=m_lym;
	str+="#";
	//strcpy(ch,str);
	ch=(char*)malloc(str.GetLength()+1);
	strcpy_s(ch,str.GetLength()+1,(const char*)str);
	MessageBox(ch);
	arraySend1.RemoveAll();
	arraySend1.SetSize(strlen(ch));
	for(UINT i=0;i<strlen(ch);i++)
		arraySend1.SetAt(i,ch[i]);
	m_pDlg->m_CtrlComm1.put_Output(COleVariant(arraySend1));
	free(ch);

}


void Cpage3::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *ch=NULL;
	CString str;
	str="$MIMA=";
	str+=m_lymm;
	str+="#";
	//strcpy(ch,str);
	ch=(char*)malloc(str.GetLength()+1);
	strcpy_s(ch,str.GetLength()+1,(const char*)str);
	MessageBox(ch);
	arraySend1.RemoveAll();
	arraySend1.SetSize(strlen(ch));
	for(UINT i=0;i<strlen(ch);i++)
		arraySend1.SetAt(i,ch[i]);
	m_pDlg->m_CtrlComm1.put_Output(COleVariant(arraySend1));
	free(ch);
}


void Cpage3::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *ch=NULL;
	CString str;
	str="$IPDR=";
	str+=m_ip;
	str+=":";
	str+=m_dk;
	str+="#";
	//strcpy(ch,str);
	ch=(char*)malloc(str.GetLength()+1);
	strcpy_s(ch,str.GetLength()+1,(const char*)str);
	MessageBox(ch);
	arraySend1.RemoveAll();
	arraySend1.SetSize(strlen(ch));
	for(UINT i=0;i<strlen(ch);i++)
		arraySend1.SetAt(i,ch[i]);
	m_pDlg->m_CtrlComm1.put_Output(COleVariant(arraySend1));
	free(ch);
}


void Cpage3::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *ch=NULL;
	CString str;
	str="$ZERO=";
	str+=m_djcssq;
	str+="#";
	//strcpy(ch,str);
	ch=(char*)malloc(str.GetLength()+1);
	strcpy_s(ch,str.GetLength()+1,(const char*)str);
	MessageBox(ch);
	arraySend1.RemoveAll();
	arraySend1.SetSize(strlen(ch));
	for(UINT i=0;i<strlen(ch);i++)
		arraySend1.SetAt(i,ch[i]);
	m_pDlg->m_CtrlComm1.put_Output(COleVariant(arraySend1));
	free(ch);
}


void Cpage3::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *ch=NULL;
	CString str;
	str="$DIRE=";
	str+=m_fxdyxw;
	str+="#";
	//strcpy(ch,str);
	ch=(char*)malloc(str.GetLength()+1);
	strcpy_s(ch,str.GetLength()+1,(const char*)str);
	MessageBox(ch);
	arraySend1.RemoveAll();
	arraySend1.SetSize(strlen(ch));
	for(UINT i=0;i<strlen(ch);i++)
		arraySend1.SetAt(i,ch[i]);
	m_pDlg->m_CtrlComm1.put_Output(COleVariant(arraySend1));
	free(ch);
}


void Cpage3::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *ch=NULL;
	CString str;
	str="$TAIL=";
	str+=m_wdyxw;
	str+="#";
	//strcpy(ch,str);
	ch=(char*)malloc(str.GetLength()+1);
	strcpy_s(ch,str.GetLength()+1,(const char*)str);
	MessageBox(ch);
	arraySend1.RemoveAll();
	arraySend1.SetSize(strlen(ch));
	for(UINT i=0;i<strlen(ch);i++)
		arraySend1.SetAt(i,ch[i]);
	m_pDlg->m_CtrlComm1.put_Output(COleVariant(arraySend1));
	free(ch);
}


void Cpage3::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *ch=NULL;
	CString str;
	str="$SHEL=";
	str+=m_wkdyxw;
	str+="#";
	//strcpy(ch,str);
	ch=(char*)malloc(str.GetLength()+1);
	strcpy_s(ch,str.GetLength()+1,(const char*)str);
	MessageBox(ch);
	arraySend1.RemoveAll();
	arraySend1.SetSize(strlen(ch));
	for(UINT i=0;i<strlen(ch);i++)
		arraySend1.SetAt(i,ch[i]);
	m_pDlg->m_CtrlComm1.put_Output(COleVariant(arraySend1));
	free(ch);
}


void Cpage3::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	BYTE data[6];
	unsigned short crcCheck=0;
	data[0]=0xa5;data[1]='C';data[5]=0x0d;
	if(m_start==TRUE)
	{		CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			data[2]=1;
			crcCheck=m_pDlg->CRC16(data,3);
			data[3]=crcCheck/256;
			data[4]=crcCheck%256;
			m_pDlg->SSJCKZSocket->Send(data,6,0);   //发送启动配置报文至基础控制单元
			/*BYTE crc;
			crc=m_pDlg->compute_crc8(data,3);
			data[3]=crc;
			data[4]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,5,0);*/
			GetDlgItem(IDC_BUTTON_FS_WKD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_CC_WKD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_FS_FXD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_CC_FXD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_FS_ZWD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_CC_ZWD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_FS_YWD)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_CC_YWD)->EnableWindow(TRUE);
		}
		else
		{
		m_start=FALSE;
		UpdateData(FALSE);
		MessageBox("密码错误");
		}
	}

	
	}

	else
	{
		data[2]=0;
		crcCheck=m_pDlg->CRC16(data,3);
		data[3]=crcCheck/256;
		data[4]=crcCheck%256;
		m_pDlg->SSJCKZSocket->Send(data,6,0);   //发送退出配置报文至基础控制单元
		/*BYTE crc;
		crc=m_pDlg->compute_crc8(data,3);
		data[3]=crc;
		data[4]=0x0d;
		m_pDlg->SSJCKZSocket->Send(data,5,0);*/
		GetDlgItem(IDC_BUTTON_FS_WKD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CC_WKD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_FS_FXD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CC_FXD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_FS_ZWD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CC_ZWD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_FS_YWD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CC_YWD)->EnableWindow(FALSE);
	}
}


BOOL Cpage3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_FS_WKD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CC_WKD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_FS_FXD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CC_FXD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_FS_ZWD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CC_ZWD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_FS_YWD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CC_YWD)->EnableWindow(FALSE);
	drawpicture(IDC_PICTURE_FSCG_WKD,0);
	drawpicture(IDC_PICTURE_CCWC_WKD,0);
	drawpicture(IDC_PICTURE_FSCG_FXD,0);
	drawpicture(IDC_PICTURE_CCWC_FXD,0);
	drawpicture(IDC_PICTURE_FSCG_ZWD,0);
	drawpicture(IDC_PICTURE_CCWC_ZWD,0);
	drawpicture(IDC_PICTURE_FSCG_YWD,0);
	drawpicture(IDC_PICTURE_CCWC_YWD,0);
	drawpicture(IDC_PICTURE_JCKZTXZT,0);
	//GetDlgItem(IDC_EDIT_SPEED_LIMIT)->EnableWindow(false);
	//GetDlgItem(IDC_EDIT_SPEED_LIMIT2)->EnableWindow(false);
	//GetDlgItem(IDC_EDIT_FAIRWATER_RUDDER_CTR)->EnableWindow(false);
	//GetDlgItem(IDC_EDIT_DIRECTION_RUDDER_CTR)->EnableWindow(false);
	//GetDlgItem(IDC_EDIT_LEFTRIGHT_RUDDER_CTR)->EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Cpage3::OnBnClickedButtonFsWkd()
{
	// TODO: 在此添加控件通知处理程序代码
			UpdateData(TRUE);
			m_wkdcspzFlag=false;
			drawpicture(IDC_PICTURE_FSCG_WKD,0);
			Sleep(50);
			/*RUDDER_PARAMETER pdata;
			BYTE* sendata;
			sendata=(BYTE*)malloc(sizeof(RUDDER_PARAMETER));
			pdata.pktHead1=0xa5;
			pdata.pktHead2='M';
			pdata.rudderIndex=1;
			pdata.kp=ntohl(m_kp_wkd);
			pdata.ki=ntohl(m_ki_wkd);
			pdata.kd=ntohl(m_kd_wkd);
			pdata.upperLimit=ntohl(m_sx_wkd);
			pdata.lowerLimit=ntohl(m_xx_wkd);
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER)-3);
			pdata.crcCheck=m_pDlg->CRC16(sendata,sizeof(RUDDER_PARAMETER)-3);
			pdata.crcCheck=ntohl(pdata.crcCheck);
			pdata.pktEnd=0x0d;
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER));
			m_pDlg->SSJCKZSocket->Send(sendata,sizeof(RUDDER_PARAMETER));*/
			BAF baf;
			BAI bai;
			BYTE data[26];
			data[0]=0xa5;
			data[1]='M';
			data[2]=1;
			baf.f=m_kp_wkd;
			data[3]=baf.by[3];data[4]=baf.by[2];data[5]=baf.by[1];data[6]=baf.by[0];
			baf.f=m_ki_wkd;
			data[7]=baf.by[3];data[8]=baf.by[2];data[9]=baf.by[1];data[10]=baf.by[0];
			baf.f=m_kd_wkd;
			data[11]=baf.by[3];data[12]=baf.by[2];data[13]=baf.by[1];data[14]=baf.by[0];
			bai.i=m_sx_wkd;
			data[15]=bai.by[3];data[16]=bai.by[2];data[17]=bai.by[1];data[18]=bai.by[0];
			bai.i=m_xx_wkd;
			data[19]=bai.by[3];data[20]=bai.by[2];data[21]=bai.by[1];data[22]=bai.by[0];
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(data,23);
			data[23]=crcCheck/256;
			data[24]=crcCheck%256;
			data[25]=0x0d;
			/*CString str,strtemp;
			for(int i=0;i<26;i++)
			{strtemp.Format("%02x ",data[i]);str+=strtemp;}
			MessageBox(str);*/
			m_pDlg->SSJCKZSocket->Send(data,26,0);
			SetTimer(1,2000,NULL);
			/*BYTE crc;
			crc=m_pDlg->compute_crc8(data,23);
			data[23]=crc;
			data[24]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,25,0);*/

}

void Cpage3::OnBnClickedButtonCcWkd()
{
	// TODO: 在此添加控件通知处理程序代码
	drawpicture(IDC_PICTURE_CCWC_WKD,0);
	Sleep(50);
	BYTE data[6];
	data[0]=0xa5;
	data[1]='$';
	data[2]=1;   //舵机序号
	unsigned short crcCheck=0;
	crcCheck=m_pDlg->CRC16(data,3);
	data[3]=crcCheck/256;
	data[4]=crcCheck%256;
	data[5]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,6);
	/*BYTE crc;
	crc=m_pDlg->compute_crc8(data,3);
	data[3]=crc;
	data[4]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,5,0);*/
}


void Cpage3::OnBnClickedButtonFsFxd()
{
	// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			m_fxdcspzFlag=false;
			drawpicture(IDC_PICTURE_FSCG_FXD,0);
			Sleep(50);
			/*RUDDER_PARAMETER pdata;
			BYTE* sendata;
			sendata=(BYTE*)malloc(sizeof(RUDDER_PARAMETER));
			pdata.pktHead1=0xa5;
			pdata.pktHead2='M';
			pdata.rudderIndex=2;
			pdata.kp=ntohl(m_kp_fxd);
			pdata.ki=ntohl(m_ki_fxd);
			pdata.kd=ntohl(m_kd_fxd);
			pdata.upperLimit=ntohl(m_sx_fxd);
			pdata.lowerLimit=ntohl(m_xx_fxd);
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER)-3);
			//unsigned short crcCheck;
			pdata.crcCheck=m_pDlg->CRC16(sendata,sizeof(RUDDER_PARAMETER)-3);
			pdata.crcCheck=ntohl(pdata.crcCheck);
			pdata.pktEnd=0x0d;
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER));
			m_pDlg->SSJCKZSocket->Send(sendata,sizeof(RUDDER_PARAMETER));*/
			BAF baf;
			BAI bai;
			BYTE data[26];
			data[0]=0xa5;
			data[1]='M';
			data[2]=2;
			baf.f=m_kp_fxd;
			data[3]=baf.by[3];data[4]=baf.by[2];data[5]=baf.by[1];data[6]=baf.by[0];
			baf.f=m_ki_fxd;
			data[7]=baf.by[3];data[8]=baf.by[2];data[9]=baf.by[1];data[10]=baf.by[0];
			baf.f=m_kd_fxd;
			data[11]=baf.by[3];data[12]=baf.by[2];data[13]=baf.by[1];data[14]=baf.by[0];
			bai.i=m_sx_fxd;
			data[15]=bai.by[3];data[16]=bai.by[2];data[17]=bai.by[1];data[18]=bai.by[0];
			bai.i=m_xx_fxd;
			data[19]=bai.by[3];data[20]=bai.by[2];data[21]=bai.by[1];data[22]=bai.by[0];
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(data,23);
			data[23]=crcCheck/256;
			data[24]=crcCheck%256;
			data[25]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,26,0);
			SetTimer(2,2000,NULL);
			/*BYTE crc;
			crc=m_pDlg->compute_crc8(data,23);
			data[23]=crc;
			data[24]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,25,0);*/
			MessageBox("发送成功");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}

}


void Cpage3::OnBnClickedButtonCcFxd()
{
	// TODO: 在此添加控件通知处理程序代码
	drawpicture(IDC_PICTURE_CCWC_FXD,0);
	Sleep(50);
	BYTE data[6];
	data[0]=0xa5;
	data[1]='$';
	data[2]=2;   //舵机序号
	unsigned short crcCheck=0;
	crcCheck=m_pDlg->CRC16(data,3);
	data[3]=crcCheck/256;
	data[4]=crcCheck%256;
	data[5]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,6);
	/*BYTE crc;
	crc=m_pDlg->compute_crc8(data,3);
	data[3]=crc;
	data[4]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,5,0);*/
}


void Cpage3::OnBnClickedButtonFsZwd()
{
	// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			m_zwdcspzFlag=false;
			drawpicture(IDC_PICTURE_FSCG_ZWD,0);
			Sleep(50);
			/*RUDDER_PARAMETER pdata;
			BYTE* sendata;
			sendata=(BYTE*)malloc(sizeof(RUDDER_PARAMETER));
			pdata.pktHead1=0xa5;
			pdata.pktHead2='M';
			pdata.rudderIndex=3;
			pdata.kp=ntohl(m_kp_zwd);
			pdata.ki=ntohl(m_ki_zwd);
			pdata.kd=ntohl(m_kd_zwd);
			pdata.upperLimit=ntohl(m_sx_zwd);
			pdata.lowerLimit=ntohl(m_xx_zwd);
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER)-3);
			//unsigned short crcCheck;
			pdata.crcCheck=m_pDlg->CRC16(sendata,sizeof(RUDDER_PARAMETER)-3);
			pdata.crcCheck=ntohl(pdata.crcCheck);
			pdata.pktEnd=0x0d;
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER));
			m_pDlg->SSJCKZSocket->Send(sendata,sizeof(RUDDER_PARAMETER));*/
			BAF baf;
			BAI bai;
			BYTE data[26];
			data[0]=0xa5;
			data[1]='M';
			data[2]=3;     //舵机序号
			baf.f=m_kp_zwd;
			data[3]=baf.by[3];data[4]=baf.by[2];data[5]=baf.by[1];data[6]=baf.by[0];
			baf.f=m_ki_zwd;
			data[7]=baf.by[3];data[8]=baf.by[2];data[9]=baf.by[1];data[10]=baf.by[0];
			baf.f=m_kd_zwd;
			data[11]=baf.by[3];data[12]=baf.by[2];data[13]=baf.by[1];data[14]=baf.by[0];
			bai.i=m_sx_zwd;
			data[15]=bai.by[3];data[16]=bai.by[2];data[17]=bai.by[1];data[18]=bai.by[0];
			bai.i=m_xx_zwd;
			data[19]=bai.by[3];data[20]=bai.by[2];data[21]=bai.by[1];data[22]=bai.by[0];
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(data,23);
			data[23]=crcCheck/256;
			data[24]=crcCheck%256;
			data[25]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,26,0);
			SetTimer(3,2000,NULL);
			/*BYTE crc;
			crc=m_pDlg->compute_crc8(data,23);
			data[23]=crc;
			data[24]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,25,0);*/
			MessageBox("发送成功");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}

}


void Cpage3::OnBnClickedButtonCcZwd()
{
	// TODO: 在此添加控件通知处理程序代码
	drawpicture(IDC_PICTURE_CCWC_ZWD,0);
	Sleep(50);
	BYTE data[6];
	data[0]=0xa5;
	data[1]='$';
	data[2]=3;   //舵机序号
	unsigned short crcCheck=0;
	crcCheck=m_pDlg->CRC16(data,3);
	data[3]=crcCheck/256;
	data[4]=crcCheck%256;
	data[5]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,6);
	/*BYTE crc;
	crc=m_pDlg->compute_crc8(data,3);
	data[3]=crc;
	data[4]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,5,0);*/
}


void Cpage3::OnBnClickedButtonFsYwd()
{
	// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			m_ywdcspzFlag=false;
			drawpicture(IDC_PICTURE_FSCG_YWD,0);
			Sleep(50);
			/*RUDDER_PARAMETER pdata;
			BYTE* sendata;
			sendata=(BYTE*)malloc(sizeof(RUDDER_PARAMETER));
			pdata.pktHead1=0xa5;
			pdata.pktHead2='M';
			pdata.rudderIndex=4;
			pdata.kp=ntohl(m_kp_ywd);
			pdata.ki=ntohl(m_ki_ywd);
			pdata.kd=ntohl(m_kd_ywd);
			pdata.upperLimit=ntohl(m_sx_ywd);
			pdata.lowerLimit=ntohl(m_xx_ywd);
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER)-3);
			//unsigned short crcCheck;
			pdata.crcCheck=m_pDlg->CRC16(sendata,sizeof(RUDDER_PARAMETER)-3);
			pdata.crcCheck=ntohl(pdata.crcCheck);
			pdata.pktEnd=0x0d;
			memcpy(sendata,&pdata,sizeof(RUDDER_PARAMETER));
			m_pDlg->SSJCKZSocket->Send(sendata,sizeof(RUDDER_PARAMETER));*/
			BAF baf;
			BAI bai;
			BYTE data[26];
			data[0]=0xa5;
			data[1]='M';
			data[2]=4;
			baf.f=m_kp_ywd;
			data[3]=baf.by[3];data[4]=baf.by[2];data[5]=baf.by[1];data[6]=baf.by[0];
			baf.f=m_ki_ywd;
			data[7]=baf.by[3];data[8]=baf.by[2];data[9]=baf.by[1];data[10]=baf.by[0];
			baf.f=m_kd_ywd;
			data[11]=baf.by[3];data[12]=baf.by[2];data[13]=baf.by[1];data[14]=baf.by[0];
			bai.i=m_sx_ywd;
			data[15]=bai.by[3];data[16]=bai.by[2];data[17]=bai.by[1];data[18]=bai.by[0];
			bai.i=m_xx_ywd;
			data[19]=bai.by[3];data[20]=bai.by[2];data[21]=bai.by[1];data[22]=bai.by[0];
			unsigned short crcCheck=0;
			crcCheck=m_pDlg->CRC16(data,23);
			data[23]=crcCheck/256;
			data[24]=crcCheck%256;
			data[25]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,26,0);
			SetTimer(4,2000,NULL);
			/*BYTE crc;
			crc=m_pDlg->compute_crc8(data,23);
			data[23]=crc;
			data[24]=0x0d;
			m_pDlg->SSJCKZSocket->Send(data,25,0);*/
			MessageBox("发送成功");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}

}


void Cpage3::OnBnClickedButtonCcYwd()
{
	// TODO: 在此添加控件通知处理程序代码
	drawpicture(IDC_PICTURE_CCWC_YWD,0);
	Sleep(50);
	BYTE data[6];
	data[0]=0xa5;
	data[1]='$';
	data[2]=4;   //舵机序号
	unsigned short crcCheck=0;
	crcCheck=m_pDlg->CRC16(data,3);
	data[3]=crcCheck/256;
	data[4]=crcCheck%256;
	data[5]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,6);
	/*BYTE crc;
	crc=m_pDlg->compute_crc8(data,3);
	data[3]=crc;
	data[4]=0x0d;
	m_pDlg->SSJCKZSocket->Send(data,5,0);*/
}

void Cpage3::drawpicture(int m_image_ID, int m_image_num)
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


void Cpage3::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1)
	{
		KillTimer(1);
		if(m_wkdcspzFlag==false)
			MessageBox("围壳舵参数设置失败，请重新发送");
	}
	if(nIDEvent==2)
	{
		KillTimer(2);
		if(m_fxdcspzFlag==false)
			MessageBox("方向舵参数设置失败，请重新发送");
	}
	if(nIDEvent==3)
	{
		KillTimer(3);
		if(m_zwdcspzFlag==false)
			MessageBox("左艉舵参数设置失败，请重新发送");
	}
	if(nIDEvent==4)
	{
		KillTimer(4);
		if(m_ywdcspzFlag==false)
			MessageBox("右艉舵参数设置失败，请重新发送");
	}
	CDialogEx::OnTimer(nIDEvent);
}




void Cpage3::OnBnClickedButtonCspzSxzk()
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
			MessageBox("写入成功");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}

}


void Cpage3::OnBnClickedCheckCspzSch()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_cspz_sch==TRUE)
	{		CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
		}
		else
		{
			//GetDlgItem(IDC_CHECK_CSPZ_SCH)->OnActivate(false);
			m_cspz_sch=FALSE;
			UpdateData(FALSE);
			MessageBox("密码错误");
		}
	}

	else
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	}
	}
}


BOOL Cpage3::PreTranslateMessage(MSG* pMsg)
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


//void Cpage3::OnBnClickedButtonSpeedLimit()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//}
//
//
//void Cpage3::OnBnClickedCheckSpeedLimitEnable()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	//if(m_speed_limit_flag==true)
//	//{
//	//	GetDlgItem(IDC_EDIT_SPEED_LIMIT)->EnableWindow(true);
//	//	GetDlgItem(IDC_EDIT_SPEED_LIMIT2)->EnableWindow(true);
//	//	GetDlgItem(IDC_BUTTON_SPEED_LIMIT)->EnableWindow(true);
//	//}
//	//else
//	//{
//	//	GetDlgItem(IDC_EDIT_SPEED_LIMIT)->EnableWindow(false);
//	//	GetDlgItem(IDC_EDIT_SPEED_LIMIT2)->EnableWindow(false);
//	//	GetDlgItem(IDC_BUTTON_SPEED_LIMIT)->EnableWindow(false);
//	//}
//}
//void Cpage3::UpdateInf()
//{
//	if(m_wkd==0)
//	{
//		m_fairwater_rudder=abs(m_fairwater_rudder);
//		if(m_fairwater_rudder>22)
//			m_fairwater_rudder=22;
//		p_wkd=m_fairwater_rudder;
//	}
//	if(m_wkd==1)
//	{
//		m_fairwater_rudder2=abs(m_fairwater_rudder2);
//		if(m_fairwater_rudder2>22)
//			m_fairwater_rudder2=22;
//		p_wkd=m_fairwater_rudder2*(-1);
//	}
//	if(m_fxd==0)
//	{
//		m_direction_rudder=abs(m_direction_rudder);
//		if(m_direction_rudder>25)
//			m_direction_rudder=25;
//		p_fxd=m_direction_rudder;
//	}
//	if(m_fxd==1)
//	{
//		m_direction_rudder2=abs(m_direction_rudder2);
//		if(m_direction_rudder2>25)
//			m_direction_rudder2=25;
//		p_fxd=m_direction_rudder2*(-1);
//	}
//	if(m_zywd==0)
//	{
//		m_leftright_rudder=abs(m_leftright_rudder);
//		if(m_leftright_rudder>30)
//			m_leftright_rudder=30;
//		p_zywd=m_leftright_rudder*(-1);
//		
//	}
//	if(m_zywd==1)
//	{
//		m_leftright_rudder2=abs(m_leftright_rudder2);
//		if(m_leftright_rudder2>10)
//			m_leftright_rudder2=10;
//		p_zywd=m_leftright_rudder2;
//	}
//}
//
//
//void Cpage3::OnBnClickedRadioFx()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(m_fxd==0)
//	{
//		m_direction_rudder=abs(m_direction_rudder);
//		if(m_direction_rudder>25)
//			m_direction_rudder=25;
//		p_fxd=m_direction_rudder;
//		/*CString str;
//		str.Format("方向舵%d",p_fxd);
//		MessageBox(str);*/
//	}
//}
//
//void Cpage3::OnBnClickedButtonRudderCtr()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	UpdateInf();
//
//}
//
//
//void Cpage3::OnBnClickedCheckRudderCtrEnable()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	if(true==m_rudder_ctr_flag)
//		UpdateInf();
//}
//
//
//
//void Cpage3::OnBnClickedCheckFxRudderCtrEnable()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	if(true==m_fx_rudder_ctr_flag)
//		UpdateInf();
//}
//
//
//void Cpage3::OnBnClickedCheckZyRudderCtrEnable3()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	if(true==m_zy_rudder_ctr_flag)
//		UpdateInf();
//}
//
//
//void Cpage3::OnBnClickedCheckSpeedCtr()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//}
//
//
//void Cpage3::OnBnClickedCheckSpeedAwmuCmd()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//}
//
//
//void Cpage3::OnBnClickedButtonSpeedTidu()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//}
//
//
//void Cpage3::OnBnClickedButtonSpeedAwmuCmd()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//}
//
//
//
//void Cpage3::OnBnClickedRadioWk()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(m_wkd==0)
//	{
//		m_fairwater_rudder=abs(m_fairwater_rudder);
//		if(m_fairwater_rudder>22)
//			m_fairwater_rudder=22;
//		p_wkd=m_fairwater_rudder;
//		/*CString str;
//		str.Format("围壳舵%d",p_wkd);
//		MessageBox(str);*/
//	}
//}
//
//
//void Cpage3::OnBnClickedRadio2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(m_wkd==1)
//	{
//		m_fairwater_rudder2=abs(m_fairwater_rudder2);
//		if(m_fairwater_rudder2>22)
//			m_fairwater_rudder2=22;
//		p_wkd=m_fairwater_rudder2*(-1);
//		/*CString str;
//		str.Format("围壳舵%d",p_wkd);
//		MessageBox(str);*/
//
//	}
//}


//void Cpage3::OnBnClickedRadioFx()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(m_fxd==0)
//	{
//		m_direction_rudder=abs(m_direction_rudder);
//		if(m_direction_rudder>25)
//			m_direction_rudder=25;
//		p_fxd=m_direction_rudder;
//		CString str;
//		str.Format("方向舵%d",p_fxd);
//		MessageBox(str);
//	}
//}


//void Cpage3::OnBnClickedRadio4()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(m_fxd==1)
//	{
//		m_direction_rudder2=abs(m_direction_rudder2);
//		if(m_direction_rudder2>25)
//			m_direction_rudder2=25;
//		p_fxd=m_direction_rudder2*(-1);
//		/*CString str;
//		str.Format("方向舵%d",p_fxd);
//		MessageBox(str);*/
//	}
//}
//
//
//void Cpage3::OnBnClickedRadioZywd()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(m_zywd==0)
//	{
//		m_leftright_rudder=abs(m_leftright_rudder);
//		if(m_leftright_rudder>30)
//			m_leftright_rudder=30;
//		p_zywd=m_leftright_rudder*(-1);
//		/*CString str;
//		str.Format("左右尾舵%d",p_zywd);
//		MessageBox(str);*/
//	}
//}
//
//
//void Cpage3::OnBnClickedRadio6()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(m_zywd==1)
//	{
//		m_leftright_rudder2=abs(m_leftright_rudder2);
//		if(m_leftright_rudder2>10)
//			m_leftright_rudder2=10;
//		p_zywd=m_leftright_rudder2;
//		/*CString str;
//		str.Format("左右尾舵%d",p_zywd);
//		MessageBox(str);*/
//	}
//}
//
//
//void Cpage3::OnBnClickedCheckShuibengEnable()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	if(0==m_shuibeng)
//	{
//		m_shuibeng_command=true;
//	}
//	if(1==m_shuibeng)
//	{
//		m_shuibeng_command=false;
//	}
//}
//
//
//void Cpage3::OnBnClickedRadioShuibnengStart()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//	if(0==m_shuibeng)
//	{
//		m_shuibeng_command=true;
//	}
//}
//
//
//void Cpage3::OnBnClickedRadioShuibengStop()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(true);
//		if(1==m_shuibeng)
//	{
//		m_shuibeng_command=false;
//	}
//}
