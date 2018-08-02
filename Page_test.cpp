// Page_test.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page_test.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include "RwyzDlg.h"

// CPage_test 对话框

IMPLEMENT_DYNAMIC(CPage_test, CDialogEx)

CPage_test::CPage_test(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage_test::IDD, pParent)
	
{
	m_pDlg=pDlg;
	m_gps_data = _T("");
	m_usbl_data = _T("");
	m_gongkuang = 0;
	m_moshi = 0;
	m_binpinqi_reset = 1;
	m_bianpinqi_start = 1;
	m_cable = 1;
	m_camera1 = 0;
	m_camera2 = 0;
	m_camera3 = 0;
	m_chaoshen = 1;
	m_float = 1;
	m_gasbag = 1;
	m_jueyuan = 1;
	m_loushui = 1;
	m_motor1 = 1;
	m_motor2 = 1;
	m_motor3 = 1;
	m_motor4 = 1;
	m_power1 = 1;
	m_power2 = 1;
	m_power3 = 1;
	m_power4 = 1;
	m_power5 = 1;
	m_qiangao = 1;
	m_stop = 1;
	m_yingjiganyu = 1;
	m_bianpinqi_jiting = 1;
	m_wxd_data = _T("");
	m_recvwxd_flag=FALSE;
	m_angle = _T("");
	m_distance = _T("");
	jingdu=0;
	weidu=0;
	//  m_show_weidu = 0.0;
	m_show_jingdu = _T("");
	m_show_weidu = _T("");
	m_weidu_set = 31.01966;
	m_jingdu_set = 111.98680;
	m_m_weidu_set2 = 31.01406;
	m_jingdu_set2 = 111.99110;
	m_real_distance = _T("");
	//  m_x = 0.0f;
	//  m_y = 0.0f;
	m_y = _T("");
	m_x = _T("");
	m_fangwei = _T("");
	m_distance_jizhan = _T("");
	jingdu_last=111.984603;
	weidu_last=31.024170;
	jingdu_now=0;
	weidu_now=0;
	distance_sum=0;
	m_diastance_base2 = _T("");
	m_base_lat = 0.0;
	m_base_lon = 0.0;
	m_speed_limit_n = 0;
	m_speed_limit_p = 0;
	m_speed_gradient = 0;
}

CPage_test::~CPage_test()
{
}

