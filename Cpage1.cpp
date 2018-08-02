// Cpage1.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Cpage1.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include "DLL.h"
#include "Rwck.h"
#include "RwyzDlg.h"
#include <fstream>
#include<sys/timeb.h>
using namespace std;

// Cpage1 对话框

IMPLEMENT_DYNAMIC(Cpage1, CDialogEx)

Cpage1::Cpage1(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage1::IDD, pParent)
{
	m_pocuEnable=FALSE;
	m_nauEnable=TRUE;
	m_emuEnable=TRUE;
	m_dsuEnable=TRUE;
	m_prcuEnable=FALSE;
	m_meuEnable=TRUE;
	str1="";
	str2="";
	str3="";
	m_pDlg1=pDlg;
	//m_zqtj = 0.0f;
	//m_zwddj = 0.0f;
	//m_tjqzs = 0.0f;
	//m_wkddj = 0.0f;
	//m_ywddj = 0.0f;
	//m_fxddj = 0.0f;
	num_hc1=0;
	num_hc2=0;
	num_hc3=0;
	m_imagelist[0] = IDB_BITMAP_GRAY;
	m_imagelist[1] = IDB_BITMAP_GREEN;
	m_imagelist[2] = IDB_BITMAP_RED;
	int m_image[35]= {IDC_PICTURE_1,IDC_PICTURE_2,IDC_PICTURE_3,IDC_PICTURE_4,IDC_PICTURE_5,IDC_PICTURE_6,IDC_PICTURE_7,IDC_PICTURE_8,IDC_PICTURE_9,
		IDC_PICTURE_10,IDC_PICTURE_11,IDC_PICTURE_12,IDC_PICTURE_13,IDC_PICTURE_SS_SCH_CK,IDC_PICTURE_17,IDC_PICTURE_18,
		IDC_PICTURE_19,IDC_PICTURE_20,IDC_PICTURE_21,IDC_PICTURE_22,IDC_PICTURE_23,IDC_PICTURE_24,IDC_PICTURE_25,IDC_PICTURE_SS_SX_WXD,IDC_PICTURE_27,
		IDC_PICTURE_28,IDC_PICTURE_29,IDC_PICTURE_30,IDC_PICTURE_31,IDC_PICTURE_32,IDC_PICTURE_33,IDC_PICTURE_34,IDC_PICTURE_35,IDC_PICTURE_36,
		IDC_PICTURE_37};
	for( int i = 0; i < 35; i++)
	{
		m_showimage[i]=m_image[i];
	}
	strcpy_s(rwyz,"");
	pdata_page1=(Data_page1*)malloc(sizeof(Data_page1));
	memset(pdata_page1,0,sizeof(Data_page1));
	m_wd_cmd_down = 0;
	m_wd_cmd_up = 0;
	m_wkd_cmd_down = 0;
	m_wkd_cmd_up = 0;
	m_fxd_cmd_l = 0;
	m_fxd_cmd_r = 0;
	m_speed_cmd = 0;
	m_second_num = 0;
	p_wkd=0;
	p_fxd=0;
	p_zywd=0;
}

Cpage1::~Cpage1()
{
	
}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT_ZQTJ, m_zqtj);
	//DDX_Text(pDX, IDC_EDIT_ZWDDJ, m_zwddj);
	//DDX_Text(pDX, IDC_EDIT_TJQZS, m_tjqzs);
	//DDX_Text(pDX, IDC_EDIT_WKDDJ, m_wkddj);
	//DDX_Text(pDX, IDC_EDIT_YWDDJ, m_ywddj);
	//DDX_Text(pDX, IDC_EDIT_FXDDJ, m_fxddj);
	DDX_Check(pDX, IDC_CHECK_KSDD, m_ksdd_flag);
	//  DDX_Check(pDX, IDC_CHECK_DDDLXT, m_dddlxt);
	DDX_Check(pDX, IDC_CHECK_DSU_ENABLE, m_dsuEnable);
	DDX_Check(pDX, IDC_CHECK_EMU_ENABLE, m_emuEnable);
	//  DDX_Check(pDX, IDC_CHECK_MPU_ENABLE, m_mpuEnable);
	DDX_Check(pDX, IDC_CHECK_NAU_ENABLE, m_nauEnable);
	DDX_Check(pDX, IDC_CHECK_PRCU_ENABLE, m_prcuEnable);
	DDX_Check(pDX, IDC_CHECK_DDDLXT, m_pocuEnable);
	DDX_Check(pDX, IDC_CHECK_MEU_ENABLE, m_meuEnable);
	DDX_Check(pDX, IDC_CHECK_WKD_CTR_ENABLE, m_wkd_ctr_enable);
	DDX_Check(pDX, IDC_CHECK_WD_CTR_ENABLE, m_wd_ctr_enable);
	DDX_Check(pDX, IDC_CHECK_FXD_CTR_ENABLE, m_fxd_ctr_enable);
	DDX_Check(pDX, IDC_CHECK_SPEED_CMD, m_speed_ctr_enable);
	//  DDX_Radio(pDX, IDC_RADIO_FXD_CMD, m_fxd_up);
	DDX_Radio(pDX, IDC_RADIO_START_SHUIBENG, m_shuibeng_start);
	DDX_Radio(pDX, IDC_RADIO_WD_CMD, m_wd_up);
	DDX_Radio(pDX, IDC_RADIO_FXD_CMD, m_fxd_l);
	DDX_Radio(pDX, IDC_RADIO_WKD_CMD, m_wkd_up);
	DDX_Text(pDX, IDC_EDIT_WD_CMD_DOWN, m_wd_cmd_down);
	DDX_Text(pDX, IDC_EDIT_WD_CMD_UP, m_wd_cmd_up);
	DDX_Text(pDX, IDC_EDIT_WKD_CMD_DOWN, m_wkd_cmd_down);
	DDX_Text(pDX, IDC_EDIT_WKD_CMD_UP, m_wkd_cmd_up);
	DDX_Text(pDX, IDC_EDIT_FXD_CMD_L, m_fxd_cmd_l);
	DDX_Text(pDX, IDC_EDIT_FXD_CMD_R, m_fxd_cmd_r);
	DDX_Check(pDX, IDC_CHECK_CTR_SHUIBENG_ENABLE, m_shuibeng_ctr_enable);
	DDX_Text(pDX, IDC_EDIT_SPEED_CMD, m_speed_cmd);
	DDX_Text(pDX, IDC_EDIT_AUTO_TIMER, m_second_num);
}


