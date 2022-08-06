#include<iostream>
using namespace std;
#define MaxSize 50
typedef struct                                //类型声明
{
	char data[MaxSize];
	int length;
}SqString;

void StrAssign(SqString& s, char cstr[])     //将字符串常量cstr赋给串
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}
void DestroyStr(SqString& s) {}                  //销毁串         
void GetNext(SqString t, int next[])             //由模式串t求出next数组
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
int KMPIndex(SqString s, SqString t)               //KMP算法 
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

void MySearch()	//调用KMP
{
	char tar[MaxSize], par[MaxSize];
	SqString tarstr, parstr;
	cout << "请输入目标串：";
	cin >> tar;
	int flag = 1;
	while (flag)
	{
		cout << "请输入模式串：";
		cin >> par;
		StrAssign(tarstr, tar);
		StrAssign(parstr, par);
		cout << "模式串位置为：" << KMPIndex(tarstr, parstr) << endl;
		cout << "继续查找请输入“1”，退出请输入“0”" << endl;
		cin >> flag;
	}
}

int main()
{
	MySearch();
	return 0;
}
