
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
	ON_COMMAND(ID_32777, &CMy201916010728View::OnLineMid)
	ON_COMMAND(ID_Menu, &CMy201916010728View::OnBresenham)
	ON_COMMAND(ID_32780, &CMy201916010728View::OnPolyScan)
	ON_COMMAND(ID_32781, &CMy201916010728View::OnBoundaryFill)
	ON_COMMAND(ID_32789, &CMy201916010728View::OnTransform)
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


void CMy201916010728View::OnDDA() {
	// TODO: 在此添加命令处理程序代码

	int x1, y1, x2, y2;
	LineDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		x1 = _wtoi(inputDlg.sx.GetBuffer(0));
		y1 = _wtoi(inputDlg.sy.GetBuffer(0));
		x2 = _wtoi(inputDlg.ex.GetBuffer(0));
		y2 = _wtoi(inputDlg.ey.GetBuffer(0));
	}
	else return;
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
	pDC->SetPixel(x, y, RGB(255, 0, 0));		// DDA画线用红色的（以表区分）
	for (int i = 1; i <= steps; i++) {
		x += delta_x;
		y += delta_y;
		pDC->SetPixel(x, y, RGB(255, 0, 0));
	}
}

// 中点画线法绘制直线
void CMy201916010728View::OnLineMid() {
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CPoint vstart, vend;
	LineDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		vstart.x = _wtoi(inputDlg.sx.GetBuffer(0));
		vstart.y = _wtoi(inputDlg.sy.GetBuffer(0));
		vend.x = _wtoi(inputDlg.ex.GetBuffer(0));
		vend.y = _wtoi(inputDlg.ex.GetBuffer(0));
	}
	else return;
	CPoint p, t;
	COLORREF clr = RGB(255, 99, 71);
	if (fabs(vstart.x - vend.x) < 1e-6) {
		if (vstart.y > vend.y) {
			t = vstart;
			vstart = vend;
			vend = t;
		}
		for (p = vstart; p.y < vend.y; p.y++) {
			pDC->SetPixelV(Round(p.x), Round(p.y), clr);
		}

	}
	else {
		double k, d;
		k = (vend.y - vstart.y) / (vend.x - vstart.x);

		if (k > 1.0)
		{
			if (vstart.y > vend.y)
			{
				t = vstart;
				vstart = vend;
				vend = t;
			}
			d = 1 - 0.5 * k;
			for (p = vstart; p.y < vend.y; p.y++)
			{
				pDC->SetPixelV(Round(p.x), Round(p.y), clr);
				if (d >= 0)
				{
					p.x++;
					d += 1 - k;
				}
				else
					d += 1;
			}
		}
		if (0.0 <= k && k <= 1.0)
		{
			if (vstart.x > vend.x) {
				t = vstart;
				vstart = vend;
				vend = t;
			}
			d = 0.5 - k;
			for (p = vstart; p.x < vend.x; p.x++)
			{
				pDC->SetPixelV(Round(p.x), Round(p.y), clr);

				if (d < 0)
				{
					p.y++;
					d += 1 - k;
				}
				else
					d -= k;
			}
		}

		if (k >= -1.0 && k < 0.0)
		{
			if (vstart.x > vend.x)
			{
				t = vstart;
				vstart = vend;
				vend = t;
			}
			d = -0.5 - k;

			for (p = vstart; p.x < vend.x; p.x++)
			{
				pDC->SetPixelV(Round(p.x), Round(p.y), clr);
				if (d > 0)
				{
					p.y--;
					d -= 1 + k;
				}
				else
					d -= k;

			}
		}

		if (k < -1.0)
		{
			if (vstart.y < vend.y)
			{
				t = vstart;
				vstart = vend;
				vend = t;
			}
			d = -1 - 0.5 * k;
			for (p = vstart; p.y < vend.y; p.y--)
			{
				pDC->SetPixelV(Round(p.x), Round(p.y), clr);
				if (d < 0)
				{
					p.x++;
					d -= 1 + k;
				}
				else
					d -= 1;
			}
		}
	}
	vstart = vend;
}


void CMy201916010728View::OnBresenham() {
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int r = 200;
	int x0 = 200, y0 = 200, x, y;
	CircleDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		x0 = _wtoi(inputDlg.x.GetBuffer(0));
		y0 = _wtoi(inputDlg.y.GetBuffer(0));
		r = _wtoi(inputDlg.r.GetBuffer(0));
	}
	else return;
	int c = RGB(219, 112, 147);
	float d;
	d = 3 - 2 * r;
	x = 0;
	y = r;
	while (x <= y) {
		if (d < 0) {
			d = d + 4 * x + 6;
			x = x + 1;
		}
		else if (d >= 0) {
			d = d + 4 * (x - y) + 10;
			x = x + 1;
			y = y - 1;
		}
		pDC->SetPixel(x + x0, y + y0, c);
		pDC->SetPixel(-x + x0, y + y0, c);
		pDC->SetPixel(x + x0, -y + y0, c);
		pDC->SetPixel(-x + x0, -y + y0, c);
		pDC->SetPixel(y + x0, x + y0, c);
		pDC->SetPixel(-y + x0, x + y0, c);
		pDC->SetPixel(y + x0, -x + y0, c);
		pDC->SetPixel(-y + x0, -x + y0, c);
	}
}


