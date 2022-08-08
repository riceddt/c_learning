#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define MaxSize 50

//结构体类型声明
typedef struct                                
{
	char data[MaxSize];
	int length;
}SqString;

//将字符串常量cstr赋给串
void StrAssign(SqString& s, char cstr[])     
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

//销毁串  
void DestroyStr(SqString& s) {}  

//由模式串t求出next数组
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

//KMP算法
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
		else j = next[j];//模式串中第j个数要和目标串中第i个数比较
	}
	if (j >= t.length)
		return(i - t.length + 1);
	else
		return -1;
}

//获取循环模式子串并进行匹配
void KMPSearch(char* tar,char* par)
{
	SqString tarstr, parstr;
	StrAssign(tarstr, tar);
	char par_doublecpy[MaxSize * 2];
	strcpy(par_doublecpy, par);
	strcat(par_doublecpy, par);
	int par_len = int(strlen(par));
	for (int i = 0; i < par_len; i++)	//获取循环状态下的模式子串
	{
		for (int j = 0; j < par_len; j++)
		{
			par[j] = par_doublecpy[j+i];
		}
		cout << par << endl;
		StrAssign(parstr, par);
		cout << "模式串位置为：" << KMPIndex(tarstr, parstr) << endl;
	}
}

//输入目标串与模式串，并调用KMP
void MySearch()	
{
	char tar[MaxSize], par[MaxSize];
	int flag = 1;	//设置是否进行新模式串查找的标志位
	while (flag)
	{
		cout << "请输入目标串：";
		cin >> tar;
		cout << "请输入模式串：";
		cin >> par;
		KMPSearch(tar,par);
		cout << "重新进行模式匹配请输入“1”，退出请输入“0”" << endl;
		cin >> flag;
	}
}

int main()
{
	MySearch();
	return 0;
}
