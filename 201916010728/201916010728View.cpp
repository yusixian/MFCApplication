
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
	ON_COMMAND(ID_CDC32771, &CMy201916010728View::OnCdcLine)
	ON_COMMAND(ID_CDC32772, &CMy201916010728View::OnCdcTriangle)
	ON_COMMAND(ID_CDC32774, &CMy201916010728View::OnCdcCircle)
	ON_COMMAND(ID_CDC32773, &CMy201916010728View::OnCdcRectangle)
	ON_COMMAND(ID_CDC32775, &CMy201916010728View::OnCdcPainting)
	ON_COMMAND(ID_32776, &CMy201916010728View::OnDDA)
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

void CMy201916010728View::OnCdcLine()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int sx, sy, ex, ey;
	LineDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		sx = _wtoi(inputDlg.sx.GetBuffer(0));
		sy = _wtoi(inputDlg.sy.GetBuffer(0));
		ex = _wtoi(inputDlg.ex.GetBuffer(0));
		ey = _wtoi(inputDlg.ey.GetBuffer(0));
	}
	else return;
	pDC->MoveTo(sx, sy);
	pDC->LineTo(ex, ey);
}


void CMy201916010728View::OnCdcTriangle()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int x1, y1, x2, y2, x3, y3;
	TriangleDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		x1 = _wtoi(inputDlg.x1.GetBuffer(0));
		y1 = _wtoi(inputDlg.y1.GetBuffer(0));
		x2 = _wtoi(inputDlg.x2.GetBuffer(0));
		y2 = _wtoi(inputDlg.y2.GetBuffer(0));
		x3 = _wtoi(inputDlg.x3.GetBuffer(0));
		y3 = _wtoi(inputDlg.y3.GetBuffer(0));
	} else return;
	CPoint pt[3] = { CPoint(x1, y1),CPoint(x2, y2), CPoint(x3, y3) };
	pDC->Polygon(pt, 3);
}


void CMy201916010728View::OnCdcCircle()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int x, y, r;
	CircleDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		x = _wtoi(inputDlg.x.GetBuffer(0));
		y = _wtoi(inputDlg.y.GetBuffer(0));
		r = _wtoi(inputDlg.r.GetBuffer(0));
	} else return;
	double w, u, d;
	int R = 0, G = 0, B = 0;
	w = r; d = w / 255;
	while (w >= 0) {
		for (u = 0; u < 628; u = u + 1) {
			pDC->SetPixel((int)(x + w * cos(u / 100)), (int)(y + w * sin(u / 100)), RGB(R, G, B));
		}
		R++; G++; B++;
		w = w - d;
	}
}


void CMy201916010728View::OnCdcRectangle()
{
	Invalidate(false);
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int left, right;

	left = 5;
	right = 200;
	for (int i = 0; i < 10; ++i) {
		pDC->Rectangle(left, left, right, right);//画一个矩形 左上 左下 右上 右下
		left += 10;
		right -= 10;
		Sleep(100);
	}

	int LUX, LUY, RDX, RDY;
	RectangleDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		LUX = _wtoi(inputDlg.LUX.GetBuffer(0));
		LUY = _wtoi(inputDlg.LUY.GetBuffer(0));
		RDX = _wtoi(inputDlg.RDX.GetBuffer(0));
		RDY = _wtoi(inputDlg.RDY.GetBuffer(0));
		pDC->Rectangle(LUX, LUY, RDX, RDY);
	} else return;
}
// 创意绘图
void CMy201916010728View::OnCdcPainting()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	pDC->Ellipse(100, 100, 300, 300);// 风车圆
	pDC->Ellipse(250, 350, 350, 450);// 小人头
	pDC->MoveTo(300, 450);
	pDC->LineTo(300, 500);	// 小人脖子
	pDC->MoveTo(200, 500);
	pDC->LineTo(400, 500);	// 小人手
	pDC->MoveTo(300, 500);
	pDC->LineTo(220, 620);	// 小人左腿
	pDC->MoveTo(300, 500);
	pDC->LineTo(380, 620);	// 小人右腿
	CPoint pt[3] = { CPoint(200, 100),CPoint(250, 150), CPoint(200, 200) };	// 风车小三角1
	CPoint pt2[3] = { CPoint(200, 200),CPoint(300, 200), CPoint(250, 250) };// 风车小三角2
	CPoint pt3[3] = { CPoint(200, 200),CPoint(150, 150), CPoint(100, 200) };// 风车小三角3
	CPoint pt4[3] = { CPoint(200, 200),CPoint(150, 250), CPoint(200, 300) };// 风车小三角4
	CPen MyPen, * OldPen;//定义画笔
	MyPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));//创建蓝色画笔
	OldPen = pDC->SelectObject(&MyPen);//选中画笔到设备上下文
	CBrush MyBrush, * OldBrush;//定义填充画刷
	MyBrush.CreateSolidBrush(RGB(255, 0, 0));//创建红色画刷
	OldBrush = pDC->SelectObject(&MyBrush);//选中画刷到设备山下文
	pDC->Polygon(pt, 3);
	pDC->Polygon(pt2, 3);
	pDC->Polygon(pt3, 3);
	pDC->Polygon(pt4, 3);
	pDC->MoveTo(200, 300);
	pDC->LineTo(200, 600);
	pDC->SelectObject(OldPen); //画框线为蓝色
	pDC->SelectObject(OldBrush); // 填充为红色
	MyPen.DeleteObject();//删除画笔
	MyBrush.DeleteObject();//删除画刷
}


void CMy201916010728View::OnDDA()
{
	// TODO: 在此添加命令处理程序代码

	int x1, y1, x2, y2;
	x1 = y1 = 100;
	x2 = 300, y2 = 200;
	double delta_x, delta_y, x, y;
	int dx, dy, steps;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) > abs(dy)) steps = abs(dx);
	else steps = abs(dy);
	delta_x = dx * 1.0 / steps;
	delta_y = dy * 1.0 / steps;
	x = x1, y = y1;
	CDC* pDC = GetDC();
	pDC->SetPixel(x, y, RGB(255, 0, 0));
	for (int i = 1; i <= steps; i++) {
		x += delta_x;
		y += delta_y;
		pDC->SetPixel(x, y, RGB(255, 0, 0));
	}
}
