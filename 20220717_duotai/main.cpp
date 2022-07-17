#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	//抽象显示函数
	virtual void display() = 0;
};

class Memory
{
public:
	//抽象存储函数
	virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
	//构造函数中传入三个零件指针
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数，调用每个零件工作的接口
	void Work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//提供析构函数，释放3个电脑零件
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
	CPU* m_cpu;//CPU的零件指针
	VideoCard* m_vc;//显卡的零件指针
	Memory* m_mem;//内存的零件指针
};

//具体零件厂商
class IntelCPU :public CPU
{
	void calculate()
	{
		cout << "Intel的CPU开始计算"<<endl;
	}
};

class IntelVideoCard :public VideoCard
{
	void display()
	{
		cout << "Intel的显卡开始显示" << endl;
	}
};

class IntelMemory :public Memory
{
	void storage()
	{
		cout << "Intel的内存条开始存储" << endl;
	}
};

//Lenovo厂商
class LenovoCPU :public CPU
{
	void calculate()
	{
		cout << "Lenovo的CPU开始计算" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
	void display()
	{
		cout << "Lenovo的显卡开始显示" << endl;
	}
};

class LenovoMemory :public Memory
{
	void storage()
	{
		cout << "Lenovo的内存条开始存储" << endl;
	}
};


void test01()
{
	//第一台电脑零件
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelvideocard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;
	//创建第一台电脑
	Computer* computer1 = new Computer(intelCPU, intelvideocard, intelMem);
	computer1->Work();
	delete computer1;
	cout << "-----------------------------------" << endl;
	//创建第二台电脑
	Computer* computer2 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->Work();
	delete computer2;
}

int main()
{
	test01();
	return 0;
}