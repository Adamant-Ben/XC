#pragma once


// CPage_ljdd �Ի���

class CPage_ljdd : public CDialogEx
{
	DECLARE_DYNAMIC(CPage_ljdd)

public:
	CPage_ljdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage_ljdd();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString m_msg_str;
};
