#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	//������ʾ����
	virtual void display() = 0;
};

class Memory
{
public:
	//����洢����
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	//���캯���д����������ָ��
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���������ÿ����������Ľӿ�
	void Work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//�ṩ�����������ͷ�3���������
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;//CPU�����ָ��
	VideoCard* m_vc;//�Կ������ָ��
	Memory* m_mem;//�ڴ�����ָ��
};

//�����������
class IntelCPU :public CPU
{
	void calculate()
	{
		cout << "Intel��CPU��ʼ����"<<endl;
	}
};

class IntelVideoCard :public VideoCard
{
	void display()
	{
		cout << "Intel���Կ���ʼ��ʾ" << endl;
	}
};

class IntelMemory :public Memory
{
	void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢" << endl;
	}
};

//Lenovo����
class LenovoCPU :public CPU
{
	void calculate()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
	void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ" << endl;
	}
};

class LenovoMemory :public Memory
{
	void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢" << endl;
	}
};


void test01()
{
	//��һ̨�������
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelvideocard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;
	//������һ̨����
	Computer* computer1 = new Computer(intelCPU, intelvideocard, intelMem);
	computer1->Work();
	delete computer1;
	cout << "-----------------------------------" << endl;
	//�����ڶ�̨����
	Computer* computer2 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->Work();
	delete computer2;
}

int main()
{
	test01();
	return 0;
}