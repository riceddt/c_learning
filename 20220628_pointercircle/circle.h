#pragma once

#include<iostream>
#include"pointer.h"
using namespace std;


//Բ��
class Circle
{
public:
	//���ð뾶
	void setR(int r);
	//����Բ��
	void setP(Pointer p);
	//��ȡ�뾶
	int getR();

	//��ȡԲ��
	Pointer getP();

	//�жϵ��Բ�Ĺ�ϵ
	void posP_C(Pointer p);

private:
	//�뾶
	int m_R;
	//Բ��
	Pointer m_P;
};