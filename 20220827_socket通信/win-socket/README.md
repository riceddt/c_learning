**程序作用：**

windows环境下使用C++&Socket实现文件传输

**具体：**

1.客户端输入想获取的服务器端文件的绝对路径，可接收服务器端发送的文件并保存在客户端所在路径。

2.客户端可直接输入文件名，可接收与服务器端同一路径下的文件。

执行程序：

```
g++ .\client.cpp -lwsock32 -o client

g++ .\server.cpp -lwsock32 -o  server
```

