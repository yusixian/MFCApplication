// TriangleDlg.cpp: 实现文件
//

#include "pch.h"
#include "201916010728.h"
#include "TriangleDlg.h"
#include "afxdialogex.h"


// TriangleDlg 对话框

IMPLEMENT_DYNAMIC(TriangleDlg, CDialog)

TriangleDlg::TriangleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, x1(_T(""))
	, x2(_T(""))
	, x3(_T(""))
	, y1(_T(""))
	, y2(_T(""))
	, y3(_T(""))
{

}

TriangleDlg::~TriangleDlg()
{
}

void TriangleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_x1, x1);
	DDX_Text(pDX, IDC_x2, x2);
	DDX_Text(pDX, IDC_x3, x3);
	DDX_Text(pDX, IDC_y1, y1);
	DDX_Text(pDX, IDC_y2, y2);
	DDX_Text(pDX, IDC_y3, y3);
}


BEGIN_MESSAGE_MAP(TriangleDlg, CDialog)
END_MESSAGE_MAP()


// TriangleDlg 消息处理程序
