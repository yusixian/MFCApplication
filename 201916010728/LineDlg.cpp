// LineDlg.cpp: 实现文件
//

#include "pch.h"
#include "201916010728.h"
#include "LineDlg.h"
#include "afxdialogex.h"


// LineDlg 对话框

IMPLEMENT_DYNAMIC(LineDlg, CDialog)

LineDlg::LineDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, ex(_T(""))
	, ey(_T(""))
	, sx(_T(""))
	, sy(_T(""))
{

}

LineDlg::~LineDlg()
{
}

void LineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ex, ex);
	DDX_Text(pDX, IDC_ey, ey);
	DDX_Text(pDX, IDC_sx, sx);
	DDX_Text(pDX, IDC_sy, sy);
}


BEGIN_MESSAGE_MAP(LineDlg, CDialog)
END_MESSAGE_MAP()


// LineDlg 消息处理程序
