// Cpage_config_ydgh.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Cpage_config_ydgh.h"
#include "afxdialogex.h"
#include "Pag_Password.h"

// Cpage_config_ydgh 对话框

IMPLEMENT_DYNAMIC(Cpage_config_ydgh, CDialogEx)

Cpage_config_ydgh::Cpage_config_ydgh(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage_config_ydgh::IDD, pParent)
{

	m_cyc1 = _T("0");
	m_cyc2 = _T("0");
	m_cyc3 = _T("0");
	m_cyc4 = _T("0");
	m_cyct = _T("1.0");
	m_ssv_l = _T("80");
	m_k_e1 = _T("0.5");
	m_k_e2 = _T("0.5");
	m_k_e3 = _T("0.5");
	m_k_e4 = _T("0");
	m_k_e5 = _T("0");
	m_k_e6 = _T("0");
	m_k_h1 = _T("1.00");
	m_k_h2 = _T("0");
	m_k_h3 = _T("0");
	m_k_h4 = _T("0");
	m_k_h5 = _T("0");
	m_k_h6 = _T("0");
	m_kdu1 = _T("55");
	m_kdu2 = _T("0");
	m_kiu1 = _T("0");
	m_kiu2 = _T("0");
	m_kpu1 = _T("10");
	m_speed_a1 = _T("0");
	m_speed_a2 = _T("0");
	m_speed_a3 = _T("0");
	m_speed_a4 = _T("0");
	m_speed_a5 = _T("0");
	m_speed_a6 = _T("0");
	m_kpu2 = _T("0");
	m_deltar_a1 = _T("0");
	m_deltar_a2 = _T("0");
	m_deltar_a3 = _T("0");
	m_deltar_a4 = _T("0");
	m_deltar_a5 = _T("0");
	m_deltar_a6 = _T("0");
	m_kdr1 = _T("30");
	m_kdr2 = _T("30");
	m_kdr3 = _T("65");
	m_kir1 = _T("0");
	m_kir2 = _T("0");
	m_kir3 = _T("0");
	m_kpr1 = _T("42");
	m_kpr2 = _T("14");
	m_kpr3 = _T("10");
	m_ydr = _T("0");
	m_ydb = _T("0.8");
	m_kpb1 = _T("70");
	m_kpb2 = _T("10");
	m_kpb3 = _T("0");
	m_kib1 = _T("0");
	m_kib2 = _T("0");
	m_kib3 = _T("0");
	m_kdb1 = _T("110");
	m_kdb2 = _T("30");
	m_kdb3 = _T("0");
	m_deltab_a1 = _T("0");
	m_deltab_a2 = _T("0");
	m_deltab_a3 = _T("0");
	m_deltab_a4 = _T("0");
	m_deltab_a5 = _T("0");
	m_deltab_a6 = _T("0");
	m_deltas_a1 = _T("0");
	m_deltas_a2 = _T("0");
	m_deltas_a3 = _T("0");
	m_deltas_a4 = _T("0");
	m_deltas_a5 = _T("0");
	m_deltas_a6 = _T("0");
	m_kds1 = _T("27");
	m_kds2 = _T("0");
	m_kds3 = _T("0");
	m_kis1 = _T("0");
	m_kis2 = _T("0");
	m_kis3 = _T("0");
	m_kps1 = _T("33");
	m_kps2 = _T("0");
	m_yds = _T("0");
	m_kps3 = _T("0");
}

Cpage_config_ydgh::~Cpage_config_ydgh()
{
}