void CMy201916010728View::OnPolyScan() {
	int col = RGB(255, 182, 193);	//粉嫩嫩颜色
	// TODO: 在此处添加实现代码.	
	point polypoint[POINTNUM] = { 170,10, 360,100, 360,200, 230,130, 140,170, 140,80 };//多边形顶点  
	polyScanDraw(polypoint, col);		//画准备好的多边形

	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	PolyDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		polypoint[0].x = _wtoi(inputDlg.x1.GetBuffer(0));
		polypoint[0].y = _wtoi(inputDlg.y1.GetBuffer(0));

		polypoint[1].x = _wtoi(inputDlg.x2.GetBuffer(0));
		polypoint[1].y = _wtoi(inputDlg.y2.GetBuffer(0));

		polypoint[2].x = _wtoi(inputDlg.x3.GetBuffer(0));
		polypoint[2].y = _wtoi(inputDlg.y3.GetBuffer(0));

		polypoint[3].x = _wtoi(inputDlg.x4.GetBuffer(0));
		polypoint[3].y = _wtoi(inputDlg.y4.GetBuffer(0));

		polypoint[4].x = _wtoi(inputDlg.x5.GetBuffer(0));
		polypoint[4].y = _wtoi(inputDlg.y5.GetBuffer(0));

		polypoint[5].x = _wtoi(inputDlg.x6.GetBuffer(0));
		polypoint[5].y = _wtoi(inputDlg.y6.GetBuffer(0));
	}
	else return;
	polyScanDraw(polypoint, RGB(127, 255, 212));	//绿的


}


void CMy201916010728View::polyScanDraw(point* polypoint, int col) {
	CDC* pDC = GetDC();
	if (!polypoint) return;
	// TODO: 在此处添加实现代码.	
	int MaxY = 0;
	int MinY = 2000;
	int i;
	for (i = 0; i < POINTNUM; i++) {
		if (polypoint[i].y > MaxY)
			MaxY = polypoint[i].y;
		if (polypoint[i].y < MinY)
			MinY = polypoint[i].y;
	}

	/*******初始化AET表，即初始化活跃边表**********/
	AET* pAET = new AET;
	pAET->next = NULL;

	/******初始化NET表，即初始化边表***************/
	NET* pNET[1024];
	for (i = MinY; i <= MaxY; ++i) {
		pNET[i] = new NET;
		pNET[i]->next = NULL;
	}

	/******扫描并建立NET表，即建立边表***************/
	for (i = MinY; i <= MaxY; ++i) {
		for (int j = 0; j < POINTNUM; ++j) {
			if (polypoint[j].y == i) {
				if (polypoint[(j - 1 + POINTNUM) % POINTNUM].y > polypoint[j].y) {
					NET* p = new NET;
					p->x = polypoint[j].x;
					p->ymax = polypoint[(j - 1 + POINTNUM) % POINTNUM].y;
					p->dx = (polypoint[(j - 1 + POINTNUM) % POINTNUM].x - polypoint[j].x) / (polypoint[(j - 1 + POINTNUM) % POINTNUM].y - polypoint[j].y);
					p->next = pNET[i]->next;
					pNET[i]->next = p;
				}

				if (polypoint[(j + 1 + POINTNUM) % POINTNUM].y > polypoint[j].y) {
					NET* p = new NET;
					p->x = polypoint[j].x;
					p->ymax = polypoint[(j + 1 + POINTNUM) % POINTNUM].y;
					p->dx = (polypoint[(j + 1 + POINTNUM) % POINTNUM].x - polypoint[j].x) / (polypoint[(j + 1 + POINTNUM) % POINTNUM].y - polypoint[j].y);
					p->next = pNET[i]->next;
					pNET[i]->next = p;
				}
			}
		}
	}

	/******建立并更新活性边表AET***********************/
	for (i = MinY; i <= MaxY; ++i) {
		//计算新的交点x,更新AET***************************/  
		NET* p = pAET->next;
		while (p != NULL) {
			p->x = p->x + p->dx;
			p = p->next;
		}

		//更新后新AET先排序***************************/  
		//断表排序,不再开辟空间  
		AET* tq = pAET;
		p = pAET->next;
		tq->next = NULL;

		while (p != NULL) {
			while (tq->next != NULL && p->x >= tq->next->x)
				tq = tq->next;
			NET* s = p->next;
			p->next = tq->next;
			tq->next = p;
			p = s;
			tq = pAET;
		}

		//(改进算法)先从AET表中删除ymax==i的结点**************/  
		AET* q = pAET;
		p = q->next;
		while (p != NULL) {
			if (p->ymax == i) {
				q->next = p->next;
				delete p;
				p = q->next;
			}
			else {
				q = q->next;
				p = q->next;
			}
		}

		//将NET中的新点加入AET,并用插入法按X值递增排序************/  
		p = pNET[i]->next;
		q = pAET;
		while (p != NULL) {
			while (q->next != NULL && p->x >= q->next->x)
				q = q->next;
			NET* s = p->next;
			p->next = q->next;
			q->next = p;
			p = s;
			q = pAET;
		}

		/******配对填充颜色************************/
		p = pAET->next;
		while (p != NULL && p->next != NULL)
		{
			for (float j = p->x; j <= p->next->x; j++)
			{
				pDC->SetPixel(static_cast<int>(j), i, col);
			}  // pDC.MoveTo( static_cast<int>(p->x), i ); 用画直线来替换上面的设置像素点颜色，速度更快  
							  //  pDC.LineTo( static_cast<int>(p->next->x), i );  

			p = p->next->next;//考虑端点情况  
		}
	}

	NET* phead = NULL;
	NET* pnext = NULL;
	//释放边表  
	/*
	for( i = MinY;i <= MaxY;i++ )
	{
		phead = pNET[i];

		while( phead != NULL )
		{
			pnext = phead->next;
			delete phead;
			phead = pnext;
		}

		pNET[i] = NULL;
	}
	*/
	//释放活跃边表  
	phead = pAET;
	while (phead != NULL)
	{
		pnext = phead->next;
		delete phead;
		phead = pnext;
	}
}


