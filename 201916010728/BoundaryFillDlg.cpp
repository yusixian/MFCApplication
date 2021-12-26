// BoundaryFillDlg.cpp: 实现文件
//

#include "pch.h"
#include "201916010728.h"
#include "BoundaryFillDlg.h"
#include "afxdialogex.h"


// BoundaryFillDlg 对话框

IMPLEMENT_DYNAMIC(BoundaryFillDlg, CDialog)

BoundaryFillDlg::BoundaryFillDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG6, pParent)
	, LUX(_T(""))
	, LUY(_T(""))
	, RDX(_T(""))
	, RDY(_T(""))
	, SX(_T(""))
	, SY(_T(""))
{

}

BoundaryFillDlg::~BoundaryFillDlg()
{
}

void BoundaryFillDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LUx, LUX);
	DDX_Text(pDX, IDC_LUy, LUY);
	DDX_Text(pDX, IDC_RDx, RDX);
	DDX_Text(pDX, IDC_RDy, RDY);
	DDX_Text(pDX, IDC_sx, SX);
	DDX_Text(pDX, IDC_sy, SY);
}


BEGIN_MESSAGE_MAP(BoundaryFillDlg, CDialog)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// BoundaryFillDlg 消息处理程序