BEGIN_MESSAGE_MAP(Cpage1, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_RWZJ, &Cpage1::OnBnClickedButtonRwzj)
	ON_BN_CLICKED(IDC_BUTTON_RWXZ, &Cpage1::OnBnClickedButtonRwxz)
	ON_BN_CLICKED(IDC_BUTTON_RWCK, &Cpage1::OnBnClickedButtonRwck)
	ON_BN_CLICKED(IDC_BUTTON_RWSC, &Cpage1::OnBnClickedButtonRwsc)
	ON_BN_CLICKED(IDC_BUTTON_RWJL, &Cpage1::OnBnClickedButtonRwjl)
	ON_BN_CLICKED(IDC_BUTTON_TXZTCX, &Cpage1::OnBnClickedButtonTxztcx)
	ON_BN_CLICKED(IDC_CHECK_KSDD, &Cpage1::OnBnClickedCheckKsdd)
	ON_BN_CLICKED(IDC_CHECK_DDDLXT, &Cpage1::OnBnClickedCheckDddlxt)
	ON_BN_CLICKED(IDC_CHECK_PRCU_ENABLE, &Cpage1::OnBnClickedCheckPrcuEnable)
	ON_BN_CLICKED(IDC_CHECK_NAU_ENABLE, &Cpage1::OnBnClickedCheckNauEnable)
	ON_BN_CLICKED(IDC_CHECK_EMU_ENABLE, &Cpage1::OnBnClickedCheckEmuEnable)
	ON_BN_CLICKED(IDC_CHECK_DSU_ENABLE, &Cpage1::OnBnClickedCheckDsuEnable)
	ON_BN_CLICKED(IDC_BUTTON_TIME_SET, &Cpage1::OnBnClickedButtonTimeSet)
	ON_BN_CLICKED(IDC_BUTTON_UWMU_W_RECNET, &Cpage1::OnBnClickedButtonUwmuWRecnet)
	ON_BN_CLICKED(IDC_BUTTON_EMU_W_RECNET, &Cpage1::OnBnClickedButtonEmuWRecnet)
	ON_BN_CLICKED(IDC_CHECK_MEU_ENABLE, &Cpage1::OnBnClickedCheckMeuEnable)
	ON_BN_CLICKED(IDC_BUTTON2, &Cpage1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_TO_WXD, &Cpage1::OnBnClickedButtonToWxd)
	ON_BN_CLICKED(IDC_RADIO_WKD_CMD, &Cpage1::OnBnClickedRadioWkdCmd)
	ON_BN_CLICKED(IDC_RADIO3, &Cpage1::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_CHECK_WKD_CTR_ENABLE, &Cpage1::OnBnClickedCheckWkdCtrEnable)
	ON_BN_CLICKED(IDC_CHECK_FXD_CTR_ENABLE, &Cpage1::OnBnClickedCheckFxdCtrEnable)
	ON_BN_CLICKED(IDC_RADIO_FXD_CMD_L, &Cpage1::OnBnClickedRadioFxdCmdL)
	ON_BN_CLICKED(IDC_RADIO_FXD_CMD_R, &Cpage1::OnBnClickedRadioFxdCmdR)
	ON_BN_CLICKED(IDC_CHECK_WD_CTR_ENABLE, &Cpage1::OnBnClickedCheckWdCtrEnable)
	ON_BN_CLICKED(IDC_RADIO_WD_CMD_UP, &Cpage1::OnBnClickedRadioWdCmdUp)
	ON_BN_CLICKED(IDC_RADIO_WD_CMD_DOWN, &Cpage1::OnBnClickedRadioWdCmdDown)
	ON_BN_CLICKED(IDC_BUTTON_RUDDER_CONFIRM, &Cpage1::OnBnClickedButtonRudderConfirm)
	ON_BN_CLICKED(IDC_CHECK_SPEED_CMD, &Cpage1::OnBnClickedCheckSpeedCmd)
	ON_BN_CLICKED(IDC_BUTTON_SPEED_CMD, &Cpage1::OnBnClickedButtonSpeedCmd)
	ON_BN_CLICKED(IDC_CHECK_CTR_SHUIBENG_ENABLE, &Cpage1::OnBnClickedCheckCtrShuibengEnable)
	ON_BN_CLICKED(IDC_RADIO_START_SHUIBENG, &Cpage1::OnBnClickedRadioStartShuibeng)
	ON_BN_CLICKED(IDC_RADIO_STOP_SHUIBENG, &Cpage1::OnBnClickedRadioStopShuibeng)
END_MESSAGE_MAP()


// Cpage1 消息处理程序


