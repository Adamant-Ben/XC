// Page_ljdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page_ljdd.h"
#include "afxdialogex.h"


// CPage_ljdd �Ի���

IMPLEMENT_DYNAMIC(CPage_ljdd, CDialogEx)

CPage_ljdd::CPage_ljdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage_ljdd::IDD, pParent)
{

	m_msg_str = _T("");
}

CPage_ljdd::~CPage_ljdd()
{
}

void CPage_ljdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_STATIC_CAPTION, m_msg_str);
}


BEGIN_MESSAGE_MAP(CPage_ljdd, CDialogEx)
END_MESSAGE_MAP()


// CPage_ljdd ��Ϣ�������


BOOL CPage_ljdd::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
    {
        // �����Ϣ�Ǽ��̰����¼�������Esc����ִ�����´��루ʲô��������������Լ������Ҫ�Ĵ��룩
        return TRUE;
    }
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        // �����Ϣ�Ǽ��̰����¼�������Entert����ִ�����´��루ʲô��������������Լ������Ҫ�Ĵ��룩
        return TRUE;
    }

	return CDialogEx::PreTranslateMessage(pMsg);
}
