#include<iostream>
#include "Building.h"
#include "Goodgay.h"

using std::cout;
using std::endl;

Goodgay::Goodgay()
{
	building = new Building;//创建指向一个对象空间的指针，需要知道这个类的具体情况，因此需要Building头文件
}
void Goodgay::visit()
{
	cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit函数正在访问：" << building->m_BedRoom << endl;
}