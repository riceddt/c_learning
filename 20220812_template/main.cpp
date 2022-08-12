#include<iostream>
#include<string>
using namespace std;

//使用引用的交换函数模板
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//选择排序实现
template <typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (arr[max] != arr[i])
		{
			mySwap(arr[max], arr[i]);
		}
	}
}


//打印输出
template<typename T>
void myPrintArr(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}


//测试字符数组
void testChar()
{
	char charArr[] = "bacfde";
	int len = sizeof(charArr) / sizeof(char);
	mySort(charArr, len);
	myPrintArr(charArr,len);
}

//测试整型数组
void testInt()
{
	int intArr[] = { 1,2,9,5,8,3 };
	int len = sizeof(intArr) / sizeof(int);
	mySort(intArr, len);
	myPrintArr(intArr, len);
}

int main()
{
	testInt();
	return 0;
}