#pragma once



int cmp_int(const void* e1, const void* e2);//�Ƚ�����
int cmp_double(const void* e1, const void* e2);//�Ƚ�double
int cmp_by_age(const void* e1, const void* e2);//�ȽϽṹ������
int cmp_by_name(const void* e1, const void* e2); //�ȽϽṹ������
void Swap(char* base1, char* base2, int width);//����
void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2));//����ʵ��


struct Stu	//�Զ���ṹ��
{
	char name[20];
	int age;
};
