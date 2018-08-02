// RwyzDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "RwyzDlg.h"
#include "afxdialogex.h"
#include "Cpage1.h"
#include "XiaoBiLiDlg.h"


// CRwyzDlg 对话框

IMPLEMENT_DYNAMIC(CRwyzDlg, CDialogEx)

CRwyzDlg::CRwyzDlg(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(CRwyzDlg::IDD, pParent)
{
	m_pDlg=pDlg;
	m_num_hc1 = 50;
	m_num_hc2 = 50;
	m_num_hc3 = 50;
	/*m_z1 = 1.025f;
	m_z2 = 1.025f;
	m_z3 = 1.025f;
	m_z4 = 1.025f;*/
	m_z1 = 10.0f;
	m_z2 = 10.0f;
	m_z3 = 10.0f;
	m_z4 = 10.0f;
	//  m_rwlx = 0;
	m_speed = 1.5f;
	/*m_x1 = _T("112.042088");
	m_x2 = _T("112.042088");
	m_x3 = _T("112.042088");
	m_x4 = _T("112.042088");
	m_y1 = _T("30.975949");
	m_y2 = _T("30.984933");
	m_y3 = _T("30.989424");
	m_y4 = _T("30.998407");
	m_rwlx = 0;*/
	/*m_x1 = _T("111.98680");
	m_x2 = _T("111.988233");
	m_x3 = _T("111.989666");
	m_x4 = _T("111.99110");
	m_y1 = _T("31.01966");
	m_y2 = _T("31.01779");
	m_y3 = _T("31.015926");
	m_y4 = _T("31.01406");
	m_rwlx = 0;*/
	////从起点到终点
	//m_x1 = _T("111.994789");
	//m_x2 = _T("111.992461");
	//m_x3 = _T("111.990132");
	//m_x4 = _T("111.987804");
	//m_y1 = _T("31.023963");
	//m_y2 = _T("31.023980");
	//m_y3 = _T("31.023996");
	//m_y4 = _T("31.024013");
	//m_rwlx = 0;
	////从终点到起点
	//m_x4 = _T("111.994789");
	//m_x3 = _T("111.992461");
	//m_x2 = _T("111.990132");
	//m_x1 = _T("111.987804");
	//m_y4 = _T("31.023963");
	//m_y3 = _T("31.023980");
	//m_y2 = _T("31.023996");
	//m_y1 = _T("31.024013");
	//m_rwlx = 0;
	//测噪从起点到终点
	/*m_x1 = _T("111.98680");
	m_x2 = _T("111.988233");
	m_x3 = _T("111.989667");
	m_x4 = _T("111.99110");
	m_y1 = _T("31.01966");
	m_y2 = _T("31.017793");
	m_y3 = _T("31.015927");
	m_y4 = _T("31.01406");
	m_rwlx = 0;*/
	m_x1 = _T("");
	m_x2 = _T("");
	m_x3 = _T("");
	m_x4 = _T("");
	m_y1 = _T("");
	m_y2 = _T("");
	m_y3 = _T("");
	m_y4 = _T("");
	m_rwlx = 0;
	//  m_speed_kn = _T("");
	m_speed_kn = _T("6");
}

CRwyzDlg::~CRwyzDlg()
{
}

void CRwyzDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HC1_NUM, m_num_hc1);
	DDX_Text(pDX, IDC_EDIT_HC2_NUM, m_num_hc2);
	DDX_Text(pDX, IDC_EDIT_HC3_NUM, m_num_hc3);
	//  DDX_Text(pDX, IDC_EDIT_SPEED, m_speed);
	DDX_Text(pDX, IDC_EDIT_Z1, m_z1);
	DDX_Text(pDX, IDC_EDIT_Z2, m_z2);
	DDX_Text(pDX, IDC_EDIT_Z3, m_z3);
	DDX_Text(pDX, IDC_EDIT_Z4, m_z4);
	//  DDX_Radio(pDX, IDC_RADIO1, m_rwlx);
	//  DDX_Text(pDX, IDC_EDIT_X1, m_x1);
	//  DDX_Text(pDX, IDC_EDIT_X2, m_x2);
	//  DDX_Text(pDX, IDC_EDIT_X3, m_x3);
	//  DDX_Text(pDX, IDC_EDIT_X4, m_x4);
	//  DDX_Text(pDX, IDC_EDIT_Y1, m_y1);
	//  DDX_Text(pDX, IDC_EDIT_Y2, m_y2);
	//  DDX_Text(pDX, IDC_EDIT_Y3, m_y3);
	//  DDX_Text(pDX, IDC_EDIT_Y4, m_y4);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_speed);
	DDX_Text(pDX, IDC_EDIT_X1, m_x1);
	DDX_Text(pDX, IDC_EDIT_X2, m_x2);
	DDX_Text(pDX, IDC_EDIT_X3, m_x3);
	DDX_Text(pDX, IDC_EDIT_X4, m_x4);
	DDX_Text(pDX, IDC_EDIT_Y1, m_y1);
	DDX_Text(pDX, IDC_EDIT_Y2, m_y2);
	DDX_Text(pDX, IDC_EDIT_Y3, m_y3);
	DDX_Text(pDX, IDC_EDIT_Y4, m_y4);
	//  DDX_Radio(pDX, IDC_RADIO4, m_rwlx);
	DDX_Radio(pDX, IDC_RADIO4, m_rwlx);
	DDX_Control(pDX, IDC_COMBO_SPEED, m_speed_ctr);
	//  DDX_CBString(pDX, IDC_COMBO_SPEED, m_speed_kn);
	DDX_CBString(pDX, IDC_COMBO_SPEED, m_speed_kn);
}
BOOL CRwyzDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_speed_ctr.AddString("6");
	m_speed_ctr.AddString("9");
	m_speed_ctr.AddString("10");
	m_speed_ctr.AddString("13");
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BEGIN_MESSAGE_MAP(CRwyzDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_TURN, &CRwyzDlg::OnBnClickedButtonTurn)
	ON_BN_CLICKED(IDOK, &CRwyzDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_READ_INI, &CRwyzDlg::OnBnClickedButtonReadIni)
	ON_BN_CLICKED(IDC_BUTTON_WRITE_INI, &CRwyzDlg::OnBnClickedButtonWriteIni)
	ON_CBN_SELCHANGE(IDC_COMBO_SPEED, &CRwyzDlg::OnCbnSelchangeComboSpeed)
