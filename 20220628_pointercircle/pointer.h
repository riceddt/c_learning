#pragma once
#include<iostream>
using namespace std;
//����
class Pointer
{
public:
	//����x
	void setX(int x);
	//����y
	void setY(int y);
	//��ȡx
	int getX();
	//��ȡy
	int getY();

private:
	//x����
	int m_X;
	//y����
	int m_Y;
};