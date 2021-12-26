#pragma once


// CircleDlg 对话框

class CircleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CircleDlg)

public:
	CircleDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CircleDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString r;
	CString x;
	CString y;
};
