#include<iostream>
#include "Building.h"
#include "Goodgay.h"

using std::cout;
using std::endl;

Goodgay::Goodgay()
{
	building = new Building;//����ָ��һ������ռ��ָ�룬��Ҫ֪�������ľ�������������ҪBuildingͷ�ļ�
}
void Goodgay::visit()
{
	cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit�������ڷ��ʣ�" << building->m_BedRoom << endl;
}