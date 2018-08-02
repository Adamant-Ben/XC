// Page_nau_config.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page_nau_config.h"
#include "afxdialogex.h"
#include "Pag_Password.h"

// CPage_nau_config �Ի���

IMPLEMENT_DYNAMIC(CPage_nau_config, CDialogEx)

CPage_nau_config::CPage_nau_config(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage_nau_config::IDD, pParent)
{
	m_pDlg=pDlg;
	m_Altimeter1_BaudRate = _T("9600");
	m_Altimeter1_BoardNo = _T("1");
	m_Altimeter1_ChannelNo = _T("1");
	m_Altimeter1_RcvLevel = _T("10");
	m_clientPortNumber = _T("2004");
	m_Depther_BaudRate = _T("19200");
	m_Depther_BoardNo = _T("2");
	m_Depther_ChannelNo = _T("2");
	m_Depther_RcvLevel = _T("13");
	m_DVL_BaudRate = _T("19200");
	m_DVL_BoardNo = _T("2");
	m_DVL_ChannelNo = _T("0");
	m_DVL_RcvLevel = _T("1");
	m_EMU_BaudRate = _T("19200");
	m_EMU_CpuSerialName = _T("/tyCo/0");
	m_GPS_BaudRate = _T("19200");
	m_GPS_BoardNo = _T("1");
	m_GPS_ChannelNo = _T("3");
	m_GPS_RcvLevel = _T("1");
	m_LRPA200_BaudRate = _T("9600");
	m_LRPA200_BoardNo = _T("0");
	m_LRPA200_ChannelNo = _T("1");
	m_LRPA200_RcvLevel = _T("11");
	m_NavigationUnit = _T("192.168.0.104");
	m_PHINS_BaudRate = _T("57600");
	m_PHINS_BoardNo = _T("0");
	m_PHINS_ChannelNo = _T("0");
	m_PHINS_RcvLevel = _T("1");
	m_SeverPortNumber = _T("2003");
	m_UnderWaterMaster = _T("192.168.0.103");
}

CPage_nau_config::~CPage_nau_config()
{
}

void CPage_nau_config::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Altimeter1_BaudRate, m_Altimeter1_BaudRate);
	DDX_Text(pDX, IDC_EDIT_Altimeter1_BoardNo, m_Altimeter1_BoardNo);
	DDX_Text(pDX, IDC_EDIT_Altimeter1_ChannelNo, m_Altimeter1_ChannelNo);
	DDX_Text(pDX, IDC_EDIT_Altimeter1_RcvLevel, m_Altimeter1_RcvLevel);
	DDX_Text(pDX, IDC_EDIT_clientPortNumber, m_clientPortNumber);
	DDX_Text(pDX, IDC_EDIT_Depther_BaudRate, m_Depther_BaudRate);
	DDX_Text(pDX, IDC_EDIT_Depther_BoardNo, m_Depther_BoardNo);
	DDX_Text(pDX, IDC_EDIT_Depther_ChannelNo, m_Depther_ChannelNo);
	DDX_Text(pDX, IDC_EDIT_Depther_RcvLevel, m_Depther_RcvLevel);
	DDX_Text(pDX, IDC_EDIT_DVL_BaudRate, m_DVL_BaudRate);
	DDX_Text(pDX, IDC_EDIT_DVL_BoardNo, m_DVL_BoardNo);
	DDX_Text(pDX, IDC_EDIT_DVL_ChannelNo, m_DVL_ChannelNo);
	DDX_Text(pDX, IDC_EDIT_DVL_RcvLevel, m_DVL_RcvLevel);
	DDX_Text(pDX, IDC_EDIT_EMU_BaudRate, m_EMU_BaudRate);
	DDX_Text(pDX, IDC_EDIT_EMU_CpuSerialName, m_EMU_CpuSerialName);
	DDX_Text(pDX, IDC_EDIT_GPS_BaudRate, m_GPS_BaudRate);
	DDX_Text(pDX, IDC_EDIT_GPS_BoardNo, m_GPS_BoardNo);
	DDX_Text(pDX, IDC_EDIT_GPS_ChannelNo, m_GPS_ChannelNo);
	DDX_Text(pDX, IDC_EDIT_GPS_RcvLevel, m_GPS_RcvLevel);
	DDX_Text(pDX, IDC_EDIT_LRPA200_BaudRate, m_LRPA200_BaudRate);
	DDX_Text(pDX, IDC_EDIT_LRPA200_BoardNo, m_LRPA200_BoardNo);
	DDX_Text(pDX, IDC_EDIT_LRPA200_ChannelNo, m_LRPA200_ChannelNo);
	DDX_Text(pDX, IDC_EDIT_LRPA200_RcvLevel, m_LRPA200_RcvLevel);
	DDX_Text(pDX, IDC_EDIT_NavigationUnit, m_NavigationUnit);
	DDX_Text(pDX, IDC_EDIT_PHINS_BaudRate, m_PHINS_BaudRate);
	DDX_Text(pDX, IDC_EDIT_PHINS_BoardNo, m_PHINS_BoardNo);
	DDX_Text(pDX, IDC_EDIT_PHINS_ChannelNo, m_PHINS_ChannelNo);
	DDX_Text(pDX, IDC_EDIT_PHINS_RcvLevel, m_PHINS_RcvLevel);
	DDX_Text(pDX, IDC_EDIT_SeverPortNumber, m_SeverPortNumber);
	DDX_Text(pDX, IDC_EDIT_UnderWaterMaster, m_UnderWaterMaster);
}


