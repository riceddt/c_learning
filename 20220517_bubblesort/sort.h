#pragma once



int cmp_int(const void* e1, const void* e2);//比较整数
int cmp_double(const void* e1, const void* e2);//比较double
int cmp_by_age(const void* e1, const void* e2);//比较结构体年龄
int cmp_by_name(const void* e1, const void* e2); //比较结构体姓名
void Swap(char* base1, char* base2, int width);//交换
void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2));//排序实现


struct Stu	//自定义结构体
{
	char name[20];
	int age;
};
