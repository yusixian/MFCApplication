// PolyDlg.cpp: 实现文件
//

#include "pch.h"
#include "201916010728.h"
#include "PolyDlg.h"
#include "afxdialogex.h"


// PolyDlg 对话框

IMPLEMENT_DYNAMIC(PolyDlg, CDialog)

PolyDlg::PolyDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG5, pParent)
	, x1(_T(""))
	, x2(_T(""))
	, x3(_T(""))
	, x4(_T(""))
	, x5(_T(""))
	, x6(_T(""))
	, y1(_T(""))
	, y2(_T(""))
	, y3(_T(""))
	, y4(_T(""))
	, y5(_T(""))
	, y6(_T(""))
{

}

PolyDlg::~PolyDlg()
{
}

void PolyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_x1, x1);
	DDX_Text(pDX, IDC_x2, x2);
	DDX_Text(pDX, IDC_x3, x3);
	DDX_Text(pDX, IDC_x4, x4);
	DDX_Text(pDX, IDC_x5, x5);
	DDX_Text(pDX, IDC_x6, x6);
	DDX_Text(pDX, IDC_y1, y1);
	DDX_Text(pDX, IDC_y2, y2);
	DDX_Text(pDX, IDC_y3, y3);
	DDX_Text(pDX, IDC_y4, y4);
	DDX_Text(pDX, IDC_y5, y5);
	DDX_Text(pDX, IDC_y6, y6);
}


BEGIN_MESSAGE_MAP(PolyDlg, CDialog)
END_MESSAGE_MAP()


// PolyDlg 消息处理程序
