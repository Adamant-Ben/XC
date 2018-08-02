#pragma once
#include"packetProc.h"
class CXiaoBiLiDlg;

// CPage4 对话框
/*typedef struct
{
	bool fault_pdxt;
	bool fault_ddl;
	bool fault_ldcxt;
	bool fault_600vsx;
	bool fault_tjxt;
	bool fault_tjqgw;
	bool fault_wkdtx;
	bool fault_fxdtx;
	bool fault_zwdtx;
	bool fault_ywdtx;
	bool fault_wkdfxdtx;
	bool fault_wkdwd1tx;
	bool fault_wkdwd2tx;
	bool fault_fxdwd1tx;
	bool fault_fxdwd2tx;
	bool fault_wd1wd2tx;
	bool fault_wkdfxdwd1tx;
	bool fault_wkdfxdwd2tx;
	bool fault_wkdwd1wd2tx;
	bool fault_fxdwd1wd2tx;
	bool fault_wkdfxdwd1wd2tx;
	bool fault_dj1gw;
	bool fault_dj2gw;
	bool fault_dj3gw;
	bool fault_dj4gw;
	bool fault_dj1dj2gw;
	bool fault_dj1dj3gw;
	bool fault_dj1dj4gw;
	bool fault_dj2dj3gw;
	bool fault_dj2dj4gw;
	bool fault_dj3dj4gw;
	bool fault_dj1dj2dj3gw;
	bool fault_dj1dj2dj4gw;
	bool fault_dj1dj3dj4gw;
	bool fault_dj2dj3dj4gw;
	bool fault_dj1dj2dj3dj4gw;
	bool fault_wkdkd;
	bool fault_fxdkd;
	bool fault_wd1kd;
	bool fault_wd2kd;
	bool fault_wdsdksfd;
	bool fault_wdsdkxqdsdjd;
	bool fault_phinstx;
	bool fault_phinsyx;
	bool fault_gpssjwx;
	bool fault_sdjsjwx;
	bool fault_dvlsjwx;
	bool fault_sbgdjsjwx;
	bool fault_wbgdjsjwx;
	bool fault_zqbpsnsjwx;
	bool fault_yqbpsnsjwx;
	bool fault_zhqbpsnsjwx;
	bool fault_sxzkshzkytwtx;  
	bool fault_sxzkdhytwtx;
	bool fault_sxzkydghytwtx;
	bool fault_sxzkjckzytwtx;
	bool fault_sxzkdlxtcantx;
	bool fault_sxzkcldyytwtx;
	bool fault_sxzksjccytwtx;
}Data_page4;*/

class CPage4 : public CDialogEx
{
	DECLARE_DYNAMIC(CPage4)

public:
	CPage4(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage4();
	CXiaoBiLiDlg* m_pDlg;
	UINT faultType[3];
	MEU_INFO meu_show_fault;
	int m_imagelist[3];
	void drawpicture(int m_image_ID, int m_image_num);
	void ShowData();
// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedPictureSbgdjsjwx();
	CString m_meu_channel_state;
    void  EMU_Fault_Analysis();
};
