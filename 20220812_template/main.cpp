#include<iostream>
#include<string>
using namespace std;

//ʹ�����õĽ�������ģ��
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//ѡ������ʵ��
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


//��ӡ���
template<typename T>
void myPrintArr(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}


//�����ַ�����
void testChar()
{
	char charArr[] = "bacfde";
	int len = sizeof(charArr) / sizeof(char);
	mySort(charArr, len);
	myPrintArr(charArr,len);
}

//������������
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