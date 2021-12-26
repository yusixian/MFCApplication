// CircleDlg.cpp: 实现文件
//

#include "pch.h"
#include "201916010728.h"
#include "CircleDlg.h"
#include "afxdialogex.h"


// CircleDlg 对话框

IMPLEMENT_DYNAMIC(CircleDlg, CDialogEx)

CircleDlg::CircleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, r(_T(""))
	, x(_T(""))
	, y(_T(""))
{

}

CircleDlg::~CircleDlg()
{
}

void CircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_r, r);
	DDX_Text(pDX, IDC_x, x);
	DDX_Text(pDX, IDC_y, y);
}


BEGIN_MESSAGE_MAP(CircleDlg, CDialogEx)
END_MESSAGE_MAP()


// CircleDlg 消息处理程序
