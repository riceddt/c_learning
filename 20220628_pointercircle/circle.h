#pragma once

#include<iostream>
#include"pointer.h"
using namespace std;


//圆类
class Circle
{
public:
	//设置半径
	void setR(int r);
	//设置圆心
	void setP(Pointer p);
	//获取半径
	int getR();

	//获取圆心
	Pointer getP();

	//判断点和圆的关系
	void posP_C(Pointer p);

private:
	//半径
	int m_R;
	//圆心
	Pointer m_P;
};