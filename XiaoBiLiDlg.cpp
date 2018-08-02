
// XiaoBiLiDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "XiaoBiLiDlg.h"
#include "afxdialogex.h"
#include "math.h"
#include "Page_ljdd.h"
#include "Page_test.h"
#include "Page_nau_config.h"
#include "Pag_Password.h"
#include "RwyzDlg.h"
#include "SkinH.h"
#pragma comment(lib, "SkinH.lib")


UINT T_S03=1000;   //发送至水下主控报文s_03周期
UINT T_S07=2000;    //发送至应急单元以太网报文S_07周期
UINT T_S07E=3000;   //发送至应急单元水声（串口）报文S_07E周期
UINT T_R70E=15000;   //应急单元反馈水声（串口）报文R_70E周期
UINT T_WXD=1000; //无线电报文S_03下发周期
//变量和PING函数声明为全局变量
HANDLE hThread_uwmu;
HANDLE hThread_emu;
int PingFlag_uwmu=0;
int PingFlag_emu=0;
int StopPing_uwmu=0;
int StopPing_emu=0;
//多线程函数
void WINAPI ConnectProc_uwmu( LPVOID lpParam);
void WINAPI ConnectProc_emu( LPVOID lpParam);
BOOL CheckIPReachable(LPCTSTR strIPAddress);
BOOL CheckIPReachable(LPCTSTR strIPAddress)   //返回ping某个IP成功或失败
{
    char strIP[100];
    strcpy_s(strIP,strIPAddress); 
    IPAddr ipaddr=inet_addr(strIP); 
    ULONG ulHopCount,ulRTT; 
    return (BOOL)GetRTTAndHopCount(ipaddr,&ulHopCount,1,&ulRTT); 
}
void WINAPI ConnectProc_uwmu( LPVOID lpParam)
{
	//CString *pIP=(CString *)lpParam;
	CString pIP;
	pIP="192.168.0.103";
	PingFlag_uwmu=0;
	while(1)
	{
		if(CheckIPReachable(pIP))  
		{
			PingFlag_uwmu=1;  
			break;
		}
		else
			PingFlag_uwmu=0;
		if(1==StopPing_uwmu)
			break;
	}
	    StopPing_uwmu=0;
}
void WINAPI ConnectProc_emu( LPVOID lpParam)
{
	//CString *pIP=(CString *)lpParam;
	CString pIP;
	pIP="192.168.0.107";
	PingFlag_emu=0;
	while(1)
	{
		if(CheckIPReachable(pIP))  
		{
			PingFlag_emu=1;  
			break;
		}
		else
			PingFlag_emu=0;
		if(1==StopPing_emu)
			break;
	}
	StopPing_emu=0;
}

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CXiaoBiLiDlg 对话框




CXiaoBiLiDlg::CXiaoBiLiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CXiaoBiLiDlg::IDD, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_NEW);
	flag_net_uwmu_awmu=0;
	flag_wxd_net_uwmu_awmu=0;
	tx_sx_num=0;
	moshi_curr=0;
	moshi_last=0;
	gongkuang_last=0;
	gongkuang_curr=0;
	zijian_last=0;
	zijian_curr=0;
	yjcs_last=0;
	yjcs_curr=0;
	tx_sch_wl_flag=0;
	tx_sch_ck_flag=0;
	tx_yj_wxd_ck_flag=0;
	tx_yj_ck_flag=0;
	tx_sx_wxd_flag=0;
	gps_data_num=0;
	gps_timeflag=0;
	fault_flag_r30_curr=false;
	fault_flag_r30_last=false;
	fault_flag_r70_curr=false;
	fault_flag_r70_last=false;
	fault_flag_r70e_curr=false;
	fault_flag_r70e_last=false;
	fault_flag_r303_curr=false;   //20170507
	fault_flag_r303_last=false;
	fault_flag_r3008_curr=false;
	fault_flag_r3008_last=false;
	page_config_sxzk=new Cpage0(this);
	page1=new Cpage1(this);
	page2=new Cpage2(this);
	page3=new Cpage3(this);
	page4=new CPage4(this);
	page_sch=new CPage_SCH(this);
	page_nau_config=new CPage_nau_config(this);
	page_test=new CPage_test(this);
	page_cspz_yj=new CPage_cspz_yj(this);
	page_cspz_yj_2=new CPage_cspz_yj_2(this);
	page_cspz_yj_3=new Cpage_cspz_yj_3(this);
	page_ljdd=new CPage_ljdd();
	page_wxwdk=new CPage_ljdd();
	page_wxwdk=new CPage_ljdd();
	page_wxwdk_wxddk=new CPage_ljdd();
	page_sch_txzt=new CPage_ljdd();
	//page_password=new CPag_Password();
	page_config_ydgh=new Cpage_config_ydgh();
	pdata_s07=(S_AWMU_2_EMU_EP*)malloc(sizeof(S_AWMU_2_EMU_EP));
	memset(pdata_s07,0,sizeof(S_AWMU_2_EMU_EP));
	pdata_s07e=(S_AWMU_2_EMU_SA*)malloc(sizeof(S_AWMU_2_EMU_SA));
	memset(pdata_s07e,0,sizeof(S_AWMU_2_EMU_SA));
	pdata_gps=(GPSData*)malloc(sizeof(GPSData));
	memset(pdata_gps,0,sizeof(GPSData));
	pdata_usbl=(USBLData*)malloc(sizeof(USBLData));     //20170620   
	memset(pdata_usbl,0,sizeof(USBLData));
	pdata_s02=(AWMU_AWRU_S02*)malloc(sizeof(AWMU_AWRU_S02));
	memset(pdata_s02,0,sizeof(AWMU_AWRU_S02));
	pdata_s02->pktHead1=0xA5;
	pdata_s02->pktHead2=0x0200;
	pdata_r30=(S_UWMU_2_AWMU_EP*)malloc(sizeof(S_UWMU_2_AWMU_EP));
	memset(pdata_r30,0,sizeof(S_UWMU_2_AWMU_EP));
	pdata_r10=(struct Data_SCH_R10*)malloc(sizeof(struct Data_SCH_R10));
	memset(pdata_r10,0,sizeof(struct Data_SCH_R10));
	pdata_r20=(AWRU_AWMU_R20*)malloc(sizeof(AWRU_AWMU_R20));
	memset(pdata_r20,0,sizeof(AWRU_AWMU_R20));
	pdata_r303=(S_UWMU_2_AWMU_SP*)malloc(sizeof(S_UWMU_2_AWMU_SP));
	memset(pdata_r303,0,sizeof(S_UWMU_2_AWMU_SP));
	pdata_s021=(S_UWMU_2_AWMU_SP*)malloc(sizeof(AWMU_AWRU_S021));
	memset(pdata_s021,0,sizeof(AWMU_AWRU_S021));
	pdata_r70=(S_EMU_2_AWMU_EP*)malloc(sizeof(S_EMU_2_AWMU_EP));
	memset(pdata_r70,0,sizeof(S_EMU_2_AWMU_EP));
	pdata_r70e=(S_EMU_2_AWMU_SP*)malloc(sizeof(S_EMU_2_AWMU_SP));
	memset(pdata_r70e,0,sizeof(S_EMU_2_AWMU_SP));
	pdata_r701e=(S_EMU_2_AWMU_SP1*)malloc(sizeof(S_EMU_2_AWMU_SP1));
	memset(pdata_r701e,0,sizeof(S_EMU_2_AWMU_SP1));
	pdata_r702e=(S_EMU_2_AWMU_SP2*)malloc(sizeof(S_EMU_2_AWMU_SP2));
	memset(pdata_r702e,0,sizeof(S_EMU_2_AWMU_SP2));
	pdata_r703e=(S_EMU_2_AWMU_SP3*)malloc(sizeof(S_EMU_2_AWMU_SP3));
	memset(pdata_r703e,0,sizeof(S_EMU_2_AWMU_SP3));
	pdata_s03=(S_AWMU_2_UWMU_ESP*)malloc(sizeof(S_AWMU_2_UWMU_ESP));
	memset(pdata_s03,0,sizeof(S_AWMU_2_UWMU_ESP));
	pdata_s03->pktHead1=0xa5;
	pdata_s03->pktHead2=AWMU_2_UWMU_ESP;
	pdata_s034=(S_AWMU_2_UWMU_EA1*)malloc(sizeof(S_AWMU_2_UWMU_EA1));
	memset(pdata_s034,0,sizeof(S_AWMU_2_UWMU_EA1));
	pdata_s034->pktHead1=0xa5;
	pdata_s034->pktHead2=AWMU_2_UWMU_EA1;
	pdata_r304=(S_UWMU_2_AWMU_EA1*)malloc(sizeof(S_UWMU_2_AWMU_EA1));
	memset(pdata_r304,0,sizeof(S_UWMU_2_AWMU_EA1));
	pdata_s031_1=(S_AWMU_2_UWMU_EA_1*)malloc(sizeof(S_AWMU_2_UWMU_EA_1));
	memset(pdata_s031_1,0,sizeof(S_AWMU_2_UWMU_EA_1));
	pdata_s031_2=(S_AWMU_2_UWMU_EA_2*)malloc(sizeof(S_AWMU_2_UWMU_EA_2));
	memset(pdata_s031_2,0,sizeof(S_AWMU_2_UWMU_EA_2));
	pdata_s031_3=(S_AWMU_2_UWMU_EA_2*)malloc(sizeof(S_AWMU_2_UWMU_EA_2));
	memset(pdata_s031_3,0,sizeof(S_AWMU_2_UWMU_EA_2));
	pdata_s031_4=(S_AWMU_2_UWMU_EA_2*)malloc(sizeof(S_AWMU_2_UWMU_EA_2));
	memset(pdata_s031_4,0,sizeof(S_AWMU_2_UWMU_EA_2));
	pdata_r301=(S_UWMU_2_AWMU_EA*)malloc(sizeof(S_UWMU_2_AWMU_EA));
	memset(pdata_r301,0,sizeof(S_UWMU_2_AWMU_EA));
	pdata_r201=(AWRU_AWMU_R201*)malloc(sizeof(AWRU_AWMU_R201));
	memset(pdata_r201,0,sizeof(AWRU_AWMU_R201));
	pdata_s0307=(S_AWMU_2_UWMU_EA4*)malloc(sizeof(S_AWMU_2_UWMU_EA4));
	memset(pdata_s0307,0,sizeof(S_AWMU_2_UWMU_EA4));
	pdata_r3007=(S_UWMU_2_AWMU_EA4*)malloc(sizeof(S_UWMU_2_AWMU_EA4));
	memset(pdata_r3007,0,sizeof(S_UWMU_2_AWMU_EA4));
	pdata_s0702=(AWMU_2_EMU_EA_TIMESET*)malloc(sizeof(AWMU_2_EMU_EA_TIMESET));
	memset(pdata_s0702,0,sizeof(AWMU_2_EMU_EA_TIMESET));
	pdata_r7002=(EMU_2_AWMU_EA_TIMESET*)malloc(sizeof(EMU_2_AWMU_EA_TIMESET));
	memset(pdata_r7002,0,sizeof(EMU_2_AWMU_EA_TIMESET));
	pdata_s0208=(AWMU_AWRU_S028*)malloc(sizeof(AWMU_AWRU_S028));
	memset(pdata_s0208,0,sizeof(AWMU_AWRU_S028));
	pdata_r2008=(AWRU_AWMU_R208*)malloc(sizeof(AWRU_AWMU_R208));
	memset(pdata_r2008,0,sizeof(pdata_r2008));
	pdata_s0209=(AWMU_AWRU_S029*)malloc(sizeof(AWMU_AWRU_S029));
	memset(pdata_s0209,0,sizeof(AWMU_AWRU_S029));
	arraySend_s01.RemoveAll();
	arraySend_s01.SetSize(23);
	arraySend_s03.RemoveAll();
	arraySend_s03.SetSize(sizeof(S_AWMU_2_UWMU_ESP)+3);
	arraySend_s034_wxd.RemoveAll();
	arraySend_s034_wxd.SetSize(sizeof(S_AWMU_2_UWMU_EA1)+3);
	arraySend_s07e.RemoveAll();
	arraySend_s07e.SetSize(sizeof(S_AWMU_2_EMU_SA)+3);
	arraySend_s0308.SetSize(43);
	arraySend_s0308.RemoveAll();                                //20170506
	arraySend_s0308.SetSize(sizeof(S_AWMU_2_UWMU_EA5)+3);
	recdata_r10=(BYTE*)malloc(35);
	memset(recdata_r10,0,35);
	sendata_s03=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_ESP)+3);
	memset(sendata_s03,0,sizeof(S_AWMU_2_UWMU_ESP)+3);
	memcpy(sendata_s03,pdata_s03,sizeof(S_AWMU_2_UWMU_ESP));
	BAUS bas;
	bas.s=CRC16(sendata_s03,sizeof(S_AWMU_2_UWMU_ESP));
	sendata_s03[sizeof(S_AWMU_2_UWMU_ESP)]=bas.by[0];
	sendata_s03[sizeof(S_AWMU_2_UWMU_ESP)+1]=bas.by[1];
	sendata_s02=(BYTE*)malloc(sizeof(AWMU_AWRU_S02)+3);
	memset(sendata_s02,0,sizeof(AWMU_AWRU_S02)+3);
	FuZhi_CC_S02();
	sendata_s021=(BYTE*)malloc(sizeof(AWMU_AWRU_S021)+3);
	memset(sendata_s021,0,sizeof(AWMU_AWRU_S021)+3);
	sendata_s021[0]=0xa5;
	sendata_s021[2]=0x01;
	sendata_s021[3]=0x02;
	sendata_s031_1=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_1)+3);
	memset(sendata_s031_1,0,sizeof(S_AWMU_2_UWMU_EA_1)+3);
	sendata_s031_2=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_2)+3);
	memset(sendata_s031_2,0,sizeof(S_AWMU_2_UWMU_EA_2)+3);
	sendata_s031_3=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_2)+3);
	memset(sendata_s031_3,0,sizeof(S_AWMU_2_UWMU_EA_2)+3);
	sendata_s031_4=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_2)+3);
	memset(sendata_s031_4,0,sizeof(S_AWMU_2_UWMU_EA_2)+3);
	recdata_r30=(BYTE*)malloc(sizeof(S_UWMU_2_AWMU_EP)+3);
	memset(recdata_r30,0,sizeof(S_UWMU_2_AWMU_EP)+3);
	recdata_r303=(BYTE*)malloc(sizeof(S_UWMU_2_AWMU_SP)+3);
	memset(recdata_r303,0,sizeof(S_UWMU_2_AWMU_SP)+3);
	sendata_s034=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA1)+3);
	memset(sendata_s034,0,sizeof(S_AWMU_2_UWMU_EA1)+3);
	recdata_r304=(BYTE*)malloc(sizeof(S_UWMU_2_AWMU_EA1)+3);
	memset(recdata_r304,0,sizeof(S_UWMU_2_AWMU_EA1)+3);
	recdata_r301=(BYTE*)malloc(sizeof(S_UWMU_2_AWMU_EA)+3);
	memset(recdata_r301,0,sizeof(S_UWMU_2_AWMU_EA)+3);
	sendata_s07=(BYTE*)malloc(sizeof(S_AWMU_2_EMU_EP)+3);
	memset(sendata_s07,0,sizeof(S_AWMU_2_EMU_EP)+3);
	pdata_r306=(S_UWMU_2_AWMU_EA3*)malloc(sizeof(S_UWMU_2_AWMU_EA3));
	memset(pdata_r306,0,sizeof(S_UWMU_2_AWMU_EA3));
	pdata_s022=(AWMU_AWRU_S022*)malloc(sizeof(AWMU_AWRU_S022));
	memset(pdata_s022,0,sizeof(AWMU_AWRU_S022));
	sendata_s022=(BYTE*)malloc(sizeof(AWMU_AWRU_S022)+3);
	memset(sendata_s022,0,sizeof(AWMU_AWRU_S022)+3);
	pdata_s023=(AWMU_AWRU_S023*)malloc(sizeof(AWMU_AWRU_S023));
	memset(pdata_s023,0,sizeof(AWMU_AWRU_S023));
	sendata_s023=(BYTE*)malloc(sizeof(AWMU_AWRU_S023)+3);
	memset(sendata_s023,0,sizeof(AWMU_AWRU_S023)+3);
	pdata_s024=(AWRU_AWMU_S024*)malloc(sizeof(AWRU_AWMU_S024));
	memset(pdata_s024,0,sizeof(AWRU_AWMU_S024));
	sendata_s024=(BYTE*)malloc(sizeof(AWRU_AWMU_S024)+3);
	memset(sendata_s024,0,sizeof(AWRU_AWMU_S024)+3);
	pdata_r305=(S_UWMU_2_DSU_EP*)malloc(sizeof(S_UWMU_2_DSU_EP));
	memset(pdata_r305,0,sizeof(S_UWMU_2_DSU_EP));
	pdata_s025=(AWRU_AWMU_S025*)malloc(sizeof(AWRU_AWMU_S025));
	memset(pdata_s025,0,sizeof(AWRU_AWMU_S025));
	sendata_s025=(BYTE*)malloc(sizeof(AWRU_AWMU_S025)+3);
	memset(sendata_s025,0,sizeof(AWRU_AWMU_S025)+3);
	pdata_s026=(AWRU_AWMU_S026*)malloc(sizeof(AWRU_AWMU_S026));
	memset(pdata_s026,0,sizeof(AWRU_AWMU_S026));
	sendata_s026=(BYTE*)malloc(sizeof(AWRU_AWMU_S026)+3);
	memset(sendata_s026,0,sizeof(AWRU_AWMU_S026)+3);
	pdata_s027_1=(S_AWMU_2_UWMU_EA_1*)malloc(sizeof(S_AWMU_2_UWMU_EA_1));
	memset(pdata_s027_1,0,sizeof(S_AWMU_2_UWMU_EA_1));
	sendata_s027_1=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_1)+3);
	memset(sendata_s027_1,0,sizeof(S_AWMU_2_UWMU_EA_1)+3);
	pdata_s027_2=(S_AWMU_2_UWMU_EA_2*)malloc(sizeof(S_AWMU_2_UWMU_EA_2));
	memset(pdata_s027_2,0,sizeof(S_AWMU_2_UWMU_EA_2));
	sendata_s027_2=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_2)+3);
	memset(sendata_s027_2,0,sizeof(S_AWMU_2_UWMU_EA_2)+3);
	pdata_s027_3=(S_AWMU_2_UWMU_EA_2*)malloc(sizeof(S_AWMU_2_UWMU_EA_2));
	memset(pdata_s027_3,0,sizeof(S_AWMU_2_UWMU_EA_2));
	sendata_s027_3=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_2)+3);
	memset(sendata_s027_3,0,sizeof(S_AWMU_2_UWMU_EA_2)+3);
	pdata_s027_4=(S_AWMU_2_UWMU_EA_2*)malloc(sizeof(S_AWMU_2_UWMU_EA_2));
	memset(pdata_s027_4,0,sizeof(S_AWMU_2_UWMU_EA_2));
	sendata_s027_4=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA_2)+3);
	memset(sendata_s027_4,0,sizeof(S_AWMU_2_UWMU_EA_2)+3);
	sendata_0208=(BYTE*)malloc(sizeof(AWMU_AWRU_S028)+3);
	memset(sendata_0208,0,sizeof(AWMU_AWRU_S028)+3);
	sendata_0209=(BYTE*)malloc(sizeof(AWMU_AWRU_S029)+3);
	memset(sendata_0209,0,sizeof(AWMU_AWRU_S029)+3);
	pdata_0701=(AWMU_2_EMU_EA_PARAM_CONFIG*)malloc(sizeof(AWMU_2_EMU_EA_PARAM_CONFIG));
	memset(pdata_0701,0,sizeof(AWMU_2_EMU_EA_PARAM_CONFIG));
	sendata_0701=(BYTE*)malloc(sizeof(AWMU_2_EMU_EA_PARAM_CONFIG)+3);
	memset(sendata_0701,0,sizeof(AWMU_2_EMU_EA_PARAM_CONFIG)+3);
	sendata_0702=(BYTE*)malloc(sizeof(AWMU_2_EMU_EA_TIMESET)+3);
	memset(sendata_0702,0,sizeof(AWMU_2_EMU_EA_TIMESET)+3);
	sendata_0307=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA4)+3);
	memset(sendata_0307,0,sizeof(S_AWMU_2_UWMU_EA4)+3);
	pdata_s3008=(S_UWMU_2_AWMU_EA5*)malloc(sizeof(S_UWMU_2_AWMU_EA5));   //20170506新增
	memset(pdata_s3008,0,sizeof(S_UWMU_2_AWMU_EA5));
	pdata_r0308=(S_AWMU_2_UWMU_EA5*)malloc(sizeof(S_AWMU_2_UWMU_EA5));     //20170506新增
	memset(pdata_r0308,0,sizeof(S_AWMU_2_UWMU_EA5));
//	sendata_0308=(BYTE*)malloc(sizeof(S_AWMU_2_UWMU_EA5)+3);            //20170506新增
//	memset(sendata_0308,0,sizeof(S_AWMU_2_UWMU_EA5)+3); 
	pt1=new float*[6];
	for(int i=0;i<6;i++)
	{pt1[i]=new float[70];memset(pt1[i],0,280);}
	pt2=new float*[6];
	for(int i=0;i<6;i++)
	{pt2[i]=new float[70];memset(pt2[i],0,280);}
	pt3=new float*[6];
	for(int i=0;i<6;i++)
	{pt3[i]=new float[70];memset(pt3[i],0,280);}
	pt=new float*[6];
	for(int i=0;i<6;i++)
	{pt[i]=new float[200];memset(pt[i],0,800);}
	recdata_r10_wx=(BYTE*)malloc(35);
	memset(recdata_r10_wx,0,35);
	sendata_s01=(BYTE*)malloc(23);
	memset(sendata_s01,0,23);
	for(int i=0;i<4;i++)
		rwyz_fs_flag[i]=false;
	Init_s01();
	FuZhi_CC_S025(recdata_r10);
	fault_flag_r305_last=0;
	fault_flag_r305_curr=0;
	wxd_send=0;
	wxd_recv=0;
	wxd_error=0;
	Speed_out=0;
	page_rwyz=new CRwyzDlg(this);
	stop_remote_cmd=false;         //初始化为允许在网络和无线电定时器中下发周期性的遥控调度报文 20180310
}

CXiaoBiLiDlg::~CXiaoBiLiDlg()
{
	delete page_config_sxzk;
	delete page1;
	delete page2;
	delete page3;
	delete page4;
	delete page_config_ydgh;
	delete page_ljdd;
	delete page_wxwdk;
	delete page_wxwdk_wxddk;
	delete page_sch_txzt;
	delete page_rwyz;
	free(sendata_s03);
	free(sendata_s031_1);
	free(sendata_s031_2);
	free(sendata_s031_3);
	free(sendata_s031_4);
	free(sendata_s034);
	free(sendata_s01);
	free(sendata_s02);
	free(sendata_s021);
	free(sendata_s022);
	free(sendata_s023);
	free(sendata_s024);
	free(sendata_s025);
	free(sendata_s026);
	free(sendata_s027_1);
	free(sendata_s027_2);
	free(sendata_s027_3);
	free(sendata_s027_4);
	free(sendata_s07);
	free(recdata_r30);
	free(recdata_r301);
	free(recdata_r303);
	free(recdata_r304);
	free(recdata_r10);
	free(recdata_r10_wx);
	free(pdata_s02);
	free(pdata_s021);
	free(pdata_s022);
	free(pdata_s023);
	free(pdata_s024);
	free(pdata_s025);
	free(pdata_s026);
	free(pdata_s027_1);
	free(pdata_s027_2);
	free(pdata_s027_3);
	free(pdata_s027_4);
	free(pdata_s03);
	free(pdata_s031_1);
	free(pdata_s031_2);
	free(pdata_s031_3);
	free(pdata_s031_4);
	free(pdata_s034);
	free(pdata_r10);
	free(pdata_r20);
	free(pdata_r30);
	free(pdata_r303);
	free(pdata_r304);
	free(pdata_r305);
	free(pdata_r306);
	free(pdata_r301);
	free(pdata_r201);
	free(pdata_s07);
	free(pdata_s07e);
	free(pdata_r70);
	free(pdata_r70e);
	free(pdata_r701e);
	free(pdata_r702e);
	free(pdata_r703e);
	free(pdata_gps);
	free(pdata_usbl);
	arraySend_s01.RemoveAll();
	arraySend_s07e.RemoveAll();
	arraySend_s03.RemoveAll();
	arraySend_s034_wxd.RemoveAll();
	if(!pt1)
	{
		for(int i=0;i<6;i++)
			delete []pt1[i];
		delete []pt1;
	}
	if(!pt2)
	{
		for(int i=0;i<6;i++)
			delete []pt2[i];
		delete []pt2;
	}
	if(!pt3)
	{
		for(int i=0;i<6;i++)
			delete []pt3[i];
		delete []pt3;
	}
	if(!pt)
	{
		for(int i=0;i<6;i++)
			delete []pt[i];
		delete []pt;
	}
	file.close();
	filewxd.close();
}

void CXiaoBiLiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	DDX_Control(pDX, IDC_MSCOMM1, m_CtrlComm1);
	DDX_Control(pDX, IDC_MSCOMM2, m_CtrlComm2);
	DDX_Control(pDX, IDC_MSCOMM3, m_CtrlComm3);
	DDX_Control(pDX, IDC_MSCOMM4, m_CtrlComm4);
	DDX_Control(pDX, IDC_MSCOMM5, m_CtrlComm5);
}

