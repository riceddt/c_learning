#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define MaxSize 50

//�ṹ����������
typedef struct                                
{
	char data[MaxSize];
	int length;
}SqString;

//���ַ�������cstr������
void StrAssign(SqString& s, char cstr[])     
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

//���ٴ�  
void DestroyStr(SqString& s) {}  

//��ģʽ��t���next����
void GetNext(SqString t, int next[])             
{
	int j, k;
	j = 0; k = -1;
	next[0] = -1;
	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			next[++j] = ++k;//next[j++] = k++;
			//next[j++] = k++;
		}
		else
			k = next[k];
	}
}

//KMP�㷨
int KMPIndex(SqString s, SqString t)                
{
	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++; j++;
		}
		else j = next[j];//ģʽ���е�j����Ҫ��Ŀ�괮�е�i�����Ƚ�
	}
	if (j >= t.length)
		return(i - t.length + 1);
	else
		return -1;
}

//��ȡѭ��ģʽ�Ӵ�������ƥ��
void KMPSearch(char* tar,char* par)
{
	SqString tarstr, parstr;
	StrAssign(tarstr, tar);
	char par_doublecpy[MaxSize * 2];
	strcpy(par_doublecpy, par);
	strcat(par_doublecpy, par);
	int par_len = int(strlen(par));
	for (int i = 0; i < par_len; i++)	//��ȡѭ��״̬�µ�ģʽ�Ӵ�
	{
		for (int j = 0; j < par_len; j++)
		{
			par[j] = par_doublecpy[j+i];
		}
		cout << par << endl;
		StrAssign(parstr, par);
		cout << "ģʽ��λ��Ϊ��" << KMPIndex(tarstr, parstr) << endl;
	}
}

//����Ŀ�괮��ģʽ����������KMP
void MySearch()	
{
	char tar[MaxSize], par[MaxSize];
	int flag = 1;	//�����Ƿ������ģʽ�����ҵı�־λ
	while (flag)
	{
		cout << "������Ŀ�괮��";
		cin >> tar;
		cout << "������ģʽ����";
		cin >> par;
		KMPSearch(tar,par);
		cout << "���½���ģʽƥ�������롰1�����˳������롰0��" << endl;
		cin >> flag;
	}
}

int main()
{
	MySearch();
	return 0;
}