void CPage_test::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GPS_DATA, m_gps_data);
	DDX_Text(pDX, IDC_EDIT_USBL_DATA, m_usbl_data);
	DDX_Radio(pDX, IDC_RADIO_SHIYAN, m_gongkuang);
	DDX_Radio(pDX, IDC_RADIO_YAOKONG, m_moshi);
	DDX_Radio(pDX, IDC_RADIO_BIANPINQI_RESET, m_binpinqi_reset);
	DDX_Radio(pDX, IDC_RADIO_BIANPINQI_START, m_bianpinqi_start);
	DDX_Radio(pDX, IDC_RADIO_CABLE_Y, m_cable);
	DDX_Radio(pDX, IDC_RADIO_CAMERA1_Y, m_camera1);
	DDX_Radio(pDX, IDC_RADIO_CAMERA2_Y, m_camera2);
	DDX_Radio(pDX, IDC_RADIO_CAMERA3_Y, m_camera3);
	DDX_Radio(pDX, IDC_RADIO_CHAOSHEN_Y, m_chaoshen);
	DDX_Radio(pDX, IDC_RADIO_FLOAT_Y, m_float);
	DDX_Radio(pDX, IDC_RADIO_GASBAG_Y, m_gasbag);
	DDX_Radio(pDX, IDC_RADIO_JUEYUAN_Y, m_jueyuan);
	DDX_Radio(pDX, IDC_RADIO_LOUSHUI_Y, m_loushui);
	DDX_Radio(pDX, IDC_RADIO_MOTOR1_START, m_motor1);
	DDX_Radio(pDX, IDC_RADIO_MOTOR2_START, m_motor2);
	DDX_Radio(pDX, IDC_RADIO_MOTOR3_START, m_motor3);
	DDX_Radio(pDX, IDC_RADIO_MOTOR4_START, m_motor4);
	DDX_Radio(pDX, IDC_RADIO_POWER1_ON, m_power1);
	DDX_Radio(pDX, IDC_RADIO_POWER2_ON, m_power2);
	DDX_Radio(pDX, IDC_RADIO_POWER3_ON, m_power3);
	DDX_Radio(pDX, IDC_RADIO_POWER4_ON, m_power4);
	DDX_Radio(pDX, IDC_RADIO_POWER5_ON, m_power5);
	DDX_Radio(pDX, IDC_RADIO_QIANGAO_Y, m_qiangao);
	DDX_Radio(pDX, IDC_RADIO_STOP_Y, m_stop);
	DDX_Radio(pDX, IDC_RADIO_YINGJIGY_Y, m_yingjiganyu);
	DDX_Radio(pDX, IDC_RADIO_BIANPINQI_JITING_Y, m_bianpinqi_jiting);
	DDX_Text(pDX, IDC_EDIT_WXD_DATA, m_wxd_data);
	DDX_Check(pDX, IDC_CHECK_RECV, m_recvwxd_flag);
	DDX_Check(pDX, IDC_CHECK_WXD_DETECT, m_wxd_detect);
	DDX_Check(pDX, IDC_CHECK_TX_DISTANCE, m_distance_flag);
	DDX_Text(pDX, IDC_EDIT_ANGLE, m_angle);
	DDX_Text(pDX, IDC_EDIT_DISTANCE, m_distance);
	//  DDX_Control(pDX, IDC_EDIT_WEIDU, m_show_weidu);
	//  DDX_Text(pDX, IDC_EDIT_WEIDU, m_show_weidu);
	DDX_Text(pDX, IDC_EDIT_JINGDU, m_show_jingdu);
	DDX_Text(pDX, IDC_EDIT_WEIDU, m_show_weidu);
	DDX_Text(pDX, IDC_EDIT_WEIDU_SET, m_weidu_set);
	DDX_Text(pDX, IDC_EDIT_JINGDU_SET, m_jingdu_set);
	DDX_Text(pDX, IDC_EDIT_REAL_DISTANCE, m_real_distance);
	//  DDX_Text(pDX, IDC_EDIT_X, m_x);
	//  DDX_Text(pDX, IDC_EDIT_Y, m_y);
	DDX_Text(pDX, IDC_EDIT_Y, m_y);
	DDX_Text(pDX, IDC_EDIT_X, m_x);
	DDX_Text(pDX, IDC_EDIT_FANGWEI, m_fangwei);
	DDX_Text(pDX, IDC_EDIT_DISTANCE_JIZHAN, m_distance_jizhan);
	DDX_Text(pDX, IDC_EDIT_WEIDU_SET2, m_m_weidu_set2);
	DDX_Text(pDX, IDC_EDIT_JINGDU_SET2, m_jingdu_set2);
	//  DDX_Control(pDX, IDC_EDIT_DISTANCE_BASE2, m_distance_base2);
	DDX_Text(pDX, IDC_EDIT_DISTANCE_BASE2, m_diastance_base2);
	DDX_Text(pDX, IDC_EDIT_DISTANCE_BASE_LATI, m_base_lat);
	DDX_Text(pDX, IDC_EDIT_DISTANCE_BASE_LON, m_base_lon);
	DDX_Check(pDX, IDC_CHECK_SPEED_LIMIT, m_speed_limit_flag);
	DDX_Check(pDX, IDC_CHECK_SPEED_GRADIENT_CTR, m_speed_ctr_flag);
	DDX_Text(pDX, IDC_EDIT_SPEED_LIMIT_N, m_speed_limit_n);
	DDV_MinMaxShort(pDX, m_speed_limit_n, -1500, 0);
	DDX_Text(pDX, IDC_EDIT_SPEED_LIMIT_P, m_speed_limit_p);
	DDV_MinMaxShort(pDX, m_speed_limit_p, 0, 1500);
	DDX_Text(pDX, IDC_EDIT_SPEED_GRADIENT, m_speed_gradient);
}


BEGIN_MESSAGE_MAP(CPage_test, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON__SCH_FEEDBACK, &CPage_test::OnBnClickedButton)
	ON_BN_CLICKED(IDC_BUTTON_SEND_WXD, &CPage_test::OnBnClickedButtonSendWxd)
	ON_BN_CLICKED(IDC_CHECK_RECV, &CPage_test::OnBnClickedCheckRecv)
	ON_BN_CLICKED(IDC_CHECK_WXD_DETECT, &CPage_test::OnBnClickedCheckWxdDetect)
	ON_BN_CLICKED(IDC_CHECK_TX_DISTANCE, &CPage_test::OnBnClickedCheckTxDistance)