void Cpage_config_ydgh::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CYC1, m_cyc1);
	DDX_Text(pDX, IDC_EDIT_CYC2, m_cyc2);
	DDX_Text(pDX, IDC_EDIT_CYC3, m_cyc3);
	DDX_Text(pDX, IDC_EDIT_CYC4, m_cyc4);
	DDX_Text(pDX, IDC_EDIT_CYCT, m_cyct);
	DDX_Text(pDX, IDC_EDIT_SSV_L, m_ssv_l);
	DDX_Text(pDX, IDC_EDIT_K_E1, m_k_e1);
	DDX_Text(pDX, IDC_EDIT_K_E2, m_k_e2);
	DDX_Text(pDX, IDC_EDIT_K_E3, m_k_e3);
	DDX_Text(pDX, IDC_EDIT_K_E4, m_k_e4);
	DDX_Text(pDX, IDC_EDIT_K_E5, m_k_e5);
	DDX_Text(pDX, IDC_EDIT_K_E6, m_k_e6);
	DDX_Text(pDX, IDC_EDIT_K_H1, m_k_h1);
	DDX_Text(pDX, IDC_EDIT_K_H2, m_k_h2);
	DDX_Text(pDX, IDC_EDIT_K_H3, m_k_h3);
	DDX_Text(pDX, IDC_EDIT_K_H4, m_k_h4);
	DDX_Text(pDX, IDC_EDIT_K_H5, m_k_h5);
	DDX_Text(pDX, IDC_EDIT_K_H6, m_k_h6);
	DDX_Text(pDX, IDC_EDIT_KDU1, m_kdu1);
	DDX_Text(pDX, IDC_EDIT_KDU2, m_kdu2);
	DDX_Text(pDX, IDC_EDIT_KIU1, m_kiu1);
	DDX_Text(pDX, IDC_EDIT_KIU2, m_kiu2);
	DDX_Text(pDX, IDC_EDIT_KPU1, m_kpu1);
	DDX_Text(pDX, IDC_EDIT_SPEED_A1, m_speed_a1);
	DDX_Text(pDX, IDC_EDIT_SPEED_A2, m_speed_a2);
	DDX_Text(pDX, IDC_EDIT_SPEED_A3, m_speed_a3);
	DDX_Text(pDX, IDC_EDIT_SPEED_A4, m_speed_a4);
	DDX_Text(pDX, IDC_EDIT_SPEED_A5, m_speed_a5);
	DDX_Text(pDX, IDC_EDIT_SPEED_A6, m_speed_a6);
	DDX_Text(pDX, IDC_EDIT_KPU2, m_kpu2);
	DDX_Text(pDX, IDC_EDIT_DELTAR_A1, m_deltar_a1);
	DDX_Text(pDX, IDC_EDIT_DELTAR_A2, m_deltar_a2);
	DDX_Text(pDX, IDC_EDIT_DELTAR_A3, m_deltar_a3);
	DDX_Text(pDX, IDC_EDIT_DELTAR_A4, m_deltar_a4);
	DDX_Text(pDX, IDC_EDIT_DELTAR_A5, m_deltar_a5);
	DDX_Text(pDX, IDC_EDIT_DELTAR_A6, m_deltar_a6);
	DDX_Text(pDX, IDC_EDIT_KDR1, m_kdr1);
	DDX_Text(pDX, IDC_EDIT_KDR2, m_kdr2);
	DDX_Text(pDX, IDC_EDIT_KDR3, m_kdr3);
	DDX_Text(pDX, IDC_EDIT_KIR1, m_kir1);
	DDX_Text(pDX, IDC_EDIT_KIR2, m_kir2);
	DDX_Text(pDX, IDC_EDIT_KIR3, m_kir3);
	DDX_Text(pDX, IDC_EDIT_KPR1, m_kpr1);
	DDX_Text(pDX, IDC_EDIT_KPR2, m_kpr2);
	DDX_Text(pDX, IDC_EDIT_KPR3, m_kpr3);
	DDX_Text(pDX, IDC_EDIT_YDR, m_ydr);
	DDX_Text(pDX, IDC_EDIT_YDB, m_ydb);
	DDX_Text(pDX, IDC_EDIT_KPB1, m_kpb1);
	DDX_Text(pDX, IDC_EDIT_KPB2, m_kpb2);
	DDX_Text(pDX, IDC_EDIT_KPB3, m_kpb3);
	DDX_Text(pDX, IDC_EDIT_KIB1, m_kib1);
	DDX_Text(pDX, IDC_EDIT_KIB2, m_kib2);
	DDX_Text(pDX, IDC_EDIT_KIB3, m_kib3);
	DDX_Text(pDX, IDC_EDIT_KDB1, m_kdb1);
	DDX_Text(pDX, IDC_EDIT_KDB2, m_kdb2);
	DDX_Text(pDX, IDC_EDIT_KDB3, m_kdb3);
	DDX_Text(pDX, IDC_EDIT_DELTAB_A1, m_deltab_a1);
	DDX_Text(pDX, IDC_EDIT_DELTAB_A2, m_deltab_a2);
	DDX_Text(pDX, IDC_EDIT_DELTAB_A3, m_deltab_a3);
	DDX_Text(pDX, IDC_EDIT_DELTAB_A4, m_deltab_a4);
	DDX_Text(pDX, IDC_EDIT_DELTAB_A5, m_deltab_a5);
	DDX_Text(pDX, IDC_EDIT_DELTAB_A6, m_deltab_a6);
	DDX_Text(pDX, IDC_EDIT_DELTAS_A1, m_deltas_a1);
	DDX_Text(pDX, IDC_EDIT_DELTAS_A2, m_deltas_a2);
	DDX_Text(pDX, IDC_EDIT_DELTAS_A3, m_deltas_a3);
	DDX_Text(pDX, IDC_EDIT_DELTAS_A4, m_deltas_a4);
	DDX_Text(pDX, IDC_EDIT_DELTAS_A5, m_deltas_a5);
	DDX_Text(pDX, IDC_EDIT_DELTAS_A6, m_deltas_a6);
	DDX_Text(pDX, IDC_EDIT_KDS1, m_kds1);
	DDX_Text(pDX, IDC_EDIT_KDS2, m_kds2);
	DDX_Text(pDX, IDC_EDIT_KDS3, m_kds3);
	DDX_Text(pDX, IDC_EDIT_KIS1, m_kis1);
	DDX_Text(pDX, IDC_EDIT_KIS2, m_kis2);
	DDX_Text(pDX, IDC_EDIT_KIS3, m_kis3);
	DDX_Text(pDX, IDC_EDIT_KPS1, m_kps1);
	DDX_Text(pDX, IDC_EDIT_KPS2, m_kps2);
	DDX_Text(pDX, IDC_EDIT_YDS, m_yds);
	DDX_Text(pDX, IDC_EDIT_KPS3, m_kps3);
}