void Cpage1::ShowData()
{

	if(pdata_page1->sssch_ck_tx_state==true)  //显示手操盒串口状态
		drawpicture(IDC_PICTURE_SS_SCH_CK,1);
	else
		drawpicture(IDC_PICTURE_SS_SCH_CK,0);
	if(pdata_page1->awmu_uwmu_wxd_state==true)  //显示无线电串口状态
	{
		drawpicture(IDC_PICTURE_SS_SX_WXD,1);
	}
	else
	{
		drawpicture(IDC_PICTURE_SS_SX_WXD,0);
	}
	if(pdata_page1->sssch_wl_tx_state==true)   //显示手操盒网络状态
		drawpicture(IDC_PICTURE_24,1);
	else
		drawpicture(IDC_PICTURE_24,0);
	if(pdata_page1->awmu_uwmu_net_state==true) //水上主控-水下主控网络
	{
		drawpicture(IDC_PICTURE_25,1);
	}
	else
	{
		drawpicture(IDC_PICTURE_25,0);
	}
	if(pdata_page1->uwmu_nau_net_state==true)  //水下主控-导航网络
		drawpicture(IDC_PICTURE_27,1);
	else
		drawpicture(IDC_PICTURE_27,0);
	if(pdata_page1->uwmu_mpu_net_state==true)  //水下主控-运动规划
		drawpicture(IDC_PICTURE_28,1);
	else
		drawpicture(IDC_PICTURE_28,0);
	if(pdata_page1->uwmu_prcu_net_state==true) //水下主控-基础控制网络
		drawpicture(IDC_PICTURE_29,1);
	else
		drawpicture(IDC_PICTURE_29,0);
	if(pdata_page1->uwmu_pocu_net_state==true) //水下主控-动力系统
		drawpicture(IDC_PICTURE_30,1);
	else
		drawpicture(IDC_PICTURE_30,0);
	if(pdata_page1->uwmu_dsu_net_state==true)  //水下主控-数据存储
		drawpicture(IDC_PICTURE_32,1);
	else
		drawpicture(IDC_PICTURE_32,0);
	if(pdata_page1->uwmu_emu_net_state==true) //水下主控-应急网络
		drawpicture(IDC_PICTURE_33,1);
	else
		drawpicture(IDC_PICTURE_33,0);
	if(pdata_page1->uwmu_meu_net_state==true) //水下主控-测量单元 网络 20170429新增
		drawpicture(IDC_UWMU_MEU_NET_STATE,1);
	else
		drawpicture(IDC_UWMU_MEU_NET_STATE,0);
	if(pdata_page1->awmu_emu_net_state==true) //水上主控应急网络
		drawpicture(IDC_PICTURE_SS_YJ_YTW,1);
	else
		drawpicture(IDC_PICTURE_SS_YJ_YTW,0);
	if(pdata_page1->awmu_emu_ss_state==true) //水上主控应急水声通信
		drawpicture(IDC_PICTURE_SS_YJ_SS,1);
	else
		drawpicture(IDC_PICTURE_SS_YJ_SS,0);
	if(pdata_page1->awmu_dsu_net_state==true) //水上主控水上数据存储网络通信
		drawpicture(IDC_PICTURE_TX_SS_SSCC,1);
	else
		drawpicture(IDC_PICTURE_TX_SS_SSCC,0);
	if(pdata_page1->fault_light_state==true)  //故障指示灯
	{
		drawpicture(IDC_PICTURE_FAULT,2);
	}
	else
	{
		drawpicture(IDC_PICTURE_FAULT,0);
	}
	if(pdata_page1->selfTest_light_state==true)  //自检指示灯
		drawpicture(IDC_PICTURE_SELFTEST_LIGHT_FB,1);
	else
		drawpicture(IDC_PICTURE_SELFTEST_LIGHT_FB,0);
	if(pdata_page1->beginEmergency_light_state==true) //进入应急指示灯
		drawpicture(IDC_PICTURE_EMU_LIGHT_FB,1);
	else
		drawpicture(IDC_PICTURE_EMU_LIGHT_FB,0);
	if(m_pDlg1->pdata_r3007->timeset==true)               //对时状态显示 20170427
		drawpicture(IDC_PICTURE_TIME_SET,1);
	else
		drawpicture(IDC_PICTURE_TIME_SET,0);
	if(m_pDlg1->pdata_r7002->timeset==true)               //对时状态显示 20170428
		drawpicture(IDC_PICTURE_EMU_TIME_SET,1);
	else
		drawpicture(IDC_PICTURE_EMU_TIME_SET,0);
	if(m_pDlg1->pdata_r2008->timeset==true)               //对时状态显示 20170428
		drawpicture(IDC_PICTURE_SSCC_TIME_SET,1);
	else
		drawpicture(IDC_PICTURE_SSCC_TIME_SET,0);
	if(pdata_page1->meu_state_test_light==true)      //显示测量系统状态  20170502  
		drawpicture(IDC_MEU_STATE_TEST_LIGHT,1);     //测量自检
	else
		drawpicture(IDC_MEU_STATE_TEST_LIGHT,0);
	if(pdata_page1->meu_state_debug_light==true)    //测量调试
		drawpicture(IDC_MEU_STATE_DEBUG_LIGHT,1);
	else
		drawpicture(IDC_MEU_STATE_DEBUG_LIGHT,0);
	if(pdata_page1->meu_state_fault_light==true)   //测量故障
		drawpicture(IDC_MEU_STATE_FAULT_LIGHT,2);
	else
		drawpicture(IDC_MEU_STATE_FAULT_LIGHT,0);
	if(pdata_page1->gongkuang_light_state==0x00)   //集控界面试验工况状态显示20180722
	{
		drawpicture(IDC_PICTURE_TEST_FB,1);
		drawpicture(IDC_PICTURE_DATAUP_FB,0);
	}
	else
	{
		drawpicture(IDC_PICTURE_TEST_FB,0);
		drawpicture(IDC_PICTURE_DATAUP_FB,1);
	}
}

void Cpage1::drawpicture(int m_image_ID, int m_image_num)
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

void Cpage1::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1)
		ShowData();
	
	CDialogEx::OnTimer(nIDEvent);
}


BOOL Cpage1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1,500,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Cpage1::OnBnClickedButtonRwzj()
{
	// TODO: 在此添加控件通知处理程序代码
	//CRwyzDlg dlg;
	//if(dlg.DoModal()==IDOK)
	//{
	//	if((dlg.m_num_hc1==0)||(dlg.m_num_hc2==0)||(dlg.m_num_hc3==0))
	//	{MessageBox("航程一、航程二、航程三规划出的航迹点个数均不能为0，请重新输入任务！","错误");}
	//	else
	//	{
	//		rwlx=dlg.m_rwlx+1;
	//		x11=atof(dlg.m_x1);
	//		y11=atof(dlg.m_y1);
	//		z11=dlg.m_z1;
	//		x12=atof(dlg.m_x2);
	//		y12=atof(dlg.m_y2);
	//		z12=dlg.m_z2;
	//		x21=atof(dlg.m_x2);
	//		y21=atof(dlg.m_y2);
	//		z21=dlg.m_z2;
	//		x22=atof(dlg.m_x3);
	//		y22=atof(dlg.m_y3);
	//		z22=dlg.m_z3;
	//		x31=atof(dlg.m_x3);
	//		y31=atof(dlg.m_y3);
	//		z31=dlg.m_z3;
	//		x32=atof(dlg.m_x4);
	//		y32=atof(dlg.m_y4);
	//		z32=dlg.m_z4;
	//		num_hc1=dlg.m_num_hc1;
	//		num_hc2=dlg.m_num_hc2;
	//		num_hc3=dlg.m_num_hc3;
	//		speed=(BYTE)(dlg.m_speed*10);
	//		GuiHua_hc1();
	//		GuiHua_hc2();
	//		GuiHua_hc3();
	//		m_pDlg1->FuZhi_SX_S031(num_hc1+1,num_hc2+1,num_hc3+1,rwlx,speed);  //将输出数据赋值给S_031
	//		m_pDlg1->FuZhi_CC_S027();   //给任务预置报文S_027赋值
	//	}
	//}
	m_pDlg1->page_rwyz->ShowWindow(true);
	m_pDlg1->page_rwyz->ReadIni();
}


void Cpage1::OnBnClickedButtonRwxz()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i=0;i<4;i++)
		m_pDlg1->rwyz_fs_flag[i]=false;
	m_pDlg1->SSSXSocket->SendTo(m_pDlg1->sendata_s031_1,sizeof(S_AWMU_2_UWMU_EA_1)+3,0,NULL);
	/*CString str,strtemp;
			for(int i=0;i<sizeof(S_AWMU_2_UWMU_EA_1)+3;i++)
				{strtemp.Format("%02x ",m_pDlg1->sendata_s031_1[i]);str+=strtemp;}
			MessageBox(str);*/
	//m_pDlg1->SSCCSocket->SendTo(m_pDlg1->sendata_s031_1,sizeof(S_AWMU_2_UWMU_EA_1)+3,0,NULL);  //发送任务至水上存储
	/*m_pDlg1->SSCCSocket->SendTo(m_pDlg1->sendata_s031_2,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
	m_pDlg1->SSCCSocket->SendTo(m_pDlg1->sendata_s031_3,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);
	m_pDlg1->SSCCSocket->SendTo(m_pDlg1->sendata_s031_4,sizeof(S_AWMU_2_UWMU_EA_2)+3,0,NULL);*/
}


void Cpage1::OnBnClickedButtonRwck()
{
	// TODO: 在此添加控件通知处理程序代码
	CRwck* dlg;
	dlg=new CRwck(this);
	dlg->DoModal();
}


void Cpage1::OnBnClickedButtonRwsc()
{
	// TODO: 在此添加控件通知处理程序代码
	if(IDYES == MessageBox(_T("确定删除任务么?"), "确认删除", MB_YESNO|MB_ICONQUESTION))
	{
		str1="";
		str2="";
		str3="";
		strcpy_s(rwyz,"");
		/*ofstream file("rwyz.txt",ios::trunc);   //任务信息写入rwyz.txt
		if(!file.fail())
		{
			file<<rwyz<<endl;
		}
		file.close();*/
	}
}


void Cpage1::OnBnClickedButtonRwjl()  //任务记录
{
	// TODO: 在此添加控件通知处理程序代码
	CTime time = CTime::GetCurrentTime();   //创建并获得当前时间
	CString strTime=time.Format("%Y%m%d_%H.%M.%S");  //格式化时间字符串
	CString strtemp="rwyz"+strTime+".txt";
	char *pa;
	pa=(char*)malloc(strtemp.GetLength()+1);
	strcpy_s(pa,strtemp.GetLength()+1,strtemp);
	const char* pb=pa;
	ofstream file(pb,ios::trunc);   //任务信息写入txt
	if(!file.fail())
	{
		file<<rwyz<<endl;
	}
	file.close();
	free(pa);
}

void Cpage1::GuiHua_hc1()
{
	CString str;
	Caculate c1;                             
	Point2* point1 = c1.guihua1(x11,y11,z11,x12,y12,z12,num_hc1);
	//float pt1[6][70];
	for(int i = 0; i < 6; ++i)
		memcpy(m_pDlg1->pt1[i],point1->p[i],(num_hc1+1)*4); 
	str1="经度";
	for(UINT k = 0;k < num_hc1+1;++k)
	{
		str.Format(" %f",m_pDlg1->pt1[0][k]);
		str1+=str;
	}
	str1+="\r\n";
	str1+="纬度";
	for(UINT m = 0;m < num_hc1+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt1[1][m]);
		str1+=str;
	}
	str1+="\r\n";
	str1+="深度";
	for(UINT  m = 0;m < num_hc1+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt1[2][m]);
		str1+=str;
	}
	str1+="\r\n";
	str1+="航向角";
	for(UINT m = 0;m < num_hc1+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt1[3][m]);
		str1+=str;
	}
	str1+="\r\n";
	str1+="纵倾角";
	for(UINT m = 0;m < num_hc1+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt1[4][m]);
		str1+=str;
	}
    str1+="\r\n";
	str1+="横滚角";
	for(UINT m = 0;m < num_hc1+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt1[5][m]);
		str1+=str;
	}
	/*CString str_rw,str_temp;            //存储点的信息至str_rw
	int num_d=num_hc1+num_hc2+num_hc3+1;  //点的总个数
	str_temp.Format("%d",num_d);
	str_rw+="航迹点个数："+str_temp+"\n";
	str_temp.Format("%d",2);    //必达点个数
	str_rw+="必达点个数："+str_temp+"\n";
	str_temp.Format("%d",speed);   //速度
	str_rw+="速度："+str_temp+"\n";
	int wz_bdd=num_hc1+1;  //必达点一位置
	str_temp.Format("%d",wz_bdd);
	str_rw+="必达点位置："+str_temp+",";
	wz_bdd=num_hc1+1+num_hc2;  //必达点二位置
	str_temp.Format("%d",wz_bdd);
	str_rw+=str_temp+"\n";
	str_rw+="航迹点：\n";
	for(UINT i=0;i<num_hc1;i++)
	{
		for(int j=0;j<6;j++)
		{
			str_temp.Format("%f",m_pDlg1->pt1[j][i]);
			if(j<5)
				str_rw+=str_temp+",";
			else
				str_rw+=str_temp;
		}
		str_rw+="\n";
	}
	strcpy_s(rwyz,20000,(const char*)str_rw);*/
}

