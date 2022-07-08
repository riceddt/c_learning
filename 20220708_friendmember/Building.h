#pragma once
#include <string>
#include "Goodgay.h"
using namespace std;

class Building
{
	friend void Goodgay::visit();//用到另一个类中的具体成员函数，需要引用另一个类的头文件
public:
	Building();
public:
	string m_SittingRoom; //客厅

private:
	string m_BedRoom;//卧室
};
