#pragma once


// RectangleDlg 对话框

class RectangleDlg : public CDialog
{
	DECLARE_DYNAMIC(RectangleDlg)

public:
	RectangleDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RectangleDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString LUX;
	CString LUY;
	CString RDX;
	CString RDY;
};
