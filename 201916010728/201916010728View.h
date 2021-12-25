
// 201916010728View.h: CMy201916010728View 类的接口
//

#pragma once


class CMy201916010728View : public CView
{
protected: // 仅从序列化创建
	CMy201916010728View() noexcept;
	DECLARE_DYNCREATE(CMy201916010728View)

// 特性
public:
	CMy201916010728Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy201916010728View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 201916010728View.cpp 中的调试版本
inline CMy201916010728Doc* CMy201916010728View::GetDocument() const
   { return reinterpret_cast<CMy201916010728Doc*>(m_pDocument); }
#endif

