#include<iostream>
#include "Goodgay.h"
#include"Building.h"
using namespace std;

Goodgay::Goodgay()
{
	building = new Building;//����ָ��һ������ռ��ָ�룬��Ҫ֪�������ľ�������������ҪBuildingͷ�ļ�
}
void Goodgay::visit()
{
	cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit�������ڷ��ʣ�" << building->m_BedRoom << endl;
}