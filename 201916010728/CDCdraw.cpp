#include "pch.h"
#include "CDCdraw.h"

void CDCdraw::drawRectangle(int LUx, int LUy, int RDx, int RDy) {
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	pDC->Rectangle(LUx, LUy, RDx, RDy);//画一个矩形 左上 左下 右上 右下
}
