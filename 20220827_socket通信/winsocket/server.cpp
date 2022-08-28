#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include<windows.h>
#pragma comment(lib, "ws2_32.lib")

#define FILE_NAME_MAX_SIZE 512 
#define BUFFER_SIZE 1024 

using namespace std;

SOCKET m_Client;

string RecvFileName();

void SendFile(string);

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(65001);//用于解决中文乱码问题

	//初始化WSA  
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	//创建套接字  
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		cout<<"socket error !"<<endl;
		return 0;
	}

	//绑定IP和端口  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		cout<<"bind error !"<<endl;
	}

	//开始监听  
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}

	//循环接收数据  
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];
	while (true)
	{
		printf("等待连接..");
		m_Client = accept(slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);
		if (m_Client == INVALID_SOCKET)
		{
			//printf("accept error !");
			cout<<"accept error !"<<endl;
			continue;
		}
		//printf("接受到一个连接：%s ", inet_ntoa(remoteAddr.sin_addr));
		cout<<"接受到一个连接："<<inet_ntoa(remoteAddr.sin_addr)<<endl;
		string file_name; //定义接收到的文件名
		file_name = RecvFileName();
		SendFile(file_name);
		closesocket(m_Client);
	}

	closesocket(slisten);
	WSACleanup();
	return 0;
}

//接收客户端发送的文件名
string RecvFileName()
{
	// recv函数接收数据到缓冲区buffer中 
    char buffer[BUFFER_SIZE];  
	memset(buffer,0,sizeof(buffer));
    if(recv(m_Client, buffer, BUFFER_SIZE, 0) < 0) 
    { 
      perror("Server Recieve Data Failed:"); 
      return 0; 
    } 
 
    // 然后从buffer(缓冲区)拷贝到file_name中 
    char file_name[FILE_NAME_MAX_SIZE+1]; 
	memset(file_name,0,sizeof(file_name));
    strncpy(file_name, buffer, strlen(buffer)>FILE_NAME_MAX_SIZE?FILE_NAME_MAX_SIZE:strlen(buffer)); 
	cout<<file_name<<endl;
	string fname = file_name;//进行char[]到string的转换
	return fname;
}

void SendFile(string filename) {
	int haveSend = 0;	//发送的数据量
	const int bufferSize = 1024;	//发送缓冲区大小
	char buffer[bufferSize] = { 0 };	//建立发送缓冲区
	int readLen = 0;
	string srcFileName = filename;	//发送文件名称
	ifstream srcFile;	//建立读操作的对象
	srcFile.open(srcFileName.c_str(), ios::binary);
	if (!srcFile) {
		return;
	}
	while (!srcFile.eof()) {
		srcFile.read(buffer, bufferSize);
		readLen = srcFile.gcount();
		send(m_Client, buffer, readLen, 0);
		haveSend += readLen;
	}
	srcFile.close();
	cout << "send: " << haveSend << "B" << endl;
}

