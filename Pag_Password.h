#pragma once


// CPag_Password 对话框

class CPag_Password : public CDialogEx
{
	DECLARE_DYNAMIC(CPag_Password)

public:
	CPag_Password(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPag_Password();

// 对话框数据
	enum { IDD = IDD_DIALOG_PAASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_password;
	CEdit m_password_ctr;
};
