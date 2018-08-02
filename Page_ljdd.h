#pragma once


// CPage_ljdd 对话框

class CPage_ljdd : public CDialogEx
{
	DECLARE_DYNAMIC(CPage_ljdd)

public:
	CPage_ljdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage_ljdd();

// 对话框数据
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString m_msg_str;
};