BEGIN_MESSAGE_MAP(CXiaoBiLiDlg, CDialogEx)
	ON_WM_TIMER()
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CXiaoBiLiDlg::OnTcnSelchangeTab1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CXiaoBiLiDlg 消息处理程序
void CXiaoBiLiDlg::CommInit_SCH()
{
	if(m_CtrlComm1.get_PortOpen())  //串口2初始化，该串口与手操盒通信
		m_CtrlComm1.put_PortOpen(FALSE);
	m_CtrlComm1.put_CommPort(2);         //选择串口1
	m_CtrlComm1.put_InBufferSize(1024);  //设置输入缓冲区大小
	if(!m_CtrlComm1.get_PortOpen())
		m_CtrlComm1.put_PortOpen(TRUE);  //打开串口
	else
		AfxMessageBox(_T("cannot open serial port1"));
	m_CtrlComm1.put_Settings(_T("115200,n,8,1"));
	m_CtrlComm1.put_InputMode(1);
	m_CtrlComm1.put_RThreshold(18);
	m_CtrlComm1.put_InputLen(0);
	m_CtrlComm1.get_Input();
}
void CXiaoBiLiDlg::CommInit_GPS()
{
	if(m_CtrlComm4.get_PortOpen())        //串口5初始化，该串口接收GPS消息
		m_CtrlComm4.put_PortOpen(FALSE);
	m_CtrlComm4.put_CommPort(5);         
	m_CtrlComm4.put_InBufferSize(1024);  //设置输入缓冲区大小
	if(!m_CtrlComm4.get_PortOpen())
		m_CtrlComm4.put_PortOpen(TRUE);  //打开串口
	else
		AfxMessageBox(_T("cannot open serial port"));
	m_CtrlComm4.put_Settings(_T("19200,n,8,1"));
	m_CtrlComm4.put_InputMode(1);
	m_CtrlComm4.put_RThreshold(28);
	m_CtrlComm4.put_InputLen(0);
	m_CtrlComm4.get_Input();
}
void CXiaoBiLiDlg::CommInit_USBL()
{
	if(m_CtrlComm5.get_PortOpen())        //串口3初始化，该串口接收USBL消息
		m_CtrlComm5.put_PortOpen(FALSE);
	m_CtrlComm5.put_CommPort(3);         
	m_CtrlComm5.put_InBufferSize(1024);  //设置输入缓冲区大小
	if(!m_CtrlComm5.get_PortOpen())
		m_CtrlComm5.put_PortOpen(TRUE);  //打开串口
	else
		AfxMessageBox(_T("cannot open serial port"));
	m_CtrlComm5.put_Settings(_T("19200,n,8,1"));
	m_CtrlComm5.put_InputMode(1);
	m_CtrlComm5.put_RThreshold(28);
	m_CtrlComm5.put_InputLen(0);
	m_CtrlComm5.get_Input();
}
void CXiaoBiLiDlg::CommInit_WXD()
{
   if(m_CtrlComm2.get_PortOpen())        //串口4初始化，该串口接收无线电消息
		m_CtrlComm2.put_PortOpen(FALSE);
	m_CtrlComm2.put_CommPort(4);        
	m_CtrlComm2.put_InBufferSize(1024);  //设置输入缓冲区大小
	if(!m_CtrlComm2.get_PortOpen())
		m_CtrlComm2.put_PortOpen(TRUE);  //打开串口
	else
		AfxMessageBox(_T("cannot open serial port"));
	m_CtrlComm2.put_Settings(_T("19200,n,8,1"));
	m_CtrlComm2.put_InputMode(1);    //以字节的形式接收
	m_CtrlComm2.put_RThreshold(1);  //每接收到1个字节触发OnCom事件
	m_CtrlComm2.put_InputLen(0);     //OnCom事件触发时接收缓冲区所有数据
	m_CtrlComm2.get_Input();         //接收并清空缓冲区
}
void CXiaoBiLiDlg::CommInit_SSTX()
{
   if(m_CtrlComm3.get_PortOpen())        //串口1初始化，该串口接收水声通信消息
		m_CtrlComm3.put_PortOpen(FALSE);
	m_CtrlComm3.put_CommPort(1);         
	m_CtrlComm3.put_InBufferSize(1024);  //设置输入缓冲区大小
	if(!m_CtrlComm3.get_PortOpen())
		m_CtrlComm3.put_PortOpen(TRUE);  //打开串口
	else
		AfxMessageBox(_T("cannot open serial port"));
	m_CtrlComm3.put_Settings(_T("9600,n,8,1"));
	m_CtrlComm3.put_InputMode(1);
	m_CtrlComm3.put_RThreshold(sizeof(S_EMU_2_AWMU_SP1)+3);
	m_CtrlComm3.put_InputLen(0);
	m_CtrlComm3.get_Input();
}
void CXiaoBiLiDlg::ServerStart()
{
	m_pListenSocket=new CListenSocket(this);  //服务器启动，与水上存储通信
	m_pListenSocket->Create(2000,SOCK_STREAM,"192.168.0.100");
	m_pListenSocket->Listen();
}

BOOL CXiaoBiLiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//SkinH_Attach();
	// TODO: 在此添加额外的初始化代码
	/*CString str;
	str.Format("%d ",sizeof(S_UWMU_2_AWMU_EP));
	MessageBox(str);*/
	T_S03=GetPrivateProfileInt("T","T_S03",1000,"D:\\SSZKConfig\\config.ini");
	T_S07=GetPrivateProfileInt("T","T_S07",2000,"D:\\SSZKConfig\\config.ini");
	T_S07E=GetPrivateProfileInt("T","T_S07E",3000,"D:\\SSZKConfig\\config.ini");
	T_R70E=GetPrivateProfileInt("T","T_R70E",15000,"D:\\SSZKConfig\\config.ini");
	T_WXD=GetPrivateProfileInt("T","T_WXD",1000,"D:\\SSZKConfig\\config.ini");
	ShowWindow(SW_SHOWMAXIMIZED);
	//m_Tab.InsertItem(0,_T("远程操控"));
	//m_Tab.InsertItem(1,_T("手操盒、水下主控、基础控制参数配置"));
	//m_Tab.InsertItem(2,_T("应急参数配置1"));
	//m_Tab.InsertItem(3,_T("应急参数配置2"));
	//m_Tab.InsertItem(4,_T("应急参数配置3"));
	//m_Tab.InsertItem(5,_T("运动规划参数配置"));
	//m_Tab.InsertItem(6,_T("导航参数配置"));
	//m_Tab.InsertItem(7,_T("故障显示界面"));
	//m_Tab.InsertItem(8,_T("动力系统状态显示"));
	//m_Tab.InsertItem(9,_T("调试界面 "));
	//m_Tab.InsertItem(10,_T("手操盒指令"));
	m_Tab.InsertItem(0,_T("  集中控制  "));
	m_Tab.InsertItem(1,_T(" 手操盒指令 "));
	m_Tab.InsertItem(2,_T(" 故障显示  "));
	m_Tab.InsertItem(3,_T(" 动力系统状态显示 "));
	m_Tab.InsertItem(4,_T(" 手操盒、水下主控、基础控制配置 "));
	m_Tab.InsertItem(5,_T("应急配置1 "));
	m_Tab.InsertItem(6,_T(" 应急配置2 "));
	m_Tab.InsertItem(7,_T(" 应急配置3 "));
	m_Tab.InsertItem(8,_T(" 运动规划配置 "));
	m_Tab.InsertItem(9,_T(" 导航配置  "));
	m_Tab.InsertItem(10,_T("    调试     "));
	page3->Create(IDD_DIALOG4,GetDlgItem(IDC_TAB1));   //手操盒、水下主控、基础控制配置界面
	page_config_ydgh->Create(IDD_DIALOG6,GetDlgItem(IDC_TAB1));   //运动规划配置界面
	page_cspz_yj->Create(IDD_DIALOG_CSPZ_YJ,GetDlgItem(IDC_TAB1)); //应急单元参数配置界面1
	page_cspz_yj_2->Create(IDD_DIALOG_CSPZ_YJ_2,GetDlgItem(IDC_TAB1)); //应急单元参数配置界面2
	page_cspz_yj_3->Create(IDD_DIALOG_CSPZ_YJ_3,GetDlgItem(IDC_TAB1)); //应急单元参数配置界面3
	page_nau_config->Create(IDD_DIALOG_NAU_CONFIG,GetDlgItem(IDC_TAB1));//导航参数配置
	page1->Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1));   //远程操控界面
	page4->Create(IDD_DIALOG5,GetDlgItem(IDC_TAB1));   //故障显示界面
	page2->Create(IDD_DIALOG3,GetDlgItem(IDC_TAB1));   //动力系统状态显示界面
	page_test->Create(IDD_DIALOG9,GetDlgItem(IDC_TAB1));   //调试界面
	page_sch->Create(IDD_DIALOG_SCH,GetDlgItem(IDC_TAB1));
	//page_config_sxzk->Create(IDD_DIALOG1,GetDlgItem(IDC_TAB1));   //水下主控配置界面
	page_wxwdk->Create(IDD_DIALOG7);
	page_wxwdk_wxddk->Create(IDD_DIALOG7);
	page_ljdd->Create(IDD_DIALOG7);   //连接等待对话框
	page_sch_txzt->Create(IDD_DIALOG7); 
	page_rwyz->Create(IDD_DIALOG_RWYZ);
	//CRect rcDlgs;
	//page_ljdd->GetClientRect(rcDlgs);  //得到对话框的Rect 对话框的大小
	//page_ljdd->SetWindowPos(GetDlgItem(IDD_XIAOBILI_DIALOG),470,350,rcDlgs.Width(),rcDlgs.Height(),0);
	page_ljdd->m_msg_str="正在连接应急和水下主控，请等待...";
	//page_password->Create(IDD_DIALOG_PAASSWORD);
	//CRect rcDlgs_pw;
	//page_password->GetClientRect(rcDlgs_pw);
	//page_password->SetWindowPos(GetDlgItem(IDD_XIAOBILI_DIALOG),470,350,rcDlgs_pw.Width(),rcDlgs_pw.Height(),0);
	CRect rect;
	m_Tab.GetClientRect(&rect);
/*
	rect.top+=0;  //横的选项卡，要在这个地方腾出选项页的标签，+20即可
	rect.bottom-=0;
	rect.left+=20;
	rect.right-=0;
*/
	rect.top+=0;  //横的选项卡，要在这个地方腾出选项页的标签，+20即可
	rect.bottom-=30;
	rect.left+=0;
	rect.right-=0;
	page1->MoveWindow(&rect);
	page2->MoveWindow(&rect);
	page3->MoveWindow(&rect);
	page4->MoveWindow(&rect);
	page_nau_config->MoveWindow(&rect);
	page_config_ydgh->MoveWindow(&rect);
	//page_config_sxzk->MoveWindow(&rect);
	page_cspz_yj->MoveWindow(&rect);
	page_cspz_yj_2->MoveWindow(&rect);
	page_cspz_yj_3->MoveWindow(&rect);
	page_test->MoveWindow(&rect);
	page_sch->MoveWindow(&rect);
	//设置默认显示的选项卡页面
	page1->ShowWindow(TRUE);
	m_Tab.SetCurSel(0);
	page_ljdd->ShowWindow(TRUE);
	page_ljdd->UpdateData(false);
	SSSXSocket=new CSessionSocket(this);   //水上主控与水下主控通信套接字
	SSSXSocket->Create(5001,SOCK_STREAM,"192.168.0.100");//设置本机端口
	unsigned long ul = 1;
    ioctlsocket(*SSSXSocket, FIONBIO, &ul);
	int timeout=10;
	setsockopt(*SSSXSocket,SOL_SOCKET,SO_SNDTIMEO,(char*)&timeout,sizeof(int));
	SSCCSocket=new CSessionSocket(this);   //水上主控与水上存储套接字
	SSCCSocket->Create(5002,SOCK_STREAM,"192.168.0.100");//设置本机端口
	ioctlsocket(*SSCCSocket, FIONBIO, &ul);
	SCHSocket=new CSessionSocket(this);  //水上主控与手操盒通信套接字
	SCHSocket->Create(5003,SOCK_STREAM,"192.168.0.100");
    ioctlsocket(*SCHSocket, FIONBIO, &ul);
	SSJCKZSocket=new CSessionSocket(this);  //水上主控与基础控制单元通信套接字
	SSJCKZSocket->Create(5004,SOCK_STREAM,"192.168.0.100");
    ioctlsocket(*SSJCKZSocket, FIONBIO, &ul);
	SSYJSocket=new CSessionSocket(this);  //水上主控与应急单元通信套接字
	SSYJSocket->Create(5005,SOCK_STREAM,"192.168.0.100");
    ioctlsocket(*SSYJSocket, FIONBIO, &ul);

	Connect_EMU();   //连接应急
	SetTimer(9,2000,NULL); //两秒钟后查看应急连接状态
	//初始化串口和服务器
	ServerStart();
	//CommInit_SCH();
	//CommInit_GPS();	
	//CommInit_USBL();
	SetTimer(5,250,NULL);   //设置循环处理手操盒消息的定时器    //20170507  改成250ms
	//SetTimer(8,1000,NULL);  //定时写入三维数据文件
	SetTimer(11,T_R70E,NULL);   //定时判断水声通信状态
	SetTimer(12,T_WXD,NULL);   //定时检测无线电通信状态
	//CommInit_WXD();         //初始化无线电通信串口  
 //   CommInit_SSTX();        //初始化水声通信串口
	/*STARTUPINFO sui;
	PROCESS_INFORMATION pi;
	ZeroMemory(&sui,sizeof(STARTUPINFO));
	sui.cb=sizeof(STARTUPINFO);
	sui.dwFlags=STARTF_USESTDHANDLES;
	sui.hStdError=GetStdHandle(STD_ERROR_HANDLE);
	if(!CreateProcess("HMDebug\\0.exe",NULL,NULL,NULL,TRUE,0,NULL,NULL,&sui,&pi))
	{}
	else
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}*/
	file=ofstream("SCH.txt",ios::app);
	filewxd=ofstream("SCHwxd.txt",ios::app);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CXiaoBiLiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CXiaoBiLiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CXiaoBiLiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CXiaoBiLiDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//	int CurSel;
//	CurSel=m_Tab.GetCurSel();
//	switch(CurSel)    //包括应急配置界面和运动规划配置界面
//	{
//	case 0:
//	page1->ShowWindow(TRUE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 1:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(TRUE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 2:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(TRUE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 3:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(TRUE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 4:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(TRUE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 5:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(TRUE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 6:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(TRUE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 7:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(TRUE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 8:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(TRUE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 9:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(TRUE);
//	page_sch->ShowWindow(FALSE);
//	break;
//	case 10:
//	page1->ShowWindow(FALSE);
//	page3->ShowWindow(FALSE);
//	page_cspz_yj->ShowWindow(FALSE);
//	page_cspz_yj_2->ShowWindow(FALSE);
//	page_cspz_yj_3->ShowWindow(FALSE);
//	page_config_ydgh->ShowWindow(FALSE);
//	page_nau_config->ShowWindow(FALSE);
//	page4->ShowWindow(FALSE);
//	page2->ShowWindow(FALSE);
//	page_test->ShowWindow(FALSE);
//	page_sch->ShowWindow(TRUE);
//	break;
//	default: ;
//	}
//}

void CXiaoBiLiDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int CurSel;
	CurSel=m_Tab.GetCurSel();
	switch(CurSel)    //包括应急配置界面和运动规划配置界面
	{
	case 0:
	page1->ShowWindow(TRUE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 1:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(TRUE);
	break;
	case 2:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(TRUE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 3:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(TRUE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 4:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(TRUE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 5:
    page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(TRUE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 6:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(TRUE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 7:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(TRUE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 8:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(TRUE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 9:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(TRUE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(FALSE);
	page_sch->ShowWindow(FALSE);
	break;
	case 10:
	page1->ShowWindow(FALSE);
	page3->ShowWindow(FALSE);
	page_cspz_yj->ShowWindow(FALSE);
	page_cspz_yj_2->ShowWindow(FALSE);
	page_cspz_yj_3->ShowWindow(FALSE);
	page_config_ydgh->ShowWindow(FALSE);
	page_nau_config->ShowWindow(FALSE);
	page4->ShowWindow(FALSE);
	page2->ShowWindow(FALSE);
	page_test->ShowWindow(TRUE);
	page_sch->ShowWindow(FALSE);
	break;
	default: ;
	}
}
void CXiaoBiLiDlg::OnAccept()
{
	SOCKADDR_IN m_RemoteAddr;
	int len=sizeof(m_RemoteAddr);
	memset(&m_RemoteAddr,0,sizeof(m_RemoteAddr));
	CSessionSocket *pSocket=new CSessionSocket(this);
	//pSocket->Create(0,SOCK_STREAM,"192.168.0.100");
	/*unsigned long ul = 1;
    ioctlsocket(*pSocket, FIONBIO, &ul);*/
	m_pListenSocket->Accept(*pSocket,(SOCKADDR*)&m_RemoteAddr,&len);
	BYTE b=m_RemoteAddr.sin_addr.S_un.S_un_b.s_b4;
	if(b==102)
	{
		if(SSCCSocket!=NULL)
			delete SSCCSocket;
		SSCCSocket=pSocket;
		SetTimer(10,1000,NULL); //定时发送报文S_025至水上存储
		page1->pdata_page1->awmu_dsu_net_state=true;
		//SetTimer(2,1000,NULL);
	}
	/*else if(b==107)
	{
		if(SSYJSocket!=NULL)
			delete SSYJSocket;
		SSYJSocket=pSocket;
	}*/
	else if(b==106)
	{
		if(SSJCKZSocket!=NULL)
			delete SSJCKZSocket;
		SSJCKZSocket=pSocket;
		page3->drawpicture(IDC_PICTURE_JCKZTXZT,1);
	}
	else    //手操盒连接请求来了
	{
		if(SCHSocket!=NULL)
			delete SCHSocket;
		//page1->pdata_page1->sssch_wl_tx_state=true;   //收到手操盒无线网数据再显示连接成功
		SCHSocket=pSocket;
		BYTE data[3];
		data[0]=0x5a;
		data[1]=0xff;
		data[2]=0x0d;
		SCHSocket->Send(data,3,0);
      //  MessageBox("已发送");
	}
}


void CXiaoBiLiDlg::ProcData_CC_R20(BYTE* lbuff)
{
	memcpy(pdata_r20,lbuff,sizeof(AWRU_AWMU_R20));
}

void CXiaoBiLiDlg::ProcData_CC_R201(BYTE* lbuff)
{
	memcpy(pdata_r201,lbuff,sizeof(AWRU_AWMU_R201));
}

void CXiaoBiLiDlg::ProcData_SX_R30(BYTE* lbuff)    //解包水下主控发来的数据,只解我要的数据
{                                                //可以取pdata_r30中的值使用
	memcpy(recdata_r30,lbuff,sizeof(S_UWMU_2_AWMU_EP)+3);
	memcpy(pdata_r30,recdata_r30,sizeof(S_UWMU_2_AWMU_EP));
	memcpy(page2->power_infor_page2,&(pdata_r30->powerControlUnitInfo),sizeof(POWER_INFO));  //在和动力系统显示界面上显示动力系统和基础控制单元信息
	//memcpy(page2->prcu_info_page2,&(pdata_r30->primaryControlUnitInfo),sizeof(PRCU_INFO));
	/*
	if(pdata_r30->MEUstate==110)
	{
		page1->pdata_page1->meu_state_test_light=true;
		page1->pdata_page1->meu_state_debug_light=false;
		page1->pdata_page1->meu_state_fault_light=false;
	}
	else if(pdata_r30->MEUstate==111)
	{
		page1->pdata_page1->meu_state_test_light=false;
		page1->pdata_page1->meu_state_debug_light=true;
		page1->pdata_page1->meu_state_fault_light=false;
	}
	else if(pdata_r30->MEUstate==112)
	{
		page1->pdata_page1->meu_state_test_light=false;
		page1->pdata_page1->meu_state_debug_light=false;
		page1->pdata_page1->meu_state_fault_light=true;
	}
	else{} */
	/*CString str,strtemp;
	strtemp.Format("舱室温度%d ",pdata_r30->primaryControlUnitInfo.cabinTempreture);
	str+=strtemp;
	strtemp.Format("围壳舵舵角%d ",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.fairwaterRudderAngle);
	str+=strtemp;
	strtemp.Format("方向舵舵角%d ",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.rudderAngle);
	str+=strtemp;
	strtemp.Format("左艉舵舵角%d ",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.leftRearRudderAngle);
	str+=strtemp;
	strtemp.Format("右艉舵舵角%d ",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.rightRearRudderAngle);
	str+=strtemp;
	strtemp.Format("舵机1电压%d ",pdata_r30->primaryControlUnitInfo.steering[0].voltage);
	str+=strtemp;
	strtemp.Format("舵机1电流%d ",pdata_r30->primaryControlUnitInfo.steering[0].current);
	str+=strtemp;
	strtemp.Format("通信状态%d ",pdata_r30->primaryControlUnitInfo.steeringCommStatus);
	str+=strtemp;
	strtemp.Format("艏向高度%d ",pdata_r30->navigationInfo.processedData.headingHeight);
	str+=strtemp;
	strtemp.Format("艏向速度%d ",pdata_r30->navigationInfo.processedData.headingSpeed);
	str+=strtemp;*/
	//MessageBox(str);
	//开始调度后会取消控制器通信状态查询，但第一次运行程序时，需要调度后为运动规划单元和基础控制单元上电，这时控制器通信状态查询已经禁用，只能使用调度后水下主控反馈的使状态来显示
	
	//if(pdata_r30->communicationStatus[2]==0)   //运动规划单元状态显示
	//	page1->pdata_page1->uwmu_mpu_net_state=true;
	//if(pdata_r30->communicationStatus[3]==0)   //基础控制单元状态显示
	//	page1->pdata_page1->uwmu_prcu_net_state=true;
	/*
	if(pdata_r30->communicationStatus[0]==0)
		page1->pdata_page1->awmu_uwmu_net_state=false;
	else
		page1->pdata_page1->awmu_uwmu_net_state=true;
	if(pdata_r30->communicationStatus[1]==0)
		page1->pdata_page1->uwmu_nau_net_state=false;
	else
		page1->pdata_page1->uwmu_nau_net_state=true;
	if(pdata_r30->communicationStatus[2]==0)
		page1->pdata_page1->uwmu_mpu_net_state=false;
	else
		page1->pdata_page1->uwmu_mpu_net_state=true;
	if(pdata_r30->communicationStatus[3]==0)
		page1->pdata_page1->uwmu_prcu_net_state=false;
	else
		page1->pdata_page1->uwmu_prcu_net_state=true;
	if(pdata_r30->communicationStatus[4]==0)
		page1->pdata_page1->uwmu_pocu_net_state=false;
	else
		page1->pdata_page1->uwmu_pocu_net_state=true;
	if(pdata_r30->communicationStatus[5]==0)
		page1->pdata_page1->uwmu_dsu_net_state=false;
	else
		page1->pdata_page1->uwmu_dsu_net_state=true;
	if(pdata_r30->communicationStatus[6]==0)  //应急以太网
		page1->pdata_page1->uwmu_emu_net_state=false;
	else
		page1->pdata_page1->uwmu_emu_net_state=true;
	if(pdata_r30->communicationStatus[7]==0)
		page1->pdata_page1->uwmu_emu_seri_state=false;
	else
		page1->pdata_page1->uwmu_emu_seri_state=true;
	*/
}

void CXiaoBiLiDlg::FuZhi_CC_S02()
{
	pdata_s02->pktHead1=0xA5;
	pdata_s02->pktHead2=0x0200;
	memcpy(&(pdata_s02->operatorCmd),&(pdata_r30->operatorcmd),sizeof(HAND_OPERATOR_INFO));
	memcpy(&(pdata_s02->navigationInfo),&(pdata_r30->navigationInfo),sizeof(NAU_INFO));
	memcpy(&(pdata_s02->primaryControlUnitInfo),&(pdata_r30->primaryControlUnitInfo),sizeof(PRCU_INFO));
	memcpy(&(pdata_s02->emergencyInfo),&(pdata_r30->emergencyInfo),sizeof(EMERGENCY_INFO));
	memcpy(pdata_s02->communicationStatus,pdata_r30->communicationStatus,40);  
	memcpy(&(pdata_s02->powerControlUnitInfo),&(pdata_r30->powerControlUnitInfo),sizeof(POWER_INFO));
	memcpy(&(pdata_s02->MEUfeedback),&(pdata_r30->MEUfeedback),sizeof(MEU_INFO));
	memcpy(sendata_s02,pdata_s02,sizeof(AWMU_AWRU_S02));
	unsigned short crcCheck=0;
	crcCheck=CRC16(sendata_s02,sizeof(AWMU_AWRU_S02));
	sendata_s02[sizeof(AWMU_AWRU_S02)]=(BYTE)(crcCheck%256);
	sendata_s02[sizeof(AWMU_AWRU_S02)+1]=(BYTE)(crcCheck/256);
	sendata_s02[sizeof(AWMU_AWRU_S02)+2]=0x0d;
	///*CString str,strtemp;
	//			for(int i=0;i<10;i++)
	//			{
	//				strtemp.Format(" %d",pdata_s02->communicationStatus[i]);
	//				str+=strtemp;
	//			}
	//			AfxMessageBox(str);*/

}

void CXiaoBiLiDlg::FuZhi_CC_S022()
{
	memcpy(pdata_s022,pdata_r70,sizeof(AWMU_AWRU_S022));
	pdata_s022->pktHead1=0xa5;
	pdata_s022->pktHead2=0x0202;
	memcpy(sendata_s022,pdata_s022,sizeof(AWMU_AWRU_S022));
	unsigned short crcCheck=0;
	crcCheck=CRC16(sendata_s022,sizeof(AWMU_AWRU_S022));
	sendata_s022[sizeof(AWMU_AWRU_S022)]=(BYTE)(crcCheck%256);
	sendata_s022[sizeof(AWMU_AWRU_S022)+1]=(BYTE)(crcCheck/256);
	sendata_s022[sizeof(AWMU_AWRU_S022)+2]=0x0d;
}

void CXiaoBiLiDlg::FuZhi_CC_S023()
{
	memcpy(pdata_s023,pdata_r70e,sizeof(AWMU_AWRU_S023));
	pdata_s023->pktHead1=0xa5;
	pdata_s023->pktHead2=0x0203;
	memcpy(sendata_s023,pdata_s023,sizeof(AWMU_AWRU_S023));
	unsigned short crcCheck=0;
	crcCheck=CRC16(sendata_s023,sizeof(AWMU_AWRU_S023));
	sendata_s023[sizeof(AWMU_AWRU_S023)]=(BYTE)(crcCheck%256);
	sendata_s023[sizeof(AWMU_AWRU_S023)+1]=(BYTE)(crcCheck/256);
	sendata_s023[sizeof(AWMU_AWRU_S023)+2]=0x0d;
}

void CXiaoBiLiDlg::FuZhi_CC_S024()
{
	memcpy(pdata_s024,pdata_r305,sizeof(AWRU_AWMU_S024));
	pdata_s024->pktHead1=0xa5;
	pdata_s024->pktHead2=0x0204;
	memcpy(sendata_s024,pdata_s024,sizeof(AWRU_AWMU_S024));
	unsigned short crcCheck=0;
	crcCheck=CRC16(sendata_s024,sizeof(AWRU_AWMU_S024));
	sendata_s024[sizeof(AWRU_AWMU_S024)]=(BYTE)(crcCheck%256);
	sendata_s024[sizeof(AWRU_AWMU_S024)+1]=(BYTE)(crcCheck/256);
	sendata_s024[sizeof(AWRU_AWMU_S024)+2]=0x0d;
}

void CXiaoBiLiDlg::FuZhi_CC_S025(BYTE* recdata)
{
	pdata_s025->pktHead1=0xa5;
	pdata_s025->pktHead2=0x0205;
	pdata_s025->workingStage=recdata[3];
	pdata_s025->workingMode=recdata[4];
	memcpy(sendata_s025,pdata_s025,sizeof(AWRU_AWMU_S025));
	unsigned short crcCheck=0;
	crcCheck=CRC16(sendata_s025,sizeof(AWRU_AWMU_S025));
	sendata_s025[sizeof(AWRU_AWMU_S025)]=(BYTE)(crcCheck%256);
	sendata_s025[sizeof(AWRU_AWMU_S025)+1]=(BYTE)(crcCheck/256);
	sendata_s025[sizeof(AWRU_AWMU_S025)+2]=0x0d;
}

void CXiaoBiLiDlg::FuZhi_CC_S026()
{
	pdata_s026->pktHead1=0xa5;
	pdata_s026->pktHead2=0x0206;
	memcpy(pdata_s026->time,pdata_usbl->time,9);
	pdata_s026->logitude_usbl=(pdata_usbl->longitude+pdata_usbl->longitude_minu/60.0);
	pdata_s026->latitude_usbl=(pdata_usbl->latitude+pdata_usbl->latitude_minu/60.0);
	pdata_s026->depth_usbl=pdata_usbl->depth;
	memcpy(sendata_s026,pdata_s026,sizeof(AWRU_AWMU_S026));
	unsigned short crcCheck=0;
	crcCheck=CRC16(sendata_s026,sizeof(AWRU_AWMU_S026));
	sendata_s026[sizeof(AWRU_AWMU_S026)]=(BYTE)(crcCheck%256);
	sendata_s026[sizeof(AWRU_AWMU_S026)+1]=(BYTE)(crcCheck/256);
	sendata_s026[sizeof(AWRU_AWMU_S026)+2]=0x0d;
}

BEGIN_EVENTSINK_MAP(CXiaoBiLiDlg, CDialogEx)
	ON_EVENT(CXiaoBiLiDlg, IDC_MSCOMM1, 1, CXiaoBiLiDlg::OnCommMscomm1, VTS_NONE)
	ON_EVENT(CXiaoBiLiDlg, IDC_MSCOMM2, 1, CXiaoBiLiDlg::OnCommMscomm2, VTS_NONE)
	ON_EVENT(CXiaoBiLiDlg, IDC_MSCOMM3, 1, CXiaoBiLiDlg::OnCommMscomm3, VTS_NONE)
	ON_EVENT(CXiaoBiLiDlg, IDC_MSCOMM4, 1, CXiaoBiLiDlg::OnCommMscomm4, VTS_NONE)
	ON_EVENT(CXiaoBiLiDlg, IDC_MSCOMM5, 1, CXiaoBiLiDlg::OnCommMscomm5, VTS_NONE)
END_EVENTSINK_MAP()


void CXiaoBiLiDlg::OnCommMscomm1()  //手操盒消息来了
{
	// TODO: 在此处添加消息处理程序代码
	BYTE recdata[512];
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	if(m_CtrlComm1.get_CommEvent()==2)
	{
		//MessageBox("aa");
		Sleep(20);
		variant_inp=m_CtrlComm1.get_Input();
		safearray_inp=variant_inp;
		len=safearray_inp.GetOneDimSize();
		if(len<36)
		{
			for(k=0;k<len;k++)
				safearray_inp.GetElement(&k,recdata+k);
			if((recdata[0]==0xA5)&&(recdata[1]==0x10)&&(recdata[2]==0x00)&&(recdata[34]==0x0D))
			{
				unsigned short crcCheck=0;
				crcCheck=CalculateSendCRC(recdata,32);
				//if((buff[33]==crcCheck%256)&&(buff[32]==crcCheck/256))
				memcpy(recdata_r10,recdata,35);     //手操盒消息赋值给recdata_r10
				m_CtrlComm1.put_Output(COleVariant(arraySend_s01));  //反馈串口消息至手操盒
				/*CString str,strtemp;
				str="schck";
				for(int i=0;i<23;i++)
				{
					strtemp.Format("%02X",arraySend_s01.GetAt(i));
					str+=strtemp;
				}
				if(!filewxd.fail())
		{
		   filewxd<<endl<<str;
		}*/
				FuZhi_CC_S029(recdata);  //手操盒消息赋值给水上存储报文
			}
			if((recdata[15]=='C')&&(recdata[16]=='o')&&(recdata[17]=='r'))
				MessageBox("配置成功");
			if((recdata[15]=='E')&&(recdata[16]=='r')&&(recdata[17]=='r'))
				MessageBox("配置信息格式错误，配置失败");
		}
	
	}

}
short CXiaoBiLiDlg::SpeedCtr(short r_SC,short r_SN,short r_SO)
{
	short SC,SN,SO;
	SC=r_SC;SN=r_SN;SO=r_SO;
	if(SC>=100)
	{
		if(SC>SN)
		{
			SO+=(page_test->m_speed_gradient/2);    //手操盒指令周期为500ms  
			if(SO>SC)
			{
				SO=SC;
			}
		}
		else
		{
			SO=SC;
		}
	}
	else
	{
		SO=SC;
	}
	return SO;
}
void CXiaoBiLiDlg::LimitSpeed()
{
	if((pdata_s03->operatorCmd.thrusterSpeedCmd*1500/0x4000)>=0)
	{
		if(((pdata_s03->operatorCmd.thrusterSpeedCmd*1500/0x4000)*(pdata_s03->operatorCmd.thrusterSpeedCmd*1500/0x4000))>((page_test->m_speed_limit_p)*(page_test->m_speed_limit_p)))
		{
			pdata_s03->operatorCmd.thrusterSpeedCmd=abs(page_test->m_speed_limit_p)*0x4000/1500;
		}
	}
	else
	{
		if(((pdata_s03->operatorCmd.thrusterSpeedCmd*1500/0x4000)*(pdata_s03->operatorCmd.thrusterSpeedCmd*1500/0x4000))>((page_test->m_speed_limit_n)*(page_test->m_speed_limit_n)))
		{
			pdata_s03->operatorCmd.thrusterSpeedCmd=abs(page_test->m_speed_limit_n)*(-1)*0x4000/1500;
		}
	
	}


	/*short speed;
	speed=pdata_s03->operatorCmd.thrusterSpeedCmd;
	speed=speed*1.5;
	CString strspeed;
	strspeed.Format("转速为 %d",speed);*/
	//MessageBox(strspeed);

}
void CXiaoBiLiDlg::RudderCtr()
{
	if(page1->m_wkd_ctr_enable==true)  // 围壳舵
	pdata_s03->operatorCmd.rudderAngleCmd.fairwaterRudderAngle=page1->p_wkd*10;
	if(page1->m_fxd_ctr_enable==true)   // 方向舵
	{
	pdata_s03->operatorCmd.rudderAngleCmd.rudderAngle=page1->p_fxd*10;
	}
	if(page1->m_wd_ctr_enable==true)  // 左右尾舵
	{
	pdata_s03->operatorCmd.rudderAngleCmd.leftRearRudderAngle=page1->p_zywd*10;
	pdata_s03->operatorCmd.rudderAngleCmd.rightRearRudderAngle=page1->p_zywd*10;
	}
}
void CXiaoBiLiDlg::FuZhi_SX_S03(BYTE* recdata)
{
	BAUS bas1;
	bas1.s=0;
	memcpy(&pdata_s03->operatorCmd.workingStageMode,&recdata[3],2);
	bool sch_shuibeng_flag=false;
	if((recdata[5]&0x20)==0x20)   //手操盒启变频器同时 启水泵
	{
		sch_shuibeng_flag=true;
	}
	else
	{
		sch_shuibeng_flag=false;
	}
	
	pdata_s03->operatorCmd.powerSwitch=0;
	{
		if((recdata[5]&0x01)==0x01)
			pdata_s03->operatorCmd.powerSwitch+=1;
		if((recdata[5]&0x02)==0x02)
			pdata_s03->operatorCmd.powerSwitch+=2;
		if((recdata[5]&0x04)==0x04)
			pdata_s03->operatorCmd.powerSwitch+=4;
		if((recdata[5]&0x08)==0x08)
			pdata_s03->operatorCmd.powerSwitch+=8;

		if(true==page1->m_shuibeng_ctr_enable)       //水上主控界面水泵起停控制指令
		{
			if(page1->m_shuibeng_command)
				pdata_s03->operatorCmd.powerSwitch+=16;
		}
		else   //手操盒水泵起停控制指令
		{
			if(sch_shuibeng_flag)                  
				pdata_s03->operatorCmd.powerSwitch+=16;
		}
		if((recdata[5]&0x20)!=0x20)   //手操盒关变频器同时关水泵    0X10(0001 0000)
		{
			pdata_s03->operatorCmd.powerSwitch=pdata_s03->operatorCmd.powerSwitch&0xef;  //关水泵   1110 1111 水泵控制位置0
		}


	}
	pdata_s03->operatorCmd.frequencyConverterCommand=0;
	{
		if((recdata[5]&0x20)==0x20)
			pdata_s03->operatorCmd.frequencyConverterCommand+=1;
		if((recdata[5]&0x40)==0x40)
			pdata_s03->operatorCmd.frequencyConverterCommand+=2;
		if((recdata[5]&0x80)==0x80)
			pdata_s03->operatorCmd.frequencyConverterCommand+=4;
	}
	memcpy(&pdata_s03->operatorCmd.thrusterSpeedCmd,&recdata[7],2);
	//手操盒转速指令
	pdata_s03->operatorCmd.thrusterSpeedCmd=ntohs(pdata_s03->operatorCmd.thrusterSpeedCmd);
	pdata_s03->operatorCmd.thrusterSpeedCmd=pdata_s03->operatorCmd.thrusterSpeedCmd*0x4000/1000;
	//水上主控转速指令
	if(page1->m_speed_ctr_enable==true)
		pdata_s03->operatorCmd.thrusterSpeedCmd=page1->m_speed_cmd*0x4000/1500;
	//转速梯度控制
	if(page_test->m_speed_ctr_flag==true)
	{
		short SpeedCmd,Speed_now;   //指令转速 当前转速 输出转速
		SpeedCmd=pdata_s03->operatorCmd.thrusterSpeedCmd*1500/0x4000;   //转速 
		BAS bas;
		bas.by[0]=page2->power_infor_page2->powerSystem_r932.motorSpeedLow;
		bas.by[1]=page2->power_infor_page2->powerSystem_r932.motorSpeedHigh;
		Speed_now=(bas.s)*1500/0x4000;
		Speed_out=SpeedCtr(SpeedCmd,Speed_now,Speed_out);
		pdata_s03->operatorCmd.thrusterSpeedCmd=Speed_out*0x4000/1500;
	}
	//限速
	if(page_test->m_speed_limit_flag==true)
		LimitSpeed();		
	memcpy(&pdata_s03->operatorCmd.cameraSwitch,&recdata[6],1);
	memcpy(&pdata_s03->operatorCmd.trimCmd,&recdata[9],10);
	pdata_s03->operatorCmd.trimCmd=ntohs(pdata_s03->operatorCmd.trimCmd);
	pdata_s03->operatorCmd.rudderAngleCmd.fairwaterRudderAngle=ntohs(pdata_s03->operatorCmd.rudderAngleCmd.fairwaterRudderAngle);
	pdata_s03->operatorCmd.rudderAngleCmd.rudderAngle=ntohs(pdata_s03->operatorCmd.rudderAngleCmd.rudderAngle);
	pdata_s03->operatorCmd.rudderAngleCmd.rudderAngle=pdata_s03->operatorCmd.rudderAngleCmd.rudderAngle*(-1);
	pdata_s03->operatorCmd.rudderAngleCmd.leftRearRudderAngle=(-1)*ntohs(pdata_s03->operatorCmd.rudderAngleCmd.leftRearRudderAngle);
	pdata_s03->operatorCmd.rudderAngleCmd.rightRearRudderAngle=(-1)*ntohs(pdata_s03->operatorCmd.rudderAngleCmd.rightRearRudderAngle);
	//舵角控制
	RudderCtr();
	memcpy(&pdata_s03->operatorCmd.electricPushRodCmd,&recdata[19],1);
	pdata_s03->dsuEnable=page1->m_dsuEnable;
	pdata_s03->nauEnable=page1->m_nauEnable;
	pdata_s03->pocuEnable=page1->m_pocuEnable;
	pdata_s03->emuEnable=page1->m_emuEnable;
	pdata_s03->prcuEnable=page1->m_prcuEnable;
	pdata_s03->meuEnable=page1->m_meuEnable;
	memcpy(sendata_s03,pdata_s03,sizeof(S_AWMU_2_UWMU_ESP));
	bas1.s=CRC16(sendata_s03,sizeof(S_AWMU_2_UWMU_ESP));
	sendata_s03[sizeof(S_AWMU_2_UWMU_ESP)]=bas1.by[0];
	sendata_s03[sizeof(S_AWMU_2_UWMU_ESP)+1]=bas1.by[1];
	sendata_s03[sizeof(S_AWMU_2_UWMU_ESP)+2]=0x0d;
	for(int i=0;i<sizeof(S_AWMU_2_UWMU_ESP)+3;i++)
		arraySend_s03.SetAt(i,sendata_s03[i]);
}

void CXiaoBiLiDlg::ProcData_R10(BYTE* recdata)
{
	BYTE data[2];
	memcpy(&pdata_r10->workingStage,&recdata[3],4);
	//data[0]=recdata[8];
	//data[1]=recdata[7];
	//memcpy(&pdata_r10->thrusterSpeedCmd,data,2);
	memcpy(&pdata_r10->thrusterSpeedCmd,&recdata[7],2);
	pdata_r10->thrusterSpeedCmd=ntohs(pdata_r10->thrusterSpeedCmd);
	
	data[0]=recdata[10];
	data[1]=recdata[9];
	memcpy(&pdata_r10->trimCmd,data,2);
	data[0]=recdata[12];
	data[1]=recdata[11];
	memcpy(&pdata_r10->fairwaterRudderAngle,data,2);
	data[0]=recdata[14];
	data[1]=recdata[13];
	memcpy(&pdata_r10->rudderAngle,data,2);
	pdata_r10->rudderAngle=pdata_r10->rudderAngle;  //方向舵取反
	data[0]=recdata[16];
	data[1]=recdata[15];
	memcpy(&pdata_r10->leftRearRudderAngle,data,2);
	data[0]=recdata[18];
	data[1]=recdata[17];
	memcpy(&pdata_r10->rightRearRudderAngle,data,2);
	memcpy(&pdata_r10->electricPushRodCmd,&recdata[19],3);
	//if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(pdata_r10->emergencyEnable==0x01)&&(pdata_r70->EMUselfTestStatus==0x01))//遥控模式下按下了应急使能且应急单元反馈处于自检状态
	//	page1->pdata_page1->selfTest_light_state=true;
	//else
	//	page1->pdata_page1->selfTest_light_state=false;
	//if((pdata_r10->emergencyCmd&0x03)==0x03)
	//	page1->pdata_page1->emergencyCmd_fault_light=true;
	//else
	//	page1->pdata_page1->emergencyCmd_fault_light=false;
}

void CXiaoBiLiDlg::QingLing_SCH_R10()
{
	memset(pdata_r10,0,sizeof(struct Data_SCH_R10));
}

void CXiaoBiLiDlg::FuZhi_SCH_S01_R30()
{
	BYTE b=0;
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	arraySend_s01.SetAt(3,pdata_r10->workingStage);  //写入实际工况
	arraySend_s01.SetAt(4,pdata_r10->workingMode);  //写入正常工况下模式反馈
	if(((page4->faultType[1]&0x00000004)==0x00000004)||((page4->faultType[1]&0x00000002)==0x00000002)||((page4->faultType[1]&0x00000001)==0x00000001)||((page4->faultType[2]&0x80000000)==0x80000000))
		b+=1;
	if((page4->faultType[2]&0x00200000)==0x00200000)       
		b+=4;
	if((page4->faultType[2]&0x00400000)==0x00400000)
		b+=8;
	if((page4->faultType[2]&0x00800000)==0x00800000)
		b+=16;
	arraySend_s01.SetAt(5,b);  //写入故障
	b=0;
	if((pdata_r30->powerControlUnitInfo.powerSystem_r932.liBatteryState&0x10)==0x10)
		b+=0;
	else
		b+=1;
	if(((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState1&0x02)==0x02)||((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState1&0x04)==0x04))
		b+=0;
	else
		b+=2;
	if(((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState1&0x08)==0x08))
		b+=0;
	else
		b+=4;
	if(((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState1&0x01)==0x01))
		b+=0;
	else
		b+=8;
	if(((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState2&0x08)==0x08))  
		b+=0;
	else
		b+=16;
	if(((pdata_r30->powerControlUnitInfo.powerSystem_r933.frequencyConverterState&0x02)==0x02))
		b+=32;
	else
		b+=0;
	if((pdata_r10->powerSwitch&0x40)==0x40)
		b+=64;
	if((pdata_r10->powerSwitch&0x80)==0x80)
		b+=128;
	arraySend_s01.SetAt(6,b);   //电源开关真实状态
	b=0;
	if(pdata_r30->primaryControlUnitInfo.steering[0].motorStatus==0x01)
		b+=1;
	if(pdata_r30->primaryControlUnitInfo.steering[1].motorStatus==0x01)
		b+=2;
	if(pdata_r30->primaryControlUnitInfo.steering[2].motorStatus==0x01)
		b+=4;
	if(pdata_r30->primaryControlUnitInfo.steering[3].motorStatus==0x01)
		b+=8;
	arraySend_s01.SetAt(7,b); //写入电机状态
	if((page1->pdata_page1->awmu_uwmu_net_state==false)&&(page1->pdata_page1->awmu_uwmu_wxd_state==false))
		arraySend_s01.SetAt(10,1); //写入水上水下通信状态20170904 0X00 正常状态 0x01 通信断开
	else
		arraySend_s01.SetAt(10,0);
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
}
void CXiaoBiLiDlg::FuZhi_SCH_S01_R304()    //模式切换报文确认后反馈至手操盒
{
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	arraySend_s01.SetAt(3,pdata_r10->workingStage);  //此时手操盒上的指令即为实际的反馈
	arraySend_s01.SetAt(4,pdata_r10->workingMode);  
	page1->pdata_page1->gongkuang_light_state=pdata_r10->workingStage;  //集控界面试验工况状态显示20180722
	page1->pdata_page1->mode_light_state=pdata_r10->workingMode;
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
}
void CXiaoBiLiDlg::FuZhi_SCH_S01_TXZT()   
{
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	if((page1->pdata_page1->awmu_uwmu_net_state==false)&&(page1->pdata_page1->awmu_uwmu_wxd_state==false))
		arraySend_s01.SetAt(10,1); //写入水上水下通信状态20170904 0X00 正常状态 0x01 通信断开
	else
		arraySend_s01.SetAt(10,0);
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
}
	
	

void CXiaoBiLiDlg::FuZhi_SCH_S01_R305()
{
	BYTE b=0;
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	arraySend_s01.SetAt(3,pdata_r10->workingStage);  //写入实际工况
	arraySend_s01.SetAt(4,pdata_r10->workingMode);  //写入正常工况下模式反馈
	if(((page4->faultType[1]&0x00000004)==0x00000004)||((page4->faultType[1]&0x00000002)==0x00000002)||((page4->faultType[1]&0x00000001)==0x00000001)||((page4->faultType[2]&0x80000000)==0x80000000))
		b+=1;
	if((page4->faultType[2]&0x00200000)==0x00200000)       
		b+=4;
	if((page4->faultType[2]&0x00400000)==0x00400000)
		b+=8;
	if((page4->faultType[2]&0x00800000)==0x00800000)
		b+=16;
	arraySend_s01.SetAt(5,b);    //写入故障
	b=0;
	if((pdata_r305->POCUfeedback.powerSystem_r932.liBatteryState&0x10)==0x10)
		b+=0;
	else
		b+=1;
	if(((pdata_r305->POCUfeedback.powerSystem_r934.powerState1&0x02)==0x02)||((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState1&0x04)==0x04))
		b+=0;
	else
		b+=2;
	if(((pdata_r305->POCUfeedback.powerSystem_r934.powerState1&0x08)==0x08))
		b+=0;
	else
		b+=4;
	if(((pdata_r305->POCUfeedback.powerSystem_r934.powerState1&0x01)==0x01))
		b+=0;
	else
		b+=8;
	if(((pdata_r305->POCUfeedback.powerSystem_r934.powerState2&0x08)==0x08))
		b+=0;
	else
		b+=16;
	if(((pdata_r305->POCUfeedback.powerSystem_r933.frequencyConverterState&0x02)==0x02))
		b+=32;
	else
		b+=0;
	if((pdata_r10->powerSwitch&0x40)==0x40)
		b+=64;
	if((pdata_r10->powerSwitch&0x80)==0x80)
		b+=128;
	arraySend_s01.SetAt(6,b);   //电源开关真实状态
	b=0;
	if(pdata_r305->PRCUfeedback.steering[0].motorStatus==0x01)
		b+=1;
	if(pdata_r305->PRCUfeedback.steering[1].motorStatus==0x01)
		b+=2;
	if(pdata_r305->PRCUfeedback.steering[2].motorStatus==0x01)
		b+=4;
	if(pdata_r305->PRCUfeedback.steering[3].motorStatus==0x01)
		b+=8;
	arraySend_s01.SetAt(7,b); //写入电机状态
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
}

void CXiaoBiLiDlg::FuZhi_SCH_S01_R303()
{
	BYTE b=0;
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	arraySend_s01.SetAt(3,pdata_r10->workingStage);  //写入实际工况
	arraySend_s01.SetAt(4,pdata_r10->workingMode);  //写入正常工况下模式反馈
	if(((page4->faultType[1]&0x00000004)==0x00000004)||((page4->faultType[1]&0x00000002)==0x00000002)||((page4->faultType[1]&0x00000001)==0x00000001)||((page4->faultType[2]&0x80000000)==0x80000000))
		b+=1;
	if((page4->faultType[2]&0x00200000)==0x00200000)       
		b+=4;
	if((page4->faultType[2]&0x00400000)==0x00400000)
		b+=8;
	if((page4->faultType[2]&0x00800000)==0x00800000)
		b+=16;
	arraySend_s01.SetAt(5,b);//写入故障
	b=0;
	if((pdata_r303->powerControlUnitInfo.powerSystem_r932.liBatteryState&0x10)==0x10)
		b+=0;
	else
		b+=1;
	if(((pdata_r303->powerControlUnitInfo.powerSystem_r934.powerState1&0x02)==0x02)||((pdata_r303->powerControlUnitInfo.powerSystem_r934.powerState1&0x04)==0x04))
		b+=0;
	else
		b+=2;
	if(((pdata_r303->powerControlUnitInfo.powerSystem_r934.powerState1&0x08)==0x08))
		b+=0;
	else
		b+=4;
	if(((pdata_r303->powerControlUnitInfo.powerSystem_r934.powerState1&0x01)==0x01))
		b+=0;
	else
		b+=8;
	if(((pdata_r303->powerControlUnitInfo.powerSystem_r934.powerState2&0x08)==0x08))
		b+=0;
	else
		b+=16;
	if(((pdata_r303->powerControlUnitInfo.powerSystem_r933.frequencyConverterState&0x02)==0x02))
		b+=32;
	else
		b+=0;
	if((pdata_r10->powerSwitch&0x40)==0x40)
		b+=64;
	if((pdata_r10->powerSwitch&0x80)==0x80)
		b+=128;
	arraySend_s01.SetAt(6,b);   //电源开关真实状态
	b=0;
	if(pdata_r303->primaryControlUnitInfo.steering[0].motorStatus==0x01)
		b+=1;
	if(pdata_r303->primaryControlUnitInfo.steering[1].motorStatus==0x01)
		b+=2;
	if(pdata_r303->primaryControlUnitInfo.steering[2].motorStatus==0x01)
		b+=4;
	if(pdata_r303->primaryControlUnitInfo.steering[3].motorStatus==0x01)
		b+=8;
	arraySend_s01.SetAt(7,b); //写入电机状态
	if((page1->pdata_page1->awmu_uwmu_net_state==false)&&(page1->pdata_page1->awmu_uwmu_wxd_state==false))
		arraySend_s01.SetAt(10,1); //写入水上水下通信状态20170904 0X00 正常状态 0x01 通信断开
	else
		arraySend_s01.SetAt(10,0);
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
	/*CString strtemp,str;
	str="水上主控反馈给手操盒的无线电报文";
	for(int i=0;i<23;i++)
		{
		strtemp.Format("%02x ",sendata_s03[i]);
		str+=strtemp;
		}
		if(!file.fail())
		{
		   file<<endl<<str;
		}*/
	
}

void CXiaoBiLiDlg::FuZhi_SCH_S01_R70()
{
	BYTE b=0;
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	arraySend_s01.SetAt(3,pdata_r10->workingStage);  //写入实际工况
	arraySend_s01.SetAt(4,pdata_r10->workingMode);  //写入正常工况下模式反馈
	if(((page4->faultType[1]&0x00000004)==0x00000004)||((page4->faultType[1]&0x00000002)==0x00000002)||((page4->faultType[1]&0x00000001)==0x00000001)||((page4->faultType[2]&0x80000000)==0x80000000))
		b+=1;
	if((page4->faultType[2]&0x00200000)==0x00200000)       
		b+=4;
	if((page4->faultType[2]&0x00400000)==0x00400000)
		b+=8;
	if((page4->faultType[2]&0x00800000)==0x00800000)
		b+=16;
	arraySend_s01.SetAt(5,b);   //写入故障
	b=0;
	if((pdata_r70->powerSystemInfo.powerSystem_r932.liBatteryState&0x10)==0x10)
		b+=0;
	else
		b+=1;
	if(((pdata_r70->powerSystemInfo.powerSystem_r934.powerState1&0x02)==0x02)||((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState1&0x04)==0x04))
		b+=0;
	else
		b+=2;
	if(((pdata_r70->powerSystemInfo.powerSystem_r934.powerState1&0x08)==0x08))
		b+=0;
	else
		b+=4;
	if(((pdata_r70->powerSystemInfo.powerSystem_r934.powerState1&0x01)==0x01))
		b+=0;
	else
		b+=8;
	if(((pdata_r70->powerSystemInfo.powerSystem_r934.powerState2&0x08)==0x08))
		b+=0;
	else
		b+=16;
	if(((pdata_r70->powerSystemInfo.powerSystem_r933.frequencyConverterState&0x02)==0x02))
		b+=32;
	else
		b+=0;
	if((pdata_r10->powerSwitch&0x40)==0x40)
		b+=64;
	if((pdata_r10->powerSwitch&0x80)==0x80)
		b+=128;
	arraySend_s01.SetAt(6,b);   //电源开关真实状态
	b=0;
	if(pdata_r70->primaryControlUnitInfo.steering[0].motorStatus==0x01)
		b+=1;
	if(pdata_r70->primaryControlUnitInfo.steering[1].motorStatus==0x01)
		b+=2;
	if(pdata_r70->primaryControlUnitInfo.steering[2].motorStatus==0x01)
		b+=4;
	if(pdata_r70->primaryControlUnitInfo.steering[3].motorStatus==0x01)
		b+=8;
	arraySend_s01.SetAt(7,b); //写入电机状态
	arraySend_s01.SetAt(8,pdata_r70->EMUselfTestStatus); //写入应急使能
	arraySend_s01.SetAt(9,pdata_r70->EMUselfTestCmd); //写入应急措施执行状态
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
}

void CXiaoBiLiDlg::FuZhi_SCH_S01_R70E()
{
	BYTE b=0;
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	arraySend_s01.SetAt(3,pdata_r10->workingStage);  //写入实际工况
	arraySend_s01.SetAt(4,pdata_r10->workingMode);  //写入正常工况下模式反馈
	if(((page4->faultType[1]&0x00000004)==0x00000004)||((page4->faultType[1]&0x00000002)==0x00000002)||((page4->faultType[1]&0x00000001)==0x00000001)||((page4->faultType[2]&0x80000000)==0x80000000))
		b+=1;
	if((page4->faultType[2]&0x00200000)==0x00200000)       
		b+=4;
	if((page4->faultType[2]&0x00400000)==0x00400000)
		b+=8;
	if((page4->faultType[2]&0x00800000)==0x00800000)
		b+=16;
	arraySend_s01.SetAt(5,b);   //写入故障
	b=0;
	if((pdata_r70e->powerSystemInfo.powerSystem_r932.liBatteryState&0x10)==0x10)
		b+=0;
	else
		b+=1;
	if(((pdata_r70e->powerSystemInfo.powerSystem_r934.powerState1&0x02)==0x02)||((pdata_r30->powerControlUnitInfo.powerSystem_r934.powerState1&0x04)==0x04))
		b+=0;
	else
		b+=2;
	if(((pdata_r70e->powerSystemInfo.powerSystem_r934.powerState1&0x08)==0x08))
		b+=0;
	else
		b+=4;
	if(((pdata_r70e->powerSystemInfo.powerSystem_r934.powerState1&0x01)==0x01))
		b+=0;
	else
		b+=8;
	if(((pdata_r70e->powerSystemInfo.powerSystem_r934.powerState2&0x08)==0x08))
		b+=0;
	else
		b+=16;
	if(((pdata_r70e->powerSystemInfo.powerSystem_r933.frequencyConverterState&0x02)==0x02))
		b+=32;
	else
		b+=0;
	if((pdata_r10->powerSwitch&0x40)==0x40)
		b+=64;
	if((pdata_r10->powerSwitch&0x80)==0x80)
		b+=128;
	arraySend_s01.SetAt(6,b);   //电源开关真实状态
	//arraySend_s01.SetAt(7,0); //写入电机状态
	arraySend_s01.SetAt(8,pdata_r70e->interfereState); //写入应急使能
	arraySend_s01.SetAt(9,pdata_r70e->executionState); //写入应急措施执行状态
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
}
//
//void CXiaoBiLiDlg::OnCommMscomm2()   //无线电报文
//{
//	// TODO: 在此处添加消息处理程序代码
//	BYTE recdata[1024];
//	VARIANT variant_inp;
//	COleSafeArray safearray_inp;
//	LONG len,k;
//	CString strtemp;
//	if(m_CtrlComm2.get_CommEvent()==2)
//	{
//		//Sleep(10);
//		variant_inp=m_CtrlComm2.get_Input();
//		safearray_inp=variant_inp;
//		len=safearray_inp.GetOneDimSize();
//		/*CString strlen;
//		strlen.Format("%d",len);
//		MessageBox(strlen);*/
//		for(k=0;k<len;k++)
//			safearray_inp.GetElement(&k,recdata+k);
//		//	unsigned char crchi,crclo;
//		//	CRC_Check((char*)recdata_r303,74,&crchi,&crclo);
//		//	MessageBox("收到无线电报文");
//		if((recdata[0]!=0x5A)&&(recdata[0]!=0xA5))  //出现报文错位
//		{
//			wxd_error++;
//			wxd_recv++;
//			SetTimer(16,155,NULL);
//			//Sleep(50);
//			//m_CtrlComm2.put_InputLen(0);      //等待错位报文接收完毕，清空结束缓冲区，等待下一组报文
//			//m_CtrlComm2.get_Input();    
//			//MessageBox("报文R_70E报文头错误");
//		}
//		else
//		{
//			if((recdata[0]==0x5A)&&(recdata[2]==0x03)&&(recdata[3]==0x30))
//			{
//				wxd_recv++;
//				unsigned short crcCheck=CRC16(recdata,sizeof(S_UWMU_2_AWMU_SP));
//				if((recdata[sizeof(S_UWMU_2_AWMU_SP)]==(BYTE)(crcCheck%256))&&(recdata[sizeof(S_UWMU_2_AWMU_SP)+1]==(BYTE)(crcCheck/256)))
//				{
//					memcpy(recdata_r303,recdata,sizeof(S_UWMU_2_AWMU_SP)+3);
//					//   MessageBox("无线电报文3003校验通过");
//					page1->pdata_page1->awmu_uwmu_wxd_state=true;
//					ProcData_SX_R303();
//					memcpy(page2->power_infor_page2,&(pdata_r303->powerControlUnitInfo),sizeof(POWER_INFO));  //在和动力系统显示界面上显示动力系统信息
//					ProcData_FAULT_R303();
//					FuZhi_SCH_S01_R303();
//					FuZhi_CC_S021();
//					SSCCSocket->Send(sendata_s021,sizeof(AWMU_AWRU_S021)+3,0);
//					page1->ShowData_R30();
//					Fuzhu_Test_Show();     //调试界面获取信息 //辅助操舵界面显示 获取舵角反馈
//				}
//				else
//					wxd_error++;
//			}
//			if((recdata[0]==0xA5)&&(recdata[2]==0x08)&&(recdata[3]==0x30))
//			{
//				unsigned short crcCheck=CRC16(recdata,sizeof(S_UWMU_2_AWMU_EA5));
//				if((recdata[sizeof(S_UWMU_2_AWMU_EA5)]==(BYTE)(crcCheck%256))&&(recdata[sizeof(S_UWMU_2_AWMU_EA5)+1]==(BYTE)(crcCheck/256)))
//				{
//					//   MessageBox("无线电报文3008校验通过");
//					memcpy(pdata_s3008,recdata,sizeof(S_UWMU_2_AWMU_EA5));
//
//					page1->pdata_page1->awmu_uwmu_wxd_state=true;
//					ProcData_SX_R308();
//				}
//			}
//
//			/* CString str,strtemp;
//			for(int i=0;i<sizeof(S_UWMU_2_AWMU_EA1)+3;i++)
//			{strtemp.Format("%02X",recdata[i]);str+=strtemp;}
//			MessageBox(str);*/
//			if((recdata[0]==0x5A)&&(recdata[2]==0x04)&&(recdata[3]==0x30))
//			{
//				unsigned short crcCheck=CRC16(recdata,sizeof(S_UWMU_2_AWMU_EA1));
//				if((recdata[sizeof(S_UWMU_2_AWMU_EA1)]==(BYTE)(crcCheck%256))&&(recdata[sizeof(S_UWMU_2_AWMU_EA1)+1]==(BYTE)(crcCheck/256)))
//				{
//					//MessageBox("SD无线电报文3004");
//					if(recdata[4]==1)
//					{
//						KillTimer_19();
//						FuZhi_SCH_S01_R304();
//						/*AfxMessageBox("通过无线电发送模式切换成功");*/
//						if(0x01==pdata_r10->workingMode)  //切到自主后，转速辅助控制归零
//						{
//							page1->m_speed_cmd=0;
//							page1->SetDlgItemText(IDC_EDIT_SPEED_CMD,"0");
//							Auto_timer_start();
//						}
//						if(0x00==pdata_r10->workingMode)  //切到遥控后,自主计数清零
//						{
//							Auto_timer_end();
//							if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(page1->m_ksdd_flag==true))
//							{
//								SetTimer(1,T_S03,NULL);
//							}
//						}
//						//AfxMessageBox("通过无线电发送模式切换成功");
//					}
//					/*else
//					AfxMessageBox("通过无线电发送模式切换失败");*/
//				}
//				/*else
//				MessageBox("无线电报文3004校验失败");*/
//
//			}
//		}
//		if(TRUE==page_test->m_wxd_detect)
//		{
//			//MessageBox("无线电SSNN");
//
//			CString str,strtemp;
//			str="发送包： ";
//			strtemp.Format("%d, ",wxd_send);
//			str+=strtemp;
//			str+="接收包：";
//			strtemp.Format("%d, ",wxd_recv);
//			str+=strtemp;
//			str+="误码包：";
//			strtemp.Format("%d, ",wxd_error);
//			str+=strtemp;
//			str+="丢包率：";
//			strtemp.Format("%f, ",(float)(wxd_send-wxd_recv+1)/wxd_send);
//			str+=strtemp;
//			str+="误码率：";
//			strtemp.Format("%f, ",(float)wxd_error/wxd_send);
//			str+=strtemp;
//			page_test->SetDlgItemText(IDC_EDIT_WXD_DATA,str);
//
//		}
//		if(TRUE==page_test->m_recvwxd_flag)
//		{
//			//MessageBox("无线电SSNN");
//
//			CString str,strtemp;
//			for(int i=0;i<len;i++)
//			{strtemp.Format("%02X",recdata[i]);str+=strtemp;}
//			page_test->SetDlgItemText(IDC_EDIT_WXD_DATA,str);
//
//		}
//
//	}
//}

//
void CXiaoBiLiDlg::OnCommMscomm2()   //无线电报文
{
	// TODO: 在此处添加消息处理程序代码
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len;
	//k要声明为全局变量
	k=0; 
	LONG i; //从缓冲区接收的字节数
	BYTE recv_temp[1];
	CString strtemp;
	if(m_CtrlComm2.get_CommEvent()==2)       //接收阈值设置为1
	{
		//Sleep(10);
		variant_inp=m_CtrlComm2.get_Input(); //接收缓冲区数据并清空缓冲区
		safearray_inp=variant_inp;
		len=safearray_inp.GetOneDimSize();   //接收到的缓冲区数据长度
		/*CString strlen;
		strlen.Format("%d",len);
		MessageBox(strlen);*/
		for(i=0;i<len;i++)
		safearray_inp.GetElement(&i,recdata+k);
		k++;
		if(k>800)   //长时间没接受到报文尾，则认为通信错误
		{
			k=0;
			wxd_error++;
		}
		else
		{
		if('0x0d'==recdata[k])   //按字节接收至报文尾 （若报文中也含0xd则可能出现错误判断）
		{
			if((recdata[0]!=0x5A)&&(recdata[0]!=0xA5))  //出现报文错位
			{
				wxd_error++;
				wxd_recv++;
				//SetTimer(16,10,NULL);  //每次只接收一个字节，不需要清空缓冲区
				
			}
			else
			{
				if((recdata[0]==0x5A)&&(recdata[2]==0x03)&&(recdata[3]==0x30))
				{
					wxd_recv++;
					unsigned short crcCheck=CRC16(recdata,k+1-3);
					if((recdata[k-2]==(BYTE)(crcCheck%256))&&(recdata[k-1]==(BYTE)(crcCheck/256)))
					{
						memcpy(recdata_r303,recdata,sizeof(S_UWMU_2_AWMU_SP)+3);
						//   MessageBox("无线电报文3003校验通过");
						page1->pdata_page1->awmu_uwmu_wxd_state=true;
						ProcData_SX_R303();
						memcpy(page2->power_infor_page2,&(pdata_r303->powerControlUnitInfo),sizeof(POWER_INFO));  //在和动力系统显示界面上显示动力系统信息
						ProcData_FAULT_R303();
						FuZhi_SCH_S01_R303();
						FuZhi_CC_S021();
						SSCCSocket->Send(sendata_s021,sizeof(AWMU_AWRU_S021)+3,0);
						page1->ShowData_R30();
						Fuzhu_Test_Show();     //调试界面获取信息 //辅助操舵界面显示 获取舵角反馈
					}
					else
						wxd_error++;
				}
				if((recdata[0]==0xA5)&&(recdata[2]==0x08)&&(recdata[3]==0x30))
				{
					unsigned short crcCheck=CRC16(recdata,k+1-3);
					if((recdata[k-2]==(BYTE)(crcCheck%256))&&(recdata[k-1]==(BYTE)(crcCheck/256)))
					{
						//   MessageBox("无线电报文3008校验通过");
						memcpy(pdata_s3008,recdata,sizeof(S_UWMU_2_AWMU_EA5));

						page1->pdata_page1->awmu_uwmu_wxd_state=true;
						ProcData_SX_R308();
					}
				}

				/* CString str,strtemp;
				for(int i=0;i<sizeof(S_UWMU_2_AWMU_EA1)+3;i++)
				{strtemp.Format("%02X",recdata[i]);str+=strtemp;}
				MessageBox(str);*/
				if((recdata[0]==0x5A)&&(recdata[2]==0x04)&&(recdata[3]==0x30))
				{
					unsigned short crcCheck=CRC16(recdata,k+1-3);
					if((recdata[k-2]==(BYTE)(crcCheck%256))&&(recdata[k-1]==(BYTE)(crcCheck/256)))
					{
						//MessageBox("SD无线电报文3004");
						if(recdata[4]==1)
						{
							KillTimer_19();
							FuZhi_SCH_S01_R304();
							/*AfxMessageBox("通过无线电发送模式切换成功");*/
							if(0x01==pdata_r10->workingMode)  //切到自主后，转速辅助控制归零
							{
								page1->m_speed_cmd=0;
								page1->SetDlgItemText(IDC_EDIT_SPEED_CMD,"0");
								Auto_timer_start();
							}
							if(0x00==pdata_r10->workingMode)  //切到遥控后,自主计数清零
							{
								Auto_timer_end();
								if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(page1->m_ksdd_flag==true))
								{
									SetTimer(1,T_S03,NULL);
								}
							}
							//AfxMessageBox("通过无线电发送模式切换成功");
						}
						/*else
						AfxMessageBox("通过无线电发送模式切换失败");*/
					}
					/*else
					MessageBox("无线电报文3004校验失败");*/

				}
			}
			if(TRUE==page_test->m_wxd_detect)
			{
				//MessageBox("无线电SSNN");

				CString str,strtemp;
				str="发送包： ";
				strtemp.Format("%d, ",wxd_send);
				str+=strtemp;
				str+="接收包：";
				strtemp.Format("%d, ",wxd_recv);
				str+=strtemp;
				str+="误码包：";
				strtemp.Format("%d, ",wxd_error);
				str+=strtemp;
				str+="丢包率：";
				strtemp.Format("%f, ",(float)(wxd_send-wxd_recv+1)/wxd_send);
				str+=strtemp;
				str+="误码率：";
				strtemp.Format("%f, ",(float)wxd_error/wxd_send);
				str+=strtemp;
				page_test->SetDlgItemText(IDC_EDIT_WXD_DATA,str);

			}
			if(TRUE==page_test->m_recvwxd_flag)
			{
				//MessageBox("无线电SSNN");

				CString str,strtemp;
				for(int i=0;i<len;i++)
				{strtemp.Format("%02X",recdata[i]);str+=strtemp;}
				page_test->SetDlgItemText(IDC_EDIT_WXD_DATA,str);

			}
			memset(recdata,0,k+1);   //报文接收处理完成后清空报文及计数
			k=0;

		}
		}


	}
}

void CXiaoBiLiDlg::ProcData_SX_R303()
{
	memcpy(pdata_r303,recdata_r303,sizeof(S_UWMU_2_AWMU_SP));
	/*
	if(pdata_r303->MEUstate==110)
	{
		page1->pdata_page1->meu_state_test_light=true;
		page1->pdata_page1->meu_state_debug_light=false;
		page1->pdata_page1->meu_state_fault_light=false;
	}
	else if(pdata_r303->MEUstate==111)
	{
		page1->pdata_page1->meu_state_test_light=false;
		page1->pdata_page1->meu_state_debug_light=true;
		page1->pdata_page1->meu_state_fault_light=false;
	}
	else if(pdata_r303->MEUstate==112)
	{
		page1->pdata_page1->meu_state_test_light=false;
		page1->pdata_page1->meu_state_debug_light=false;
		page1->pdata_page1->meu_state_fault_light=true;
	}
	else{}
	*/
}
void CXiaoBiLiDlg::ProcData_SX_R308()
{
	
	if(pdata_s3008->isSurface==1)
	{
		CString str,strtem;
		str.Format("自航模已经浮上水面，深度为%f,高度为%f",pdata_s3008->deepth,pdata_s3008->Height);
		FuZhi_SX_S038();
		m_CtrlComm2.put_Output(COleVariant(arraySend_s0308));  //反馈无线电消息至水下主控
		MessageBox(str);
		page1->m_ksdd_flag=0;
		//page1->m_dsuEnable=0;
		page1->m_emuEnable=0;
		//page1->m_nauEnable=0;
		//page1->m_prcuEnable=0;
		//page1->m_pocuEnable=0;  
		//page1->m_meuEnable=0;
		page1->UpdateData(false); //更新调度选项

	}

	//MessageBox("jin308");
	if((pdata_s3008->faultType[0]==0x00000000)&&(pdata_s3008->faultType[1]==0x00000000)&&(pdata_s3008->faultType[2]==0x00000000))
	{
		//str="应急单元与其它各单元通信状态正常  自航模无故障";
		fault_flag_r3008_curr=false;
		page1->pdata_page1->fault_light_state=0;
	}
	else
	{
		fault_flag_r3008_curr=true;
	}
	if((fault_flag_r3008_curr==true)&&(fault_flag_r3008_last==false))
	{
		//MessageBox("出现故障，请切换至故障显示界面查看故障");
		page1->pdata_page1->fault_light_state=1;
	}
	fault_flag_r3008_last=fault_flag_r3008_curr;
	memcpy(page4->faultType,pdata_s3008->faultType,12);

}
void CXiaoBiLiDlg::FuZhi_SX_S038()
{
	arraySend_s0308.SetAt(0,0x5A);
	arraySend_s0308.SetAt(1,0x00);
	arraySend_s0308.SetAt(2,0x08);
	arraySend_s0308.SetAt(3,0x03);
	arraySend_s0308.SetAt(4,1);
	unsigned short crcCheck=CRC16(arraySend_s0308.GetData(),40);
	arraySend_s0308.SetAt(40,(BYTE)(crcCheck%256));
	arraySend_s0308.SetAt(41,(BYTE)(crcCheck/256));
	arraySend_s0308.SetAt(42,0x0D); //包尾'\r'


}
void CXiaoBiLiDlg::FuZhi_CC_S021()
{
	memcpy(pdata_s021,pdata_r303,sizeof(S_UWMU_2_AWMU_SP));
	pdata_s021->pktHead1=0xa5;
	pdata_s021->pktHead2=0x0201;
	memcpy(sendata_s021,pdata_s021,sizeof(AWMU_AWRU_S021));
	unsigned short crcCheck=CRC16(sendata_s021,sizeof(AWMU_AWRU_S021));
	sendata_s021[sizeof(AWMU_AWRU_S021)]=(BYTE)(crcCheck%256);
	sendata_s021[sizeof(AWMU_AWRU_S021)+1]=(BYTE)(crcCheck/256);
	sendata_s021[sizeof(AWMU_AWRU_S021)+2]=0x0d;
}

void CXiaoBiLiDlg::FuZhi_SX_S034(BYTE* recdata)
{
	//unsigned char crclo,crchi;
	BAUS bas1;
	sendata_s034[0]=0xA5;
	memcpy(&pdata_s034->workingStageMode,&recdata[3],3);
	memcpy(&pdata_s034->theLatestTrimCmd,&recdata[9],2);
	memcpy(sendata_s034,pdata_s034,sizeof(S_AWMU_2_UWMU_EA1));
	//if(sendata_s032[sizeof(S_AWMU_2_UWMU_EA1)-1]==0x0d)
	{
		bas1.s=CRC16(sendata_s034,sizeof(S_AWMU_2_UWMU_EA1));
		sendata_s034[sizeof(S_AWMU_2_UWMU_EA1)]=bas1.by[0];
		sendata_s034[sizeof(S_AWMU_2_UWMU_EA1)+1]=bas1.by[1];
	}
	/*if(sendata_s032[sizeof(S_AWMU_2_UWMU_EA1)-2]==0x0d)
	{
		bas1.s=CRC16(sendata_s032,sizeof(S_AWMU_2_UWMU_EA1)-4);
		sendata_s032[sizeof(S_AWMU_2_UWMU_EA1)-4]=bas1.by[0];
		sendata_s032[sizeof(S_AWMU_2_UWMU_EA1)-3]=bas1.by[1];
	}*/
	sendata_s034[sizeof(S_AWMU_2_UWMU_EA1)+2]=0x0d;
	/*CString str,strtemp;
	for(int i=0;i<sizeof(S_AWMU_2_UWMU_EA1)+2;i++)
	{strtemp.Format("%02x ",sendata_s032[i]);str+=strtemp;}
	AfxMessageBox(str);*/
	for(int i=0;i<sizeof(S_AWMU_2_UWMU_EA1)+3;i++)
		arraySend_s034_wxd.SetAt(i,sendata_s034[i]);
}

void CXiaoBiLiDlg::FuZhi_YJ_S07E(BYTE* recdata)
{
	BYTE yjcs=0;
	unsigned short crcCheck=0;
	BYTE arr[sizeof(S_AWMU_2_EMU_SA)+3];
	pdata_s07e->pktHead1=0xa5;
	pdata_s07e->pktHead2=0x070e;
	pdata_s07e->interfereEnable=1;
	pdata_s07e->executionCmd=recdata[21];
	pdata_s07e->powerSwitchAndFrequencyConverter=recdata[5];
	memcpy(arr,pdata_s07e,sizeof(S_AWMU_2_EMU_SA));
	crcCheck=CRC16(arr,sizeof(S_AWMU_2_EMU_SA));
	arr[sizeof(S_AWMU_2_EMU_SA)]=crcCheck%256;
	arr[sizeof(S_AWMU_2_EMU_SA)+1]=crcCheck/256;
	arr[sizeof(S_AWMU_2_EMU_SA)+2]=0x0d;
	for(int i=0;i<sizeof(S_AWMU_2_EMU_SA)+3;i++)
		arraySend_s07e.SetAt(i,arr[i]);
}

void CXiaoBiLiDlg::QingLing_YJ_S07E()
{
	for(int i=0;i<8;i++)
		arraySend_s07e.SetAt(1,0x00);
	arraySend_s07e.SetAt(0,0xA5);
	arraySend_s07e.SetAt(1,0x07);
	arraySend_s07e.SetAt(2,0x0e);
	arraySend_s07e.SetAt(7,0x0d);
}




//void CXiaoBiLiDlg::OnCommMscomm3()   //水声通信反馈报文R_70E   
//{
//	// TODO: 在此处添加消息处理程序代码
//	BYTE *buff;
//	buff=new BYTE[512];
//	VARIANT variant_inp;
//	COleSafeArray safearray_inp;
//	LONG len,k;
//	CString strtemp;
//	if(m_CtrlComm3.get_CommEvent()==2)
//	{
//		//MessageBox("报文R_70E");
//		variant_inp=m_CtrlComm3.get_Input();
//		safearray_inp=variant_inp;
//		len=safearray_inp.GetOneDimSize();
//		/*CString s1;
//		s1.Format("%d",len);
//		MessageBox(s1);*/
//		for(k=0;k<len;k++)
//			safearray_inp.GetElement(&k,buff+k);
//		/*CString str,strtemp;
//			for(int i=0;i<sizeof(S_EMU_2_AWMU_SP)+3;i++)
//				{strtemp.Format("%02x ",buff[i]);str+=strtemp;}
//			MessageBox(str);*/
//		if((buff[0]==0x5a)&&(buff[2]==0x0e)&&(buff[3]==0x70))
//		{
//		unsigned short crcCheck=0;
//		crcCheck=CRC16(buff,sizeof(S_EMU_2_AWMU_SP));
//		if((buff[sizeof(S_EMU_2_AWMU_SP)]==crcCheck%256)&&(buff[sizeof(S_EMU_2_AWMU_SP)+1]==crcCheck/256))
//		{
//			//MessageBox("报文R_70ECRC校验通过");
//			page1->pdata_page1->awmu_emu_ss_state=true;
//			memcpy(pdata_r70e,buff,sizeof(S_EMU_2_AWMU_SP));
//			memcpy(page2->power_infor_page2,&(pdata_r70e->powerSystemInfo),sizeof(POWER_INFO));  //在和动力系统显示界面上显示动力系统信息
//			//CString s1;
//			//s1.Format("%02x %02x",pdata_r70e->interfereState,pdata_r70e->executionState);
//			//MessageBox(s1);
//			FuZhi_SCH_S01_R70E();
//			FuZhi_CC_S023();
//			SSCCSocket->Send(sendata_s023,sizeof(AWMU_AWRU_S023)+3,0);
//			if((pdata_r10->emergencyEnable==0x01)&&(pdata_r10->emergencyCmd>0))  
//			{
//				if((pdata_r70e->interfereState!=0x01)||(pdata_r10->emergencyCmd!=pdata_r70e->executionState))//如果反馈应急指令与当前指令不一致，再次下发
//				{
//					m_CtrlComm3.put_Output(COleVariant(arraySend_s07e));
//					//MessageBox("发送水声报文");
//				}
//			}
//			ProcData_YJ_R70E();
//		}
//		//else
//			//MessageBox("报文R_70ECRC校验错误");
//		}
//		else
//		{
//			SetTimer(17,150,NULL);
//			/*Sleep(30);
//			m_CtrlComm3.put_InputLen(0);
//			m_CtrlComm3.get_Input();*/
//			//MessageBox("报文R_70E报文头错误");
//		}
//		/*CString str,strtemp;
//			for(int i=0;i<sizeof(S_EMU_2_AWMU_SP)+3;i++)
//				{strtemp.Format("%02x ",buff[i]);str+=strtemp;}
//			MessageBox(str);*/
//	}
//	delete buff;
//}

void CXiaoBiLiDlg::FuZhi_70e(int i)
{
	int n=i;
	if(1==n)
	{
		CString lo_str,la_str;
		lo_str.Format("%f",pdata_r701e->longitude);
		la_str.Format("%f",pdata_r701e->latitude);
		memcpy(pdata_r70e->navigationUnitInfo.processedData.longitude,lo_str,lo_str.GetLength());
		memcpy(pdata_r70e->navigationUnitInfo.processedData.latitude,lo_str,la_str.GetLength());
		pdata_r70e->navigationUnitInfo.processedData.headingAngle=pdata_r701e->headingAngle;
		pdata_r70e->navigationUnitInfo.processedData.rollingAngle=pdata_r701e->rollingAngle;
		pdata_r70e->navigationUnitInfo.processedData.trimAngle=pdata_r701e->trimAngle;
		pdata_r70e->navigationUnitInfo.processedData.headingSpeed=pdata_r701e->headingSpeed;
		pdata_r70e->navigationUnitInfo.processedData.verticalSpeed=pdata_r701e->verticalSpeed;
		pdata_r70e->navigationUnitInfo.processedData.depth=pdata_r701e->depth;
		pdata_r70e->navigationUnitInfo.processedData.dvlToBottomHeignt=pdata_r701e->dvlToBottomHeignt;
		pdata_r70e->navigationUnitInfo.processedData.leftHeadingDistance=pdata_r701e->leftHeadingDistance;
		pdata_r70e->navigationUnitInfo.processedData.headingDistance=pdata_r701e->headingDistance;
		pdata_r70e->navigationUnitInfo.processedData.rightHeadingDistance=pdata_r701e->rightHeadingDistance;


	}
	if(2==n)
	{
		memcpy(&(pdata_r70e->powerSystemInfo.powerSystem_r932),pdata_r702e->powerSystem_r932,8);
		memcpy(&(pdata_r70e->powerSystemInfo.powerSystem_r933),pdata_r702e->powerSystem_r933,8);
		memcpy(&(pdata_r70e->powerSystemInfo.powerSystem_r934),pdata_r702e->powerSystem_r934,8);
		memcpy(&(pdata_r70e->powerSystemInfo.powerSystem_r935),pdata_r702e->powerSystem_r935,8);

	}
	if(3==n)
	{
		memcpy(&(pdata_r70e->faultType),pdata_r703e->faultType,12);
		pdata_r70e->AWMUInterfaceEnable=pdata_r703e->AWMUinterfereEnable;
		pdata_r70e->AWMUexecutaionCmd=pdata_r703e->AWMUexecutionCmd;
		pdata_r70e->interfereState=pdata_r703e->EMUinterfereState;
		pdata_r70e->executionState=pdata_r703e->EMUexecutionState;
		memcpy(&(pdata_r70e->rudderAngleInfo),&(pdata_r703e->rudderAngleInfo),sizeof(pdata_r70e->rudderAngleInfo));
	}

}
void CXiaoBiLiDlg::OnCommMscomm3()   //水声通信反馈报文R_70E    //应急水生报文拆分后
{
	// TODO: 在此处添加消息处理程序代码
	BYTE *buff;
	buff=new BYTE[512];
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	CString strtemp;
	if(m_CtrlComm3.get_CommEvent()==2)
	{
		//MessageBox("报文R_70E");
		variant_inp=m_CtrlComm3.get_Input();
		safearray_inp=variant_inp;
		len=safearray_inp.GetOneDimSize();
		/*CString s1;
		s1.Format("%d",len);
		MessageBox(s1);*/
		for(k=0;k<len;k++)
			safearray_inp.GetElement(&k,buff+k);
		/*CString str,strtemp;
		for(int i=0;i<sizeof(S_EMU_2_AWMU_SP)+3;i++)
		{strtemp.Format("%02x ",buff[i]);str+=strtemp;}
		MessageBox(str);*/
		if((buff[0]==0x5a))
		{
			if((buff[0]==0x5a)&&(buff[2]==0x01)&&(buff[3]==0x70))
			{
				//MessageBox("报文R_701E");
				//unsigned short crcCheck=0;
				//crcCheck=CRC16(buff,sizeof(S_EMU_2_AWMU_SP1));
				//if((buff[sizeof(S_EMU_2_AWMU_SP1)]==crcCheck%256)&&(buff[sizeof(S_EMU_2_AWMU_SP1)+1]==crcCheck/256))
				//{
				//	//MessageBox("报文R_701E CRC校验通过");
				//	page1->pdata_page1->awmu_emu_ss_state=true;
				//	memcpy(pdata_r701e,buff,sizeof(S_EMU_2_AWMU_SP1));
				//	FuZhi_70e(1);

				//}
				page1->pdata_page1->awmu_emu_ss_state=true;  
				memcpy(pdata_r701e,buff,sizeof(S_EMU_2_AWMU_SP1));
				FuZhi_70e(1);
			}

			if((buff[0]==0x5a)&&(buff[2]==0x02)&&(buff[3]==0x70))
			{
				//unsigned short crcCheck=0;
				//crcCheck=CRC16(buff,sizeof(S_EMU_2_AWMU_SP2));
				//if((buff[sizeof(S_EMU_2_AWMU_SP2)]==crcCheck%256)&&(buff[sizeof(S_EMU_2_AWMU_SP2)+1]==crcCheck/256))
				//{
				//	//MessageBox("报文R_702E CRC校验通过");
				//	page1->pdata_page1->awmu_emu_ss_state=true;
				//	memcpy(pdata_r702e,buff,sizeof(S_EMU_2_AWMU_SP2));
				//	FuZhi_70e(2);
				//}
				page1->pdata_page1->awmu_emu_ss_state=true;
					memcpy(pdata_r702e,buff,sizeof(S_EMU_2_AWMU_SP2));
					FuZhi_70e(2);
			}
			if((buff[0]==0x5a)&&(buff[2]==0x03)&&(buff[3]==0x70))
			{
				//unsigned short crcCheck=0;
				//crcCheck=CRC16(buff,sizeof(S_EMU_2_AWMU_SP3));
				//if((buff[sizeof(S_EMU_2_AWMU_SP3)]==crcCheck%256)&&(buff[sizeof(S_EMU_2_AWMU_SP3)+1]==crcCheck/256))
				//{
				//	//MessageBox("报文R_701E CRC校验通过");
				//	page1->pdata_page1->awmu_emu_ss_state=true;
				//	memcpy(pdata_r703e,buff,sizeof(S_EMU_2_AWMU_SP3));
				//	FuZhi_70e(3);

				//}
				page1->pdata_page1->awmu_emu_ss_state=true;
					memcpy(pdata_r703e,buff,sizeof(S_EMU_2_AWMU_SP3));
					FuZhi_70e(3);
			}
		}
		else
		{
			SetTimer(17,150,NULL);
			/*Sleep(30);
			m_CtrlComm3.put_InputLen(0);
			m_CtrlComm3.get_Input();*/
			//MessageBox("报文R_70E报文头错误");
		}
		/*CString str,strtemp;
		for(int i=0;i<sizeof(S_EMU_2_AWMU_SP)+3;i++)
		{strtemp.Format("%02x ",buff[i]);str+=strtemp;}
		MessageBox(str);*/
		memcpy(page2->power_infor_page2,&(pdata_r70e->powerSystemInfo),sizeof(POWER_INFO));  //在和动力系统显示界面上显示动力系统信息
		page2->ShowData();
		//CString s1;
		//s1.Format("%02x %02x",pdata_r70e->interfereState,pdata_r70e->executionState);
		//MessageBox(s1);
		FuZhi_SCH_S01_R70E();
		FuZhi_CC_S023();
		SSCCSocket->Send(sendata_s023,sizeof(AWMU_AWRU_S023)+3,0);
		if((pdata_r10->emergencyEnable==0x01)&&(pdata_r10->emergencyCmd>0))  
		{
			if((pdata_r70e->interfereState!=0x01)||(pdata_r10->emergencyCmd!=pdata_r70e->executionState))//如果反馈应急指令与当前指令不一致，再次下发
			{
				m_CtrlComm3.put_Output(COleVariant(arraySend_s07e));
				//MessageBox("发送水声报文");
			}
		}
		ProcData_YJ_R70E();

		//else
		//MessageBox("报文R_70ECRC校验错误");
	}
	delete buff;
}

void CXiaoBiLiDlg::ProcData_YJ_R70()
{
	//CString str,strtemp;
	//str="";strtemp="";
	if((pdata_r70->communicationStatus==0x00)&&(pdata_r70->faultType[0]==0x00000000)&&(pdata_r70->faultType[1]==0x00000000)&&(pdata_r70->faultType[2]==0x00000000))
	{
		//str="应急单元与其它各单元通信状态正常  自航模无故障";
		fault_flag_r70_curr=false;
		page1->pdata_page1->fault_light_state=0;
	}
	else
	{
		fault_flag_r70_curr=true;
	}
	if((fault_flag_r70_curr==true)&&(fault_flag_r70_last==false))
	{
		//MessageBox("出现故障，请切换至故障显示界面查看故障");
		page1->pdata_page1->fault_light_state=1;
	}
	fault_flag_r70_last=fault_flag_r70_curr;
	memcpy(page4->faultType,pdata_r70->faultType,12);
}

void CXiaoBiLiDlg::ProcData_YJ_R70E()
{
	CString str;
	if((pdata_r70e->faultType[0]==0x00000000)&&(pdata_r70e->faultType[1]==0x00000000)&&(pdata_r70e->faultType[2]==0x00000000))
	{
		//str="应急单元与其它各单元通信状态正常  自航模无故障";
		fault_flag_r70e_curr=false;
		page1->pdata_page1->fault_light_state=0;
	}
	else
	{
		fault_flag_r70e_curr=true;
	}
	if((fault_flag_r70e_curr==true)&&(fault_flag_r70e_last==false))
	{
		//MessageBox("出现故障，请切换至故障显示界面查看故障");
		page1->pdata_page1->fault_light_state=1;
	}
	fault_flag_r70e_last=fault_flag_r70e_curr;
	if(pdata_r70e->interfereState==0x01)
		page1->pdata_page1->beginEmergency_light_state=true;
	else
		page1->pdata_page1->beginEmergency_light_state=false;
	memcpy(page4->faultType,pdata_r70e->faultType,12);
}

void CXiaoBiLiDlg::ProcData_FAULT_R30()
{
	//CString str,strtemp;
	//str="";strtemp="";
	if((pdata_r30->emergencyInfo.faultType[0]==0x00000000)&&(pdata_r30->emergencyInfo.faultType[1]==0x00000000)&&(pdata_r30->emergencyInfo.faultType[2]==0x00000000)&&(pdata_r30->MEUfeedback.MEUstate!=0x02))
	{
		//str="应急单元与其它各单元通信状态正常  自航模无故障";
		fault_flag_r30_curr=false;
		page1->pdata_page1->fault_light_state=0;
	}
	else
	{
		fault_flag_r30_curr=true;
	}
	if((fault_flag_r30_curr==true)&&(fault_flag_r30_last==false))
	{
		//MessageBox("出现故障，请切换至故障显示界面查看故障");
		page1->pdata_page1->fault_light_state=1;
	}
	fault_flag_r30_last=fault_flag_r30_curr;
	memcpy(page4->faultType,pdata_r30->emergencyInfo.faultType,12);
	memcpy(&(page4->meu_show_fault.MEUstate),&(pdata_r30->MEUfeedback.MEUstate),sizeof(MEU_INFO));
}
void CXiaoBiLiDlg::ProcData_FAULT_R303()
{
	//CString str,strtemp;
	//str="";strtemp="";
	if((pdata_r303->emergencyInfo.faultType[0]==0x00000000)&&(pdata_r303->emergencyInfo.faultType[1]==0x00000000)&&(pdata_r303->emergencyInfo.faultType[2]==0x00000000)&&(pdata_r303->MEUfeedback.MEUstate!=0x02))
	{
		//str="应急单元与其它各单元通信状态正常  自航模无故障";
		fault_flag_r303_curr=false;
		page1->pdata_page1->fault_light_state=0;
	}
	else
	{
		fault_flag_r303_curr=true;
	}
	if((fault_flag_r303_curr==true)&&(fault_flag_r303_last==false))
	{
		//MessageBox("出现故障，请切换至故障显示界面查看故障");
		page1->pdata_page1->fault_light_state=1;
	}
	fault_flag_r303_last=fault_flag_r303_curr;
	memcpy(page4->faultType,pdata_r303->emergencyInfo.faultType,12);
	memcpy(&(page4->meu_show_fault.MEUstate),&(pdata_r303->MEUfeedback.MEUstate),sizeof(MEU_INFO));
}
void CXiaoBiLiDlg::ProcData_FAULT_R305()
{
	if((pdata_r305->EMUfeedback.faultType[0]==0x00000000)&&(pdata_r305->EMUfeedback.faultType[1]==0x00000000)&&(pdata_r305->EMUfeedback.faultType[2]==0x00000000)&&(pdata_r305->MEUfeedback.MEUstate!=0x02))
	{
		//str="应急单元与其它各单元通信状态正常  自航模无故障";
		fault_flag_r305_curr=false;
		page1->pdata_page1->fault_light_state=0;
	}
	else
	{
		fault_flag_r305_curr=true;
	}
	if((fault_flag_r305_curr==true)&&(fault_flag_r305_last==false))
	{
		//MessageBox("出现故障，请切换至故障显示界面查看故障");
		page1->pdata_page1->fault_light_state=1;
	}
	fault_flag_r305_last=fault_flag_r305_curr;
	memcpy(page4->faultType,pdata_r305->EMUfeedback.faultType,12);
	memcpy(&(page4->meu_show_fault.MEUstate),&(pdata_r305->MEUfeedback.MEUstate),sizeof(MEU_INFO));
}

void CXiaoBiLiDlg::QingLing_SX_S03()
{
	memset(sendata_s03,0,33);
	sendata_s03[0]=0xA5;
	sendata_s03[1]=0x03;
	sendata_s03[2]=0x00;
	sendata_s03[32]=0x0D;
}

void CXiaoBiLiDlg::QingLing_SCH_S01()
{
	for(int i=0;i<22;i++)
		arraySend_s01.SetAt(i,0x00);
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	arraySend_s01.SetAt(21,0x0d);
}



void CXiaoBiLiDlg::CRC_Check(char *Data,unsigned char DataLen,unsigned char *CRCHi,unsigned char *CRCLo)
{
	char Index ;           /* CRC 循环中的索引*/
	*CRCHi = 0xFF ;	        /* 高8位CRC 初始化*/
	*CRCLo = 0xFF ;	        /* 低8位CRC 初始化*/
	
	while (DataLen != 0)    /* 传输消息缓冲区*/
	{
		DataLen--;
		Index = (*CRCHi) ^ (*Data);		/* 计算CRC */
		Data++;
		*CRCHi = (*CRCLo) ^ CRCHi_table[Index];
		*CRCLo = CRCLo_table[Index];
	}
}


void CXiaoBiLiDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1)  //定时发送数据至水下主控
	{
		if(stop_remote_cmd==false)   //允许在网络和无线电定时器中下发周期性的遥控调度报文20180310
		{
			/*if(SSSXSocket->Send(sendata_s03,sizeof(S_AWMU_2_UWMU_ESP)+3,0)==SOCKET_ERROR)
			{
			TCHAR seERROR[256];
			wsprintf(seERROR,"Server Socket Failed to send %d",GetLastError());
			MessageBox(seERROR);
			}*/
			SSSXSocket->Send(sendata_s03,sizeof(S_AWMU_2_UWMU_ESP)+3,0);
			FuZhi_CC_S029_AWMU(0);// 水上主控通过无线网发送的手操盒指令存储
			SSCCSocket->Send(sendata_0209,sizeof(AWMU_AWRU_S029)+3);
			/*CString str,strtemp;	
			for(int i=0;i<sizeof(S_AWMU_2_UWMU_ESP)+3;i++)
			{
			strtemp.Format("%02x ",sendata_s03[i]);
			str+=strtemp;
			}
			if(!file.fail())
			{
			file<<endl<<str;
			}*/


			//MessageBox("03报文已发送");
			//CString str,strtemp;
			/*for(int i=0;i<sizeof(S_AWMU_2_UWMU_ESP)+3;i++)
			{
			strtemp.Format("%02x ",sendata_s03[i]);
			str+=strtemp;
			}
			MessageBox(str);*/
			if(pdata_r30->pktHead2==0x3000)
			{
				page1->pdata_page1->awmu_uwmu_net_state=true;
				flag_net_uwmu_awmu=0;
				memset(pdata_r30,0,4);
			}
			else
				flag_net_uwmu_awmu++;
			if(3==flag_net_uwmu_awmu)
			{
				//MessageBox("4次未收到");
				flag_net_uwmu_awmu=0;
				page1->pdata_page1->awmu_uwmu_net_state=false;
				KillTimer(1);
				//SetTimer(2,T_WXD,NULL);   //无线电报文S_03周期性下发定时器
				//SetTimer(14,4000,NULL);  //判断无线电是否连上，没连上弹框提醒
				page_wxwdk->ShowWindow(true);
				page_wxwdk->m_msg_str="与水下主控网络已断开";
	/*			page_wxwdk->m_msg_str="与水下主控网络已断开，正在切换至无线电";*/
				page_wxwdk->UpdateData(false);

			}
		}
	}
	if(nIDEvent==2)  //无线电周期性下发
	{
		if(stop_remote_cmd==false)   //允许在网络和无线电定时器中下发周期性的遥控调度报文20180310
		{
			m_CtrlComm2.put_Output(COleVariant(arraySend_s03));
			FuZhi_CC_S029_AWMU(1);   //水上主控通过无线电发送的手操盒指令存储
			SSCCSocket->Send(sendata_0209,sizeof(AWMU_AWRU_S029)+3);
			wxd_send++;
			/*CString str,strtemp;	
			for(int i=0;i<sizeof(S_AWMU_2_UWMU_ESP)+3;i++)
			{
			strtemp.Format("%02x ",arraySend_s03[i]);
			str+=strtemp;
			}
			if(!filewxd.fail())
			{
			filewxd<<endl<<str;
			}*/
		}
	}
	if(nIDEvent==3)    //程序启动时自动连接水下主控
	{
		if(PingFlag_uwmu)  
		{
			KillTimer(3);
			//MessageBox("连接成功");
			BYTE f0,f1,f2,f3;
			f0=192;f1=168;f2=0;f3=103;  //水下主控IP
			CString IP;
			IP.Format("%d.%d.%d.%d",f0,f1,f2,f3);
			SSSXSocket->Close();
			if(SSSXSocket!=NULL)
				delete SSSXSocket;
			SSSXSocket=new CSessionSocket(this);   //水上主控发送连接请求给水下主控
			SSSXSocket->Create(0,SOCK_STREAM,"192.168.0.100");//设置本机端口
			if(!SSSXSocket->Connect(IP,2003))
			{
			    SSSXSocket->CancelBlockingCall();
	            MessageBox("水下主控网络ping通后连接不成功");
				/*int nError = GetLastError();
				if(nError==WSAEINTR)
					MessageBox("No Connections Arrived For 10 Seconds");
				 ErroSwitch(nError);*/
			}
			else
			{
					//AfxMessageBox("重启连接水下主控成功");  
				page_ljdd->ShowWindow(FALSE);
				page1->pdata_page1->awmu_uwmu_net_state=true;//水上水下主控通信灯亮	
				if((page1->m_ksdd_flag==TRUE)&&(pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00))//开始调度已勾选且处于遥控模式
					SetTimer(1,T_S03,NULL);		
			}
		
		}
		
	}
	if(nIDEvent==4)   //与水下主控网络断开后重新连接
	{
		KillTimer(4);
		if(PingFlag_uwmu)
		{
			SSSXSocket->Close();
			if(SSSXSocket!=NULL)
				delete SSSXSocket;
			BYTE f0,f1,f2,f3;
			f0=192;f1=168;f2=0;f3=103;  //水下主控IP
			CString IP;
			IP.Format("%d.%d.%d.%d",f0,f1,f2,f3);
			SSSXSocket=new CSessionSocket(this);   //水上主控发送连接请求给水下主控
			SSSXSocket->Create(0,SOCK_STREAM,"192.168.0.100");//设置本机端口
			if(!SSSXSocket->Connect(IP,2003))
			{
			    SSSXSocket->CancelBlockingCall();
				page1->pdata_page1->awmu_uwmu_net_state=false;//水上水下主控通信灯灭	
	            MessageBox("水下主控网络ping通后连接不成功");
				/*int nError = GetLastError();
				if(nError==WSAEINTR)
					MessageBox("No Connections Arrived For 10 Seconds");
				 ErroSwitch(nError);*/
			}
			else
			{
				page1->pdata_page1->awmu_uwmu_net_state=true;//水上水下主控网络通信灯亮	
				KillTimer(2);
				if((page1->m_ksdd_flag==TRUE)&&(pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00))//开始调度已勾选且处于遥控模式
					SetTimer(1,T_S03,NULL);

			}
		}
		else
		{
			StopPing_uwmu=1;
			page1->pdata_page1->awmu_uwmu_net_state=false;//水上水下主控通信灯灭	
            MessageBox("与水下主控网络ping不通");
		}
		
	}
	if(nIDEvent==6)    //发送自检报文
	{
		if(SOCKET_ERROR==SSYJSocket->Send(sendata_s07,sizeof(S_AWMU_2_EMU_EP)+3))  //发送自检报文至应急单元
		{
			KillTimer(6);
			page1->pdata_page1->awmu_emu_net_state=false;
			Connect_EMU();
			SetTimer(13,2000,NULL);
		/*
			CString IP;
			IP.Format("%d.%d.%d.%d",(BYTE)192,(BYTE)168,(BYTE)0,(BYTE)107);
			SSYJSocket->Close();
			if(SSYJSocket!=NULL)
				delete SSYJSocket;
			SSYJSocket=new CSessionSocket(this);   //水上主控发送连接请求给水下主控
			SSYJSocket->Create(0,SOCK_STREAM,"192.168.0.100");//设置本机端口
			unsigned long ul = 1;
			ioctlsocket(*SSYJSocket, FIONBIO, &ul);
			if(FALSE==SSYJSocket->Connect(IP,2007))
			{KillTimer(6);SetTimer(9,T_ZJ_DDH,NULL);}
			else
				page1->pdata_page1->awmu_emu_net_state=true;
		*/
		}
		//MessageBox("发送至应急以太网报文");
		/*CString str,strtemp;
		for(int i=0;i<sizeof(S_AWMU_2_EMU_EP)+3;i++)
		{strtemp.Format("%02x ",sendata_s07[i]);str+=strtemp;}
		MessageBox(str);*/
	}
	if(nIDEvent==7)   //发送至应急水声报文
	{
		m_CtrlComm3.put_Output(COleVariant(arraySend_s07e));
		//MessageBox("发送至应急水声报文");
	}
	if(nIDEvent==8)
	{
		DataWrite_SWSJ();
	}
	if(nIDEvent==9)   //水上主控启动后连接应急单元
	{			
		if(PingFlag_emu)
		{
			KillTimer(9);
			CString IP;
			IP.Format("%d.%d.%d.%d",(BYTE)192,(BYTE)168,(BYTE)0,(BYTE)107);
			SSYJSocket->Close();
			if(SSYJSocket!=NULL)
				delete SSYJSocket;
			SSYJSocket=new CSessionSocket(this);   //水上主控发送连接请求给应急
			SSYJSocket->Create(0,SOCK_STREAM,"192.168.0.100");//设置本机端口
			if(!SSYJSocket->Connect(IP,2007))
			{
				SSYJSocket->CancelBlockingCall();
				Connect_UWMU();
				SetTimer(3,1000,NULL);
	            MessageBox("应急网络ping通后连接不成功");
				/*int nError = GetLastError();
				if(nError==WSAEINTR)
					MessageBox("No Connections Arrived For 10 Seconds");
				 ErroSwitch(nError);*/
			}
			else
			{
				page1->pdata_page1->awmu_emu_net_state=true;
				Connect_UWMU();
				SetTimer(3,1000,NULL);
				if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(pdata_r10->emergencyEnable==0x01))
					SetTimer(6,T_S07,NULL);
			}
		/*	if(TRUE==SSYJSocket->Connect(IP,2007))
			{
				KillTimer(9);
				page1->pdata_page1->awmu_emu_net_state=true;
				Connect_UWMU();
				SetTimer(3,1000,NULL);
				if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(pdata_r10->emergencyEnable==0x01))
					SetTimer(6,T_S07,NULL);
			}*/

		}

	}
	if(nIDEvent==10)//发送工况模式报文至水上存储
	{
		if(SOCKET_ERROR==SSCCSocket->Send(sendata_s025,sizeof(AWRU_AWMU_S025)+3,0))
			page1->pdata_page1->awmu_dsu_net_state=false;
		else
			page1->pdata_page1->awmu_dsu_net_state=true;
	}
	if(nIDEvent==11)//周期性判断水声报文是否有数据
	{
		if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x01))
		{
			if(pdata_r70e->pktHead2==0x700e)
			{
				tx_yj_ck_flag=0;
				page1->pdata_page1->awmu_emu_ss_state=true;
			}
			else
				tx_yj_ck_flag++;
			memset(pdata_r70e,0,4);
			if(tx_yj_ck_flag==3)
			{tx_yj_ck_flag=0;page1->pdata_page1->awmu_emu_ss_state=false;}
		}
		else
			page1->pdata_page1->awmu_emu_ss_state=false;
	}
	if(nIDEvent==12)//周期性判断无线电报文是否有数据
	{
		if(pdata_r303->pktHead2==0x3003)
		{
			tx_sx_wxd_flag=0;
			page1->pdata_page1->awmu_uwmu_wxd_state=true;
			page_wxwdk->ShowWindow(false);
			page_wxwdk_wxddk->ShowWindow(false);
		}
		else
			tx_sx_wxd_flag++;
		memset(pdata_r303,0,4);
		if(tx_sx_wxd_flag==2)
		{
			tx_sx_wxd_flag=0;page1->pdata_page1->awmu_uwmu_wxd_state=false;
		}
	}
	if(nIDEvent==13)  //连接应急单元两秒
	{
		KillTimer(13);
		if(PingFlag_emu)
		{
			CString IP;
			IP.Format("%d.%d.%d.%d",(BYTE)192,(BYTE)168,(BYTE)0,(BYTE)107);
			SSYJSocket->Close();
			if(SSYJSocket!=NULL)
				delete SSYJSocket;
			SSYJSocket=new CSessionSocket(this);   //水上主控发送连接请求给应急
			SSYJSocket->Create(0,SOCK_STREAM,"192.168.0.100");//设置本机端口
			if(!SSYJSocket->Connect(IP,2007))
			{
				SSYJSocket->CancelBlockingCall();
				page1->pdata_page1->awmu_emu_net_state=false;
	            MessageBox("应急网络ping通后连接不成功");
			}
			else
			{
				page1->pdata_page1->awmu_emu_net_state=true;
				if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(pdata_r10->emergencyEnable==0x01))
				SetTimer(6,T_S07,NULL);
			}
		}
		else
			{
				StopPing_emu=1;
				page1->pdata_page1->awmu_emu_net_state=false;
                MessageBox("与应急单元网络ping不通");
			}
	}
	
	if(nIDEvent==14)   ////无线电断开后弹窗提醒1次
	{
		KillTimer(14);
		if((FALSE==page1->pdata_page1->awmu_uwmu_net_state)&&(TRUE==page1->m_ksdd_flag)&&(FALSE==page1->pdata_page1->awmu_uwmu_wxd_state))  //无线电断开后弹窗提醒1次
			//MessageBox("与水下主控网络和无线电均已断开");
		{
			page_wxwdk_wxddk->ShowWindow(true);
			page_wxwdk_wxddk->m_msg_str="与水下主控网络和无线电均已断开";
			page_wxwdk_wxddk->UpdateData(false);
			FuZhi_SCH_S01_TXZT();
		}

	}
	if(nIDEvent==15)  //与水下主控网络断开后重新连接 1秒连接不成功切无线电
	{
		KillTimer(15);
		if(PingFlag_uwmu)
		{
			
			SSSXSocket->Close();
			if(SSSXSocket!=NULL)
				delete SSSXSocket;
			BYTE f0,f1,f2,f3;
			f0=192;f1=168;f2=0;f3=103;  //水下主控IP
			CString IP;
			IP.Format("%d.%d.%d.%d",f0,f1,f2,f3);
			SSSXSocket=new CSessionSocket(this);   //水上主控发送连接请求给水下主控
			SSSXSocket->Create(0,SOCK_STREAM,"192.168.0.100");//设置本机端口
			if(!SSSXSocket->Connect(IP,2003))
			{
			    SSSXSocket->CancelBlockingCall();
				StopPing_uwmu=1;
			    SetTimer(2,T_WXD,NULL);   //无线电报文S_03周期性下发定时器
			   // SetTimer(16,T_WXD,NULL);   //弹窗提醒与水下主控网络已断开，正在切换至无线电
				page_wxwdk->ShowWindow(true);
		    page_wxwdk->m_msg_str="与水下主控网络已断开，正在切换至无线电";
		    page_wxwdk->UpdateData(false);
			}
			else
			{
				if((page1->m_ksdd_flag==TRUE)&&(pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00))//开始调度已勾选且处于遥控模式
				SetTimer(1,T_S03,NULL);
			}

		}
		else
		{
			StopPing_uwmu=1;
			SetTimer(2,T_WXD,NULL);   //无线电报文S_03周期性下发定时器
			SetTimer(14,4000,NULL);  //判断无线电是否连上，没连上弹框提醒
			//SetTimer(16,T_WXD,NULL);   //弹窗提醒与水下主控网络已断开，正在切换至无线电
			page_wxwdk->ShowWindow(true);
		    page_wxwdk->m_msg_str="与水下主控网络已断开，正在切换至无线电";
		    page_wxwdk->UpdateData(false);

		}
	}
	//if(nIDEvent==16)
	//{
	//	KillTimer(16);
	//	SetTimer(14,4000,NULL);  //判断无线电是否连上，没连上弹框提醒
	//	MessageBox("与水下主控网络已断开，正在切换至无线电");
	//
	//}
	if(nIDEvent==16)
	{
		KillTimer(16);
		m_CtrlComm2.put_InBufferCount(0);  //接收完截断报文后，清空缓冲区
	}
	if(nIDEvent==17)
	{
		KillTimer(17);
		m_CtrlComm3.put_InBufferCount(0);  //接收完截断报文后，清空缓冲区
	}
	if(nIDEvent==18)
	{
		CString num_str;
		page1->m_second_num++;
		num_str.Format("%d",page1->m_second_num);
		page1->SetDlgItemTextA(IDC_EDIT_AUTO_TIMER,num_str);
	}
	if(nIDEvent==19)
	{
		if(page1->pdata_page1->awmu_uwmu_net_state==true)
		{
			try
			{
				if(SOCKET_ERROR==SSSXSocket->Send(sendata_s034,sizeof(S_AWMU_2_UWMU_EA1)+3,0)) //下发模式切换报文
					throw false;
			}
			catch(bool e)
			{
				if(e==false)
				{

					m_CtrlComm2.put_Output(COleVariant(arraySend_s034_wxd));
				}    //无线电下发
			}
		}
		else
			m_CtrlComm2.put_Output(COleVariant(arraySend_s034_wxd));//无线电下发
	}          
	if(nIDEvent==5)              
	{
		if((recdata_r10_wx[0]==0xA5)&&(recdata_r10_wx[1]==0x10)&&(recdata_r10_wx[2]==0x00))  
		{
			ProcData_R10(recdata_r10_wx);    //处理手操盒无线网消息
			FuZhi_CC_S025(recdata_r10_wx);   //给报文S_025赋值
			if(recdata_r10_wx[3]==0x00)     //若模式发生变化则发送模式切换报文
			{
				moshi_curr=recdata_r10_wx[4];
				if((moshi_curr==0x01)&&(moshi_last==0x00))//遥控切到自主
				{
					stop_remote_cmd=true;   //在网络和无线电定时器中停止下发周期性的遥控调度报文20180310
					KillTimer(1);
					KillTimer(2);
					FuZhi_SX_S034(recdata_r10_wx);    //赋值S_034
					SetTimer(19,1500,NULL);   //发送模式切换指令
				}
				if((moshi_curr==0x00)&&(moshi_last==0x01))//自主切到遥控
				{
					stop_remote_cmd=false;   //允许在网络和无线电定时器中下发周期性的遥控调度报文20180310
					FuZhi_SX_S034(recdata_r10_wx);    //赋值S_034
					SetTimer(19,1500,NULL);
				}
				moshi_last=moshi_curr;
			}
			gongkuang_curr=recdata_r10_wx[3];      //若工况发生变化则发送模式切换报文
			if((gongkuang_last==0x00)&&(gongkuang_curr==0x01))//试验且数据上传
			{
				KillTimer(1);
				KillTimer(2);
				page1->m_ksdd_flag=false;        //切换至数据上传工况后 取消开始调度选项20170423
				page1->UpdateData(false); //更新调度选项
				FuZhi_SX_S034(recdata_r10_wx);    //赋值S_034
				SetTimer(19,1500,NULL);   //发送模式切换指令
				
			}
			if((gongkuang_last==0x01)&&(gongkuang_curr==0x00))//数据上传切到试验
			{
				if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(page1->m_ksdd_flag==true))
					SetTimer(1,T_S03,NULL);
				FuZhi_SX_S034(recdata_r10_wx);    //赋值S_034
				SetTimer(19,1500,NULL);   //发送模式切换指令
				
			}
			gongkuang_last=gongkuang_curr;
			if((recdata_r10_wx[3]==0x00)&&(recdata_r10_wx[4]==0x00)&&(recdata_r10_wx[20]==1))
			{
				FuZhi_YJ_S07(recdata_r10_wx);  //给至应急以太网报文赋值
			}
			if((recdata_r10_wx[3]==0x00)&&(recdata_r10_wx[4]==0x01)&&(recdata_r10_wx[20]==1))
			{
				FuZhi_YJ_S07E(recdata_r10_wx);  //给至应急水声报文赋值
			}
			zijian_curr=recdata_r10_wx[20];
			if((recdata_r10_wx[3]==0x00)&&(recdata_r10_wx[4]==0x00))  //遥控模式对发送至应急以太网报文定时器进行设置
			{
				if((zijian_curr==1)&&(zijian_last==0)&&(page1->m_ksdd_flag==TRUE))
				{SetTimer(6,T_S07,NULL);KillTimer(1);KillTimer(2);}//关掉周期性下发手操盒指令定时器，timer1是网络，timer2是无线电,开启自检定时器
				if((zijian_curr==0)&&(zijian_last==1))
				{
					FuZhi_YJ_S07(recdata_r10_wx);
					SSYJSocket->Send(sendata_s07,sizeof(S_AWMU_2_EMU_EP)+3);
					KillTimer(6);
					if(page1->m_ksdd_flag==true)
						SetTimer(1,T_S03,NULL);
				}
			}
			yjcs_curr=recdata_r10_wx[21];       //应急措施点一下发一次
			if((recdata_r10_wx[3]==0x00)&&(recdata_r10_wx[4]==0x01)&&(recdata_r10_wx[20]==0x01))  //自主模式对发送至应急水声报文定时器进行设置
			{
				if((yjcs_curr>0)&&(yjcs_last!=yjcs_curr))
				{
					m_CtrlComm3.put_Output(COleVariant(arraySend_s07e));
					//MessageBox("发送水声报文");
					//SetTimer(7,T_S07E,NULL);
				}
				if((zijian_last==0)&&(zijian_curr==1)&&(yjcs_curr>0))  //上一周期未按应急使能，这一周期按了应急使能，且应急措施不为0
				{
					m_CtrlComm3.put_Output(COleVariant(arraySend_s07e));
					//MessageBox("发送水声报文");
				}
				//if((zijian_curr==0)&&(zijian_last==1))
					//KillTimer(7);
			}
			zijian_last=zijian_curr;
			yjcs_last=yjcs_curr;
			FuZhi_SX_S03(recdata_r10_wx);
			//SCHSocket->Send(sendata_s01,23,0);   //反馈无线信息至手操盒
								//CString str,strtemp;
			//        for(int i=0;i<5;i++)
			//          {strtemp.Format(" %02X",sendata_s01[i]);str+=strtemp;}
			//		AfxMessageBox("fs"+str);
		}
		else
		{
			if((recdata_r10[0]==0xA5)&&(recdata_r10[1]==0x10)&&(recdata_r10[2]==0x00)) //处理串口消息
			{
				ProcData_R10(recdata_r10);   //处理手操盒串口消息
				FuZhi_CC_S025(recdata_r10);  //给报文S_025赋值
				if(recdata_r10[3]==0x00)
				{
					moshi_curr=recdata_r10[4];
					if((moshi_curr==0x01)&&(moshi_last==0x00))  //遥控到自主
					{
						//MessageBox("下发模式切换报文");
						stop_remote_cmd=true;   //在网络和无线电定时器中停止下发周期性的遥控调度报文20180310
						KillTimer(1);
						KillTimer(2);
						FuZhi_SX_S034(recdata_r10);    //赋值S_034
						SetTimer(19,1500,NULL);   //发送模式切换指令
					}
					if((moshi_curr==0x00)&&(moshi_last==0x01))//自主到遥控
					{
						stop_remote_cmd=false;   //允许在网络和无线电定时器中下发周期性的遥控调度报文20180310
						FuZhi_SX_S034(recdata_r10);    //赋值S_034
						SetTimer(19,1500,NULL);   //发送模式切换指令
					}
					moshi_last=moshi_curr;
				}
				gongkuang_curr=recdata_r10[3];
				if((gongkuang_last==0x00)&&(gongkuang_curr==0x01))//数据上传
				{
					KillTimer(1);
					KillTimer(2);
					page1->m_ksdd_flag=false;        //切换至数据上传工况后 取消开始调度选项20170423
					page1->UpdateData(false); //更新调度选项
					FuZhi_SX_S034(recdata_r10);    //赋值S_034
					SetTimer(19,1500,NULL);   //发送模式切换指令
				}
				if((gongkuang_last==0x01)&&(gongkuang_curr==0x00))//数据上传切到试验
				{
					if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00)&&(page1->m_ksdd_flag==true))
						SetTimer(1,T_S03,NULL);
					FuZhi_SX_S034(recdata_r10);    //赋值S_034
					SetTimer(19,1500,NULL);   //发送模式切换指令
				}
				gongkuang_last=gongkuang_curr;
				if((recdata_r10[3]==0x00)&&(recdata_r10[4]==0x00)&&(recdata_r10[20]==1))
				{
					FuZhi_YJ_S07(recdata_r10);  //给至应急以太网报文赋值
				}
				if((recdata_r10[3]==0x00)&&(recdata_r10[4]==0x01)&&(recdata_r10[20]==1))
				{
					FuZhi_YJ_S07E(recdata_r10);  //给至应急水声报文赋值
				}
				zijian_curr=recdata_r10[20];
				if((recdata_r10[3]==0x00)&&(recdata_r10[4]==0x00))  //遥控模式对发送至应急以太网报文定时器进行设置
				{
					if((zijian_curr==1)&&(zijian_last==0)&&(page1->m_ksdd_flag==TRUE))//开启自检定时器
					{
						SetTimer(6,T_S07,NULL);KillTimer(1);KillTimer(2);
					}
					if((zijian_curr==0)&&(zijian_last==1))
					{
						FuZhi_YJ_S07(recdata_r10);
						SSYJSocket->Send(sendata_s07,sizeof(S_AWMU_2_EMU_EP)+3);
						KillTimer(6);
						if(page1->m_ksdd_flag==true)
							SetTimer(1,T_S03,NULL);
					}
				}
				yjcs_curr=recdata_r10[21];
				if((recdata_r10[3]==0x00)&&(recdata_r10[4]==0x01)&&(recdata_r10[20]==0x01))  //自主模式发送水声应急干预报文
				{
					if((yjcs_curr>0)&&(yjcs_last!=yjcs_curr))   //应急指令有变化
					{
						m_CtrlComm3.put_Output(COleVariant(arraySend_s07e));
						//MessageBox("发送水声报文");
					}
					if((zijian_last==0)&&(zijian_curr==1)&&(yjcs_curr>0))  //上一周期未按应急使能，这一周期按了应急使能，且应急措施不为0
						m_CtrlComm3.put_Output(COleVariant(arraySend_s07e));
				}
				zijian_last=zijian_curr;
				yjcs_last=yjcs_curr;
				FuZhi_SX_S03(recdata_r10);
				//FuZhi_SCH_S01_R30();
				//m_CtrlComm1.put_Output(COleVariant(arraySend_s01));  //反馈串口消息至手操盒
			}
		}
		if((recdata_r10_wx[0]==0xA5)&&(recdata_r10_wx[1]==0x10)&&(recdata_r10_wx[2]==0x00))
		{
			tx_sch_wl_flag=0;
			page1->pdata_page1->sssch_wl_tx_state=true;
			//page_sch_txzt->ShowWindow(false);
		}
		else
			tx_sch_wl_flag++;
		if(tx_sch_wl_flag==8)    //20170507  定时由500改为250   次数由3改为6//20170906改为8
		{
			page1->pdata_page1->sssch_wl_tx_state=false;
			tx_sch_wl_flag=0;			
		}
		if((recdata_r10[0]==0xA5)&&(recdata_r10[1]==0x10)&&(recdata_r10[2]==0x00))
		{
			tx_sch_ck_flag=0;
			page1->pdata_page1->sssch_ck_tx_state=true;
			//page_sch_txzt->ShowWindow(false);
		}
		else
			tx_sch_ck_flag++;
		if(tx_sch_ck_flag==8)
		{
			page1->pdata_page1->sssch_ck_tx_state=false;
			tx_sch_ck_flag=0;
		}
		if((recdata_r10[0]==0)&&(recdata_r10_wx[0]==0)&&(page1->m_ksdd_flag==1))
		{
			tx_yj_wxd_ck_flag++;
		}
		else
			tx_yj_wxd_ck_flag=0;
		 if(12==tx_yj_wxd_ck_flag)
		{
			page1->m_ksdd_flag=0;   //取消开始调度
			page1->UpdateData(false); //更新调度选项
			KillTimer(1);
			KillTimer(2);
			page_sch_txzt->ShowWindow(true);
			page_sch_txzt->m_msg_str="手操盒已断开，请连接手操盒后重新调度";
			page_sch_txzt->UpdateData(false);
			tx_yj_wxd_ck_flag=0;
			/*page1->GetDlgItem(IDC_BUTTON_TXZTCX)->EnableWindow(true);
			page1->GetDlgItem(IDC_BUTTON_RWXZ)->EnableWindow(true);*/
		}
		memset(recdata_r10_wx,0,33);  //清零
		memset(recdata_r10,0,33);
	}

	CDialogEx::OnTimer(nIDEvent);
}


