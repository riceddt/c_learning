#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include "sort.h"

int cmp_int(const void* e1, const void* e2)
{
	//�Ƚ��������͵�ֵ
	return *(int*)e1 - *(int*)e2;	//ǿ������ת��Ϊ����ָ��
}

int cmp_double(const void* e1, const void* e2)
{
	if (*(double*)e1 == *(double*)e2)
		return 0;
	else if (*(double*)e1 > *(double*)e2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;	//ǿ������ת��Ϊ����ָ��
}

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);	//ǿ������ת��Ϊ����ָ��
}


void Swap(char* base1, char* base2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *base1;
		*base1 = *base2;
		*base2 = tmp;
		base1++;
		base2++;
	}
}

void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			//������Ԫ�ؽ��бȽ�
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//bubble_sort�õ����ݹ����Ĳ���ָ��󣬵������������ͬʱ������������ݲ���
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);//��������
			}
		}
	}
}