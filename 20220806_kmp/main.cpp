#include<iostream>
using namespace std;
#define MaxSize 50
typedef struct                                //��������
{
	char data[MaxSize];
	int length;
}SqString;

void StrAssign(SqString& s, char cstr[])     //���ַ�������cstr������
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}
void DestroyStr(SqString& s) {}                  //���ٴ�         
void GetNext(SqString t, int next[])             //��ģʽ��t���next����
{
	int j, k;
	j = 0; k = -1;
	next[0] = -1;
	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			next[++j]=++k;//next[j++] = k++;
			//next[j++] = k++;
		}
		else
			k = next[k];
	}
}
int KMPIndex(SqString s, SqString t)               //KMP�㷨 
{
	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++; j++;
		}
		else j = next[j];
	}
	if (j >= t.length)
		return(i - t.length + 1);
	else
		return -1;
}

void MySearch()	//����KMP
{
	char tar[MaxSize], par[MaxSize];
	SqString tarstr, parstr;
	cout << "������Ŀ�괮��";
	cin >> tar;
	int flag = 1;
	while (flag)
	{
		cout << "������ģʽ����";
		cin >> par;
		StrAssign(tarstr, tar);
		StrAssign(parstr, par);
		cout << "ģʽ��λ��Ϊ��" << KMPIndex(tarstr, parstr) << endl;
		cout << "�������������롰1�����˳������롰0��" << endl;
		cin >> flag;
	}
}

int main()
{
	MySearch();
	return 0;
}
