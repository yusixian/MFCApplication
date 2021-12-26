// TransformDlg.cpp: 实现文件
//

#include "pch.h"
#include "201916010728.h"
#include "TransformDlg.h"
#include "afxdialogex.h"


// TransformDlg 对话框

IMPLEMENT_DYNAMIC(TransformDlg, CDialog)

TransformDlg::TransformDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG7, pParent)
	, angle(_T(""))
	, sx(_T(""))
	, sy(_T(""))
	, tx(_T(""))
	, ty(_T(""))
{

}

TransformDlg::~TransformDlg()
{
}

void TransformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Angle, angle);
	DDX_Text(pDX, IDC_sx, sx);
	DDX_Text(pDX, IDC_sy, sy);
	DDX_Text(pDX, IDC_tx, tx);
	DDX_Text(pDX, IDC_ty, ty);
}


BEGIN_MESSAGE_MAP(TransformDlg, CDialog)
END_MESSAGE_MAP()


// TransformDlg 消息处理程序