void CMy201916010728View::Bfs(int x, int y, int col, int edgeCol, CDC* pDC) {
	// TODO: 在此处添加实现代码.
	long c;
	c = pDC->GetPixel(x, y);
	if (c != col && c != edgeCol) {
		pDC->SetPixel(x, y, col);
		//Sleep(2);
		Bfs(x + 1, y, col, edgeCol, pDC);
		Bfs(x - 1, y, col, edgeCol, pDC);
		Bfs(x, y + 1, col, edgeCol, pDC);
		Bfs(x, y - 1, col, edgeCol, pDC);
	}
}


void CMy201916010728View::OnBoundaryFill() {
	CDC* pDC = GetDC();
	BoundaryFillDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		//这里获取输入并在客户区输出
		point LU, RD, S;
		LU.x = _wtoi(inputDlg.LUX.GetBuffer(0));
		LU.y = _wtoi(inputDlg.LUY.GetBuffer(0));
		RD.x = _wtoi(inputDlg.RDX.GetBuffer(0));
		RD.y = _wtoi(inputDlg.RDY.GetBuffer(0));
		S.x = _wtoi(inputDlg.SX.GetBuffer(0));
		S.y = _wtoi(inputDlg.SY.GetBuffer(0));

		pDC->Rectangle(LU.x, LU.y, RD.x, RD.y);
		Bfs(S.x, S.y, RGB(255, 105, 180), RGB(0, 0, 0), pDC);
	}
}


void CMy201916010728View::OnTransform()
{
	CDC* pDC = GetDC();
	CPoint pt[3] = { CPoint(200,200),CPoint(100,100), CPoint(200,100) };
	pDC->Polygon(pt, 3);		// 先画一个三角形
	// TODO: 在此添加命令处理程序代码
	int angle, sx, sy, tx, ty;
	TransformDlg inputDlg;
	int nResponse = inputDlg.DoModal();
	if (nResponse == IDOK) {
		angle = _wtoi(inputDlg.angle.GetBuffer(0));
		sx = _wtoi(inputDlg.sx.GetBuffer(0));
		sy = _wtoi(inputDlg.sy.GetBuffer(0));
		tx = _wtoi(inputDlg.tx.GetBuffer(0));
		ty = _wtoi(inputDlg.ty.GetBuffer(0));
	}
	else return;
	CP2 pol[3] = { CP2(200,200),CP2(100,100), CP2(200,100) };
	CTransform c1(3, pol);
	//c1.rotate(90);
	//c1.translate(300, 0);
	//c1.scale(2, 2);
	c1.rotate(angle);
	c1.translate(tx, ty);
	c1.scale(sx, sy);
	CPoint pt2[3] = { CPoint(pol[0].x, pol[0].y),CPoint(pol[1].x, pol[1].y), CPoint(pol[2].x, pol[2].y) };
	pDC->Polygon(pt2, 3);
}
