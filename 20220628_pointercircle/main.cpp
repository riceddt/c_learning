#include<iostream>
#include<string>
#include"pointer.h"
#include"circle.h"

using namespace std;

int main()
{
	Circle c1;//定义一个圆的对象
	Pointer center;//定义点的对象，作为圆心
	center.setX(10);//设置圆心横坐标
	center.setY(0);//设置圆心纵坐标
	c1.setR(10);//设置半径
	c1.setP(center);//设置圆心
	Pointer p2;//定义一个点的对象
	p2.setX(10);//设置点的横坐标
	p2.setY(10);//设置点的纵坐标
	c1.posP_C(p2);//进行点和圆的位置判断
	return 0;
}