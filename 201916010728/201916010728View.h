
// 201916010728View.h: CMy201916010728View 类的接口
//

#pragma once
#include <GL\glut.h>
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

protected:
	HGLRC m_hRC;//Rendering Context着色描述表
	CClientDC* m_pDC; //Device Context设备描述表

	int m_wide; //视口的宽度
	int m_heigth;//视口的高度
	BOOL InitializeOpenGL();
	//初始化OpenGL
	BOOL SetupPixelFormat();//设置像素格式
	void RenderScene();//绘制场景
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	BOOL OnEraseBkgnd(CDC* pDC);
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
	afx_msg void OnDrawBall();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	void reshape(int w, int h);
	void display();
};

#ifndef _DEBUG  // 201916010728View.cpp 中的调试版本
inline CMy201916010728Doc* CMy201916010728View::GetDocument() const
   { return reinterpret_cast<CMy201916010728Doc*>(m_pDocument); }
#endif