//	ON_WM_TIMECHANGE()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON_SET, &CPage_test::OnBnClickedButtonSet)
ON_BN_CLICKED(IDC_BUTTON_RESET, &CPage_test::OnBnClickedButtonReset)
ON_BN_CLICKED(IDC_BUTTON_QINGLING, &CPage_test::OnBnClickedButtonQingling)
ON_BN_CLICKED(IDC_BUTTON_SET2, &CPage_test::OnBnClickedButtonSet2)
ON_BN_CLICKED(IDC_BUTTON_SET3, &CPage_test::OnBnClickedButtonSet3)
ON_BN_CLICKED(IDC_BUTTON_SET4, &CPage_test::OnBnClickedButtonSet4)
ON_BN_CLICKED(IDC_CHECK_SPEED_LIMIT, &CPage_test::OnBnClickedCheckSpeedLimit)
ON_BN_CLICKED(IDC_CHECK_SPEED_GRADIENT_CTR, &CPage_test::OnBnClickedCheckSpeedGradientCtr)
ON_BN_CLICKED(IDC_BUTTON_SPEED_LIMIT_COMFIRM, &CPage_test::OnBnClickedButtonSpeedLimitComfirm)
ON_BN_CLICKED(IDC_BUTTON_SPEED_GRADIENT_CONFIRM, &CPage_test::OnBnClickedButtonSpeedGradientConfirm)
END_MESSAGE_MAP()


// CPage_test 消息处理程序
void CPage_test::ShowData()
{
	
	int m_currentLinePos=((CEdit *)(GetDlgItem(IDC_EDIT_GPS_DATA)))->GetLineCount();
	((CEdit *)(GetDlgItem(IDC_EDIT_GPS_DATA)))->LineScroll(m_currentLinePos);
	    m_currentLinePos=((CEdit *)(GetDlgItem(IDC_EDIT_USBL_DATA)))->GetLineCount();
	((CEdit *)(GetDlgItem(IDC_EDIT_USBL_DATA)))->LineScroll(m_currentLinePos);
	SetDlgItemText(IDC_EDIT_GPS_DATA,m_gps_data);
	SetDlgItemText(IDC_EDIT_USBL_DATA,m_usbl_data);
	m_show_weidu.Format("%lf",s_weidu);
	m_show_jingdu.Format("%lf",s_jingdu);
	SetDlgItemText(IDC_EDIT_WEIDU,m_show_weidu);
	SetDlgItemText(IDC_EDIT_JINGDU,m_show_jingdu);
}

void CPage_test::OnBnClickedButton()    //反馈信息至手操盒
{
	// TODO: 在此添加控件通知处理程序代码
      UpdateData(TRUE);
	  FUZHI_SCH_SO1_TEST();
	 //   BYTE data[3];
		//data[0]=0x5a;
		//data[1]=0xff;
		//data[2]=0x0d;
		//m_pDlg->SCHSocket->Send(data,3,0);	
}


void CPage_test::FUZHI_SCH_SO1_TEST()       
{
	m_pDlg->arraySend_s01.SetAt(0,0x5A);
	m_pDlg->arraySend_s01.SetAt(1,0x01);
	m_pDlg->arraySend_s01.SetAt(2,0x00);
	if(0==m_gongkuang)                       //工况
		m_pDlg->arraySend_s01.SetAt(3,0x00);
	else
		m_pDlg->arraySend_s01.SetAt(3,0x01);
	if(0==m_moshi)                           //模式
		m_pDlg->arraySend_s01.SetAt(4,0x00);
	else
		m_pDlg->arraySend_s01.SetAt(4,0x01);
	char baojingInf;                          //报警
	baojingInf=0;
	if(0==m_loushui)
		baojingInf+=1;
	if(0==m_jueyuan)
		baojingInf+=2;
	if(0==m_chaoshen)
		baojingInf+=4;
	if(0==m_qiangao)
		baojingInf+=8;
	m_pDlg->arraySend_s01.SetAt(5,baojingInf);
	char powerState;                          //电源状态
	powerState=0;
	if(0==m_power1)
		powerState+=1;
	if(0==m_power2)
		powerState+=2;
	if(0==m_power3)
		powerState+=4;
	if(0==m_power4)
		powerState+=8;
	if(0==m_power5)
		powerState+=16;
	if(0==m_bianpinqi_start)
		powerState+=32;
	if(0==m_bianpinqi_jiting)            //变频器急停
		powerState+=64;
	if(0==m_binpinqi_reset)
		powerState+=128;
	m_pDlg->arraySend_s01.SetAt(6,powerState);
	char motorState;                          //电机状态
	motorState=0;
	if(0==m_motor1)
		motorState+=1;
	if(0==m_motor2)
		motorState+=2;
	if(0==m_motor3)
		motorState+=4;
	if(0==m_motor4)
		motorState+=8;
	m_pDlg->arraySend_s01.SetAt(7,motorState);
	if(0==m_yingjiganyu)
        m_pDlg->arraySend_s01.SetAt(8,0x01);  //写入应急使能
	else
		m_pDlg->arraySend_s01.SetAt(8,0x00);
	char EMUState;                          //写入应急措施执行状态
	EMUState=0;
	if(0==m_stop)
		EMUState+=1;
	if(0==m_float)
		EMUState+=2;
	if(0==m_gasbag)
		EMUState+=4;
	if(0==m_cable)
		EMUState+=8;
	m_pDlg->arraySend_s01.SetAt(9,EMUState);
	unsigned short crcCheck=0;
	crcCheck=m_pDlg->CalculateSendCRC(m_pDlg->arraySend_s01.GetData(),20);
	m_pDlg->arraySend_s01.SetAt(20,(BYTE)(crcCheck%256));
	m_pDlg->arraySend_s01.SetAt(21,(BYTE)(crcCheck/256));
	m_pDlg->arraySend_s01.SetAt(22,0x0D); //包尾'\r'
	for(int i=0;i<23;i++)
		m_pDlg->sendata_s01[i]=m_pDlg->arraySend_s01.GetAt(i);
}


