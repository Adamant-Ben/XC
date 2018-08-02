// Cpage2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Cpage2.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"
#include <sys/timeb.h>
// Cpage2 �Ի���

IMPLEMENT_DYNAMIC(Cpage2, CDialogEx)

Cpage2::Cpage2(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage2::IDD, pParent)
{

	thrusterSpeed_t=0;
	m_pDlg=pDlg;
	//  m_djsszs = 0;
	//  m_djssgl = 0;
	//  m_djwd = 0;
	//  m_bpqbj = 0;
	//  m_bpqgz = 0;
	//  m_dczzdy = 0;
	//  m_dczcfddl = 0;
	m_dczpjwd = 0;
	m_ldcsoc = 0;
	m_bmssmxh = 0;
	m_dczgzdm = 0;
	//  m_dtzddy1 = 0;
	//  m_dtzddy2 = 0;
	//  m_dtzgdy1 = 0;
	//  m_dtzgdy2 = 0;
	m_dczdwd1 = 0;
	m_dczdwd1xtbh = 0;
	m_dczdwd2 = 0;
	m_dczdwd2xtbh = 0;
	m_dczgwd2 = 0;
	m_dczgwd2xtbh = 0;
	m_dczgwd1xtbh = 0;
	m_dczgwd1 = 0;
	m_imagelist[0] = IDB_BITMAP_GRAY;
	m_imagelist[1] = IDB_BITMAP_GREEN;
	m_imagelist[2] = IDB_BITMAP_RED;
	int m_image[45]={IDC_PICTURE_LDCJXZT,IDC_PICTURE_PDXTZT,IDC_PICTURE_DDLBJ,IDC_PICTURE_LDCXTBJ,IDC_PICTURE_600SDGZ,IDC_PICTURE_TJXTJX,IDC_PICTURE_TJXTZT,IDC_PICTURE_BPQJX,IDC_PICTURE_BPQYXZT,IDC_PICTURE_BPQGLXZ,IDC_PICTURE_BPQGZ,IDC_PICTURE_BPQBJ,
		IDC_PICTURE_FU1ZT,IDC_PICTURE_FU7ZT,IDC_PICTURE_FU8ZT,IDC_PICTURE_FU9ZT,IDC_PICTURE_FU10ZT,IDC_PICTURE_FU20ZT,IDC_PICTURE_FU21ZT,IDC_PICTURE_KM1ZT,IDC_PICTURE_KM2ZT,IDC_PICTURE_KM3ZT,IDC_PICTURE_KM4ZT,IDC_PICTURE_KM5ZT,IDC_PICTURE_KM6ZT,
		IDC_PICTURE_KM7ZT,IDC_PICTURE_KM8ZT,IDC_PICTURE_KM9ZT,IDC_PICTURE_KM10ZT,IDC_PICTURE_KM11ZT,IDC_PICTURE_PS1ZT,IDC_PICTURE_PS2ZT,IDC_PICTURE_PS3ZT,IDC_PICTURE_PS4ZT,IDC_PICTURE_PS5ZT,IDC_PICTURE_PS6ZT,IDC_PICTURE_PS7ZT,IDC_PICTURE_PS8ZT,
		IDC_PICTURE_PS9ZT,IDC_PICTURE_PS10ZT,IDC_PICTURE_PS11ZT,IDC_PICTURE_PS12ZT,IDC_PICTURE_PS13ZT,IDC_PICTURE_PS14ZT,IDC_PICTURE_PS15ZT};
	for(int i=0;i<45;i++)
		m_showimage[i]=m_image[i];
	CTime time=CTime::GetCurrentTime();
	CString strtemp=time.Format("%Y%m%d_%H.%M.%S.txt");
	CString str="Record_"+strtemp;
	CString str1="Record_ZS_"+strtemp;
	/*char *pa;
	pa=(char*)malloc(str.GetLength()+1);
	strcpy_s(pa,str.GetLength()+1,str);
	const char* pb=pa;
	file=ofstream(pb,ios::app);
	free(pa);
	char *pc;
	pc=(char*)malloc(str1.GetLength()+1);
	strcpy_s(pc,str1.GetLength()+1,str1);
	const char* pd=pc;
	file_zs=ofstream(pd,ios::app);
	free(pc);*/
		power_infor_page2=(POWER_INFO*)malloc(sizeof(POWER_INFO));  //20170514
	memset(power_infor_page2,0,sizeof(POWER_INFO));
	//prcu_info_page2=(PRCU_INFO*)malloc(sizeof(PRCU_INFO));
	//memset(prcu_info_page2,0,sizeof(PRCU_INFO));
	m_bpqgz = _T("");
	m_bpqbj = _T("");
	m_djsszs = 0.0f;
	m_djssgl = 0.0f;
	m_djwd = 0.0f;
	m_dczzdy = 0.0f;
	m_dczcfddl = 0.0f;
	m_dtzddy1 = 0.0f;
	m_dtzddy2 = 0.0f;
	m_dtzgdy1 = 0.0f;
	m_dtzgdy2 = 0.0f;
	m_djsdzs = 0.0f;
	//  m_speed_limit = 0;
	m_speed_limit = 0;
	m_qsdcdy = 0.0f;
	m_charge_calculate = _T("");
}

