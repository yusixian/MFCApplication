#pragma once


// LineDlg 对话框

class LineDlg : public CDialog
{
	DECLARE_DYNAMIC(LineDlg)

public:
	LineDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LineDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ex;
	CString ey;
	CString sx;
	CString sy;
};
