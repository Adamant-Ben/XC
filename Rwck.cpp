// Rwck.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Rwck.h"
#include "afxdialogex.h"
#include "Cpage1.h"

// CRwck �Ի���

IMPLEMENT_DYNAMIC(CRwck, CDialogEx)

CRwck::CRwck(Cpage1* p_page1,CWnd* pParent /*=NULL*/)
	: CDialogEx(CRwck::IDD, pParent)
{
	m_page1=p_page1;
	m_rw1 = _T("");
	m_rw2 = _T("");
	m_rw3 = _T("");
}

CRwck::~CRwck()
{
}

void CRwck::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RW1, m_rw1);
	DDX_Text(pDX, IDC_EDIT_RW2, m_rw2);
	DDX_Text(pDX, IDC_EDIT_RW3, m_rw3);
}


BEGIN_MESSAGE_MAP(CRwck, CDialogEx)
END_MESSAGE_MAP()


// CRwck ��Ϣ�������


BOOL CRwck::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_rw1=m_page1->str1;
	m_rw2=m_page1->str2;
	m_rw3=m_page1->str3;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