Cpage2::~Cpage2()
{
	m_pDlg=NULL;
	//file.close();
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_DJSSZS, m_djsszs);
	//  DDX_Text(pDX, IDC_EDIT_DJSSGL, m_djssgl);
	//  DDX_Text(pDX, IDC_EDIT_DJWD, m_djwd);
	//  DDX_Text(pDX, IDC_EDIT_BPQBJ, m_bpqbj);
	//  DDX_Text(pDX, IDC_EDIT_BPQGZ, m_bpqgz);
	//  DDX_Text(pDX, IDC_EDIT_DCZZDY, m_dczzdy);
	//  DDX_Text(pDX, IDC_EDIT_DCZCFDDL, m_dczcfddl);
	DDX_Text(pDX, IDC_EDIT_DCZPJWD, m_dczpjwd);
	DDX_Text(pDX, IDC_EDIT_LDCSOC, m_ldcsoc);
	DDX_Text(pDX, IDC_EDIT_BMSSMXH, m_bmssmxh);
	DDX_Text(pDX, IDC_EDIT_DCZGZDM, m_dczgzdm);
	//  DDX_Text(pDX, IDC_EDIT_DTZDDY1, m_dtzddy1);
	//  DDX_Text(pDX, IDC_EDIT_DTZDDY2, m_dtzddy2);
	//  DDX_Text(pDX, IDC_EDIT_DTZGDY1, m_dtzgdy1);
	//  DDX_Text(pDX, IDC_EDIT_DTZGDY2, m_dtzgdy2);
	//  DDX_Text(pDX, IDC_EDIT_DCZGWN1, m_dczdwd1);
	//  DDX_Text(pDX, IDC_EDIT_DCZGWD1XTBH, m_dczdwd1xtbh);
	DDX_Text(pDX, IDC_EDIT_DCZDWD1, m_dczdwd1);
	DDX_Text(pDX, IDC_EDIT_DCZDWD1XTBH, m_dczdwd1xtbh);
	DDX_Text(pDX, IDC_EDIT_DCZDWD2, m_dczdwd2);
	DDX_Text(pDX, IDC_EDIT_DCZDWD2XTBH, m_dczdwd2xtbh);
	DDX_Text(pDX, IDC_EDIT_DCZGWD2, m_dczgwd2);
	DDX_Text(pDX, IDC_EDIT_DCZGWD2XTBH, m_dczgwd2xtbh);
	DDX_Text(pDX, IDC_EDIT_DCZGWD1XTBH, m_dczgwd1xtbh);
	DDX_Text(pDX, IDC_EDIT_DCZGWD1, m_dczgwd1);
	DDX_Control(pDX, IDC_TCHART1, m_chart);
	DDX_Text(pDX, IDC_EDIT_BPQGZ, m_bpqgz);
	DDX_Text(pDX, IDC_EDIT_BPQBJ, m_bpqbj);
	DDX_Text(pDX, IDC_EDIT_DJSSZS, m_djsszs);
	DDX_Text(pDX, IDC_EDIT_DJSSGL, m_djssgl);
	DDX_Text(pDX, IDC_EDIT_DJWD, m_djwd);
	DDX_Text(pDX, IDC_EDIT_DCZZDY, m_dczzdy);
	DDX_Text(pDX, IDC_EDIT_DCZCFDDL, m_dczcfddl);
	DDX_Text(pDX, IDC_EDIT_DTZDDY1, m_dtzddy1);
	DDX_Text(pDX, IDC_EDIT_DTZDDY2, m_dtzddy2);
	DDX_Text(pDX, IDC_EDIT_DTZGDY1, m_dtzgdy1);
	DDX_Text(pDX, IDC_EDIT_DTZGDY2, m_dtzgdy2);
	DDX_Text(pDX, IDC_EDIT_DJSDZS, m_djsdzs);
	//  DDX_Text(pDX, IDC_EDIT_SPEED_LIMIT, m_speed_limit);
	//  DDV_MinMaxShort(pDX, m_speed_limit, -1500, 1500);
	DDX_Text(pDX, IDC_EDIT_SPEED_LIMIT, m_speed_limit);
	DDV_MinMaxShort(pDX, m_speed_limit, -1500, 1500);
	DDX_Text(pDX, IDC_EDIT_QSDCDY, m_qsdcdy);
	DDX_Text(pDX, IDC_EDIT_CHARGE_CALCULATE, m_charge_calculate);
}