void Cpage1::GuiHua_hc2()
{
	CString str;
	Caculate c2;
	Point2* point2 = c2.guihua2(x21,y21,z21,x22,y22,z22,num_hc2);
	for(UINT i = 0; i < point2->GetRow(); ++i)
		memcpy(m_pDlg1->pt2[i],point2->p[i],(num_hc2+1)*4);
	str2="经度";
	for(UINT k = 0;k < point2->GetItem()+1;++k)
	{
		str.Format(" %f",m_pDlg1->pt2[0][k]);
		str2+=str;
	}
	str2+="\r\n";
	str2+="纬度";
	for(UINT m = 0;m < point2->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt2[1][m]);
		str2+=str;
	}
	str2+="\r\n";
	str2+="深度";
	for(UINT  m = 0;m < point2->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt2[2][m]);
		str2+=str;
	}
	str2+="\r\n";
	str2+="航向角";
	for(UINT m = 0;m < point2->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt2[3][m]);
		str2+=str;
	}
	str2+="\r\n";
	str2+="纵倾角";
	for(UINT m = 0;m < point2->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt2[4][m]);
		str2+=str;
	}
    str2+="\r\n";
	str2+="横滚角";
	for(UINT m = 0;m < point2->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt2[5][m]);
		str2+=str;
	}	
	/*CString str_rw,str_temp;
	for(UINT i=0;i<point2->GetItem();i++)
	{
		for(int j=0;j<6;j++)
		{
			str_temp.Format("%f",m_pDlg1->pt2[j][i]);
			if(j<5)
				str_rw+=str_temp+",";
			else
				str_rw+=str_temp;
		}
		str_rw+="\n";
	}
	strcat_s(rwyz,20000,(const char*)str_rw);*/
}

void Cpage1::GuiHua_hc3()
{
	CString str;
	Caculate c3;
	Point2* point3 = c3.guihua3(x31,y31,z31,x32,y32,z32,num_hc3);
	for(UINT i = 0; i < point3->GetRow(); ++i)
		memcpy(m_pDlg1->pt3[i],point3->p[i],(num_hc3+1)*4); 
	str3="经度";
	for(UINT k = 0;k < point3->GetItem()+1;++k)
	{
		str.Format(" %f",m_pDlg1->pt3[0][k]);
		str3+=str;
	}
	str3+="\r\n";
	str3+="纬度";
	for(UINT m = 0;m < point3->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt3[1][m]);
		str3+=str;
	}
	str3+="\r\n";
	str3+="深度";
	for(UINT  m = 0;m < point3->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt3[2][m]);
		str3+=str;
	}
	str3+="\r\n";
	str3+="航向角";
	for(UINT m = 0;m < point3->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt3[3][m]);
		str3+=str;
	}
	str3+="\r\n";
	str3+="纵倾角";
	for(UINT m = 0;m < point3->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt3[4][m]);
		str3+=str;
	}
    str3+="\r\n";
	str3+="横滚角";
	for(UINT m = 0;m < point3->GetItem()+1;++m)
	{
		str.Format(" %f",m_pDlg1->pt3[5][m]);
		str3+=str;
	}
	/*CString str_rw,str_temp;
	for(UINT i=0;i<point3->GetItem()+1;i++)
	{
		for(int j=0;j<6;j++)
		{
			str_temp.Format("%f",m_pDlg1->pt3[j][i]);
			if(j<5)
				str_rw+=str_temp+",";
			else
				str_rw+=str_temp;
		}
		if(i<point3->GetItem())
			str_rw+="\n";
	}
	str_rw+="\r";
	strcat_s(rwyz,20000,(const char*)str_rw);*/
}



void Cpage1::OnBnClickedButtonTxztcx()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_ksdd_flag==FALSE)
	{
	BYTE data[7];
	data[0]=0xa5;
	data[1]=0x00;
	data[2]=0x06;
	data[3]=0x03;
	unsigned short crcCheck=0;
	crcCheck=m_pDlg1->CRC16(data,4);
	data[4]=crcCheck%256;
	data[5]=crcCheck/256;
	data[6]=0x0d;
	m_pDlg1->SSSXSocket->Send(data,7,0);
	}
}

