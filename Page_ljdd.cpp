// Page_ljdd.cpp : 实现文件
//

#include "stdafx.h"
#include "XiaoBiLi.h"
#include "Page_ljdd.h"
#include "afxdialogex.h"


// CPage_ljdd 对话框

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


// CPage_ljdd 消息处理程序


BOOL CPage_ljdd::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
    {
        // 如果消息是键盘按下事件，且是Esc键，执行以下代码（什么都不做，你可以自己添加想要的代码）
        return TRUE;
    }
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        // 如果消息是键盘按下事件，且是Entert键，执行以下代码（什么都不做，你可以自己添加想要的代码）
        return TRUE;
    }

	return CDialogEx::PreTranslateMessage(pMsg);
}
