// Page4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page4.h"
#include "afxdialogex.h"
#include "XiaoBiLiDlg.h"

// CPage4 �Ի���

IMPLEMENT_DYNAMIC(CPage4, CDialogEx)

CPage4::CPage4(CXiaoBiLiDlg* pDlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage4::IDD, pParent)
{
	m_pDlg=pDlg;
	faultType[0]=0;
	faultType[1]=0;
	faultType[2]=0;
	m_imagelist[0]=IDB_BITMAP_GRAY;
	m_imagelist[1]=IDB_BITMAP_GREEN;
	m_imagelist[2]=IDB_BITMAP_RED;
	m_meu_channel_state = _T("");
}

CPage4::~CPage4()
{
}

void CPage4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MEU_CHANNEL_STATE, m_meu_channel_state);
}


BEGIN_MESSAGE_MAP(CPage4, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CPage4 ��Ϣ�������
void CPage4::drawpicture(int m_image_ID, int m_image_num)
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

void CPage4::ShowData()
{
	if((faultType[0]&0x80000000)==0x80000000)
		drawpicture(IDC_PICTURE_PDXTGZ,2);
	else
		drawpicture(IDC_PICTURE_PDXTGZ,0);
	if((faultType[0]&0x40000000)==0x40000000)
		drawpicture(IDC_PICTURE_DDLBJ,2);
	else
		drawpicture(IDC_PICTURE_DDLBJ,0);
	if((faultType[0]&0x20000000)==0x20000000)
		drawpicture(IDC_PICTURE_LDCXTBJ,2);
	else
		drawpicture(IDC_PICTURE_LDCXTBJ,0);
	if((faultType[0]&0x10000000)==0x10000000)
		drawpicture(IDC_PICTURE_600VSDGZ,2);
	else
		drawpicture(IDC_PICTURE_600VSDGZ,0);
	if((faultType[0]&0x08000000)==0x08000000)
		drawpicture(IDC_PICTURE_TJXTGZ,2);
	else
		drawpicture(IDC_PICTURE_TJXTGZ,0);
	if((faultType[0]&0x04000000)==0x04000000)
		drawpicture(IDC_PICTURE_TJQGWBJ,2);
	else
		drawpicture(IDC_PICTURE_TJQGWBJ,0);
	if((faultType[0]&0x02000000)==0x02000000)
		drawpicture(IDC_PICTURE_WKDTXGZ,2);
	else
		drawpicture(IDC_PICTURE_WKDTXGZ,0);
	if((faultType[0]&0x01000000)==0x01000000)
		drawpicture(IDC_PICTURE_FXDTXGZ,2);
	else
		drawpicture(IDC_PICTURE_FXDTXGZ,0);
	if((faultType[0]&0x00800000)==0x00800000)
		drawpicture(IDC_PICTURE_ZWDTXGZ,2);
	else
		drawpicture(IDC_PICTURE_ZWDTXGZ,0);
	if((faultType[0]&0x00400000)==0x00400000)
		drawpicture(IDC_PICTURE_YWDTXGZ,2);
	else
		drawpicture(IDC_PICTURE_YWDTXGZ,0);
	if((faultType[0]&0x00000400)==0x00000400)
		drawpicture(IDC_PICTURE_WKDGWBJ,2);
	else
		drawpicture(IDC_PICTURE_WKDGWBJ,0);
	if((faultType[0]&0x00000200)==0x00000200)
		drawpicture(IDC_PICTURE_FXDGWBJ,2);
	else
		drawpicture(IDC_PICTURE_FXDGWBJ,0);
	if((faultType[0]&0x00000100)==0x00000100)
		drawpicture(IDC_PICTURE_ZWDGWBJ,2);
	else
		drawpicture(IDC_PICTURE_ZWDGWBJ,0);
	if((faultType[0]&0x00000080)==0x00000080)
		drawpicture(IDC_PICTURE_YWDGWBJ,2);
	else
		drawpicture(IDC_PICTURE_YWDGWBJ,0);
	if((faultType[1]&0x08000000)==0x08000000)
		drawpicture(IDC_PICTURE_WKDKD,2);
	else
		drawpicture(IDC_PICTURE_WKDKD,0);
	if((faultType[1]&0x04000000)==0x04000000)
		drawpicture(IDC_PICTURE_FXDKD,2);
	else
		drawpicture(IDC_PICTURE_FXDKD,0);
	if((faultType[1]&0x02000000)==0x02000000)
		drawpicture(IDC_PICTURE_ZWDKD,2);
	else
		drawpicture(IDC_PICTURE_ZWDKD,0);
	if((faultType[1]&0x01000000)==0x01000000)
		drawpicture(IDC_PICTURE_YWDKD,2);
	else
		drawpicture(IDC_PICTURE_YWDKD,0);
	if((faultType[1]&0x00800000)==0x00800000)
		drawpicture(IDC_PICTURE_WDSDKSFD,2);
	else
		drawpicture(IDC_PICTURE_WDSDKSFD,0);
	if((faultType[1]&0x00400000)==0x00400000)
		drawpicture(IDC_PICTURE_WDSDKXQD,2);
	else
		drawpicture(IDC_PICTURE_WDSDKXQD,0);
	if((faultType[1]&0x00200000)==0x00200000)
		drawpicture(IDC_PICTURE_PHINSTXGZ,2);
	else
		drawpicture(IDC_PICTURE_PHINSTXGZ,0);
	if((faultType[1]&0x00100000)==0x00100000)
		drawpicture(IDC_PICTURE_PHINSYXGZ,2);
	else
		drawpicture(IDC_PICTURE_PHINSYXGZ,0);
	if((faultType[1]&0x00080000)==0x00080000)
		drawpicture(IDC_PICTURE_GPSSJWX,2);
	else
		drawpicture(IDC_PICTURE_GPSSJWX,0);
	if((faultType[1]&0x00040000)==0x00040000)
		drawpicture(IDC_PICTURE_SDJSJWX,2);
	else
		drawpicture(IDC_PICTURE_SDJSJWX,0);
	if((faultType[1]&0x00020000)==0x00020000)
		drawpicture(IDC_PICTURE_DVLSJWX,2);
	else
		drawpicture(IDC_PICTURE_DVLSJWX,0);
	if((faultType[1]&0x00010000)==0x00010000)
		drawpicture(IDC_PICTURE_SBGDJSJWX,2);
	else
		drawpicture(IDC_PICTURE_SBGDJSJWX,0);
	if((faultType[1]&0x00008000)==0x00008000)
		drawpicture(IDC_PICTURE_WBGDJSJWX,2);
	else
		drawpicture(IDC_PICTURE_WBGDJSJWX,0);
	if((faultType[1]&0x00004000)==0x00004000)
		drawpicture(IDC_PICTURE_ZQBPSNSJWX,2);
	else
		drawpicture(IDC_PICTURE_ZQBPSNSJWX,0);
	if((faultType[1]&0x00002000)==0x00002000)
		drawpicture(IDC_PICTURE_YQBPSNSJWX,2);
	else
		drawpicture(IDC_PICTURE_YQBPSNSJWX,0);
	if((faultType[1]&0x00001000)==0x00001000)
		drawpicture(IDC_PICTURE_ZHQBPSNSJWX,2);
	else
		drawpicture(IDC_PICTURE_ZHQBPSNSJWX,0);
	if((faultType[1]&0x00000800)==0x00000800)
		drawpicture(IDC_PICTURE_SXZKSSZKYTWTXGZ,2);
	else
		drawpicture(IDC_PICTURE_SXZKSSZKYTWTXGZ,0);
	if((faultType[1]&0x00000400)==0x00000400)
		drawpicture(IDC_PICTURE_SXZKDHDYYTWTXGZ,2);
	else
		drawpicture(IDC_PICTURE_SXZKDHDYYTWTXGZ,0);
	if((faultType[1]&0x00000200)==0x00000200)
		drawpicture(IDC_SXZKYDGHDYYTWTXGZ,2);
	else
		drawpicture(IDC_SXZKYDGHDYYTWTXGZ,0);
	if((faultType[1]&0x00000100)==0x00000100)
		drawpicture(IDC_PICTURE_SXZKJCKZDYYTWTXGZ,2);
	else
		drawpicture(IDC_PICTURE_SXZKJCKZDYYTWTXGZ,0);
	if((faultType[1]&0x00000080)==0x00000080)
		drawpicture(IDC_PICTURE_SXZKDLXTCANTXGZ,2);
	else
		drawpicture(IDC_PICTURE_SXZKDLXTCANTXGZ,0);
	if((faultType[1]&0x00000040)==0x00000040)
		drawpicture(IDC_PICTURE_SXZKCLDYYTWTXGZ,2);
	else
		drawpicture(IDC_PICTURE_SXZKCLDYYTWTXGZ,0);
	if((faultType[1]&0x00000020)==0x00000020)
		drawpicture(IDC_SXZKSHCCDYYTWTXGZ,2);
	else
		drawpicture(IDC_SXZKSHCCDYYTWTXGZ,0);
	if((faultType[1]&0x00000010)==0x00000010)
		drawpicture(IDC_PICTURE_SXZKYJDYYTWTXGZ,2);
	else
		drawpicture(IDC_PICTURE_SXZKYJDYYTWTXGZ,0);
	if((faultType[1]&0x00000008)==0x00000008)
		drawpicture(IDC_PICTURE_CSYWBJ,2);
	else
		drawpicture(IDC_PICTURE_CSYWBJ,0);
	if((faultType[1]&0x00000004)==0x00000004)
		drawpicture(IDC_PICTURE_LSCGQ1BJ,2);
	else
		drawpicture(IDC_PICTURE_LSCGQ1BJ,0);
	if((faultType[1]&0x00000002)==0x00000002)
		drawpicture(IDC_PICTURE_LSCGQ2BJ,2);
	else
		drawpicture(IDC_PICTURE_LSCGQ2BJ,0);
	if((faultType[1]&0x00000001)==0x00000001)
		drawpicture(IDC_PICTURE_LSCGQ3BJ,2);
	else
		drawpicture(IDC_PICTURE_LSCGQ3BJ,0);
	if((faultType[2]&0x80000000)==0x80000000)
		drawpicture(IDC_PICTURE_LSCGQ4BJ,2);
	else
		drawpicture(IDC_PICTURE_LSCGQ4BJ,0);
	if((faultType[2]&0x40000000)==0x40000000)
		drawpicture(IDC_PICTURE_CSGWBJ,2);
	else
		drawpicture(IDC_PICTURE_CSGWBJ,0);
	if((faultType[2]&0x20000000)==0x20000000)
		drawpicture(IDC_PICTURE_CSSDBJ,2);
	else
		drawpicture(IDC_PICTURE_CSSDBJ,0);
	if((faultType[2]&0x10000000)==0x10000000)
		drawpicture(IDC_PICTURE_ZXWDBJ,2);
	else
		drawpicture(IDC_PICTURE_ZXWDBJ,0);
	if((faultType[2]&0x08000000)==0x08000000)
		drawpicture(IDC_PICTURE_ZXZSBJ,2);
	else
		drawpicture(IDC_PICTURE_ZXZSBJ,0);
	if((faultType[2]&0x04000000)==0x04000000)
		drawpicture(IDC_ZXNJBJ,2);
	else
		drawpicture(IDC_ZXNJBJ,0);
	if((faultType[2]&0x02000000)==0x02000000)
		drawpicture(IDC_PICTURE_TYLBJ,2);
	else
		drawpicture(IDC_PICTURE_TYLBJ,0);
	if((faultType[2]&0x01000000)==0x01000000)
		drawpicture(IDC_PICTURE_TZQCSJCX,2);
	else
		drawpicture(IDC_PICTURE_TZQCSJCX,0);
	if((faultType[2]&0x00800000)==0x00800000)
		drawpicture(IDC_PICTURE_TZQCX,2);
	else
		drawpicture(IDC_PICTURE_TZQCX,0);
	if((faultType[2]&0x00400000)==0x00400000)
		drawpicture(IDC_PICTURE_TLDGDCCAQFW,2);
	else
		drawpicture(IDC_PICTURE_TLDGDCCAQFW,0);
	if((faultType[2]&0x00200000)==0x00200000)
		drawpicture(IDC_PICTURE_TJSMSDCCANFW,2);
	else
		drawpicture(IDC_PICTURE_TJSMSDCCANFW,0);
	if((faultType[2]&0x00100000)==0x00100000)
		drawpicture(IDC_TJSMSDCSJZZ,2);
	else
		drawpicture(IDC_TJSMSDCSJZZ,0);
	if((faultType[2]&0x00080000)==0x00080000)
		drawpicture(IDC_PICTURE_CSJCGBZYXFW,2);
	else
		drawpicture(IDC_PICTURE_CSJCGBZYXFW,0);
	if((faultType[2]&0x00040000)==0x00040000)
		drawpicture(IDC_PICTURE_YJDYYDLXTCANTXGZ,2);
	else
		drawpicture(IDC_PICTURE_YJDYYDLXTCANTXGZ,0);
	if((faultType[2]&0x00020000)==0x00020000)
		drawpicture(IDC_PICTURE_YJDYYSXZKCKTXGZ,2);
	else
		drawpicture(IDC_PICTURE_YJDYYSXZKCKTXGZ,0);
	if((faultType[2]&0x00010000)==0x00010000)
		drawpicture(IDC_PICTURE_YJDYYDHDYCKTXGZ,2);
	else
		drawpicture(IDC_PICTURE_YJDYYDHDYCKTXGZ,0);
	if((faultType[2]&0x00008000)==0x00008000)
		drawpicture(IDC_PICTURE_YJDYYSJCCDYCKTXGZ,2);
	else
		drawpicture(IDC_PICTURE_YJDYYSJCCDYCKTXGZ,0);
	if((faultType[2]&0x00004000)==0x00004000)
		drawpicture(IDC_YJDYYJCKZDYCKTXGZ,2);
	else
		drawpicture(IDC_YJDYYJCKZDYCKTXGZ,0);
	//if(((faultType[2]&0x00001000)==0x00001000)||(meu_show_fault.MEUstate==0x02))    //20170429����  ������Ԫ������ʾ
	//	drawpicture(IDC_PICTURE_MEU_FAULT,2);
	//else
	//	drawpicture(IDC_PICTURE_MEU_FAULT,0);
	//if(meu_show_fault.MEUstate==0x00)             //������Ԫ׼����
	//	drawpicture(IDC_PICTURE_MEU_PREPARE,1);
	//else
	//	drawpicture(IDC_PICTURE_MEU_PREPARE,0);
	//if(meu_show_fault.MEUstate==0x01)             //������Ԫ������      
	//	drawpicture(IDC_PICTURE_MEU_WORK,1);
	//else
	//	drawpicture(IDC_PICTURE_MEU_WORK,0);
	//CString str,strtemp;                          //��ʾ����ͨ��
	//if(((faultType[2]&0x00001000)==0x00001000)||(meu_show_fault.MEUstate==0x02))   
	//{
	//	str="����ͨ���У�";
	//	for(int i=0;i<36;i++)
	//	{
	//		if(meu_show_fault.channelState[i]==0x01)
	//		{
	//			strtemp.Format("%02d��",meu_show_fault.channelState[i]);
	//			str+=strtemp;
	//		}
	//	}
	//	m_meu_channel_state=str;
	//}
	//else
	//	m_meu_channel_state="�޹���";
	EMU_Fault_Analysis();
	UpdateData(FALSE);
}

BOOL CPage4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPage4::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ShowData();
	CDialogEx::OnTimer(nIDEvent);
}
void  CPage4::EMU_Fault_Analysis()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str,strtemp;
	str="���Ͻ�����";
	if((faultType[0]==0)&&(faultType[1]==0)&&(faultType[2]==0))
	{
		str+="�޹���";
		m_pDlg->page1->pdata_page1->fault_light_state=0;  //���ؽ������ָʾ��
	}
	else
	{
		m_pDlg->page1->pdata_page1->fault_light_state=1;  //���ؽ������ָʾ��
		if(faultType[0]!=0)
		{
			if((faultType[0]&0x80000000)==0x80000000)
				str+="���ϵͳ����,";
			if((faultType[0]&0x40000000)==0x40000000)
				str+="�͵�������,";
			if((faultType[0]&0x20000000)==0x20000000)
				str+="﮵��ϵͳ����,";
			if((faultType[0]&0x10000000)==0x10000000)
				str+="600vʧ�����,";
			if((faultType[0]&0x08000000)==0x08000000)
				str+="�ƽ�ϵͳ����,";
			if((faultType[0]&0x04000000)==0x04000000)
				str+="�ƽ������±���,";
			if((faultType[0]&0x02000000)==0x02000000)
				str+="Χ�Ƕ�ͨ�Ź���,";
			if((faultType[0]&0x01000000)==0x01000000)

				str+="�����ͨ�Ź���,";
			if((faultType[0]&0x00800000)==0x00800000)
				str+="��Χ��ͨ�Ź���,";
			if((faultType[0]&0x00400000)==0x00400000)
				str+="��Χ��ͨ�Ź���,";
			if((faultType[0]&0x00000400)==0x00000400)
				str+="Χ�Ƕ���±���,";
			if((faultType[0]&0x00000200)==0x00000200)
				str+="�������±���,";
			if((faultType[0]&0x00000100)==0x00000100)
				str+="��������±���,";

			if((faultType[0]&0x0000080)==0x00000080)
				str+="��������±���,";

		}
		if(faultType[1]!=0)
		{

			if((faultType[1]&0x08000000)==0x08000000)
				str+="Χ�Ƕ濨��,";
			if((faultType[1]&0x04000000)==0x04000000)
				str+="����濨��,";
			if((faultType[1]&0x02000000)==0x02000000)
				str+="�����濨��,";
			if((faultType[1]&0x01000000)==0x01000000)
				str+="�����濨��,";

			if((faultType[1]&0x00800000)==0x00800000)
				str+="����˫�濨�ϸ���,";
			if((faultType[1]&0x00400000)==0x00400000)
				str+="����˫�濨��Ǳ���趨�Ƕ�,";
			if((faultType[1]&0x00200000)==0x00200000)
				str+="PHINSͨ�Ź���,";
			if((faultType[1]&0x00100000)==0x00100000)
				str+="PHINS���й���,";
			if((faultType[1]&0x00080000)==0x00080000)
				str+="GPS������Ч,";
			if((faultType[1]&0x00040000)==0x00040000)
				str+="��ȼ�������Ч,";
			if((faultType[1]&0x00020000)==0x00020000)
				str+="DVL������Ч,";
			if((faultType[1]&0x00010000)==0x00010000)
				str+="�����߶ȼ�������Ч,";

			if((faultType[1]&0x00008000)==0x00008000)
				str+="�����߶ȼ�������Ч,";
			if((faultType[1]&0x00004000)==0x00004000)
				str+="��ǰ��������������Ч,";
			if((faultType[1]&0x00002000)==0x00002000)
				str+="��ǰ��������������Ч,";
			if((faultType[1]&0x00001000)==0x00001000)
				str+="��ǰ��������������Ч,";
			if((faultType[1]&0x00000800)==0x00000800)
				str+="ˮ��������ˮ����������ͨ�Ź���,";
			if((faultType[1]&0x00000400)==0x00000400)
				str+="ˮ�������뵼������ͨ�Ź���,";
			if((faultType[1]&0x00000200)==0x00000200)
				str+="ˮ���������˶��滮����ͨ�Ź���,";
			if((faultType[1]&0x00000100)==0x00000100)
				str+="ˮ�������������������ͨ�Ź���,";

			if((faultType[1]&0x0000080)==0x00000080)
				str+="ˮ�������붯��ϵͳCANͨ�Ź���,";
			if((faultType[1]&0x0000040)==0x00000040)
				str+="ˮ�������������Ԫ����ͨ�Ź���,";
			if((faultType[1]&0x0000020)==0x00000020)
				str+="ˮ�����������ݴ洢����ͨ�Ź���,";
			if((faultType[1]&0x0000010)==0x00000010)
				str+="ˮ��������Ӧ������ͨ�Ź��ϣ�";
			if((faultType[1]&0x0000008)==0x00000008)
				str+="����������,";
			if((faultType[1]&0x0000004)==0x00000004)
				str+="©ˮ������1����,";
			if((faultType[1]&0x0000002)==0x00000002)
				str+="©ˮ������2����,";
			if((faultType[1]&0x0000001)==0x00000001)
				str+="©ˮ������3����,";

		}
		if(faultType[2]!=0)
		{
			if((faultType[2]&0x80000000)==0x80000000)
				str+="©ˮ������3����,";
			if((faultType[2]&0x40000000)==0x40000000)
				str+="���Ҹ��±�����";
			if((faultType[2]&0x20000000)==0x20000000)
				str+="����ʪ�ȱ���,";
			if((faultType[2]&0x10000000)==0x10000000)
				str+="��ϵ�¶ȱ���,";
			if((faultType[2]&0x08000000)==0x08000000)
				str+="��ϵת�ٱ���,";
			if((faultType[2]&0x04000000)==0x04000000)
				str+="��ϵŤ�ر���,";
			if((faultType[2]&0x02000000)==0x02000000)
				str+="��ѹ������,";
			if((faultType[2]&0x01000000)==0x01000000)
				str+="ͧ����ǳ�ʱ�䳬����ȫ��Χ,";

			if((faultType[2]&0x00800000)==0x00800000)
				str+="ͧ����ǳ������޷�Χ,";
			if((faultType[2]&0x00400000)==0x00400000)
				str+="ͧ��׸߶ȳ�����ȫ��Χ,";
			if((faultType[2]&0x00200000)==0x00200000)
				str+="ͧ��ˮ����ȳ�����ȫ��Χ,";
			if((faultType[2]&0x00100000)==0x00100000)
				str+="ͧ��ˮ����ȳ�ʱ������,";
			if((faultType[2]&0x00080000)==0x00080000)
				str+="��ʱ�䳬����������Χ,";
			if((faultType[2]&0x00040000)==0x00040000)
				str+="Ӧ����Ԫ�붯��ϵͳCANͨ�Ź���,";
			if((faultType[2]&0x00020000)==0x00020000)
				str+="Ӧ����Ԫ��ˮ�����ش���ͨ�Ź���,";
			if((faultType[2]&0x00010000)==0x00010000)
				str+="Ӧ����Ԫ�뵼����Ԫ����ͨ�Ź���,";

			if((faultType[2]&0x00008000)==0x00008000)
				str+="Ӧ����Ԫ�����ݴ洢����ͨ�Ź���,";
			if((faultType[2]&0x00004000)==0x00004000)
				str+="Ӧ����Ԫ��������ƴ���ͨ�Ź���,";
			if((faultType[2]&0x00002000)==0x00002000)
				str+="ˮ��������Ӧ����Ԫ��̫��ͨ�Ź���,";

		}
	}

	m_pDlg->page1->SetDlgItemTextA(IDC_EDIT_FAULT_ANALYZE,str);
}
