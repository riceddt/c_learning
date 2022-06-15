#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//���ļ����Ѵ�ŵ�ͨѶ¼��Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
}

void CheckCapacity(struct Contact* ps);

void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ��ŵ�ͨѶ¼��
	
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfread))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfread);
	pfread = NULL;
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ���\n");
		}
		else
		{
			printf("����ʧ�ܣ�\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	//��⵱ǰͨѶ¼����
	//1��������˾����ӿռ�
	//2������������ͼ���
	CheckCapacity(ps);
	//��������
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

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf(" SaveContact:%s\n", strerror(errno));
		return;
	}
	//дͨѶ¼�е����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}

