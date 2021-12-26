// RectangleDlg.cpp: 实现文件
//

#include "pch.h"
#include "201916010728.h"
#include "RectangleDlg.h"
#include "afxdialogex.h"


// RectangleDlg 对话框

IMPLEMENT_DYNAMIC(RectangleDlg, CDialog)

RectangleDlg::RectangleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, LUX(_T(""))
	, LUY(_T(""))
	, RDX(_T(""))
	, RDY(_T(""))
{

}

RectangleDlg::~RectangleDlg()
{
}

void RectangleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LUx, LUX);
	DDX_Text(pDX, IDC_LUy, LUY);
	DDX_Text(pDX, IDC_RDx, RDX);
	DDX_Text(pDX, IDC_RDy, RDY);
}


BEGIN_MESSAGE_MAP(RectangleDlg, CDialog)
END_MESSAGE_MAP()


// RectangleDlg 消息处理程序
