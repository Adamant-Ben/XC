// Pag_Password.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Pag_Password.h"
#include "afxdialogex.h"


// CPag_Password �Ի���

IMPLEMENT_DYNAMIC(CPag_Password, CDialogEx)

CPag_Password::CPag_Password(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPag_Password::IDD, pParent)
{

	m_password = _T("");
}

CPag_Password::~CPag_Password()
{
}

void CPag_Password::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_password_ctr);
}


BEGIN_MESSAGE_MAP(CPag_Password, CDialogEx)
END_MESSAGE_MAP()


// CPag_Password ��Ϣ�������
