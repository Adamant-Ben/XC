#pragma once
#include <fstream>
#include "tchart1.h"
#include "CSeries.h"
#include "packetProc.h"
using namespace std;
class CXiaoBiLiDlg;

// Cpage2 对话框

class Cpage2 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage2)

public:
	Cpage2(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage2();
	CXiaoBiLiDlg* m_pDlg;
// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	short m_djsszs;
//	short m_djssgl;
//	short m_djwd;
	CString m_bpqgz;
	CString m_bpqbj;
//	short m_dczzdy;
//	short m_dczcfddl;
	int m_dczpjwd;
	BYTE m_ldcsoc;
	BYTE m_bmssmxh;
	BYTE m_dczgzdm;
//	short m_dtzddy1;
//	short m_dtzddy2;
//	short m_dtzgdy1;
//	short m_dtzgdy2;
//	BYTE m_dczdwd1;
//	BYTE m_dczdwd1xtbh;
	BYTE m_dczdwd1;
	BYTE m_dczdwd1xtbh;
	BYTE m_dczdwd2;
	BYTE m_dczdwd2xtbh;
	BYTE m_dczgwd2;
	BYTE m_dczgwd2xtbh;
	BYTE m_dczgwd1xtbh;
	BYTE m_dczgwd1;
public:
	int m_imagelist[3];
	int m_showimage[50];
	//ofstream file;
	//ofstream file_zs;
	POWER_INFO *power_infor_page2; //20170514  动力系统状态显示界面状态显示结构体
	//PRCU_INFO *prcu_info_page2;     //基础控制单元显示结构体
private:
	void drawpicture(int m_image_ID, int m_image_num);
public:
	void ShowData();
	void ShowData_R306();
	void SetTimer1();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CTchart1 m_chart;
public:
	int thrusterSpeed_t;
	CSeries line_thrusterSpeed;
	afx_msg void OnStnClickedPictureKm7zt();

	float m_djsszs;
	float m_djssgl;
	float m_djwd;
	float m_dczzdy;
	float m_dczcfddl;
	float m_dtzddy1;
	float m_dtzddy2;
	float m_dtzgdy1;
	float m_dtzgdy2;
	float m_djsdzs;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	short m_speed_limit;
	afx_msg void OnBnClickedButtonSpeedLimit();
	short m_speed_limit;
	float m_qsdcdy;
	CString m_charge_calculate;
	CString Charge_Calculate(float c);
};
