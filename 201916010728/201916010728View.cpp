
// 201916010728View.cpp: CMy201916010728View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "201916010728.h"
#endif

#include "201916010728Doc.h"
#include "201916010728View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy201916010728View

IMPLEMENT_DYNCREATE(CMy201916010728View, CView)

BEGIN_MESSAGE_MAP(CMy201916010728View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy201916010728View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy201916010728View 构造/析构

CMy201916010728View::CMy201916010728View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy201916010728View::~CMy201916010728View()
{
}

BOOL CMy201916010728View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy201916010728View 绘图

void CMy201916010728View::OnDraw(CDC* /*pDC*/)
{
	CMy201916010728Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy201916010728View 打印


void CMy201916010728View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy201916010728View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy201916010728View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy201916010728View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy201916010728View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy201916010728View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy201916010728View 诊断

#ifdef _DEBUG
void CMy201916010728View::AssertValid() const
{
	CView::AssertValid();
}

void CMy201916010728View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy201916010728Doc* CMy201916010728View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy201916010728Doc)));
	return (CMy201916010728Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy201916010728View 消息处理程序