void Cpage1::ShowData_R306()
{
	//if(m_pDlg1->pdata_r306->unitCommStatuse[0]==TRUE)
	//{
	//	pdata_page1->awmu_uwmu_net_state=true;
	//	//MessageBox("pdata_r306->unitCommStatuse[0]==TRUE)");
	//}
	//else
	//{
	//	pdata_page1->awmu_uwmu_net_state=false;
	//}
	if(m_pDlg1->pdata_r306->unitCommStatuse[0]==FALSE)   //与水下主控的网络通信灯亮以接收到网络数据为准
	{
		pdata_page1->awmu_uwmu_net_state=false;
		//m_pDlg1->page3->drawpicture(IDC_STATIC_SXWL_B,0);  //辅助操舵界面
	}
	if(m_pDlg1->page1->m_ksdd_flag==false)
	{
		if(m_pDlg1->pdata_r306->unitCommStatuse[1]==TRUE)  //导航
		{
			pdata_page1->uwmu_nau_net_state=true;
		}
		else
		{
			pdata_page1->uwmu_nau_net_state=false;
		}
		if(m_pDlg1->pdata_r306->unitCommStatuse[2]==TRUE)  //运动规划
		{
			pdata_page1->uwmu_mpu_net_state=true;
		}
		else
		{
			pdata_page1->uwmu_mpu_net_state=false;
		}
		if(m_pDlg1->pdata_r306->unitCommStatuse[3]==TRUE)  //基础控制
		{
			pdata_page1->uwmu_prcu_net_state=true;
		}
		else
		{
			pdata_page1->uwmu_prcu_net_state=false;
		}
		if(m_pDlg1->pdata_r306->unitCommStatuse[4]==TRUE)  //应急
		{
			pdata_page1->uwmu_emu_net_state=true;
		}
		else
		{
			pdata_page1->uwmu_emu_net_state=false;
		}
		if(m_pDlg1->pdata_r306->unitCommStatuse[5]==TRUE)  //数据存储
		{
			pdata_page1->uwmu_dsu_net_state=true;
		}
		else
		{
			pdata_page1->uwmu_dsu_net_state=false;
		}
		if(m_pDlg1->pdata_r306->unitCommStatuse[6]==TRUE)  //测量
		{
			pdata_page1->uwmu_meu_net_state=true;
		}
		else
		{
			pdata_page1->uwmu_meu_net_state=false;
		}
		if(m_pDlg1->pdata_r306->unitCommStatuse[7]==TRUE)  //动力
		{
			pdata_page1->uwmu_pocu_net_state=true;
		}
		else
		{
			pdata_page1->uwmu_pocu_net_state=false;
		}
	}
	

}
void Cpage1::ShowData_R30()
{
if(m_pDlg1->page1->m_ksdd_flag==true)
	{

		if((m_pDlg1->page4->faultType[1]&0x00000400)==0x00000400)           //水下主控与导航单元通信故障
		{
			pdata_page1->uwmu_nau_net_state=false;
		}
		else
		{
			pdata_page1->uwmu_nau_net_state=true;
		}
		if((m_pDlg1->page4->faultType[1]&0x00000200)==0x00000200)          //水下主控与运动规划单元通信故障
		{
			pdata_page1->uwmu_mpu_net_state=false;
		}
		else
		{
			pdata_page1->uwmu_mpu_net_state=true;
		}
		if((m_pDlg1->page4->faultType[1]&0x00000100)==0x00000100)          //水下主控与基础控制单元通信故障
		{
			pdata_page1->uwmu_prcu_net_state=false;
		}
		else
		{
			pdata_page1->uwmu_prcu_net_state=true;
		}
		if(((m_pDlg1->page4->faultType[1]&0x00000010)==0x00000010)||(m_pDlg1->pdata_r30->communicationStatus[6]==1)||(m_pDlg1->pdata_r303->communicationStatus[6]==1) ) //水下主控与应急单元通信故障
		{
			pdata_page1->uwmu_emu_net_state=false;
		}
		else
		{
			pdata_page1->uwmu_emu_net_state=true;
		}
		if((m_pDlg1->page4->faultType[1]&0x00000020)==0x00000020)   //水下主控与数据存储单元通信故障
		{
			pdata_page1->uwmu_dsu_net_state=false;
		}
		else
		{
			pdata_page1->uwmu_dsu_net_state=true;
		}
		if((m_pDlg1->page4->faultType[1]&0x00000040)==0x00000040)       //水下主控与测量单元通信故障
		{
			pdata_page1->uwmu_meu_net_state=false;
		}
		else
		{
			pdata_page1->uwmu_meu_net_state=true;
		}
		if((m_pDlg1->page4->faultType[1]&0x00000080)==0x00000080)       //水下主控与动力系统通信故障
		{
			pdata_page1->uwmu_pocu_net_state=false;
		}
		else
		{
			pdata_page1->uwmu_pocu_net_state=true;
		}

	}
}

void Cpage1::OnBnClickedCheckKsdd()//勾选开始调度则定时下发手操盒指令，定时刷新动力系统调试界面
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_ksdd_flag==TRUE)
	{
/*		m_pDlg1->SetTimer1();
		m_pDlg1->page2->SetTimer1();
	}
	else
	{
		m_pDlg1->KillTimer(1);
		m_pDlg1->KillTimer(2);
	}
	*/
		if((pdata_page1->sssch_wl_tx_state==true) || (pdata_page1->sssch_ck_tx_state==true))  //开始调度前必须连上手操盒20170522
		{
			GetDlgItem(IDC_BUTTON_TXZTCX)->EnableWindow(false);
			GetDlgItem(IDC_BUTTON_RWXZ)->EnableWindow(false);//开始调度时禁用任务下载
			if(m_pDlg1->pdata_r10->workingMode==0x00)  //遥控模式下
			m_pDlg1->SetTimer1();        //开水上向水下发送周期性报文的定时器
			m_pDlg1->page2->SetTimer1(); //动力系统界面显示定时器
		}
		else
		{
			//CPage_LjSCH dlg;
			//dlg.DoModal();
			m_ksdd_flag=0;   //取消开始调度
			UpdateData(false); //更新调度选项
			MessageBox("请连接手操盒");
		}

	}
	else
	{
		GetDlgItem(IDC_BUTTON_TXZTCX)->EnableWindow(true);
		//GetDlgItem(IDC_BUTTON_RWZJ)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_RWXZ)->EnableWindow(true);
		m_pDlg1->KillTimer(1);
		m_pDlg1->KillTimer(2);
		//m_pDlg1->KillTimer18();      //未调度时关闭定时查询手操盒通信状态
	}
}


void Cpage1::OnBnClickedCheckDddlxt()   //是否调度动力系统
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_pocuEnable==TRUE)
	{
		m_pDlg1->pdata_s03->pocuEnable=1;
	}
	else
		m_pDlg1->pdata_s03->pocuEnable=0;
}


void Cpage1::OnBnClickedCheckPrcuEnable()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_prcuEnable==TRUE)
	{
		m_pDlg1->pdata_s03->prcuEnable=1;
	}
	else
		m_pDlg1->pdata_s03->prcuEnable=0;
}


