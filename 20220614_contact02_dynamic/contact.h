#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option  //增加代码可读性
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

///通讯录
struct Contact
{
	struct PeoInfo data[MAX];
	int size;
};

//声明函数
//初始化通讯录
void InitContact(struct Contact* ps);
//增加一个信息
void AddContact(struct Contact* ps);
//显示通讯录中的信息
void ShowContact(const struct Contact* ps);
//删除指定通讯录信息
void DelContact(struct Contact* ps);
//查找指定联系人
void SearchContact(struct Contact* ps);
//修改指定联系人信息
void ModifyContact(struct Contact* ps);
