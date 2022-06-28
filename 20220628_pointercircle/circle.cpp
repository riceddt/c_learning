#include"circle.h"

using namespace std;
void Circle::setR(int r)
{
	m_R = r;
}
void Circle::setP(Pointer p)
{
	m_P = p;
}
int Circle::getR()
{
	return m_R;
}

Pointer Circle::getP()
{
	return m_P;
}

//判断点和圆的关系
void Circle::posP_C(Pointer p)
{
	int distance = (m_P.getX() - p.getX()) * (m_P.getX() - p.getX()) + (m_P.getY() - p.getY()) * (m_P.getY() - p.getY());
	int RR = m_R * m_R;
	if (distance == RR)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > RR)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

