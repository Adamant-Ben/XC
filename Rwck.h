#pragma once

// CRwck 对话框
class Cpage1;
class CRwck : public CDialogEx
{
	DECLARE_DYNAMIC(CRwck)

public:
	CRwck(Cpage1* p_page1,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRwck();

// 对话框数据
	enum { IDD = IDD_DIALOG_RWCK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_rw1;
	CString m_rw2;
	CString m_rw3;
	Cpage1* m_page1;
	virtual BOOL OnInitDialog();
};
