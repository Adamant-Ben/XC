#pragma once


// CPag_Password �Ի���

class CPag_Password : public CDialogEx
{
	DECLARE_DYNAMIC(CPag_Password)

public:
	CPag_Password(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPag_Password();

// �Ի�������
	enum { IDD = IDD_DIALOG_PAASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_password;
	CEdit m_password_ctr;
};
