#pragma once


// TriangleDlg 对话框

class TriangleDlg : public CDialog
{
	DECLARE_DYNAMIC(TriangleDlg)

public:
	TriangleDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TriangleDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString x1;
	CString x2;
	CString x3;
	CString y1;
	CString y2;
	CString y3;
};
