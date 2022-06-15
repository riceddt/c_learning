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
	//把文件中已存放的通讯录信息加载到通讯录中
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
	//读取文件放到通讯录中
	
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
			printf("增容成功！\n");
		}
		else
		{
			printf("增容失败！\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	//检测当前通讯录容量
	//1、如果满了就增加空间
	//2、如果不满，就继续
	CheckCapacity(ps);
	//增加数据
	printf("请输入名字：>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入电话：>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：>");
	scanf("%s", ps->data[ps->size].addr);
	printf("请输入性别：>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入年龄：>");
	scanf("%d", &(ps->data[ps->size].age));
	ps->size++;
	printf("添加成功\n");
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%12s\t%6s\t%5s\t%5s\n", 
			"姓名", "电话", "住址", "年龄", "性别");
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
	printf("请输入姓名\n");
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
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(struct Contact* ps)
{
	int pos = searchbyname(ps);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%20s\t%12s\t%6s\t%5s\t%5s\n",
			"姓名", "电话", "住址", "年龄", "性别");
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
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->data[pos].name);
		printf("请输入电话：>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：>");
		scanf("%s", ps->data[pos].addr);
		printf("请输入性别：>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入年龄：>");
		scanf("%d", &(ps->data[pos].age));
		printf("修改成功\n");
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
	//写通讯录中的数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}

