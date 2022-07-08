#pragma once

class Building;//前向引用,先声明，仅用于创建指针，类中具体成员不用知道，不需要引用类的头文件
class Goodgay
{
public:
	Goodgay();
	void visit();//让visit函数访问Building中私有成员
	Building* building;//调用的类尚未定义，只有声明，只能用指针
};