BEGIN_MESSAGE_MAP(CPage_nau_config, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_NAU_PARA_CONGIRM, &CPage_nau_config::OnBnClickedButtonNauParaCongirm)
//	ON_EN_CHANGE(IDC_EDIT_GPS_ChannelNo, &CPage_nau_config::OnEnChangeEditGpsChannelno)
END_MESSAGE_MAP()


// CPage_nau_config ��Ϣ�������


void CPage_nau_config::OnBnClickedButtonNauParaCongirm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			CString PathStr;
			GetPrivateProfileString("IniFilePath","NAU","Ĭ��·��",PathStr.GetBuffer(MAX_PATH),MAX_PATH,"D:\\SSZKConfig\\config.ini");
			WritePrivateProfileString("IP_ADDR","SeverPortNumber",m_SeverPortNumber,PathStr);
			WritePrivateProfileString("IP_ADDR","UnderWaterMaster",m_UnderWaterMaster,PathStr);
			WritePrivateProfileString("IP_ADDR","clientPortNumber",m_clientPortNumber,PathStr);
			WritePrivateProfileString("IP_ADDR","NavigationUnit",m_NavigationUnit,PathStr);
			WritePrivateProfileString("IP_ADDR","PHINS_BoardNo",m_PHINS_BoardNo,PathStr);
			WritePrivateProfileString("IP_ADDR","PHINS_ChannelNo",m_PHINS_ChannelNo,PathStr);
			WritePrivateProfileString("IP_ADDR","PHINS_BaudRate",m_PHINS_BaudRate,PathStr);
			WritePrivateProfileString("IP_ADDR","PHINS_RcvLevel",m_PHINS_RcvLevel,PathStr);
			WritePrivateProfileString("IP_ADDR","Altimeter1_BoardNo",m_Altimeter1_BoardNo,PathStr);
			WritePrivateProfileString("IP_ADDR","Altimeter1_ChannelNo",m_Altimeter1_ChannelNo,PathStr);
			WritePrivateProfileString("IP_ADDR","Altimeter1_BaudRate",m_Altimeter1_BaudRate,PathStr);
			WritePrivateProfileString("IP_ADDR","Altimeter1_RcvLevel",m_Altimeter1_RcvLevel,PathStr);
			WritePrivateProfileString("IP_ADDR","LRPA200_BoardNo",m_LRPA200_BoardNo,PathStr);
			WritePrivateProfileString("IP_ADDR","LRPA200_ChannelNo",m_LRPA200_ChannelNo,PathStr);
			WritePrivateProfileString("IP_ADDR","LRPA200_BaudRate",m_LRPA200_BaudRate,PathStr);
			WritePrivateProfileString("IP_ADDR","LRPA200_RcvLevel",m_LRPA200_RcvLevel,PathStr);
			WritePrivateProfileString("IP_ADDR","GPS_BoardNo",m_GPS_BoardNo,PathStr);
			WritePrivateProfileString("IP_ADDR","GPS_ChannelNo",m_GPS_ChannelNo,PathStr);
			WritePrivateProfileString("IP_ADDR","GPS_BaudRate",m_GPS_BaudRate,PathStr);
			WritePrivateProfileString("IP_ADDR","GPS_RcvLevel",m_GPS_RcvLevel,PathStr);
			WritePrivateProfileString("IP_ADDR","DVL_BoardNo",m_DVL_BoardNo,PathStr);
			WritePrivateProfileString("IP_ADDR","DVL_ChannelNo",m_DVL_ChannelNo,PathStr);
			WritePrivateProfileString("IP_ADDR","DVL_BaudRate",m_DVL_BaudRate,PathStr);
			WritePrivateProfileString("IP_ADDR","DVL_RcvLevel",m_DVL_RcvLevel,PathStr);
			WritePrivateProfileString("IP_ADDR","Depther_BoardNo",m_Depther_BoardNo,PathStr);
			WritePrivateProfileString("IP_ADDR","Depther_ChannelNo",m_Depther_ChannelNo,PathStr);
			WritePrivateProfileString("IP_ADDR","Depther_BaudRate",m_Depther_BaudRate,PathStr);
			WritePrivateProfileString("IP_ADDR","Depther_RcvLevel",m_Depther_RcvLevel,PathStr);
			WritePrivateProfileString("IP_ADDR","EMU_CpuSerialName",m_EMU_CpuSerialName,PathStr);
			WritePrivateProfileString("IP_ADDR","EMU_BaudRate",m_EMU_BaudRate,PathStr);
			MessageBox("���ͳɹ�");
		}
		else
		{
			UpdateData(FALSE);
			MessageBox("�������");
		}

	}
}


//void CPage_nau_config::OnEnChangeEditGpsChannelno()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


BOOL CPage_nau_config::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
    {
        // �����Ϣ�Ǽ��̰����¼�������Esc����ִ�����´��루ʲô��������������Լ������Ҫ�Ĵ��룩
        return TRUE;
    }
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        // �����Ϣ�Ǽ��̰����¼�������Entert����ִ�����´��루ʲô��������������Լ������Ҫ�Ĵ��룩
        return TRUE;
    }
	return CDialogEx::PreTranslateMessage(pMsg);
}
