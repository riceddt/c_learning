#include<iostream>
#include<string>
#include"pointer.h"
#include"circle.h"

using namespace std;

int main()
{
	Circle c1;//����һ��Բ�Ķ���
	Pointer center;//�����Ķ�����ΪԲ��
	center.setX(10);//����Բ�ĺ�����
	center.setY(0);//����Բ��������
	c1.setR(10);//���ð뾶
	c1.setP(center);//����Բ��
	Pointer p2;//����һ����Ķ���
	p2.setX(10);//���õ�ĺ�����
	p2.setY(10);//���õ��������
	c1.posP_C(p2);//���е��Բ��λ���ж�
	return 0;
}