unsigned short CXiaoBiLiDlg::CRC16(unsigned char* puchMsg, unsigned short usDataLen)
{
	unsigned char uchCRCHi = 0xFF ;
    unsigned char uchCRCLo = 0xFF ;
    unsigned char uIndex ;
    while (usDataLen--)
    {
    uIndex = uchCRCHi ^ *puchMsg++;
    uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
    uchCRCLo = auchCRCLo[uIndex];
    }
    return (uchCRCHi << 8 | uchCRCLo) ;
}

void CXiaoBiLiDlg::FuZhi_SX_S031(UINT len1,UINT len2,UINT len3,char rwlx,unsigned char speed)
{
	/*CString strtemp;
	strtemp.Format("%d个点",len1+len2+len3-2);
	MessageBox(strtemp);*/
	for(UINT i=0;i<len1-1;i++)
		for(int j=0;j<6;j++)
			pt[j][i]=pt1[j][i];
	for(UINT i=len1-1;i<len1+len2-2;i++)
		for(int j=0;j<6;j++)
			pt[j][i]=pt2[j][i-len1+1];
	for(UINT i=len1+len2-2;i<len1+len2+len3-2;i++)
		for(int j=0;j<6;j++)
			pt[j][i]=pt3[j][i-len1-len2+2];
	pdata_s031_1->pktHead1=0xa5;
	pdata_s031_1->pktHead2=AWMU_2_UWMU_EA;
	pdata_s031_1->pktHead3=0x01;
	pdata_s031_1->taskType=rwlx;
	pdata_s031_1->nmuOfPoint=len1+len2+len3-2;
	pdata_s031_1->numOfMustArrivedAtPoint=2;
	pdata_s031_1->speed=speed;
	pdata_s031_1->indexOfMAAP[0]=len1;
	pdata_s031_1->indexOfMAAP[1]=len1+len2-1;
	pdata_s031_2->pktHead1=0xa5;
	pdata_s031_2->pktHead2=AWMU_2_UWMU_EA2;
	pdata_s031_2->pktHead3=0x02;
	pdata_s031_3->pktHead1=0xa5;
	pdata_s031_3->pktHead2=AWMU_2_UWMU_EA2;
	pdata_s031_3->pktHead3=0x03;
	pdata_s031_4->pktHead1=0xa5;
	pdata_s031_4->pktHead2=AWMU_2_UWMU_EA2;
	pdata_s031_4->pktHead3=0x04;
	CString str_rw,str_temp;            //存储点的信息至str_rw
	str_temp.Format("%d",pdata_s031_1->nmuOfPoint);
	str_rw+="航迹点个数："+str_temp+"\n";
	str_temp.Format("%d",pdata_s031_1->numOfMustArrivedAtPoint);    //必达点个数
	str_rw+="必达点个数："+str_temp+"\n";
	str_temp.Format("%d",pdata_s031_1->speed);   //速度
	str_rw+="速度："+str_temp+"\n";
	str_temp.Format("%d",pdata_s031_1->indexOfMAAP[0]);   //必达点一位置
	str_rw+="必达点位置："+str_temp+","; 
	str_temp.Format("%d",pdata_s031_1->indexOfMAAP[1]);    //必达点二位置
	str_rw+=str_temp+"\n";
	str_rw+="航迹点：\n";
	str_rw+="经度       纬度      深度     航向     纵倾     横滚\n";
	if((len1+len2+len3-2)<=(UINT)50)
	{
		for(int i=0;i<len1+len2+len3-2;i++)
		{
			pdata_s031_1->arrayOfTraPoint[i].longitude=pt[0][i];
			pdata_s031_1->arrayOfTraPoint[i].latitude=pt[1][i];
			pdata_s031_1->arrayOfTraPoint[i].depth=pt[2][i];
			pdata_s031_1->arrayOfTraPoint[i].headingAngle=pt[3][i];
			pdata_s031_1->arrayOfTraPoint[i].trimAngle=pt[4][i];
			pdata_s031_1->arrayOfTraPoint[i].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
	}
	else if((len1+len2+len3-2>(UINT)50)&&(len1+len2+len3-2<=(UINT)100))
	{
		for(int i=0;i<50;i++)
		{
			pdata_s031_1->arrayOfTraPoint[i].longitude=pt[0][i];
			pdata_s031_1->arrayOfTraPoint[i].latitude=pt[1][i];
			pdata_s031_1->arrayOfTraPoint[i].depth=pt[2][i];
			pdata_s031_1->arrayOfTraPoint[i].headingAngle=pt[3][i];
			pdata_s031_1->arrayOfTraPoint[i].trimAngle=pt[4][i];
			pdata_s031_1->arrayOfTraPoint[i].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
		for(UINT i=50;i<len1+len2+len3-2;i++)
		{
			pdata_s031_2->arrayOfTraPoint[i-50].longitude=pt[0][i];
			pdata_s031_2->arrayOfTraPoint[i-50].latitude=pt[1][i];
			pdata_s031_2->arrayOfTraPoint[i-50].depth=pt[2][i];
			pdata_s031_2->arrayOfTraPoint[i-50].headingAngle=pt[3][i];
			pdata_s031_2->arrayOfTraPoint[i-50].trimAngle=pt[4][i];
			pdata_s031_2->arrayOfTraPoint[i-50].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
	}
	else if((len1+len2+len3-2>(UINT)100)&&(len1+len2+len3-2<=(UINT)150))
	{
		for(int i=0;i<50;i++)
		{
			pdata_s031_1->arrayOfTraPoint[i].longitude=pt[0][i];
			pdata_s031_1->arrayOfTraPoint[i].latitude=pt[1][i];
			pdata_s031_1->arrayOfTraPoint[i].depth=pt[2][i];
			pdata_s031_1->arrayOfTraPoint[i].headingAngle=pt[3][i];
			pdata_s031_1->arrayOfTraPoint[i].trimAngle=pt[4][i];
			pdata_s031_1->arrayOfTraPoint[i].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
		for(int i=50;i<100;i++)
		{
			pdata_s031_2->arrayOfTraPoint[i-50].longitude=pt[0][i];
			pdata_s031_2->arrayOfTraPoint[i-50].latitude=pt[1][i];
			pdata_s031_2->arrayOfTraPoint[i-50].depth=pt[2][i];
			pdata_s031_2->arrayOfTraPoint[i-50].headingAngle=pt[3][i];
			pdata_s031_2->arrayOfTraPoint[i-50].trimAngle=pt[4][i];
			pdata_s031_2->arrayOfTraPoint[i-50].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
		for(UINT i=100;i<len1+len2+len3-2;i++)
		{
			pdata_s031_3->arrayOfTraPoint[i-100].longitude=pt[0][i];
			pdata_s031_3->arrayOfTraPoint[i-100].latitude=pt[1][i];
			pdata_s031_3->arrayOfTraPoint[i-100].depth=pt[2][i];
			pdata_s031_3->arrayOfTraPoint[i-100].headingAngle=pt[3][i];
			pdata_s031_3->arrayOfTraPoint[i-100].trimAngle=pt[4][i];
			pdata_s031_3->arrayOfTraPoint[i-100].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
	}
	else if((len1+len2+len3-2>(UINT)150)&&(len1+len2+len3-2<=(UINT)200))
	{
		for(int i=0;i<50;i++)
		{
			pdata_s031_1->arrayOfTraPoint[i].longitude=pt[0][i];
			pdata_s031_1->arrayOfTraPoint[i].latitude=pt[1][i];
			pdata_s031_1->arrayOfTraPoint[i].depth=pt[2][i];
			pdata_s031_1->arrayOfTraPoint[i].headingAngle=pt[3][i];
			pdata_s031_1->arrayOfTraPoint[i].trimAngle=pt[4][i];
			pdata_s031_1->arrayOfTraPoint[i].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
		for(int i=50;i<100;i++)
		{
			pdata_s031_2->arrayOfTraPoint[i-50].longitude=pt[0][i];
			pdata_s031_2->arrayOfTraPoint[i-50].latitude=pt[1][i];
			pdata_s031_2->arrayOfTraPoint[i-50].depth=pt[2][i];
			pdata_s031_2->arrayOfTraPoint[i-50].headingAngle=pt[3][i];
			pdata_s031_2->arrayOfTraPoint[i-50].trimAngle=pt[4][i];
			pdata_s031_2->arrayOfTraPoint[i-50].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
		for(int i=100;i<150;i++)
		{
			pdata_s031_3->arrayOfTraPoint[i-100].longitude=pt[0][i];
			pdata_s031_3->arrayOfTraPoint[i-100].latitude=pt[1][i];
			pdata_s031_3->arrayOfTraPoint[i-100].depth=pt[2][i];
			pdata_s031_3->arrayOfTraPoint[i-100].headingAngle=pt[3][i];
			pdata_s031_3->arrayOfTraPoint[i-100].trimAngle=pt[4][i];
			pdata_s031_3->arrayOfTraPoint[i-100].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
		for(UINT i=150;i<len1+len2+len3-2;i++)
		{
			pdata_s031_4->arrayOfTraPoint[i-150].longitude=pt[0][i];
			pdata_s031_4->arrayOfTraPoint[i-150].latitude=pt[1][i];
			pdata_s031_4->arrayOfTraPoint[i-150].depth=pt[2][i];
			pdata_s031_4->arrayOfTraPoint[i-150].headingAngle=pt[3][i];
			pdata_s031_4->arrayOfTraPoint[i-150].trimAngle=pt[4][i];
			pdata_s031_4->arrayOfTraPoint[i-150].rollingAngle=pt[5][i];
			for(int j=0;j<6;j++)
			{
				str_temp.Format("%f",pt[j][i]);
				if(j<5)
					str_rw+=str_temp+",";
				else
					str_rw+=str_temp;
			}
			str_rw+="\n";
		}
	}
	else
		MessageBox("错误，航迹点个数超过200");
	strcpy_s(page1->rwyz,20000,(const char*)str_rw);
	memcpy(sendata_s031_1,pdata_s031_1,sizeof(S_AWMU_2_UWMU_EA_1));
	unsigned short crcCheck_s031_1=CRC16(sendata_s031_1,sizeof(S_AWMU_2_UWMU_EA_1));
	sendata_s031_1[sizeof(S_AWMU_2_UWMU_EA_1)]=crcCheck_s031_1%256;
	sendata_s031_1[sizeof(S_AWMU_2_UWMU_EA_1)+1]=crcCheck_s031_1/256;
	sendata_s031_1[sizeof(S_AWMU_2_UWMU_EA_1)+2]=0x0d;
	memcpy(sendata_s031_2,pdata_s031_2,sizeof(S_AWMU_2_UWMU_EA_2));
	unsigned short crcCheck_s031_2=CRC16(sendata_s031_2,sizeof(S_AWMU_2_UWMU_EA_2));
	sendata_s031_2[sizeof(S_AWMU_2_UWMU_EA_2)]=crcCheck_s031_2%256;
	sendata_s031_2[sizeof(S_AWMU_2_UWMU_EA_2)+1]=crcCheck_s031_2/256;
	sendata_s031_2[sizeof(S_AWMU_2_UWMU_EA_2)+2]=0x0d;
	memcpy(sendata_s031_3,pdata_s031_3,sizeof(S_AWMU_2_UWMU_EA_2));
	unsigned short crcCheck_s031_3=CRC16(sendata_s031_3,sizeof(S_AWMU_2_UWMU_EA_2));
	sendata_s031_3[sizeof(S_AWMU_2_UWMU_EA_2)]=crcCheck_s031_3%256;
	sendata_s031_3[sizeof(S_AWMU_2_UWMU_EA_2)+1]=crcCheck_s031_3/256;
	sendata_s031_3[sizeof(S_AWMU_2_UWMU_EA_2)+2]=0x0d;
	memcpy(sendata_s031_4,pdata_s031_4,sizeof(S_AWMU_2_UWMU_EA_2));
	unsigned short crcCheck_s031_4=CRC16(sendata_s031_4,sizeof(S_AWMU_2_UWMU_EA_2));
	sendata_s031_4[sizeof(S_AWMU_2_UWMU_EA_2)]=crcCheck_s031_4%256;
	sendata_s031_4[sizeof(S_AWMU_2_UWMU_EA_2)+1]=crcCheck_s031_4/256;
	sendata_s031_4[sizeof(S_AWMU_2_UWMU_EA_2)+2]=0x0d;
}

void CXiaoBiLiDlg::FuZhi_CC_S027()
{
	memcpy(pdata_s027_1,pdata_s031_1,sizeof(AWRU_AWMU_S027_1));
	pdata_s027_1->pktHead1=0xa5;
	pdata_s027_1->pktHead2=0x0207;
	pdata_s027_1->pktHead3=0x01;
	memcpy(sendata_s027_1,pdata_s027_1,sizeof(AWRU_AWMU_S027_1));
	unsigned short crcCheck=CRC16(sendata_s027_1,sizeof(AWRU_AWMU_S027_1));
	sendata_s027_1[sizeof(AWRU_AWMU_S027_1)]=crcCheck%256;
	sendata_s027_1[sizeof(AWRU_AWMU_S027_1)+1]=crcCheck/256;
	sendata_s027_1[sizeof(AWRU_AWMU_S027_1)+2]=0x0d;
	memcpy(pdata_s027_2,pdata_s031_2,sizeof(AWRU_AWMU_S027_2));
	pdata_s027_2->pktHead1=0xa5;
	pdata_s027_2->pktHead2=0x0207;
	pdata_s027_2->pktHead3=0x02;
	memcpy(sendata_s027_2,pdata_s027_2,sizeof(AWRU_AWMU_S027_2));
	crcCheck=CRC16(sendata_s027_2,sizeof(AWRU_AWMU_S027_2));
	sendata_s027_2[sizeof(AWRU_AWMU_S027_2)]=crcCheck%256;
	sendata_s027_2[sizeof(AWRU_AWMU_S027_2)+1]=crcCheck/256;
	sendata_s027_2[sizeof(AWRU_AWMU_S027_2)+2]=0x0d;
	memcpy(pdata_s027_3,pdata_s031_3,sizeof(AWRU_AWMU_S027_2));
	pdata_s027_3->pktHead1=0xa5;
	pdata_s027_3->pktHead2=0x0207;
	pdata_s027_3->pktHead3=0x03;
	memcpy(sendata_s027_3,pdata_s027_3,sizeof(AWRU_AWMU_S027_2));
	crcCheck=CRC16(sendata_s027_3,sizeof(AWRU_AWMU_S027_2));
	sendata_s027_3[sizeof(AWRU_AWMU_S027_2)]=crcCheck%256;
	sendata_s027_3[sizeof(AWRU_AWMU_S027_2)+1]=crcCheck/256;
	sendata_s027_3[sizeof(AWRU_AWMU_S027_2)+2]=0x0d;
	memcpy(pdata_s027_4,pdata_s031_4,sizeof(AWRU_AWMU_S027_2));
	pdata_s027_4->pktHead1=0xa5;
	pdata_s027_4->pktHead2=0x0207;
	pdata_s027_4->pktHead3=0x04;
	memcpy(sendata_s027_4,pdata_s027_4,sizeof(AWRU_AWMU_S027_2));
	crcCheck=CRC16(sendata_s027_4,sizeof(AWRU_AWMU_S027_2));
	sendata_s027_4[sizeof(AWRU_AWMU_S027_2)]=crcCheck%256;
	sendata_s027_4[sizeof(AWRU_AWMU_S027_2)+1]=crcCheck/256;
	sendata_s027_4[sizeof(AWRU_AWMU_S027_2)+2]=0x0d;
}
void CXiaoBiLiDlg::FuZhi_CC_S029(BYTE *recdata)
{
	pdata_s0209->pktHead1=0xa5;
	pdata_s0209->pktHead2=0x0209;

	memcpy(&pdata_s0209->operatorCmd.workingStageMode,&recdata[3],2);
	pdata_s0209->operatorCmd.powerSwitch=0;
	{
		if((recdata[5]&0x01)==0x01)
			pdata_s0209->operatorCmd.powerSwitch+=1;
		if((recdata[5]&0x02)==0x02)
			pdata_s0209->operatorCmd.powerSwitch+=2;
		if((recdata[5]&0x04)==0x04)
			pdata_s0209->operatorCmd.powerSwitch+=4;
		if((recdata[5]&0x08)==0x08)
			pdata_s0209->operatorCmd.powerSwitch+=8;
		if((recdata[5]&0x10)==0x10)
			pdata_s0209->operatorCmd.powerSwitch+=16;
	}
	pdata_s0209->operatorCmd.frequencyConverterCommand=0;
	{
		if((recdata[5]&0x20)==0x20)
			pdata_s0209->operatorCmd.frequencyConverterCommand+=1;
		if((recdata[5]&0x40)==0x40)
			pdata_s0209->operatorCmd.frequencyConverterCommand+=2;
		if((recdata[5]&0x80)==0x80)
			pdata_s0209->operatorCmd.frequencyConverterCommand+=4;
	}
	memcpy(&pdata_s0209->operatorCmd.thrusterSpeedCmd,&recdata[7],2);
	pdata_s0209->operatorCmd.thrusterSpeedCmd=ntohs(pdata_s0209->operatorCmd.thrusterSpeedCmd);
	pdata_s0209->operatorCmd.thrusterSpeedCmd=pdata_s0209->operatorCmd.thrusterSpeedCmd*0x4000/1000;
	memcpy(&pdata_s0209->operatorCmd.cameraSwitch,&recdata[6],1);
	memcpy(&pdata_s0209->operatorCmd.trimCmd,&recdata[9],10);
	pdata_s0209->operatorCmd.trimCmd=ntohs(pdata_s0209->operatorCmd.trimCmd);
	pdata_s0209->operatorCmd.rudderAngleCmd.fairwaterRudderAngle=ntohs(pdata_s0209->operatorCmd.rudderAngleCmd.fairwaterRudderAngle);
	pdata_s0209->operatorCmd.rudderAngleCmd.rudderAngle=ntohs(pdata_s0209->operatorCmd.rudderAngleCmd.rudderAngle);
	pdata_s0209->operatorCmd.rudderAngleCmd.rudderAngle=pdata_s0209->operatorCmd.rudderAngleCmd.rudderAngle*(-1);
	pdata_s0209->operatorCmd.rudderAngleCmd.leftRearRudderAngle=(-1)*ntohs(pdata_s0209->operatorCmd.rudderAngleCmd.leftRearRudderAngle);
	pdata_s0209->operatorCmd.rudderAngleCmd.rightRearRudderAngle=(-1)*ntohs(pdata_s0209->operatorCmd.rudderAngleCmd.rightRearRudderAngle);
	memcpy(&pdata_s0209->operatorCmd.electricPushRodCmd,&recdata[19],1);
	
}
void CXiaoBiLiDlg::FuZhi_CC_S029_AWMU(char tx_flag)
{
	pdata_s0209->operatorCmd_flag=tx_flag;
	if(tx_flag==0)
	{
		memcpy(&pdata_s0209->operatorCmd_AWMU,&sendata_s03[4],sizeof(HAND_OPERATOR_INFO));
	}
	else
	{
		memcpy(&pdata_s0209->operatorCmd_AWMU,&arraySend_s03[4],sizeof(HAND_OPERATOR_INFO));

	}
	memcpy(sendata_0209,pdata_s0209,sizeof(AWMU_AWRU_S029));
	unsigned short crcCheck=CRC16(sendata_0209,sizeof(AWMU_AWRU_S029));
	sendata_0209[sizeof(AWMU_AWRU_S029)]=crcCheck%256;
	sendata_0209[sizeof(AWMU_AWRU_S029)+1]=crcCheck/256;
	sendata_0209[sizeof(AWMU_AWRU_S029)+2]=0x0d;
}

void CXiaoBiLiDlg::ChangeTimer_S03()
{
	if(pdata_r10->workingMode==0x00)
		{SetTimer(1,T_S03,NULL);MessageBox("set timer 1");}
	if(pdata_r10->workingMode==0x01)
		{KillTimer(1);MessageBox("kill timer 1");}
}

void CXiaoBiLiDlg::OnCommMscomm4()  //接收水上GPS数据
{
	// TODO: 在此处添加消息处理程序代码
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	BYTE recdata[512];
	CString strtemp;
	if(m_CtrlComm4.get_CommEvent()==2)
	{
		Sleep(40);
		CString str_gps= _T(""); 
		variant_inp=m_CtrlComm4.get_Input();
		safearray_inp=variant_inp;
		len=safearray_inp.GetOneDimSize();
		if(len<80)
		{
			for(k=0;k<len;k++)
				safearray_inp.GetElement(&k,recdata+k);
			recdata[k]='\0';
			gps_data_num++;
			if(gps_data_num==20)
			{
				gps_data_num=1;
				page_test->m_gps_data="";
			}
			for(k=0;k<len;k++)
			{
				//char bt=*(char*)recdata[k];
				strtemp.Format(_T("%c"),(char)recdata[k]);
				page_test->m_gps_data+=strtemp;
				//str_gps+=strtemp;
			}
			//page_test->m_gps_data+="\r\n";

			page_test->ShowData();
			/*CString strlen;
			strlen.Format("%d",len);
			MessageBox(strlen);*/

			if((recdata[0]=='$')&&(recdata[1]=='G')&&(recdata[2]=='P')&&(recdata[3]=='G')&&(recdata[4]=='G')&&(recdata[5]=='A')&&(len==79))
			{
				//sscanf((const char*)recdata,"%6s,%9s,%2d%lf,%c,%3d%lf,%c,%c,%2s,%f,%f,%c,%f,%1s,,",pdata_gps->flag,pdata_gps->time,&(pdata_gps->latitude),&(pdata_gps->latitude_minu),&(pdata_gps->flag_lati),&(pdata_gps->longitude),&(pdata_gps->longitude_minu),&(pdata_gps->flag_longi),&(pdata_gps->GPSProperty),pdata_gps->StarNum,&(pdata_gps->accuracyPercent),&(pdata_gps->earthHigh),&(pdata_gps->highUnit),&(pdata_gps->SeaLevelHigh),pdata_gps->SLhighUnit);
				sscanf_s((const char*)recdata,"%6s,%9s,%2d%lf,%c,%3d%lf,%c,%c,%2s,%f,%f,%c,%f,%1s,,",
					pdata_gps->flag,7,
					pdata_gps->time,10,
					&(pdata_gps->latitude),
					&(pdata_gps->latitude_minu),
					&(pdata_gps->flag_lati),1,
					&(pdata_gps->longitude),
					&(pdata_gps->longitude_minu),
					&(pdata_gps->flag_longi),1,
					&(pdata_gps->GPSProperty),1,
					pdata_gps->StarNum,3,
					&(pdata_gps->accuracyPercent),
					&(pdata_gps->earthHigh),
					&(pdata_gps->highUnit),1,
					&(pdata_gps->SeaLevelHigh),
					pdata_gps->SLhighUnit,2);
				page_test->s_jingdu=pdata_gps->longitude+(pdata_gps->longitude_minu/60);
				page_test->s_weidu=pdata_gps->latitude+(pdata_gps->latitude_minu/60);
				if(gps_timeflag==0)//第一次接收到有效GPS数据修改系统时间
				{
					char hour[3],minute[3],seconds[3],milliSeconds[3];
					memcpy(hour,pdata_gps->time,2);hour[2]='\0';
					memcpy(minute,&(pdata_gps->time[2]),2);minute[2]='\0';
					memcpy(seconds,&(pdata_gps->time[4]),2);seconds[2]='\0';
					memcpy(milliSeconds,&(pdata_gps->time[7]),2);milliSeconds[2]='\0';
					int h=0,m=0,s=0,ms=0;
					h=atoi(hour);m=atoi(minute);s=atoi(seconds);ms=10*atoi(milliSeconds);
					SYSTEMTIME td,tdold;
					GetLocalTime(&tdold);
					td.wMilliseconds = ms;
					td.wSecond = s;
					td.wMinute = m;
					td.wHour = h+8;
					td.wDay = tdold.wDay;
					td.wMonth = tdold.wMonth;
					td.wYear = tdold.wYear;
					SetLocalTime(&td);
					gps_timeflag=1;
				}
			}
		}

	}
}

void CXiaoBiLiDlg::FuZhi_YJ_S07(BYTE* recdata)
{
	BYTE temp[sizeof(S_AWMU_2_EMU_EP)+3];
	unsigned short crcCheck=0;
	pdata_s07->pktHead1=0xa5;
	pdata_s07->pktHead2=0x0700;
	pdata_s07->stage=recdata[4];
	pdata_s07->EMUselfTestStatus=recdata[20];
	pdata_s07->EMUselfTestCmd=recdata[21];
	pdata_s07->powerSwitchAndFrequencyConverter=recdata[5];
	memcpy(temp,pdata_s07,sizeof(S_AWMU_2_EMU_EP));
	crcCheck=CRC16(temp,sizeof(S_AWMU_2_EMU_EP));
	temp[sizeof(S_AWMU_2_EMU_EP)]=(BYTE)(crcCheck%256);
	temp[sizeof(S_AWMU_2_EMU_EP)+1]=(BYTE)(crcCheck/256);
	temp[sizeof(S_AWMU_2_EMU_EP)+2]=0x0d;
	for(int i=0;i<sizeof(S_AWMU_2_EMU_EP)+3;i++)
		sendata_s07[i]=temp[i];
}

unsigned short CXiaoBiLiDlg::CalculateSendCRC(unsigned char* sDat,unsigned short sLength)  
{
	unsigned short sCRC;
	sCRC = 0xffff;
	while(sLength--) sCRC = (sCRC>>8)^c_wTableCRC1[(sCRC^*sDat++)&0x00ff];
	return sCRC;
}

BYTE compute_crc8(BYTE* buffer, unsigned short len)
{
	BYTE crc=0;
    unsigned short i;
    for(i=0; i<len; i++)
    {
		crc = CRC8_TABLE[crc ^ buffer[i]];
    }
    return crc;
}

void CXiaoBiLiDlg::SetTimer1()
{
	SetTimer(1,T_S03,NULL);
}

void CXiaoBiLiDlg::DataWrite_SWSJ()
{
	CString str,strtemp;
	if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x00))  //遥控
	{
		//如果pdata_r30中有数据，则写pdata_r30中的数据，否则写无线电数据
		if(pdata_r30->pktHead2==0x3000)   //pdata_r30中有数据
		{
			strtemp.Format("%f,",atof(pdata_r30->navigationInfo.processedData.longitude));  //自航模经度、纬度、深度
			str+=strtemp;
			strtemp.Format("%f,",atof(pdata_r30->navigationInfo.processedData.latitude));
			str+=strtemp;
			strtemp.Format("%f",pdata_r30->navigationInfo.processedData.depth);
			str+=strtemp+"\r\n";
			strtemp.Format("%f,",pdata_r30->navigationInfo.processedData.rollingAngle);  //自航模横倾、纵倾、艏向
			str+=strtemp;
			strtemp.Format("%f,",pdata_r30->navigationInfo.processedData.trimAngle);
			str+=strtemp;
			strtemp.Format("%f",pdata_r30->navigationInfo.processedData.headingAngle);
			str+=strtemp+"\r\n";
			strtemp.Format("%f,",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.fairwaterRudderAngle);  //自航模围壳舵、方向舵、艉舵舵角
			str+=strtemp;
			strtemp.Format("%f,",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.rudderAngle);
			str+=strtemp;
			strtemp.Format("%f",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.leftRearRudderAngle);
			str+=strtemp+"\r\n";
			float speed=0.0;
			speed=sqrt(pow((double)pdata_r30->navigationInfo.processedData.headingSpeed,2)+pow((double)pdata_r30->navigationInfo.processedData.verticalSpeed,2)+pow((double)pdata_r30->navigationInfo.processedData.lateralSpeed,2));
			strtemp.Format("%f,",speed);  //自航模速度、相对码头方位、相对码头距离
			str+=strtemp;
			//纬度之差大于0，在北方；小于0，在南方。经度之差小于0，在西方。经度之差除纬度之差小于0，为北偏西；大于0，为南偏西。
			float deltaLongitude=0.0,deltaLatitude=0.0,angle=0.0,length=0.0;                            //计算出方位
			deltaLongitude=atof(pdata_r30->navigationInfo.processedData.longitude)-112.050803;
			deltaLatitude=atof(pdata_r30->navigationInfo.processedData.latitude)-30.984741;
			angle=atan(deltaLongitude/deltaLatitude);
			angle=angle*180/3.141593;
			strtemp.Format("%f,",angle);  
			str+=strtemp;
			length=sqrt(pow((double)deltaLongitude,2)+pow((double)deltaLatitude,2))*111000;    //计算出距离
			strtemp.Format("%f",length);  
			str+=strtemp+"\r\n";
			memset(pdata_r30,0,4);
		}
		else   //pdata_r30中无数据
		{
			if(pdata_r303->pktHead2==0x3003)  //无线电有数据
			{
				strtemp.Format("%f,",atof(pdata_r303->navigationInfo.processedData.longitude));   //自航模经度、纬度、深度
				str+=strtemp;
				strtemp.Format("%f,",atof(pdata_r303->navigationInfo.processedData.latitude));
				str+=strtemp;
				strtemp.Format("%f",pdata_r303->navigationInfo.processedData.depth);
				str+=strtemp+"\r\n";
				strtemp.Format("%f,",pdata_r303->navigationInfo.processedData.rollingAngle);   //自航模横倾、纵倾、艏向
				str+=strtemp;
				strtemp.Format("%f,",pdata_r303->navigationInfo.processedData.trimAngle);
				str+=strtemp;
				strtemp.Format("%f",pdata_r303->navigationInfo.processedData.headingAngle);
				str+=strtemp+"\r\n";
				strtemp.Format("%f,",pdata_r10->fairwaterRudderAngle);   //自航模围壳舵、方向舵、艉舵舵角
				str+=strtemp;
				strtemp.Format("%f,",pdata_r10->rudderAngle);
				str+=strtemp;
				strtemp.Format("%f",pdata_r10->leftRearRudderAngle);
				str+=strtemp+"\r\n";
				float speed=0.0;
				speed=sqrt(pow((double)pdata_r303->navigationInfo.processedData.headingSpeed,2)+pow((double)pdata_r303->navigationInfo.processedData.verticalSpeed,2)+pow((double)pdata_r303->navigationInfo.processedData.lateralSpeed,2));
				strtemp.Format("%f,",speed);  //自航模速度、相对码头方位、相对码头距离
				str+=strtemp;
				//纬度之差大于0，在北方；小于0，在南方。经度之差小于0，在西方。经度之差除纬度之差小于0，为北偏西；大于0，为南偏西。
				float deltaLongitude=0.0,deltaLatitude=0.0,angle=0.0,length=0.0;                            //计算出方位
				deltaLongitude=atof(pdata_r303->navigationInfo.processedData.longitude)-112.050803;
				deltaLatitude=atof(pdata_r303->navigationInfo.processedData.latitude)-30.984741;
				angle=atan(deltaLongitude/deltaLatitude);
				angle=angle*180/3.141593;
				strtemp.Format("%f,",angle);  
				str+=strtemp;
				length=sqrt(pow((double)deltaLongitude,2)+pow((double)deltaLatitude,2))*111000;    //计算出距离
				strtemp.Format("%f",length);  
				memset(pdata_r303,0,4);
			}
		}
	}
	if((pdata_r10->workingStage==0x00)&&(pdata_r10->workingMode==0x01))  //自主
	{
		//如果pdata_30中有数据，则写pdata_r30中数据，否则写水声数据
		if(pdata_r30->pktHead2==0x3000)   //pdata_r30中有数据
		{
			strtemp.Format("%f,",atof(pdata_r30->navigationInfo.processedData.longitude));  //自航模经度、纬度、深度
			str+=strtemp;
			strtemp.Format("%f,",atof(pdata_r30->navigationInfo.processedData.latitude));
			str+=strtemp;
			strtemp.Format("%f",pdata_r30->navigationInfo.processedData.depth);
			str+=strtemp+"\r\n";
			strtemp.Format("%f,",pdata_r30->navigationInfo.processedData.rollingAngle);  //自航模横倾、纵倾、艏向
			str+=strtemp;
			strtemp.Format("%f,",pdata_r30->navigationInfo.processedData.trimAngle);
			str+=strtemp;
			strtemp.Format("%f",pdata_r30->navigationInfo.processedData.headingAngle);
			str+=strtemp+"\r\n";
			strtemp.Format("%f,",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.fairwaterRudderAngle);  //自航模围壳舵、方向舵、艉舵舵角
			str+=strtemp;
			strtemp.Format("%f,",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.rudderAngle);
			str+=strtemp;
			strtemp.Format("%f",pdata_r30->primaryControlUnitInfo.rudderAngleInfo.leftRearRudderAngle);
			str+=strtemp+"\r\n";
			float speed=0.0;
			speed=sqrt(pow((double)pdata_r30->navigationInfo.processedData.headingSpeed,2)+pow((double)pdata_r30->navigationInfo.processedData.verticalSpeed,2)+pow((double)pdata_r30->navigationInfo.processedData.lateralSpeed,2));
			strtemp.Format("%f,",speed);                                                             //自航模速度、相对码头方位、相对码头距离
			str+=strtemp;
			//纬度之差大于0，在北方；小于0，在南方。经度之差小于0，在西方。经度之差除纬度之差小于0，为北偏西；大于0，为南偏西。
			float deltaLongitude=0.0,deltaLatitude=0.0,angle=0.0,length=0.0;                            //计算出方位
			deltaLongitude=atof(pdata_r30->navigationInfo.processedData.longitude)-112.050803;
			deltaLatitude=atof(pdata_r30->navigationInfo.processedData.latitude)-30.984741;
			angle=atan(deltaLongitude/deltaLatitude);
			angle=angle*180/3.141593;
			strtemp.Format("%f,",angle);  
			str+=strtemp;
			length=sqrt(pow((double)deltaLongitude,2)+pow((double)deltaLatitude,2))*111000;    //计算出距离
			strtemp.Format("%f",length);  
			str+=strtemp+"\r\n";
			strtemp.Format("%f,",pdata_r30->navigationInfo.processedData.longitude);  //本体测量轨迹当前点的坐标
			str+=strtemp;
			strtemp.Format("%f,",pdata_r30->navigationInfo.processedData.latitude);
			str+=strtemp;
			strtemp.Format("%f",pdata_r30->navigationInfo.processedData.depth);
			str+=strtemp+"\r\n";
			//外场测量轨迹当前点的坐标
			//usbl轨迹当前点的坐标
			strtemp.Format("%d",page1->num_hc1+page1->num_hc2+page1->num_hc3+1);   //任务预置轨迹点的总个数
			str+=strtemp+"\r\n";
			if(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=50)      //任务预置轨迹
			{
				for(int i=0;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
				{
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
					str+=strtemp+"\r\n";
				}
			}
			else if((50<page1->num_hc1+page1->num_hc2+page1->num_hc3+1)&&(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=100))
			{
				for(int i=0;i<50;i++)
				{
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
					str+=strtemp+"\r\n";
				}
				for(int i=50;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
				{
					strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_2->arrayOfTraPoint[i-50].depth);
					str+=strtemp+"\r\n";
				}
			}
			else if((100<page1->num_hc1+page1->num_hc2+page1->num_hc3+1)&&(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=150))
			{
				for(int i=0;i<50;i++)
				{
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
					str+=strtemp+"\r\n";
				}
				for(int i=50;i<100;i++)
				{
					strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_2->arrayOfTraPoint[i-50].depth);
					str+=strtemp+"\r\n";
				}
				for(int i=100;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
				{
					strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_3->arrayOfTraPoint[i-100].depth);
					str+=strtemp+"\r\n";
				}
			}
			else if((150<page1->num_hc1+page1->num_hc2+page1->num_hc3+1)&&(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=200))
			{
				for(int i=0;i<50;i++)
				{
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
					str+=strtemp+"\r\n";
				}
				for(int i=50;i<100;i++)
				{
					strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_2->arrayOfTraPoint[i-50].depth);
					str+=strtemp+"\r\n";
				}
				for(int i=100;i<150;i++)
				{
					strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_3->arrayOfTraPoint[i-100].depth);
					str+=strtemp+"\r\n";
				}
				for(int i=150;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
				{
					strtemp.Format("%f,",pdata_s031_4->arrayOfTraPoint[i-150].longitude);
					str+=strtemp;
					strtemp.Format("%f,",pdata_s031_4->arrayOfTraPoint[i-150].latitude);
					str+=strtemp;
					strtemp.Format("%f",pdata_s031_4->arrayOfTraPoint[i-150].depth);
					str+=strtemp+"\r\n";
				}
			}
			else{}
			memset(pdata_r30,0,4);
		}
		else   //pdata_r30中无数据
		{
			if(pdata_r70e->pktHead2==0x070e)  //水声有数据
			{
				strtemp.Format("%f,",atof(pdata_r70e->navigationUnitInfo.processedData.longitude));  //自航模经度、纬度、深度
				str+=strtemp;
				strtemp.Format("%f,",atof(pdata_r70e->navigationUnitInfo.processedData.latitude));
				str+=strtemp;
				strtemp.Format("%f",pdata_r70e->navigationUnitInfo.processedData.depth);
				str+=strtemp+"\r\n";
				strtemp.Format("%f,",pdata_r70e->navigationUnitInfo.processedData.rollingAngle);  //自航模横倾、纵倾、艏向
				str+=strtemp;
				strtemp.Format("%f,",pdata_r70e->navigationUnitInfo.processedData.trimAngle);
				str+=strtemp;
				strtemp.Format("%f",pdata_r70e->navigationUnitInfo.processedData.headingAngle);
				str+=strtemp+"\r\n";
				strtemp.Format("%f,",0.0);  //自航模围壳舵、方向舵、艉舵舵角
				str+=strtemp;
				strtemp.Format("%f,",0.0);
				str+=strtemp;
				strtemp.Format("%f",0.0);
				str+=strtemp+"\r\n";
				float speed=0.0;
				speed=sqrt(pow((double)pdata_r70e->navigationUnitInfo.processedData.headingSpeed,2)+pow((double)pdata_r70e->navigationUnitInfo.processedData.verticalSpeed,2)+pow((double)pdata_r70e->navigationUnitInfo.processedData.lateralSpeed,2));
				strtemp.Format("%f,",speed);  //自航模速度、相对码头方位、相对码头距离
				str+=strtemp;
				//纬度之差大于0，在北方；小于0，在南方。经度之差小于0，在西方。经度之差除纬度之差小于0，为北偏西；大于0，为南偏西。
				float deltaLongitude=0.0,deltaLatitude=0.0,angle=0.0,length=0.0;                            //计算出方位
				deltaLongitude=atof(pdata_r70e->navigationUnitInfo.processedData.longitude)-112.050803;
				deltaLatitude=atof(pdata_r70e->navigationUnitInfo.processedData.latitude)-30.984741;
				angle=atan(deltaLongitude/deltaLatitude);
				angle=angle*180/3.141593;
				strtemp.Format("%f,",angle);  
				str+=strtemp;
				length=sqrt(pow((double)deltaLongitude,2)+pow((double)deltaLatitude,2))*111000;    //计算出距离
				strtemp.Format("%f",length);  
				str+=strtemp+"\r\n";
				strtemp.Format("%f,",pdata_r70e->navigationUnitInfo.processedData.longitude);  //本体测量轨迹当前点的坐标
				str+=strtemp;
				strtemp.Format("%f,",pdata_r70e->navigationUnitInfo.processedData.latitude);
				str+=strtemp;
				strtemp.Format("%f",pdata_r70e->navigationUnitInfo.processedData.depth);
				str+=strtemp+"\r\n";
				//外场测量轨迹当前点的坐标
				//usbl轨迹当前点的坐标
				strtemp.Format("%d",page1->num_hc1+page1->num_hc2+page1->num_hc3+1);   //任务预置轨迹点的总个数
				str+=strtemp+"\r\n";
				if(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=50)      //任务预置轨迹
				{
					for(int i=0;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
					{
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
						str+=strtemp+"\r\n";
					}
				}
				else if((50<page1->num_hc1+page1->num_hc2+page1->num_hc3+1)&&(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=100))
				{
					for(int i=0;i<50;i++)
					{
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
						str+=strtemp+"\r\n";
					}
					for(int i=50;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
					{
						strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_2->arrayOfTraPoint[i-50].depth);
						str+=strtemp+"\r\n";
					}
				}
				else if((100<page1->num_hc1+page1->num_hc2+page1->num_hc3+1)&&(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=150))
				{
					for(int i=0;i<50;i++)
					{
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
						str+=strtemp+"\r\n";
					}
					for(int i=50;i<100;i++)
					{
						strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_2->arrayOfTraPoint[i-50].depth);
						str+=strtemp+"\r\n";
					}
					for(int i=100;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
					{
						strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_3->arrayOfTraPoint[i-100].depth);
						str+=strtemp+"\r\n";
					}
				}
				else if((150<page1->num_hc1+page1->num_hc2+page1->num_hc3+1)&&(page1->num_hc1+page1->num_hc2+page1->num_hc3+1<=200))
				{
					for(int i=0;i<50;i++)
					{
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_1->arrayOfTraPoint[i].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_1->arrayOfTraPoint[i].depth);
						str+=strtemp+"\r\n";
					}
					for(int i=50;i<100;i++)
					{
						strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_2->arrayOfTraPoint[i-50].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_2->arrayOfTraPoint[i-50].depth);
						str+=strtemp+"\r\n";
					}
					for(int i=100;i<150;i++)
					{
						strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_3->arrayOfTraPoint[i-100].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_3->arrayOfTraPoint[i-100].depth);
						str+=strtemp+"\r\n";
					}
					for(int i=150;i<page1->num_hc1+page1->num_hc2+page1->num_hc3+1;i++)
					{
						strtemp.Format("%f,",pdata_s031_4->arrayOfTraPoint[i-150].longitude);
						str+=strtemp;
						strtemp.Format("%f,",pdata_s031_4->arrayOfTraPoint[i-150].latitude);
						str+=strtemp;
						strtemp.Format("%f",pdata_s031_4->arrayOfTraPoint[i-150].depth);
						str+=strtemp+"\r\n";
					}
				}
				else{}
				memset(pdata_r70e,0,4);
			}
		}
	}

}

void CXiaoBiLiDlg::Init_s01()
{
	arraySend_s01.SetAt(0,0x5A);
	arraySend_s01.SetAt(1,0x01);
	arraySend_s01.SetAt(2,0x00);
	for(int i=3;i<23;i++)
		arraySend_s01.SetAt(i,0x00);
	arraySend_s01.SetAt(10,0x01);  //水上水下通信状态初始化为断开状态
	unsigned short crcCheck=0;
	crcCheck=CalculateSendCRC(arraySend_s01.GetData(),20);
	arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		sendata_s01[i]=arraySend_s01.GetAt(i);
}

void CXiaoBiLiDlg::FuZhi_EMU_0701()
{
	pdata_0701->pktHead1=0xa5;
	pdata_0701->pktHead2=0x0701;
	memcpy(sendata_0701,pdata_0701,sizeof(AWMU_2_EMU_EA_PARAM_CONFIG));
	unsigned short crcCheck=0;
	crcCheck=CRC16(sendata_0701,sizeof(AWMU_2_EMU_EA_PARAM_CONFIG));
	sendata_0701[sizeof(AWMU_2_EMU_EA_PARAM_CONFIG)]=crcCheck%256;
	sendata_0701[sizeof(AWMU_2_EMU_EA_PARAM_CONFIG)+1]=crcCheck/256;
	sendata_0701[sizeof(AWMU_2_EMU_EA_PARAM_CONFIG)+2]=0x0d;
}
  
void CXiaoBiLiDlg::OnCommMscomm5()        //接收USBL信息
{
	// TODO: 在此处添加消息处理程序代码
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	BYTE recdata[200];
	CString strtemp;
	if(m_CtrlComm5.get_CommEvent()==2)
	{
		Sleep(30);
		CString str_gps= _T(""); 
		variant_inp=m_CtrlComm5.get_Input();
		safearray_inp=variant_inp;
		len=safearray_inp.GetOneDimSize();
		for(k=0;k<len;k++)
			safearray_inp.GetElement(&k,recdata+k);
		recdata[k]='\0';
		usbl_data_num++;
		if(usbl_data_num==20)
		{
			usbl_data_num=1;
			page_test->m_usbl_data="";
		}
		for(k=0;k<len;k++)
		{
			//char bt=*(char*)recdata[k];
			strtemp.Format(_T("%c"),(char)recdata[k]);
			page_test->m_usbl_data+=strtemp;
			//str_gps+=strtemp;
		}
		//page_test->m_gps_data+="\r\n";
		page_test->ShowData();		
		if((recdata[0]=='$')&&(recdata[1]=='G')&&(recdata[2]=='P')&&(recdata[3]=='G')&&(recdata[4]=='G')&&(recdata[5]=='A')&&(len>60))
		{
		//sscanf((const char*)recdata,"%6s,%9s,%2d%lf,%c,%3d%lf,%c,%c,%2s,%f,%f,%c,",pdata_usbl->flag,pdata_usbl->time,&(pdata_usbl->latitude),&(pdata_usbl->latitude_minu),&(pdata_usbl->flag_lati),&(pdata_usbl->longitude),&(pdata_usbl->longitude_minu),&(pdata_usbl->flag_longi),pdata_usbl->fix_value1,pdata_usbl->fix_value2,&(pdata_usbl->accuracyPercent),&(pdata_usbl->depth),&(pdata_usbl->depthUnit));
		sscanf_s((const char*)recdata,"%6s,%9s,%2d%lf,%c,%3d%lf,%c,%c,%2s,%f,%f,%c,",
			pdata_usbl->flag,7,
			pdata_usbl->time,10,
			&(pdata_usbl->latitude),
			&(pdata_usbl->latitude_minu),
			&(pdata_usbl->flag_lati),1,
			&(pdata_usbl->longitude),
			&(pdata_usbl->longitude_minu),
			&(pdata_usbl->flag_longi),1,
			pdata_usbl->fix_value1,1,
			pdata_usbl->fix_value2,2,
			&(pdata_usbl->accuracyPercent),
			&(pdata_usbl->depth),
			&(pdata_usbl->depthUnit),1);
		FuZhi_CC_S026();
		SSCCSocket->Send(sendata_s026,sizeof(AWRU_AWMU_S026)+3,0);
		/*m_longitude=pdata_gps->longitude;
		m_latitude=pdata_gps->latitude;
		m_depth=pdata_gps->earthHigh+pdata_gps->SeaLevelHigh;*/
		/*CString str;
		str.Format("%3d %2d",pdata_gps->latitude,pdata_gps->longitude);
		MessageBox(str);*/
		//UpdateData(FALSE);
		}
    }


}
void CXiaoBiLiDlg:: AWMU_UWMU_W_ReConnect()
{
		BYTE f0,f1,f2,f3;
		f0=192;f1=168;f2=0;f3=103;  //水下主控IP
		CString IP;
		IP.Format("%d.%d.%d.%d",f0,f1,f2,f3);
		SSSXSocket->Close();
		if(SSSXSocket!=NULL)
			delete SSSXSocket;
		SSSXSocket=new CSessionSocket(this);   //水上主控发送连接请求给水下主控
		SSSXSocket->Create(0,SOCK_STREAM,"192.168.0.100");//设置本机端口
		unsigned long ul = 1;
		ioctlsocket(*SSSXSocket, FIONBIO, &ul);
		if(SSSXSocket->Connect(IP,2003))  //设置水下主控服务器端口号
		{
			page1->pdata_page1->awmu_uwmu_net_state=true;//水上水下主控通信灯亮
		}

}
void CXiaoBiLiDlg:: AWMU_EMU_W_ReConnect()
{
	BYTE f0,f1,f2,f3;
	f0=192;f1=168;f2=0;f3=107;        //应急IP
	CString IP;
	IP.Format("%d.%d.%d.%d",f0,f1,f2,f3);
	SSYJSocket->Close();
	if(SSYJSocket!=NULL)
		delete SSYJSocket;
	SSYJSocket=new CSessionSocket(this);  //水上主控与应急单元通信套接字
	SSYJSocket->Create(0,SOCK_STREAM,"192.168.0.100");
	unsigned long ul = 1;
    ioctlsocket(*SSYJSocket, FIONBIO, &ul);
	if(SSYJSocket->Connect(IP,2007))             //连接应急单元服务器
		page1->pdata_page1->awmu_emu_net_state=true;
}
void CXiaoBiLiDlg::Connect_UWMU()
{
	PingFlag_uwmu=0;
	//BYTE f0,f1,f2,f3;
	//f0=192;f1=168;f2=0;f3=103;        //水下主控IP
	//CString *pIP=new CString;
	//pIP->Format("%d.%d.%d.%d",f0,f1,f2,f3);
	//hThread_uwmu=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ConnectProc_uwmu,pIP,0,NULL);
	hThread_uwmu=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ConnectProc_uwmu,NULL,0,NULL);
	CloseHandle(hThread_uwmu);
}
void CXiaoBiLiDlg::Connect_EMU()
{
	PingFlag_emu=0;
	//BYTE f0,f1,f2,f3;
	//f0=192;f1=168;f2=0;f3=107;        //应急IP
	//CString *pIP=new CString;
	//pIP->Format("%d.%d.%d.%d",f0,f1,f2,f3);
	//hThread_emu=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ConnectProc_emu,pIP,0,NULL);
	hThread_emu=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ConnectProc_emu,NULL,0,NULL);
	CloseHandle(hThread_emu);
}

void CXiaoBiLiDlg::ErroSwitch(int erro)
{ 
	int erro_temp=erro;
	switch(erro_temp)
	{
	case WSANOTINITIALISED:
		MessageBox("WSANOTINITIALISED");
	case WSAENETDOWN:
		MessageBox("WSAENETDOWN");
	case WSAEADDRINUSE:
		MessageBox("WSAEADDRINUSE");
	case WSAEINPROGRESS:
		MessageBox("WSAEINPROGRESS");
	case WSAEADDRNOTAVAIL:
		MessageBox("WSAEADDRNOTAVAIL");
	case WSAEAFNOSUPPORT:
		MessageBox("WSAEAFNOSUPPORT");
	case WSAECONNREFUSED:
		MessageBox("WSAECONNREFUSED");
	case WSAEDESTADDRREQ:
		MessageBox("WSAEDESTADDRREQ");
	case WSAEFAULT:
		MessageBox("WSAEFAULT");
	case WSAEINVAL:
		MessageBox("WSAEINVAL");
	case WSAEISCONN:
		MessageBox("WSAEISCONN");
	case WSAEMFILE:
		MessageBox("WSAEMFILE");
	case WSAENETUNREACH:
		MessageBox("WSAENETUNREACH");
	case WSAENOBUFS:
		MessageBox("WSAENOBUFS");
	case WSAENOTSOCK:
		MessageBox("WSAENOTSOCK");
	case WSAETIMEDOUT:
		MessageBox("WSAETIMEDOUT");
	case WSAEWOULDBLOCK:
		MessageBox("WSAEWOULDBLOCK");
	case WSAEINTR:
		MessageBox("WSAEINTR");
	default:
		MessageBox("qita");
	}
}

void CXiaoBiLiDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//关闭时删除套接字
	KillTimer(1);
	SSSXSocket->Close();
			if(SSSXSocket!=NULL)
				delete SSSXSocket;
	CDialogEx::OnClose();
	//MessageBox("已关闭");
}
//void CXiaoBiLiDlg::SetTimer18()
//{
//	SetTimer(18,1000,NULL);
//}
//void CXiaoBiLiDlg::KillTimer18()
//{
//	KillTimer(1);
//	KillTimer(2);
//	KillTimer(18);
//}
void CXiaoBiLiDlg::Fuzhu_Test_Show()
{
	CString Rudder_feedback,Head_feedback,Speed_feedback,Temp_feedback,Humidity_feedback,Pressure_feedback,
		    BottomHeight_feedback,Depth_feedback,Pitch_feedback,Roll_feedback;
	if(page1->pdata_page1->awmu_uwmu_net_state==true)  //无线网络报文数据
	{
		//调试界面获取信息
		sscanf_s(pdata_r30->navigationInfo.processedData.longitude,"%lf",&(page_test->jingdu));
		sscanf_s(pdata_r30->navigationInfo.processedData.latitude,"%lf",&(page_test->weidu));
		//集中控制界面显示 获取舵角反馈
		Rudder_feedback.Format("%.1f",(pdata_r30->primaryControlUnitInfo.rudderAngleInfo.fairwaterRudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_WKD_FB,Rudder_feedback);
		Rudder_feedback.Format("%.1f",(pdata_r30->primaryControlUnitInfo.rudderAngleInfo.rudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_FXD_FB,Rudder_feedback);
		Rudder_feedback.Format("%.1f",(pdata_r30->primaryControlUnitInfo.rudderAngleInfo.leftRearRudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_ZWD_FB,Rudder_feedback);
		Rudder_feedback.Format("%.1f",(pdata_r30->primaryControlUnitInfo.rudderAngleInfo.rightRearRudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_YWD_FB,Rudder_feedback);
		Head_feedback.Format("%.1f",(pdata_r30->navigationInfo.processedData.headingAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_HEADING_FB,Head_feedback);
		Speed_feedback.Format("%.2f",(pdata_r30->navigationInfo.processedData.headingSpeed)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_SPEED_FB,Speed_feedback);
		BottomHeight_feedback.Format("%.2f",(pdata_r30->navigationInfo.processedData.dvlToBottomHeignt)*0.01); //集控界面新增 底高、深度、纵倾、横滚显示20180726
		page1->SetDlgItemTextA(IDC_EDIT_BOTTOM_HEIGHT_FB,BottomHeight_feedback);
		Depth_feedback.Format("%.2f",(pdata_r30->navigationInfo.processedData.depth)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_DEPTH_FB,Depth_feedback);
		Pitch_feedback.Format("%.2f",(pdata_r30->navigationInfo.processedData.trimAngle)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_PITCH_FB,Pitch_feedback);
		Roll_feedback.Format("%.2f",(pdata_r30->navigationInfo.processedData.rollingAngle)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_ROLL_FB,Roll_feedback);
		//集中控制界面，获取舱室环境反馈20180328
		Temp_feedback.Format("%.1f",(pdata_r30->primaryControlUnitInfo.cabinTempreture)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_TEMP_FB,Temp_feedback);
		Humidity_feedback.Format("%.1f",(pdata_r30->primaryControlUnitInfo.cabinHumidity)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_HUMIDITY_FB,Humidity_feedback);
		Pressure_feedback.Format("%.3f",pdata_r30->primaryControlUnitInfo.airPress);
		page1->SetDlgItemTextA(IDC_EDIT_PRESSER_FB,Pressure_feedback);
		 //水泵起停状态 20180131
		if(((pdata_r30->powerControlUnitInfo.powerSystem_r934.switchState2&0x08)==0x08))     //水泵起停状态 20180131
		{
			page1->drawpicture(IDC_PICTURE_SHUIBENG_STATE,1);  //水泵状态灯变绿
		}
		else
		{
			page1->drawpicture(IDC_PICTURE_SHUIBENG_STATE,0);  //水泵状态灯变灰
		}

	}
	if(page1->pdata_page1->awmu_uwmu_wxd_state==true)  //无线电报文数据
	{
		//调试界面显示 获取经纬度信息反馈
		sscanf_s(pdata_r303->navigationInfo.processedData.longitude,"%lf",&(page_test->jingdu));
		sscanf_s(pdata_r303->navigationInfo.processedData.latitude,"%lf",&(page_test->weidu));
		//集中控制界面显示 获取舵角反馈
		Rudder_feedback.Format("%.1f",(pdata_r303->primaryControlUnitInfo.rudderAngleInfo.fairwaterRudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_WKD_FB,Rudder_feedback);
		Rudder_feedback.Format("%.1f",(pdata_r303->primaryControlUnitInfo.rudderAngleInfo.rudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_FXD_FB,Rudder_feedback);
		Rudder_feedback.Format("%.1f",(pdata_r303->primaryControlUnitInfo.rudderAngleInfo.leftRearRudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_ZWD_FB,Rudder_feedback);
		Rudder_feedback.Format("%.1f",(pdata_r303->primaryControlUnitInfo.rudderAngleInfo.rightRearRudderAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_YWD_FB,Rudder_feedback);
		Head_feedback.Format("%.1f",(pdata_r303->navigationInfo.processedData.headingAngle)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_HEADING_FB,Head_feedback);
		Speed_feedback.Format("%.2f",(pdata_r303->navigationInfo.processedData.headingSpeed)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_SPEED_FB,Speed_feedback);
		BottomHeight_feedback.Format("%.2f",(pdata_r303->navigationInfo.processedData.dvlToBottomHeignt)*0.01); //集控界面新增 底高、深度、纵倾、横滚显示20180726
		page1->SetDlgItemTextA(IDC_EDIT_BOTTOM_HEIGHT_FB,BottomHeight_feedback);
		Depth_feedback.Format("%.2f",(pdata_r303->navigationInfo.processedData.depth)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_DEPTH_FB,Depth_feedback);
		Pitch_feedback.Format("%.2f",(pdata_r303->navigationInfo.processedData.trimAngle)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_PITCH_FB,Pitch_feedback);
		Roll_feedback.Format("%.2f",(pdata_r303->navigationInfo.processedData.rollingAngle)*0.01);
		page1->SetDlgItemTextA(IDC_EDIT_ROLL_FB,Roll_feedback);
		//集中控制界面，获取舱室环境反馈20180328
		Temp_feedback.Format("%.1f",(pdata_r303->primaryControlUnitInfo.cabinTempreture)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_TEMP_FB,Temp_feedback);
		Humidity_feedback.Format("%.1f",(pdata_r303->primaryControlUnitInfo.cabinHumidity)*0.1);
		page1->SetDlgItemTextA(IDC_EDIT_HUMIDITY_FB,Humidity_feedback);
		Pressure_feedback.Format("%.3f",pdata_r303->primaryControlUnitInfo.airPress);
		page1->SetDlgItemTextA(IDC_EDIT_PRESSER_FB,Pressure_feedback);
		//水泵起停状态 20180131
		if(((pdata_r303->powerControlUnitInfo.powerSystem_r934.switchState2&0x08)==0x08))
		{
			page1->drawpicture(IDC_PICTURE_SHUIBENG_STATE,1);  //水泵状态灯变绿
		}
		else
		{
			page1->drawpicture(IDC_PICTURE_SHUIBENG_STATE,0);  //水泵状态灯变灰
		}

	}
}
void CXiaoBiLiDlg::Auto_timer_start()
{
	SetTimer(18,1000,NULL);
	
}
void CXiaoBiLiDlg::Auto_timer_end()
{
	KillTimer(18);
	CString num_str;
	page1->m_second_num=0;
	num_str.Format("%d",page1->m_second_num);
	page1->SetDlgItemTextA(IDC_EDIT_AUTO_TIMER,num_str);
}
void CXiaoBiLiDlg::KillTimer_19()
{
	KillTimer(19);
}
void CXiaoBiLiDlg::SetTimer_1()
{
	SetTimer(1,T_S03,NULL);
}

