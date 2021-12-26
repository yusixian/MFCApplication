#pragma once


// TransformDlg 对话框

class TransformDlg : public CDialog
{
	DECLARE_DYNAMIC(TransformDlg)

public:
	TransformDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TransformDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString angle;
	CString sx;
	CString sy;
	CString tx;
	CString ty;
};