BEGIN_MESSAGE_MAP(Cpage2, CDialogEx)
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_PICTURE_KM7ZT, &Cpage2::OnStnClickedPictureKm7zt)
	ON_BN_CLICKED(IDC_BUTTON_SPEED_LIMIT, &Cpage2::OnBnClickedButtonSpeedLimit)
END_MESSAGE_MAP()


// Cpage2 ��Ϣ�������
void Cpage2::drawpicture(int m_image_ID, int m_image_num)
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

void Cpage2::ShowData()
{

	//CString str,strtemp,str1,strtemp1;
	//str="";
	//strtemp="";
	//CTime time = CTime::GetCurrentTime();
	//strtemp=time.Format("%Y-%m-%d %H:%M:%S");
	//str+=strtemp;
	//strtemp1=strtemp;
	//struct _timeb timebuffer;    
	//_ftime64_s(&timebuffer);
	//strtemp.Format(":%d",timebuffer.millitm);
	//str+=strtemp+"\r\n";
	//str+="����R_932\r\n";
	BAS bas;
	bas.by[0]=power_infor_page2->powerSystem_r932.motorSpeedLow;
	bas.by[1]=power_infor_page2->powerSystem_r932.motorSpeedHigh;
	m_djsszs=(float)(bas.s)*1500/0x4000;
	CString str_djsszs;//������������
	str_djsszs.Format("%f",m_djsszs);
	m_pDlg->page1->SetDlgItemText(IDC_EDIT_DJZS_FB,str_djsszs);   //���ؽ�����ʾ20180722
	//strtemp.Format("%f",m_djsszs);
	//str+="���ʵʱת��:"+strtemp;
	//str1=strtemp+",";
	//str1+=strtemp1;
	bas.by[0]=power_infor_page2->powerSystem_r932.motorPowerLow;
	bas.by[1]=power_infor_page2->powerSystem_r932.motorPowerHigh;
	m_djssgl=(float)(bas.s)*148/0x4000;
	//strtemp.Format("%f",m_djssgl);
	//str+=" ���ʵʱ����:"+strtemp;
	bas.by[0]=power_infor_page2->powerSystem_r932.motorTemperatureLow;
	bas.by[1]=power_infor_page2->powerSystem_r932.motorTemperatureHigh;
	m_djwd=bas.s*100/0x4000;   //ֻ��ʾ��������
	//strtemp.Format("%f",m_djwd);
	//str+=" ����¶�:"+strtemp+"\r\n";
	if((power_infor_page2->powerSystem_r932.liBatteryState&0x01)==0x01)
	{drawpicture(m_showimage[0],1);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[0],0);/*strtemp="δ����";*/}
	//str+="﮵�ؾ���״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r932.liBatteryState&0x02)==0x02)
	{drawpicture(m_showimage[1],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[1],0);/*strtemp="����";*/}
	//str+=" ���ϵͳ״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r932.liBatteryState&0x04)==0x04)
	{drawpicture(m_showimage[2],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[2],0);/*strtemp="����";*/}
	//str+=" �͵���������"+strtemp;
	if((power_infor_page2->powerSystem_r932.liBatteryState&0x08)==0x08)
	{drawpicture(m_showimage[3],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[3],0);/*strtemp="����";*/}
	//str+=" ﮵��ϵͳ������"+strtemp;
	if((power_infor_page2->powerSystem_r932.liBatteryState&0x10)==0x10)
	{drawpicture(m_showimage[4],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[4],0);/*strtemp="����";*/}
	//str+=" 600vʧ����ϣ�"+strtemp+"\r\n";
	if((power_infor_page2->powerSystem_r932.thrusterSystemState&0x01)==0x01)
	{drawpicture(m_showimage[5],1);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[5],0);/*strtemp="δ����";*/}
	//str+="�ƽ�ϵͳ������"+strtemp;
	if((power_infor_page2->powerSystem_r932.thrusterSystemState&0x02)==0x02)
	{drawpicture(m_showimage[6],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[6],0);/*strtemp="����";*/}
	//str+=" �ƽ�ϵͳ״̬��"+strtemp+"\r\n";
	//str+="����R_933\r\n";
	if((power_infor_page2->powerSystem_r933.frequencyConverterState&0x01)==0x01)
	{drawpicture(m_showimage[7],1);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[7],0);/*strtemp="δ����";*/}
	//str+="��Ƶ��������"+strtemp;
	if((power_infor_page2->powerSystem_r933.frequencyConverterState&0x02)==0x02)
	{drawpicture(m_showimage[8],1);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[8],0);/*strtemp="δ����";*/}
	//str+=" ��Ƶ������״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r933.frequencyConverterState&0x04)==0x04)
	{drawpicture(m_showimage[9],1);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[9],0);/*strtemp="δ����";*/}
	//str+=" ��Ƶ���������ƣ�"+strtemp;
	if((power_infor_page2->powerSystem_r933.frequencyConverterState&0x08)==0x08)
	{drawpicture(m_showimage[10],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[10],0);/*strtemp="����";*/}
	//str+=" ��Ƶ�����ϣ�"+strtemp;
	if((power_infor_page2->powerSystem_r933.frequencyConverterState&0x10)==0x10)
	{drawpicture(m_showimage[11],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[11],0);/*strtemp="����";*/}
	//str+=" ��Ƶ��������"+strtemp+"\r\n";
	bas.by[0]=power_infor_page2->powerSystem_r933.frequencyConverterAlarmLow;
	bas.by[1]=power_infor_page2->powerSystem_r933.frequencyConverterAlarmHigh;
	m_bpqbj.Format("%02X",bas.s);
	m_pDlg->page1->SetDlgItemText(IDC_EDIT_BPQ_WARN_FB,m_bpqbj);   //���ؽ�����ʾ20180722
	//strtemp=m_bpqbj;
	//str+="��Ƶ��������"+strtemp;
	bas.by[0]=power_infor_page2->powerSystem_r933.frequencyConverterFaultLow;
	bas.by[1]=power_infor_page2->powerSystem_r933.frequencyConverterFaultHigh;
	m_bpqgz.Format("%02X",bas.s);
	m_pDlg->page1->SetDlgItemText(IDC_EDIT_BPQ_FAULT_FB,m_bpqgz);   //���ؽ�����ʾ20180722
	//strtemp=m_bpqgz;
	//str+=" ��Ƶ�����ϣ�"+strtemp+"\r\n";
	//str+="����R_934\r\n";
	if((power_infor_page2->powerSystem_r934.fuseProtectorState&0x01)==0x01)
	{drawpicture(m_showimage[12],2);/*strtemp="�۶�";*/}
	else
	{drawpicture(m_showimage[12],1);/*strtemp="����";*/}
	//str+="FU1״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.fuseProtectorState&0x02)==0x02)
	{drawpicture(m_showimage[13],2);/*strtemp="�۶�";*/}
	else
	{drawpicture(m_showimage[13],1);/*strtemp="����";*/}
	//str+=" FU7״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.fuseProtectorState&0x04)==0x04)
	{drawpicture(m_showimage[14],2);/*strtemp="�۶�";*/}
	else
	{drawpicture(m_showimage[14],1);/*strtemp="����";*/}
	//str+=" FU8״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.fuseProtectorState&0x08)==0x08)
	{drawpicture(m_showimage[15],2);/*strtemp="�۶�";*/}
	else
	{drawpicture(m_showimage[15],1);/*strtemp="����";*/}
	//str+=" FU9״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.fuseProtectorState&0x10)==0x10)
	{drawpicture(m_showimage[16],2);/*strtemp="�۶�";*/}
	else
	{drawpicture(m_showimage[16],1);/*strtemp="����";*/}
	//str+=" FU10״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.fuseProtectorState&0x20)==0x20)
	{drawpicture(m_showimage[17],2);/*strtemp="�۶�";*/}
	else
	{drawpicture(m_showimage[17],1);/*strtemp="����";*/}
	//str+=" FU20״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.fuseProtectorState&0x40)==0x40)
	{drawpicture(m_showimage[18],2);/*strtemp="�۶�";*/}
	else
	{drawpicture(m_showimage[18],1);/*strtemp="����";*/}
	//str+=" FU21״̬��"+strtemp+"\r\n";
	if((power_infor_page2->powerSystem_r934.switchState1&0x01)==0x01)
	{drawpicture(m_showimage[19],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[19],0);/*strtemp="��բ";*/}
	//str+="KM1״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState1&0x02)==0x02)
	{drawpicture(m_showimage[20],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[20],0);/*strtemp="��բ";*/}
	//str+=" KM2״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState1&0x04)==0x04)
	{drawpicture(m_showimage[21],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[21],0);/*strtemp="��բ";*/}
	//str+=" KM3״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState1&0x08)==0x08)
	{drawpicture(m_showimage[22],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[22],0);/*strtemp="��բ";*/}
	//str+=" KM4״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState1&0x10)==0x10)
	{drawpicture(m_showimage[23],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[23],0);/*strtemp="��բ";*/}
	//str+=" KM5״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState1&0x20)==0x20)
	{drawpicture(m_showimage[24],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[24],0);/*strtemp="��բ";*/}
	//str+=" KM6״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState1&0x40)==0x40)
	{drawpicture(m_showimage[25],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[25],0);/*strtemp="��բ";*/}
	//str+=" KM7״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState1&0x80)==0x80)
	{drawpicture(m_showimage[26],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[26],0);/*strtemp="��բ";*/}
	//str+=" KM8״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState2&0x01)==0x01)
	{drawpicture(m_showimage[27],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[27],0);/*strtemp="��բ";*/}
	//str+=" KM9״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState2&0x02)==0x02)
	{drawpicture(m_showimage[28],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[28],0);/*strtemp="��բ";*/}
	//str+=" KM10״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.switchState2&0x04)==0x04)
	{drawpicture(m_showimage[29],1);/*strtemp="��բ";*/}
	else
	{drawpicture(m_showimage[29],0);/*strtemp="��բ";*/}
	//str+=" KM11״̬��"+strtemp+"\r\n";
	if((power_infor_page2->powerSystem_r934.powerState1&0x01)==0x01)
	{drawpicture(m_showimage[30],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[30],0);/*strtemp="����";*/}
	//str+="PS1״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState1&0x02)==0x02)
	{drawpicture(m_showimage[31],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[31],0);/*strtemp="����";*/}
	//str+=" PS2״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState1&0x04)==0x04)
	{drawpicture(m_showimage[32],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[32],0);/*strtemp="����";*/}
	//str+=" PS3״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState1&0x08)==0x08)
	{drawpicture(m_showimage[33],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[33],0);/*strtemp="����";*/}
	//str+=" PS4״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState1&0x10)==0x10)
	{drawpicture(m_showimage[34],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[34],0);/*strtemp="����";*/}
	//str+=" PS5״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState1&0x20)==0x20)
	{drawpicture(m_showimage[35],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[35],0);/*strtemp="����";*/}
	//str+=" PS6״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState1&0x40)==0x40)
	{drawpicture(m_showimage[36],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[36],0);/*strtemp="����";*/}
	//str+=" PS7״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState1&0x80)==0x80)
	{drawpicture(m_showimage[37],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[37],0);/*strtemp="����";*/}
	//str+=" PS8״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState2&0x01)==0x01)
	{drawpicture(m_showimage[38],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[38],0);/*strtemp="����";*/}
	//str+=" PS9״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState2&0x02)==0x02)
	{drawpicture(m_showimage[39],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[39],0);/*strtemp="����";*/}
	//str+=" PS10״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState2&0x04)==0x04)
	{drawpicture(m_showimage[40],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[40],0);/*strtemp="����";*/}
	//str+=" PS11״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState2&0x08)==0x08)
		{drawpicture(m_showimage[41],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[41],0);/*strtemp="����";*/}
	//str+=" PS12״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState2&0x10)==0x10)
		{drawpicture(m_showimage[42],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[42],0);/*strtemp="����";*/}
	//str+=" PS13״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState2&0x20)==0x20)
		{drawpicture(m_showimage[43],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[43],0);/*strtemp="����";*/}
	//str+=" PS14״̬��"+strtemp;
	if((power_infor_page2->powerSystem_r934.powerState2&0x40)==0x40)
	{drawpicture(m_showimage[44],2);/*strtemp="����";*/}
	else
	{drawpicture(m_showimage[44],0);/*strtemp="����";*/}
	//str+=" PS15״̬��"+strtemp+"\r\n";
	bas.by[0]=power_infor_page2->powerSystem_r934.fullChar1;  //20171013 Ǧ���ص�ѹ
	bas.by[1]=power_infor_page2->powerSystem_r934.fullChar2;
	m_qsdcdy=(float)(bas.s)*30/32767;
	m_charge_calculate=Charge_Calculate(m_qsdcdy);   //Ǧ����ʣ���ʹ��ʱ�����
	CString Str_qsdy;
	Str_qsdy.Format("%.2f",m_qsdcdy);
	m_pDlg->page1->SetDlgItemText(IDC_EDIT_PLUMBICACID_VOLTAGE,Str_qsdy); //���ؽ�����ʾ20180727
	//str+="����R_935\r\n";
	bas.by[0]=power_infor_page2->powerSystem_r935.batteryTotalVoltageLow;  
	bas.by[1]=power_infor_page2->powerSystem_r935.batteryTotalVoltageHigh;
	m_dczzdy=(float)(bas.s)*0.1;
	//str+=" PS15״̬��"+strtemp+"\r\n";
	//strtemp.Format("%f",m_dczzdy);
	//str+="������ܵ�ѹ��"+strtemp;
	bas.by[0]=power_infor_page2->powerSystem_r935.batteryCurrentLow;
	bas.by[1]=power_infor_page2->powerSystem_r935.batteryCurrentHigh;
	m_dczcfddl=(float)(bas.s)*0.1-3200;
	//strtemp.Format("%f",m_dczcfddl);
	//str+=" ������ŵ������"+strtemp;
	m_dczpjwd=(power_infor_page2->powerSystem_r935.batteryAverageTemperature)-40;
	//strtemp.Format("%d",m_dczpjwd);
	//str+=" �����ƽ���¶ȣ�"+strtemp;
	m_ldcsoc=power_infor_page2->powerSystem_r935.liBatterySOC; 
	CString LDCSOC_str;
	LDCSOC_str.Format("%d",m_ldcsoc);
	m_pDlg->page1->SetDlgItemText(IDC_EDIT_LITHIUM_SOC,LDCSOC_str); //���ؽ�����ʾ20180722
	//str+=" ﮵��SOC��"+strtemp;
	m_bmssmxh=power_infor_page2->powerSystem_r935.BMSLifeSignal;  
	CString BMS_str;
	BMS_str.Format("%d",m_bmssmxh);
	m_pDlg->page1->SetDlgItemText(IDC_EDIT_POW_BMS,BMS_str); //���ؽ�����ʾ20180722
	//strtemp.Format("%d",m_bmssmxh);
	//str+=" BMS�����źţ�"+strtemp;
	m_dczgzdm=power_infor_page2->powerSystem_r935.batteryFaultCode;
	//strtemp.Format("%d",m_dczgzdm);
	//str+=" �������ϴ��룺"+strtemp+"\r\n";
	//str+="����R_936\r\n";
	bas.by[0]=power_infor_page2->powerSystem_r936.monosomeLowVoltage1Low;
	bas.by[1]=power_infor_page2->powerSystem_r936.monosomeLowVoltage1High;
	m_dtzddy1=(float)(bas.s)*0.01;
	//strtemp.Format("%f",m_dtzddy1);
	//str+="������͵�ѹ1��"+strtemp;
	bas.by[0]=power_infor_page2->powerSystem_r936.monosomeLowVoltage2Low;
	bas.by[1]=power_infor_page2->powerSystem_r936.monosomeLowVoltage2High;
	m_dtzddy2=(float)(bas.s)*0.01;
	//strtemp.Format("%f",m_dtzddy2);
	//str+=" ������͵�ѹ2��"+strtemp;
	bas.by[0]=power_infor_page2->powerSystem_r936.monosomeHighVoltage1Low;
	bas.by[1]=power_infor_page2->powerSystem_r936.monosomeHighVoltage1High;
	m_dtzgdy1=(float)(bas.s)*0.01;
	//strtemp.Format("%f",m_dtzgdy1);
	//str+=" ������ߵ�ѹ1��"+strtemp;
	bas.by[0]=power_infor_page2->powerSystem_r936.monosomeHighVoltage2Low;
	bas.by[1]=power_infor_page2->powerSystem_r936.monosomeHighVoltage2High;
	m_dtzgdy2=(float)(bas.s)*0.01;
	//strtemp.Format("%f",m_dtzgdy2);
	//str+=" ������ߵ�ѹ2��"+strtemp+"\r\n";
	//str+="����R_937\r\n";
	m_dczdwd1=(power_infor_page2->powerSystem_r937.batteryLowTemperature1-40);
	//strtemp.Format("%d",m_dczdwd1);
	//str+="�������¶ȵ�1��"+strtemp;
	m_dczdwd1xtbh=power_infor_page2->powerSystem_r937.batteryLowTemperature1BoxNo;
	//strtemp.Format("%d",m_dczdwd1xtbh);
	//str+=" �������¶ȵ�1���������ţ�"+strtemp;
	m_dczdwd2=(power_infor_page2->powerSystem_r937.batteryLowTemperature2-40);
	//strtemp.Format("%d",m_dczdwd2);
	//str+=" �������¶ȵ�2��"+strtemp;
	m_dczdwd2xtbh=power_infor_page2->powerSystem_r937.batteryLowTemperature2BoxNo;
	//strtemp.Format("%d",m_dczdwd2xtbh);
	//str+=" �������¶ȵ�2���������ţ�"+strtemp;
	m_dczgwd1=(power_infor_page2->powerSystem_r937.batteryHighTemperature1-40);
	//strtemp.Format("%d",m_dczgwd1);
	//str+=" �������¶ȵ�1��"+strtemp;
	m_dczgwd1xtbh=power_infor_page2->powerSystem_r937.batteryHighTemperature1BoxNo;
	//strtemp.Format("%d",m_dczgwd1xtbh);
	//str+=" �������¶ȵ�1���������ţ�"+strtemp;
	m_dczgwd2=(power_infor_page2->powerSystem_r937.batteryHighTemperature2-40);
	//strtemp.Format("%d",m_dczgwd2);
	//str+=" �������¶ȵ�2��"+strtemp;
	m_dczgwd2xtbh=power_infor_page2->powerSystem_r937.batteryHighTemperature2BoxNo;
	/*strtemp.Format("%d",m_dczgwd2xtbh);
	str+=" �������¶ȵ�2���������ţ�"+strtemp+"\r\n";
	str+="�������Ƶ�Ԫ��������";
	str+="\r\n";
	strtemp.Format("%d ",m_pDlg->pdata_r30->operatorcmd.thrusterSpeedCmd*1500/0x4000);
	str+="ת�ٸ���ֵ��"+strtemp;
	strtemp.Format("%d ",m_djsszs);
	str+="ת�ٷ���ֵ��"+strtemp;
	strtemp.Format("%d ",m_pDlg->pdata_r30->primaryControlUnitInfo.shaftingTorque);
	str+="ת�أ�"+strtemp;
	strtemp.Format("%d ",m_pDlg->pdata_r30->primaryControlUnitInfo.shaftingRollingSpeed);
	str+="��ϵת�٣�"+strtemp;
	strtemp.Format("%d ",m_pDlg->pdata_r30->primaryControlUnitInfo.pushPressure);
	str+="��ѹ����"+strtemp;
	strtemp.Format("%d ",m_pDlg->pdata_r30->primaryControlUnitInfo.ringPressure);
	str+="����ѹ����"+strtemp+"\r\n\r\n";
	file<<str<<endl;
	file_zs<<str1<<endl;*/
	thrusterSpeed_t++;
    line_thrusterSpeed.AddXY((double)thrusterSpeed_t,m_djsszs,NULL,NULL);
	//m_djsdzs=m_pDlg->page1->m_tjqzs;
	UpdateData(FALSE);
}

