#include "pch.h"
#include "CDCdraw.h"

void CDCdraw::drawRectangle(int LUx, int LUy, int RDx, int RDy) {
	// TODO: �ڴ���������������
	CDC* pDC = GetDC();
	pDC->Rectangle(LUx, LUy, RDx, RDy);//��һ������ ���� ���� ���� ����
}