BEGIN_MESSAGE_MAP(Cpage_config_ydgh, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cpage_config_ydgh::OnBnClickedButton1)
//	ON_BN_CLICKED(IDC_BUTTON_SCPZWJ_SXZH, &Cpage_config_ydgh::OnBnClickedButtonScpzwjSxzh)
END_MESSAGE_MAP()


// Cpage_config_ydgh 消息处理程序


void Cpage_config_ydgh::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CPag_Password dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_password=="hust")
		{
			UpdateData(TRUE);
			CString PathStr;
			GetPrivateProfileString("IniFilePath","YDGH","默认路径",PathStr.GetBuffer(MAX_PATH),MAX_PATH,"D:\\SSZKConfig\\config.ini");
			WritePrivateProfileString("Parameter","cyct",m_cyct,PathStr);
			WritePrivateProfileString("Parameter","SSV_L",m_ssv_l,PathStr);
			WritePrivateProfileString("Parameter","cyc1",m_cyc1,PathStr);
			WritePrivateProfileString("Parameter","cyc2",m_cyc2,PathStr);
			WritePrivateProfileString("Parameter","cyc3",m_cyc3,PathStr);
			WritePrivateProfileString("Parameter","cyc4",m_cyc4,PathStr);
			WritePrivateProfileString("error","k_e1",m_k_e1,PathStr);
			WritePrivateProfileString("error","k_e2",m_k_e2,PathStr);
			WritePrivateProfileString("error","k_e3",m_k_e3,PathStr);
			WritePrivateProfileString("error","k_e4",m_k_e4,PathStr);
			WritePrivateProfileString("error","k_e5",m_k_e5,PathStr);
			WritePrivateProfileString("error","k_e6",m_k_e6,PathStr);
			WritePrivateProfileString("error","k_h1",m_k_h1,PathStr);
			WritePrivateProfileString("error","k_h2",m_k_h2,PathStr);
			WritePrivateProfileString("error","k_h3",m_k_h3,PathStr);
			WritePrivateProfileString("error","k_h4",m_k_h4,PathStr);
			WritePrivateProfileString("error","k_h5",m_k_h5,PathStr);
			WritePrivateProfileString("error","k_h6",m_k_h6,PathStr);
			WritePrivateProfileString("PIDSpeed","Kpu1",m_kpu1,PathStr);
			WritePrivateProfileString("PIDSpeed","Kiu1",m_kiu1,PathStr);
			WritePrivateProfileString("PIDSpeed","Kdu1",m_kdu1,PathStr);
			WritePrivateProfileString("PIDSpeed","Kpu2",m_kpu2,PathStr);
			WritePrivateProfileString("PIDSpeed","Kiu2",m_kiu2,PathStr);
			WritePrivateProfileString("PIDSpeed","Kdu2",m_kdu2,PathStr);
			WritePrivateProfileString("PIDSpeed","Speed_a1",m_speed_a1,PathStr);
			WritePrivateProfileString("PIDSpeed","Speed_a2",m_speed_a2,PathStr);
			WritePrivateProfileString("PIDSpeed","Speed_a3",m_speed_a3,PathStr);
			WritePrivateProfileString("PIDSpeed","Speed_a4",m_speed_a4,PathStr);
			WritePrivateProfileString("PIDSpeed","Speed_a5",m_speed_a5,PathStr);
			WritePrivateProfileString("PIDSpeed","Speed_a6",m_speed_a6,PathStr);
			WritePrivateProfileString("PIDdeltar","Kpr1",m_kpr1,PathStr);
			WritePrivateProfileString("PIDdeltar","Kir1",m_kir1,PathStr);
			WritePrivateProfileString("PIDdeltar","Kdr1",m_kdr1,PathStr);
			WritePrivateProfileString("PIDdeltar","Kpr2",m_kpr2,PathStr);
			WritePrivateProfileString("PIDdeltar","Kir2",m_kir2,PathStr);
			WritePrivateProfileString("PIDdeltar","Kdr2",m_kdr2,PathStr);
			WritePrivateProfileString("PIDdeltar","Kpr3",m_kpr3,PathStr);
			WritePrivateProfileString("PIDdeltar","Kir3",m_kir3,PathStr);
			WritePrivateProfileString("PIDdeltar","Kdr3",m_kdr3,PathStr);
			WritePrivateProfileString("PIDdeltar","deltar_a1",m_deltar_a1,PathStr);
			WritePrivateProfileString("PIDdeltar","deltar_a2",m_deltar_a2,PathStr);
			WritePrivateProfileString("PIDdeltar","deltar_a3",m_deltar_a3,PathStr);
			WritePrivateProfileString("PIDdeltar","deltar_a4",m_deltar_a4,PathStr);
			WritePrivateProfileString("PIDdeltar","deltar_a5",m_deltar_a5,PathStr);
			WritePrivateProfileString("PIDdeltar","deltar_a6",m_deltar_a6,PathStr);
			WritePrivateProfileString("PIDdeltar","ydr",m_ydr,PathStr);
			WritePrivateProfileString("PIDdeltab","Kpb1",m_kpb1,PathStr);
			WritePrivateProfileString("PIDdeltab","Kib1",m_kib1,PathStr);
			WritePrivateProfileString("PIDdeltab","Kdb1",m_kdb1,PathStr);
			WritePrivateProfileString("PIDdeltab","Kpb2",m_kpb2,PathStr);
			WritePrivateProfileString("PIDdeltab","Kib2",m_kib2,PathStr);
			WritePrivateProfileString("PIDdeltab","Kdb2",m_kdb2,PathStr);
			WritePrivateProfileString("PIDdeltab","Kpb3",m_kpb3,PathStr);
			WritePrivateProfileString("PIDdeltab","Kib3",m_kib3,PathStr);
			WritePrivateProfileString("PIDdeltab","Kdb3",m_kdb3,PathStr);
			WritePrivateProfileString("PIDdeltab","deltab_a1",m_deltab_a1,PathStr);
			WritePrivateProfileString("PIDdeltab","deltab_a2",m_deltab_a2,PathStr);
			WritePrivateProfileString("PIDdeltab","deltab_a3",m_deltab_a3,PathStr);
			WritePrivateProfileString("PIDdeltab","deltab_a4",m_deltab_a4,PathStr);
			WritePrivateProfileString("PIDdeltab","deltab_a5",m_deltab_a5,PathStr);
			WritePrivateProfileString("PIDdeltab","deltab_a6",m_deltab_a6,PathStr);
			WritePrivateProfileString("PIDdeltab","ydb",m_ydb,PathStr);
			WritePrivateProfileString("PIDdeltas","Kps1",m_kps1,PathStr);
			WritePrivateProfileString("PIDdeltas","Kis1",m_kis1,PathStr);
			WritePrivateProfileString("PIDdeltas","Kds1",m_kds1,PathStr);
			WritePrivateProfileString("PIDdeltas","Kps2",m_kps2,PathStr);
			WritePrivateProfileString("PIDdeltas","Kis2",m_kis2,PathStr);
			WritePrivateProfileString("PIDdeltas","Kds2",m_kds2,PathStr);
			WritePrivateProfileString("PIDdeltas","Kps3",m_kps3,PathStr);
			WritePrivateProfileString("PIDdeltas","Kis3",m_kis3,PathStr);
			WritePrivateProfileString("PIDdeltas","Kds3",m_kds3,PathStr);
			WritePrivateProfileString("PIDdeltas","deltas_a1",m_deltas_a1,PathStr);
			WritePrivateProfileString("PIDdeltas","deltas_a2",m_deltas_a2,PathStr);
			WritePrivateProfileString("PIDdeltas","deltas_a3",m_deltas_a3,PathStr);
			WritePrivateProfileString("PIDdeltas","deltas_a4",m_deltas_a4,PathStr);
			WritePrivateProfileString("PIDdeltas","deltas_a5",m_deltas_a5,PathStr);
			WritePrivateProfileString("PIDdeltas","deltas_a6",m_deltas_a6,PathStr);
			WritePrivateProfileString("PIDdeltas","yds",m_yds,PathStr);
			MessageBox("发送成功");
		}
		else
		{
            UpdateData(FALSE);
			MessageBox("密码错误");
		}

	}

}





BOOL Cpage_config_ydgh::PreTranslateMessage(MSG* pMsg)
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
