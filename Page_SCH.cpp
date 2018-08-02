// Page_SCH.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page_SCH.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"


// CPage_SCH 对话框

IMPLEMENT_DYNAMIC(CPage_SCH, CDialogEx)

CPage_SCH::CPage_SCH(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage_SCH::IDD, pParent)
{
	m_pDlg=pDlg;
	//  m_tjqzs = 0.0f;
	//  m_fxddj = 0.0f;
	//  m_wkddj = 0.0f;
	//  m_ywddj = 0.0f;
	//  m_zwddj = 0.0f;
	//  m_zqtj = 0.0f;
	//  m_zwddj = 0.0f;
	m_imagelist[0] = IDB_BITMAP_GRAY;
	m_imagelist[1] = IDB_BITMAP_GREEN;
	m_imagelist[2] = IDB_BITMAP_RED;
}

CPage_SCH::~CPage_SCH()
{
}

void CPage_SCH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_TJQZS, m_tjqzs);
	//  DDX_Text(pDX, IDC_EDIT_FXDDJ, m_fxddj);
	//  DDX_Text(pDX, IDC_EDIT_WKDDJ, m_wkddj);
	//  DDX_Text(pDX, IDC_EDIT_YWDDJ, m_ywddj);
	//  DDX_Text(pDX, IDC_EDIT_ZQTJ, m_zwddj);
	//  DDX_Text(pDX, IDC_EDIT_ZQTJ, m_zqtj);
	//  DDX_Text(pDX, IDC_EDIT_ZWDDJ, m_zwddj);
}


