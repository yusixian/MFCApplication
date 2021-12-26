
// 201916010728View.h: CMy201916010728View 类的接口
//

#pragma once
#include "CircleDlg.h"
#include "LineDlg.h"
#include "RectangleDlg.h"
#include "TriangleDlg.h"
#include "PolyDlg.h"
#include "BoundaryFillDlg.h"
#include "TransformDlg.h"

#include "PolyStruct.h"
#include "CTransform.h"
#define Round(d) int(floor(d+0.5)) 
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
public:
	afx_msg void OnCdcLine();
	afx_msg void OnCdcTriangle();
	afx_msg void OnCdcCircle();
	afx_msg void OnCdcRectangle();
	afx_msg void OnCdcPainting();
	afx_msg void OnDDA();
	afx_msg void OnLineMid();
	afx_msg void OnBresenham();
	afx_msg void OnPolyScan();
	void polyScanDraw(point* ptr, int col);
	void Bfs(int x, int y, int col, int edgeCol, CDC* pDC);
	afx_msg void OnBoundaryFill();
	afx_msg void OnTransform();
};

#ifndef _DEBUG  // 201916010728View.cpp 中的调试版本
inline CMy201916010728Doc* CMy201916010728View::GetDocument() const
   { return reinterpret_cast<CMy201916010728Doc*>(m_pDocument); }
#endif

