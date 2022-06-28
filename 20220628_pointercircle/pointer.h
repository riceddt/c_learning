#pragma once
#include<iostream>
using namespace std;
//点类
class Pointer
{
public:
	//设置x
	void setX(int x);
	//设置y
	void setY(int y);
	//获取x
	int getX();
	//获取y
	int getY();

private:
	//x坐标
	int m_X;
	//y坐标
	int m_Y;
};