BEGIN_MESSAGE_MAP(CPage_SCH, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CPage_SCH 消息处理程序


void CPage_SCH::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent==1)
		ShowData_Schcmd();
	CDialogEx::OnTimer(nIDEvent);
}
void CPage_SCH::drawpicture(int m_image_ID, int m_image_num)
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
void CPage_SCH::ShowData_Schcmd()
{
	if((m_pDlg->pdata_r10->workingStage)==0x00)    //手操盒控件显示
		drawpicture(IDC_PICTURE_TEST,1);
	else
		drawpicture(IDC_PICTURE_TEST,0);
	if((m_pDlg->pdata_r10->workingStage)==0x01)
		drawpicture(IDC_PICTURE_DATA_UPLOAD,1);
	else
		drawpicture(IDC_PICTURE_DATA_UPLOAD,0);
	if((m_pDlg->pdata_r10->workingMode)==0x00)
		drawpicture(IDC_PICTURE_REMOTE,1);
	else
		drawpicture(IDC_PICTURE_REMOTE,0);
	if((m_pDlg->pdata_r10->workingMode)==0x01)
		drawpicture(IDC_PICTURE_AUTO,1);
	else
		drawpicture(IDC_PICTURE_AUTO,0);
	if(((m_pDlg->pdata_r10->powerSwitch)&0x01)==0x01)
		drawpicture(IDC_PICTURE_600V,1);
	else
		drawpicture(IDC_PICTURE_600V,0);
	if(((m_pDlg->pdata_r10->powerSwitch)&0x02)==0x02)
		drawpicture(IDC_PICTURE_HUILU34,1);
	else
		drawpicture(IDC_PICTURE_HUILU34,0);
	if(((m_pDlg->pdata_r10->powerSwitch)&0x04)==0x04)
		drawpicture(IDC_PICTURE_HUILU5,1);
	else
		drawpicture(IDC_PICTURE_HUILU5,0);
	if(((m_pDlg->pdata_r10->powerSwitch)&0x08)==0x08)
		drawpicture(IDC_PICTURE_HUILU6,1);
	else
		drawpicture(IDC_PICTURE_HUILU6,0);
	//if(((m_pDlg->pdata_r10->powerSwitch)&0x10)==0x10)
	//	drawpicture(m_showimage[8],1);
	//else
	//	drawpicture(m_showimage[8],0);
	if(((m_pDlg->pdata_r10->powerSwitch)&0x20)==0x20)
		drawpicture(IDC_PICTURE_BPQ_START,1);
	else
		drawpicture(IDC_PICTURE_BPQ_START,0);
	if(((m_pDlg->pdata_r10->powerSwitch)&0x40)==0x40)
		drawpicture(IDC_PICTURE_BPQ_STOP,1);
	else
		drawpicture(IDC_PICTURE_BPQ_STOP,0);
	if(((m_pDlg->pdata_r10->powerSwitch)&0x80)==0x80)
		drawpicture(IDC_PICTURE_BPQ_RESET,1);
	else
		drawpicture(IDC_PICTURE_BPQ_RESET,0);
	if(((m_pDlg->pdata_r10->emergencyEnable)&0x01)==0x01)
		drawpicture(IDC_PICTURE_EM_INTERPOSE,1);
	else
		drawpicture(IDC_PICTURE_EM_INTERPOSE,0);
	if(((m_pDlg->pdata_r10->emergencyCmd)&0x01)==0x01)
		drawpicture(IDC_PICTURE_EM_STOP,1);
	else
		drawpicture(IDC_PICTURE_EM_STOP,0);
	if(((m_pDlg->pdata_r10->emergencyCmd)&0x02)==0x02)
		drawpicture(IDC_PICTURE_EM_FLOATE,1);
	else
		drawpicture(IDC_PICTURE_EM_FLOATE,0);
	if(((m_pDlg->pdata_r10->emergencyCmd)&0x04)==0x04)
		drawpicture(IDC_PICTURE_EM_AIRBAG,1);
	else
		drawpicture(IDC_PICTURE_EM_AIRBAG,0);
	if(((m_pDlg->pdata_r10->emergencyCmd)&0x08)==0x08)
		drawpicture(IDC_PICTURE_EM_CABLE,1);
	else
		drawpicture(IDC_PICTURE_EM_CABLE,0);
	if((m_pDlg->pdata_r10->electricPushRodCmd&0x01)==0x01)
		drawpicture(IDC_PICTURE_WKD,1);
	else
		drawpicture(IDC_PICTURE_WKD,0);
	if((m_pDlg->pdata_r10->electricPushRodCmd&0x02)==0x02)
		drawpicture(IDC_PICTURE_FXD,1);
	else
		drawpicture(IDC_PICTURE_FXD,0);
	if((m_pDlg->pdata_r10->electricPushRodCmd&0x04)==0x04)
		drawpicture(IDC_PICTURE_ZWD,1);
	else
		drawpicture(IDC_PICTURE_ZWD,0);
	if((m_pDlg->pdata_r10->electricPushRodCmd&0x08)==0x08)
		drawpicture(IDC_PICTURE_YWD,1);
	else
		drawpicture(IDC_PICTURE_YWD,0);
	if((m_pDlg->pdata_r10->emergencyCmd&0x03)==0x03)
		drawpicture(IDC_PICTURE_EMCMD_ERROR,2);
	else
		drawpicture(IDC_PICTURE_EMCMD_ERROR,0);
	CString temp_str; 
	temp_str.Format("%f",((m_pDlg->pdata_r10->trimCmd)*0.01+4.0)-12.0);
	SetDlgItemText(IDC_EDIT_ZQTJ_SCH,temp_str);
		temp_str.Format("%f",(m_pDlg->pdata_r10->thrusterSpeedCmd)*1.5);  //-1500~1500
	SetDlgItemText(IDC_EDIT_TJQZS_SCH,temp_str);
		temp_str.Format("%f",(m_pDlg->pdata_r10->fairwaterRudderAngle)*0.1); 
	SetDlgItemText(IDC_EDIT_WKDDJ_SCH,temp_str);
		temp_str.Format("%f",(m_pDlg->pdata_r10->rudderAngle)*0.1);  
	SetDlgItemText(IDC_EDIT_FXDDJ_SCH,temp_str);
		temp_str.Format("%f",(m_pDlg->pdata_r10->leftRearRudderAngle)*(-0.1));  
	SetDlgItemText(IDC_EDIT_ZWDDJ_SCH,temp_str);
		temp_str.Format("%f",(m_pDlg->pdata_r10->rightRearRudderAngle)*(-0.1));  
	SetDlgItemText(IDC_EDIT_YWDDJ_SCH,temp_str);

}

BOOL CPage_SCH::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
		SetTimer(1,500,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
