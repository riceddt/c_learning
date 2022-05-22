#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else 
	{
		printf("���������֣�>");
		scanf("%s", ps->data[ps->size].name);
		printf("������绰��>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[ps->size].addr);
		printf("�������Ա�>");
		scanf("%s", ps->data[ps->size].sex);
		printf("���������䣺>");
		scanf("%d", &(ps->data[ps->size].age));
		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%12s\t%6s\t%5s\t%5s\n", 
			"����", "�绰", "סַ", "����", "�Ա�");
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%12s\t%6s\t%5d\t%5s\n",
				ps->data[i].name,
				ps->data[i].tele,
				ps->data[i].addr,
				ps->data[i].age,
				ps->data[i].sex);
		}
	}
}


int searchbyname(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����������\n");
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;	
}

void DelContact(struct Contact* ps)
{
	int pos = searchbyname(ps);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(struct Contact* ps)
{
	int pos = searchbyname(ps);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%20s\t%12s\t%6s\t%5s\t%5s\n",
			"����", "�绰", "סַ", "����", "�Ա�");
			printf("%20s\t%12s\t%6s\t%5d\t%5s\n",
				ps->data[pos].name,
				ps->data[pos].tele,
				ps->data[pos].addr,
				ps->data[pos].age,
				ps->data[pos].sex);
	}
}

void ModifyContact(struct Contact* ps)
{
	int pos = searchbyname(ps);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", ps->data[pos].name);
		printf("������绰��>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[pos].addr);
		printf("�������Ա�>");
		scanf("%s", ps->data[pos].sex);
		printf("���������䣺>");
		scanf("%d", &(ps->data[pos].age));
		printf("�޸ĳɹ�\n");
	}
}