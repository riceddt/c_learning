#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "sort.h"


void test1()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);
	bubble_sort(arr, sz, width, cmp_int);//cmp_int是一个函数指针，指向一个回调函数，传递给bubble_sort
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test2()
{
	double arr[10] = { 10.2,9.3,8.24,7.21,6.78,5.71,4.32,3.97,2.13,1.59 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);
	bubble_sort(arr, sz, width, cmp_double);//cmp_int是一个函数指针，指向一个回调函数，传递给bubble_sort
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%.2lf ", arr[i]);
	}
}

void test3()
{
	struct Stu s[3] = { {"zhangsan",25} ,{"lisi",34},{"wangliu",18} };
	int sz = sizeof(s) / sizeof(s[0]);
	int width = sizeof(s[0]);
	bubble_sort(s, sz, width, cmp_by_age);//cmp_int是一个函数指针，指向一个回调函数，传递给bubble_sort
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", s[i].age);
	}
}

void test4()
{
	struct Stu s[3] = { {"zhangsan",25} ,{"lisi",34},{"wangliu",18} };
	int sz = sizeof(s) / sizeof(s[0]);
	int width = sizeof(s[0]);
	bubble_sort(s, sz, width, cmp_by_name);//cmp_int是一个函数指针，指向一个回调函数，传递给bubble_sort
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i].name);
	}
}

int main()
{
	test4();
	return 0;
}