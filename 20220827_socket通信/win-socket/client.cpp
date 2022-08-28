#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <winsock2.h>
#include<windows.h>

#pragma comment(lib, "ws2_32.lib")
#pragma execution_character_set("gbk") 

#define FILE_NAME_MAX_SIZE 512 
#define BUFFER_SIZE 1024 
using namespace std;
 
SOCKET m_Client; 

//先发送文件名，再接收文件数据
void RecvFile(){

	 // 输入文件名 并放到缓冲区buffer中等待发送 
  	char file_name[FILE_NAME_MAX_SIZE+1]; 
  	memset(file_name,0,sizeof(file_name));
	cout<<"Please Input File Name On Server:\t"<<endl;
	cin>>file_name;
	char buffer[BUFFER_SIZE];
	memset(buffer,0,sizeof(buffer));
	strncpy(buffer, file_name, strlen(file_name)>BUFFER_SIZE?BUFFER_SIZE:strlen(file_name)); 
	// 向服务器发送buffer中的数据 
  	if(send(m_Client, buffer, BUFFER_SIZE, 0) < 0) 
  	{ 
    	perror("Send File Name Failed:"); 
    	exit(1); 
  	} 

	cout<<"start recv!"<<endl;
	memset(buffer,0,sizeof(buffer));
	int readLen = 0;
	string desFileName = strrchr(file_name,'\\')+1;	//去掉文件路径，只获取文件名，文件保存在和client同一位置下。
	cout<<desFileName<<endl;
	ofstream desFile;
	desFile.open(desFileName.c_str(), ios::binary);
	if (!desFile)
	{
	    return ;
	}
	do 
	{
	    readLen = recv(m_Client,buffer,BUFFER_SIZE, 0);
	    if (readLen == 0)
	    {
	        break;
	    }
	    else
	    {
	        desFile.write(buffer, readLen);
	    }
	} while(true);
	desFile.close();
}

int main()
{
	SetConsoleOutputCP(65001);//用于解决中文乱码问题

	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if(WSAStartup(sockVersion, &data)!=0)
	{
		return 0;
	}
	//while(true){
		m_Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(m_Client == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}
		
		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(8888);
		serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		if(connect(m_Client, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{  //连接失败 
			printf("connect error !");
			closesocket(m_Client);
			return 0;
		}
		RecvFile();
		closesocket(m_Client);
	//}
	
	
	WSACleanup();
	return 0;
	
}