BOOL Cpage2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	line_thrusterSpeed = (CSeries)m_chart.Series(0);
	line_thrusterSpeed.Clear();
	line_thrusterSpeed.AddXY(0.0,0.0,NULL,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void Cpage2::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ShowData();
	CDialogEx::OnTimer(nIDEvent);
}

void Cpage2::ShowData_R306()
{
	if((m_pDlg->pdata_r306->powerSupplySysStatus&0x01)==0x01)
		drawpicture(IDC_PICTURE_LDCJXZT,1);
	else
		drawpicture(IDC_PICTURE_LDCJXZT,0);
	if((m_pDlg->pdata_r306->powerSupplySysStatus&0x02)==0x02)
		drawpicture(IDC_PICTURE_PDXTZT,2);
	else
		drawpicture(IDC_PICTURE_PDXTZT,0);
	if((m_pDlg->pdata_r306->powerSupplySysStatus&0x04)==0x04)
		drawpicture(IDC_PICTURE_DDLBJ,2);
	else
		drawpicture(IDC_PICTURE_DDLBJ,0);
	if((m_pDlg->pdata_r306->powerSupplySysStatus&0x08)==0x08)
		drawpicture(IDC_PICTURE_LDCXTBJ,2);
	else
		drawpicture(IDC_PICTURE_LDCXTBJ,0);
	if((m_pDlg->pdata_r306->powerSupplySysStatus&0x10)==0x10)
		drawpicture(IDC_PICTURE_600SDGZ,2);
	else
		drawpicture(IDC_PICTURE_600SDGZ,0);
	if((m_pDlg->pdata_r306->thrusterSysStatus&0x01)==0x01)
		drawpicture(IDC_PICTURE_TJXTJX,1);
	else
		drawpicture(IDC_PICTURE_TJXTJX,0);
	if((m_pDlg->pdata_r306->thrusterSysStatus&0x02)==0x02)
		drawpicture(IDC_PICTURE_TJXTZT,2);
	else
		drawpicture(IDC_PICTURE_TJXTZT,0);
}

