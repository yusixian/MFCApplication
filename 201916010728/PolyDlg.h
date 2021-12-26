#pragma once


// PolyDlg 对话框

class PolyDlg : public CDialog
{
	DECLARE_DYNAMIC(PolyDlg)

public:
	PolyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PolyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString x1;
	CString x2;
	CString x3;
	CString x4;
	CString x5;
	CString x6;
	CString y1;
	CString y2;
	CString y3;
	CString y4;
	CString y5;
	CString y6;
};