void Cpage1::OnBnClickedCheckNauEnable()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_nauEnable==TRUE)
	{
		m_pDlg1->pdata_s03->nauEnable=1;
	}
	else
		m_pDlg1->pdata_s03->nauEnable=0;
}


void Cpage1::OnBnClickedCheckEmuEnable()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_emuEnable==TRUE)
	{
		m_pDlg1->pdata_s03->emuEnable=1;
	}
	else
		m_pDlg1->pdata_s03->emuEnable=0;
}


void Cpage1::OnBnClickedCheckDsuEnable()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_dsuEnable==TRUE)
	{
		m_pDlg1->pdata_s03->dsuEnable=1;
	}
	else
		m_pDlg1->pdata_s03->dsuEnable=0;
}


void Cpage1::OnBnClickedButtonTimeSet()    //为水下主控、应急单元、水上存储赋值对时报文
{
	// TODO: 在此添加控件通知处理程序代码 
	TIME_SET TimeSet_temp;
	memset(&(TimeSet_temp),0,sizeof(TimeSet_temp));
	CTime date=CTime::GetCurrentTime();          //获取系统日期 年月日
	TimeSet_temp.year=date.GetYear();
	TimeSet_temp.month=date.GetMonth();
	TimeSet_temp.day=date.GetDay();     
	TimeSet_temp.h=date.GetHour();
	TimeSet_temp.m=date.GetMinute();
	TimeSet_temp.s=date.GetSecond();
	struct _timeb timebuff;
	_ftime64_s(&timebuff);
	TimeSet_temp.ms=timebuff.millitm;
	 //水下主控
	m_pDlg1->pdata_s0307->pktHead1=0xA5;      
	m_pDlg1->pdata_s0307->pktHead2=0x0307;
	memcpy(&(m_pDlg1->pdata_s0307->Time_Set),&TimeSet_temp,sizeof(TimeSet_temp));
	memcpy(m_pDlg1->sendata_0307,m_pDlg1->pdata_s0307,sizeof(S_AWMU_2_UWMU_EA4));
	unsigned short crcCheck=0;
	crcCheck=m_pDlg1->CRC16(m_pDlg1->sendata_0307,sizeof(S_AWMU_2_UWMU_EA4));
	m_pDlg1->sendata_0307[sizeof(S_AWMU_2_UWMU_EA4)]=(BYTE)(crcCheck%256);
	m_pDlg1->sendata_0307[sizeof(S_AWMU_2_UWMU_EA4)+1]=(BYTE)(crcCheck/256);
	m_pDlg1->sendata_0307[sizeof(S_AWMU_2_UWMU_EA4)+2]=0x0d;
	m_pDlg1->SSSXSocket->Send(m_pDlg1->sendata_0307,sizeof(S_AWMU_2_UWMU_EA4)+3,0);
	//应急单元
	m_pDlg1->pdata_s0702->pktHead1=0xA5;
	m_pDlg1->pdata_s0702->pktHead2=0x0702;
	memcpy(&(m_pDlg1->pdata_s0702->Time_Set),&TimeSet_temp,sizeof(TimeSet_temp));
	memcpy(m_pDlg1->sendata_0702,m_pDlg1->pdata_s0702,sizeof(AWMU_2_EMU_EA_TIMESET));
	crcCheck=0;
	crcCheck=m_pDlg1->CRC16(m_pDlg1->sendata_0702,sizeof(AWMU_2_EMU_EA_TIMESET));
	m_pDlg1->sendata_0702[sizeof(AWMU_2_EMU_EA_TIMESET)]=(BYTE)(crcCheck%256);
	m_pDlg1->sendata_0702[sizeof(AWMU_2_EMU_EA_TIMESET)+1]=(BYTE)(crcCheck/256);
	m_pDlg1->sendata_0702[sizeof(AWMU_2_EMU_EA_TIMESET)+2]=0x0d;
	m_pDlg1->SSYJSocket->Send(m_pDlg1->sendata_0702,sizeof(AWMU_2_EMU_EA_TIMESET)+3);
    //水上存储
	m_pDlg1->pdata_s0208->pktHead1=0xA5;
	m_pDlg1->pdata_s0208->pktHead2=0x0208;
	memcpy(&(m_pDlg1->pdata_s0208->Time_Set),&TimeSet_temp,sizeof(TimeSet_temp));
	memcpy(m_pDlg1->sendata_0208,m_pDlg1->pdata_s0208,sizeof(AWMU_AWRU_S028));
	crcCheck=0;
	crcCheck=m_pDlg1->CRC16(m_pDlg1->sendata_0208,sizeof(AWMU_AWRU_S028));
	m_pDlg1->sendata_0208[sizeof(AWMU_AWRU_S028)]=(BYTE)(crcCheck%256);
	m_pDlg1->sendata_0208[sizeof(AWMU_AWRU_S028)+1]=(BYTE)(crcCheck/256);
	m_pDlg1->sendata_0208[sizeof(AWMU_AWRU_S028)+2]=0x0d;
	m_pDlg1->SSCCSocket->Send(m_pDlg1->sendata_0208,sizeof(AWMU_AWRU_S028)+3);

}


void Cpage1::OnBnClickedButtonUwmuWRecnet()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDlg1->Connect_UWMU();
	m_pDlg1->SetTimer(4,2000,NULL);	
}


void Cpage1::OnBnClickedButtonEmuWRecnet()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDlg1->Connect_EMU();
	m_pDlg1->SetTimer(13,2000,NULL);	
}


void Cpage1::OnBnClickedCheckMeuEnable()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_meuEnable==TRUE)
	{
		m_pDlg1->pdata_s03->meuEnable=1;
	}
	else
		m_pDlg1->pdata_s03->meuEnable=0;
}



void Cpage1::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDlg1->Connect_UWMU();
	m_pDlg1->SetTimer(4,2000,NULL);	
	/*m_pDlg1->Connect_EMU();
	m_pDlg1->SetTimer(13,2000,NULL);*/
}



