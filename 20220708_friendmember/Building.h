#pragma once
#include <string>
#include "Goodgay.h"
using namespace std;

class Building
{
	friend void Goodgay::visit();//�õ���һ�����еľ����Ա��������Ҫ������һ�����ͷ�ļ�
public:
	Building();
public:
	string m_SittingRoom; //����

private:
	string m_BedRoom;//����
};
