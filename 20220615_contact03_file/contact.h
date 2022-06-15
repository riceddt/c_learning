#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3

enum Option  //���Ӵ���ɶ���
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

///ͨѶ¼
struct Contact
{
	struct PeoInfo* data;
	int size;//�Ѿ��е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼�������
};

//��������
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//����һ����Ϣ
void AddContact(struct Contact* ps);
//��ʾͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);
//ɾ��ָ��ͨѶ¼��Ϣ
void DelContact(struct Contact* ps);
//����ָ����ϵ��
void SearchContact(struct Contact* ps);
//�޸�ָ����ϵ����Ϣ
void ModifyContact(struct Contact* ps);
//����ͨѶ¼���ͷŶ�̬�����ڴ�
void DestroyContact(struct Contact* ps);
//�����ļ�
void SaveContact(struct Contact* ps);
//�����ļ��е���Ϣ��ͨѶ¼
void LoadContact(struct Contact* ps);