void Cpage2::SetTimer1()
{
	SetTimer(1,T_S03,NULL);
}

void Cpage2::OnStnClickedPictureKm7zt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL Cpage2::PreTranslateMessage(MSG* pMsg)
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


void Cpage2::OnBnClickedButtonSpeedLimit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
}
CString Cpage2::Charge_Calculate(float c)
{
  float charge=c;
  CString c_str;
  double c_temp;
  if(charge>=23.326)
  {
     c_str="���㣨210 min��";
  }
  else
  if(charge>=21.64095)
  {
    c_temp=28.33193487*charge*charge*charge*charge
    -2488.03866693*charge*charge*charge
    +81939.03459571*charge*charge
    -1199350.03114*charge+6582932;
	c_str.Format("�������ʣ��ʱ��%.3fmin",c_temp);
  }
  else
  if(charge>=18.49)
  {
    c_temp=-1.7135406903*charge*charge*charge*charge*charge*charge
		+206.0706374251*charge*charge*charge*charge*charge
    -10317.8547305298*charge*charge*charge*charge
    +275308.052757491*charge*charge*charge
    -4128791.04066723*charge*charge
    +32996795.2188089*charge-109786574.883105;
	c_str.Format("�ѹ���%.3fmin",c_temp);
  }
  else   //charge<18.49
  {
    c_str="�����ع���";
  }
  return c_str;

}