END_MESSAGE_MAP()


// CRwyzDlg 消息处理程序


BOOL CRwyzDlg::PreTranslateMessage(MSG* pMsg)
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





void CRwyzDlg::OnBnClickedButtonTurn()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CString x1_temp,x2_temp,y1_temp,y2_temp;
	x1_temp=m_x1;
	x2_temp=m_x2;
	m_x1 =m_x4;
	m_x2 =m_x3;
	m_x3 =x2_temp;
	m_x4 =x1_temp;
	y1_temp=m_y1;
	y2_temp=m_y2;
	m_y1 = m_y4;
	m_y2 = m_y3;
	m_y3 = y2_temp;
	m_y4 =y1_temp;
	UpdateData(false);
}


void CRwyzDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if((m_num_hc1==0)||(m_num_hc2==0)||(m_num_hc3==0))
		{MessageBox("航程一、航程二、航程三规划出的航迹点个数均不能为0，请重新输入任务！","错误");}
		else
		{
			m_pDlg->page1->rwlx=m_rwlx+1;
			m_pDlg->page1->x11=atof(m_x1);
			m_pDlg->page1->y11=atof(m_y1);
			m_pDlg->page1->z11=m_z1;
			m_pDlg->page1->x12=atof(m_x2);
			m_pDlg->page1->y12=atof(m_y2);
			m_pDlg->page1->z12=m_z2;
			m_pDlg->page1->x21=atof(m_x2);
			m_pDlg->page1->y21=atof(m_y2);
			m_pDlg->page1->z21=m_z2;
			m_pDlg->page1->x22=atof(m_x3);
			m_pDlg->page1->y22=atof(m_y3);
			m_pDlg->page1->z22=m_z3;
			m_pDlg->page1->x31=atof(m_x3);
			m_pDlg->page1->y31=atof(m_y3);
			m_pDlg->page1->z31=m_z3;
			m_pDlg->page1->x32=atof(m_x4);
			m_pDlg->page1->y32=atof(m_y4);
			m_pDlg->page1->z32=m_z4;
			m_pDlg->page1->num_hc1=m_num_hc1;
			m_pDlg->page1->num_hc2=m_num_hc2;
			m_pDlg->page1->num_hc3=m_num_hc3;
			//m_pDlg->page1->speed=(BYTE)(m_speed*10);
			SpeedTransform();
			m_pDlg->page1->GuiHua_hc1();
			m_pDlg->page1->GuiHua_hc2();
			m_pDlg->page1->GuiHua_hc3();
			m_pDlg->page1->Fuzhi_Rwyz();
			//page1->page_rwyz->ShowWindow(false);
		}
	CDialogEx::OnOK();
}

