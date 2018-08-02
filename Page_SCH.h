#pragma once
class CXiaoBiLiDlg;
#include "packetProc.h"

// CPage_SCH 对话框

class CPage_SCH : public CDialogEx
{
	DECLARE_DYNAMIC(CPage_SCH)

public:
	CPage_SCH(CXiaoBiLiDlg* pDlg,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage_SCH();

// 对话框数据
	enum { IDD = IDD_DIALOG_SCH };
public:
	CXiaoBiLiDlg* m_pDlg;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	float m_tjqzs;
//	float m_fxddj;
//	float m_wkddj;
//	float m_ywddj;
//	float m_zwddj;
//	float m_zqtj;
//	float m_zwddj;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void drawpicture(int m_image_ID, int m_image_num);
	void ShowData_Schcmd();
	int m_imagelist[3];
	virtual BOOL OnInitDialog();
};