BOOL Cpage1::PreTranslateMessage(MSG* pMsg)
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


void Cpage1::OnBnClickedButtonToWxd()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDlg1->SetTimer(2,T_WXD,NULL);   //无线电报文S_03周期性下发定时器
	m_pDlg1->KillTimer(1);
	pdata_page1->awmu_uwmu_net_state=false;
}
void Cpage1::Fuzhi_Rwyz()
{
	m_pDlg1->FuZhi_SX_S031(num_hc1+1,num_hc2+1,num_hc3+1,rwlx,speed);  //将输出数据赋值给S_031
	m_pDlg1->FuZhi_CC_S027();   //给任务预置报文S_027赋值
}

void Cpage1::UpdateInf()
{
	if(m_wkd_up==0)   //上浮
	{
		m_wkd_cmd_up=abs(m_wkd_cmd_up);
		if(m_wkd_cmd_up>22)
			m_wkd_cmd_up=22;
		p_wkd=m_wkd_cmd_up;
	}
	if(m_wkd_up==1)
	{
		m_wkd_cmd_down=abs(m_wkd_cmd_down);
		if(m_wkd_cmd_down>22)
			m_wkd_cmd_down=22;
		p_wkd=m_wkd_cmd_down*(-1);
	}
	if(m_fxd_l==0)  //左舵
	{
		m_fxd_cmd_l=abs(m_fxd_cmd_l);
		if(m_fxd_cmd_l>25)
			m_fxd_cmd_l=25;
		p_fxd=m_fxd_cmd_l;
	}
	if(m_fxd_l==1)
	{
		m_fxd_cmd_r=abs(m_fxd_cmd_r);
		if(m_fxd_cmd_r>25)
			m_fxd_cmd_r=25;
		p_fxd=m_fxd_cmd_r*(-1);
	}
	if(m_wd_up==0)   //尾舵上浮
	{
		m_wd_cmd_up=abs(m_wd_cmd_up);
		if(m_wd_cmd_up>30)
			m_wd_cmd_up=30;
		p_zywd=m_wd_cmd_up*(-1);
		
	}
	if(m_wd_up==1)
	{
		m_wd_cmd_down=abs(m_wd_cmd_down);
		if(m_wd_cmd_down>10)
			m_wd_cmd_down=10;
		p_zywd=m_wd_cmd_down;
	}
}


void Cpage1::OnBnClickedRadioWkdCmd()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(true);
	if(m_wkd_up==0)   //上浮
	{
		m_wkd_cmd_up=abs(m_wkd_cmd_up);
		if(m_wkd_cmd_up>22)
			m_wkd_cmd_up=22;
		p_wkd=m_wkd_cmd_up;
	}
}


void Cpage1::OnBnClickedRadio3()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
		UpdateData(true);
	if(m_wkd_up==1)
	{
		m_wkd_cmd_down=abs(m_wkd_cmd_down);
		if(m_wkd_cmd_down>22)
			m_wkd_cmd_down=22;
		p_wkd=m_wkd_cmd_down*(-1);
	}

}


void Cpage1::OnBnClickedCheckWkdCtrEnable()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
		UpdateData(TRUE);
	if(true==m_wkd_ctr_enable)
		UpdateInf();
}


void Cpage1::OnBnClickedCheckFxdCtrEnable()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
		UpdateData(TRUE);
	if(true==m_fxd_ctr_enable)
		UpdateInf();
}


void Cpage1::OnBnClickedRadioFxdCmdL()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(true);
	if(m_fxd_l==0)
	{
		m_fxd_cmd_l=abs(m_fxd_cmd_l);
		if(m_fxd_cmd_l>25)
			m_fxd_cmd_l=25;
		p_fxd=m_fxd_cmd_l;
	}
}


void Cpage1::OnBnClickedRadioFxdCmdR()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(true);
		if(m_fxd_l==1)
	{
		m_fxd_cmd_r=abs(m_fxd_cmd_r);
		if(m_fxd_cmd_r>25)
			m_fxd_cmd_r=25;
		p_fxd=m_fxd_cmd_r*(-1);
	}
}


void Cpage1::OnBnClickedCheckWdCtrEnable()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
		UpdateData(TRUE);
	if(true==m_wd_ctr_enable)
		UpdateInf();
}


void Cpage1::OnBnClickedRadioWdCmdUp()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(true);
	if(m_wd_up==0)
	{
		m_wd_cmd_up=abs(m_wd_cmd_up);
		if(m_wd_cmd_up>30)
			m_wd_cmd_up=30;
		p_zywd=m_wd_cmd_up*(-1);
		
	}

}


void Cpage1::OnBnClickedRadioWdCmdDown()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(true);
		if(m_wd_up==1)
	{
		m_wd_cmd_down=abs(m_wd_cmd_down);
		if(m_wd_cmd_down>10)
			m_wd_cmd_down=10;
		p_zywd=m_wd_cmd_down;
	}
}


void Cpage1::OnBnClickedButtonRudderConfirm()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(TRUE);
	UpdateInf();
}


void Cpage1::OnBnClickedCheckSpeedCmd()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
		UpdateData(TRUE);
}


void Cpage1::OnBnClickedButtonSpeedCmd()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(TRUE);
}


void Cpage1::OnBnClickedCheckCtrShuibengEnable()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
		UpdateData(TRUE);
	if(0==m_shuibeng_start)
	{
		m_shuibeng_command=true;
	}
	if(1==m_shuibeng_start)
	{
		m_shuibeng_command=false;
	}
}


void Cpage1::OnBnClickedRadioStartShuibeng()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
		UpdateData(true);
	if(0==m_shuibeng_start)
	{
		m_shuibeng_command=true;
	}
}


void Cpage1::OnBnClickedRadioStopShuibeng()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
			UpdateData(true);
	if(1==m_shuibeng_start)
	{
		m_shuibeng_command=false;
	}
}