void CPage_test::OnBnClickedButtonSendWxd()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDlg->wxd_send++;
	m_pDlg->m_CtrlComm2.put_Output(COleVariant(m_pDlg->arraySend_s03)); //手动向水下主控发送无线电报文

}





void CPage_test::OnBnClickedCheckRecv()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

}


void CPage_test::OnBnClickedCheckWxdDetect()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
}
double CPage_test::JINGWEIDU_TO_XY(double jingdu,double weidu,double start_jingdu,double start_weidu) //经纬度转化为大地坐标系X Y
{
	double rad_wd,a,e,d_jd,d_wd;
	double du_to_rad;
	double x,y;
	double distance;
	a=6378137;                   //地球长半轴长度，单位为m
	e=0.003352810664;            //椭球的第一偏心率，无单位
	d_jd=jingdu-start_jingdu;               //经度差，单位为度
	d_wd=weidu-start_weidu;                //纬度差，单位为度
	x=d_wd*a*(1-e*e)*3.1415926/(180*sqrt((1-e*e*sin(weidu/57.3)*sin(weidu/57.3))*(1-e*e*sin(weidu/57.3)*sin(weidu/57.3))*(1-e*e*sin(weidu/57.3)*sin(weidu/57.3))));
	y=d_jd*a*cos(weidu/57.3)*3.1415926/(180*sqrt(1-e*e*sin(weidu/57.3)*sin(weidu/57.3)));
	distance=sqrt(pow(x,2)+pow(y,2));
	return distance;
}
double CPage_test::Angle(double jingdu,double weidu,double start_jingdu,double start_weidu) //计算方位角
{
	double d_jd,d_wd,angle;
	d_jd=jingdu-start_jingdu;               //经度差，单位为度
	d_wd=weidu-start_weidu;                //纬度差，单位为度
	angle=atan2(d_jd,d_wd);
	angle=angle*180/3.141593;
	return angle;
}


void CPage_test::OnBnClickedCheckTxDistance()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_distance_flag)
	{
		SetTimer(1,1000,NULL);
	}
	else
	{
		KillTimer(1);
	}
}


//void CPage_test::OnTimeChange()
//{
//	CDialogEx::OnTimeChange();
//
//	// TODO: 在此处添加消息处理程序代码
//}