void CRwyzDlg::ReadIni()
{
	char x1[10]="";char x2[10]="";char x3[10]="";char x4[10]="";
	char y1[11]="";char y2[11]="";char y3[11]="";char y4[11]="";
	char z1[6]="";char z2[6]="";char z3[6]="";char z4[6]="";
	GetPrivateProfileString("RWYZ","Y1","31.01966",y1,10,"D:\\SSZKConfig\\config.ini");
    GetPrivateProfileString("RWYZ","X1","111.98680",x1,11,"D:\\SSZKConfig\\config.ini");
		GetPrivateProfileString("RWYZ","Y2","31.017793",y2,10,"D:\\SSZKConfig\\config.ini");
    GetPrivateProfileString("RWYZ","X2","111.988233",x2,11,"D:\\SSZKConfig\\config.ini");
		GetPrivateProfileString("RWYZ","Y3","31.015927",y3,10,"D:\\SSZKConfig\\config.ini");
    GetPrivateProfileString("RWYZ","X3","111.989667",x3,11,"D:\\SSZKConfig\\config.ini");
		GetPrivateProfileString("RWYZ","Y4","31.01406",y4,10,"D:\\SSZKConfig\\config.ini");
    GetPrivateProfileString("RWYZ","X4","111.99110",x4,11,"D:\\SSZKConfig\\config.ini");
	GetPrivateProfileString("RWYZ","Z1","10",z1,6,"D:\\SSZKConfig\\config.ini");
	GetPrivateProfileString("RWYZ","Z2","10",z2,6,"D:\\SSZKConfig\\config.ini");
	GetPrivateProfileString("RWYZ","Z3","10",z3,6,"D:\\SSZKConfig\\config.ini");
	GetPrivateProfileString("RWYZ","Z4","10",z4,6,"D:\\SSZKConfig\\config.ini");
	m_x1=x1;m_x2=x2;m_x3=x3;m_x4=x4;
	m_y1=y1;m_y2=y2;m_y3=y3;m_y4=y4;
	m_z1=atof(z1);m_z2=atof(z2);m_z3=atof(z3);m_z4=atof(z4);
	UpdateData(false);
}
void CRwyzDlg::OnBnClickedButtonReadIni()
{
	// TODO: 在此添加控件通知处理程序代码
	ReadIni();
	
}



void CRwyzDlg::OnBnClickedButtonWriteIni()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	 WritePrivateProfileString("RWYZ","X1",m_x1,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","Y1",m_y1,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","X2",m_x2,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","Y2",m_y2,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","X3",m_x3,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","Y3",m_y3,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","X4",m_x4,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","Y4",m_y4,"D:\\SSZKConfig\\config.ini");
	 CString z1,z2,z3,z4;
	 z1.Format("%f",m_z1);
	 z2.Format("%f",m_z2);
	 z3.Format("%f",m_z3);
	 z4.Format("%f",m_z4);
	 WritePrivateProfileString("RWYZ","Z1",z1,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","Z2",z2,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","Z3",z3,"D:\\SSZKConfig\\config.ini");
	 WritePrivateProfileString("RWYZ","Z4",z4,"D:\\SSZKConfig\\config.ini");
}


void CRwyzDlg::OnCbnSelchangeComboSpeed()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
}
void CRwyzDlg::SpeedTransform()   //把对话框上的kn 转化为运动规划单元能识别的m/s 并赋值给报文值
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	float speed_temp;
	speed_temp=atof(m_speed_kn);  
	if((speed_temp==6)||(speed_temp==9)||(speed_temp==10)||(speed_temp==13))
	{
		if(speed_temp==6)  //kn 
			m_pDlg->page1->speed=3*10;    //  m/s*10
		if(speed_temp==9)
			m_pDlg->page1->speed=4.5*10;
		if(speed_temp==10)
			m_pDlg->page1->speed=5*10;
		if(speed_temp==13)
			m_pDlg->page1->speed=6.5*10;
	}
	else
	{
		m_pDlg->page1->speed=(BYTE)(speed_temp*0.514*10);
	}

}