void CPage_test::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
	if(1==nIDEvent)
	{
		//计算距水上GPS距离方位
		double distance,angle;
		distance=JINGWEIDU_TO_XY(jingdu,weidu,s_jingdu,s_weidu);
		//distance=JINGWEIDU_TO_XY(0,0,s_jingdu,s_weidu);
		m_distance.Format("%.2f",distance);
		SetDlgItemText(IDC_EDIT_DISTANCE,m_distance);
		m_pDlg->page1->SetDlgItemText(IDC_EDIT_MOTHERSHIP_DISTANCE,m_distance);  //辅助操舵界面 距母船距离
		angle=Angle(jingdu,weidu,s_jingdu,s_weidu);
		//angle=Angle(0,0,s_jingdu,s_weidu);
		if(angle==0)
		{
			m_angle="正北";
		}
		if(angle==90)
		{
			m_angle="正东";
		}
		if((angle==180) ||(angle==-180))
		{
			m_angle="正南";
		}
		if(angle==-90)
		{
			m_angle="正西";
		}
		if((angle>0)&&(angle<90))
		{
			m_angle.Format("北偏东%.2f度",angle);

		}
		if((angle>90)&&(angle<180))
		{
			m_angle.Format("东偏南%.2f度",(angle-90));
		}
		if((angle>-90)&&(angle<0))
		{
			m_angle.Format("北偏西%.2f度",abs(angle));
		}
		if((angle>-180)&&(angle<-90))
		{
			m_angle.Format("西偏南%.2f度",(abs(angle)-90));
		}
		SetDlgItemText(IDC_EDIT_ANGLE,m_angle);
		m_pDlg->page1->SetDlgItemText(IDC_EDIT_MOTHERSHIP_BEARING,m_angle);  //辅助操舵界面 距母船方位20180727
		//计算据自主航行起点终点位置
		double distance_jizhan,angle_jizhan;
		CString distance_str;
		distance_jizhan=JINGWEIDU_TO_XY(jingdu,weidu,m_jingdu_set,m_weidu_set);
		distance_str.Format("%.2f",distance_jizhan);
		SetDlgItemText(IDC_EDIT_DISTANCE_JIZHAN,distance_str);
		m_pDlg->page1->SetDlgItemText(IDC_EDIT_STARTPOINT_DISTANCE,distance_str);  //辅助操舵界面
		distance_jizhan=JINGWEIDU_TO_XY(jingdu,weidu,m_jingdu_set2,m_m_weidu_set2);
		distance_str.Format("%.2f",distance_jizhan);
		SetDlgItemText(IDC_EDIT_FANGWEI,distance_str);
		m_pDlg->page1->SetDlgItemText(IDC_EDIT_ENDPOINT_DISTANCE,distance_str);  //辅助操舵界面
		/*angle_jizhan=Angle(jingdu,weidu,m_jingdu_set,m_weidu_set);  //距离基站方位，已屏蔽
		if(angle_jizhan<0)
			angle_jizhan+=360;
		m_fangwei.Format("%lf",angle_jizhan);
		SetDlgItemText(IDC_EDIT_FANGWEI,m_fangwei);*/
		//计算实际里程
		jingdu_now=jingdu;
		weidu_now=weidu;
		distance_sum+=JINGWEIDU_TO_XY(jingdu_now,weidu_now,jingdu_last,weidu_last);
		m_real_distance.Format("%.2f",distance_sum);
	    SetDlgItemText(IDC_EDIT_REAL_DISTANCE,m_real_distance);
		jingdu_last=jingdu_now;
		weidu_last=weidu_now;
		//计算距基站距离（趸船）
		double distance_jizhan2;
		CString distance_str2;
		distance_jizhan2=JINGWEIDU_TO_XY(jingdu,weidu,m_base_lon,m_base_lat);
		distance_str2.Format("%.2f",distance_jizhan2);
		SetDlgItemText(IDC_EDIT_DISTANCE_BASE2,distance_str2);
		m_pDlg->page1->SetDlgItemText(IDC_EDIT_STATION_DISTANCE,distance_str2);  //辅助操舵界面
	}
}


void CPage_test::OnBnClickedButtonSet()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
}


void CPage_test::OnBnClickedButtonReset()
{
	// TODO: 在此添加控件通知处理程序代码
	distance_sum=0;
	m_real_distance.Format("%lf",distance_sum);
	SetDlgItemText(IDC_EDIT_REAL_DISTANCE,m_real_distance);
}


void CPage_test::OnBnClickedButtonQingling()   
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDlg->wxd_send=0;
	m_pDlg->wxd_recv=0;
	m_pDlg->wxd_error=0;
}


void CPage_test::OnBnClickedButtonSet2() //自动获取自主航行起点重点经纬度
{
	// TODO: 在此添加控件通知处理程序代码
	m_weidu_set=atof(m_pDlg->page_rwyz->m_y1);
	m_jingdu_set=atof(m_pDlg->page_rwyz->m_x1);
	m_m_weidu_set2=atof(m_pDlg->page_rwyz->m_y4);
	m_jingdu_set2=atof(m_pDlg->page_rwyz->m_x4);
	UpdateData(FALSE);
}


void CPage_test::OnBnClickedButtonSet3()  //手动设置趸船经纬度 20180313
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
}


void CPage_test::OnBnClickedButtonSet4()  //自动获取趸船经纬度
{
	// TODO: 在此添加控件通知处理程序代码
    m_base_lat=s_weidu;
	m_base_lon=s_jingdu;
	UpdateData(false);

}


void CPage_test::OnBnClickedCheckSpeedLimit()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CPage_test::OnBnClickedCheckSpeedGradientCtr()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(TRUE);
}


void CPage_test::OnBnClickedButtonSpeedLimitComfirm()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(TRUE);
}


void CPage_test::OnBnClickedButtonSpeedGradientConfirm()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(TRUE);
}
