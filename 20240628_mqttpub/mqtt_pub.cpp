#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <mosquitto.h>
#include <string.h>

#include <chrono>
#include <thread>

void on_connect(struct mosquitto *mosq, void *userdata, int rc) {
    if(!rc) {
        std::cout << "Connected successfully." << std::endl;
        // 发送消息的函数调用可以在这里进行
    } else {
        std::cerr << "Connect failed with code " << rc << std::endl;
    }
}


int main() {

    std::ifstream file("imu.txt"); // 替换为你的文件名
    std::vector<std::string> lines;
    std::string line;
 
    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }
 

    struct mosquitto *mosq = mosquitto_new(NULL, true, NULL);
    if(!mosq) {
        std::cerr << "Could not create Mosquitto object." << std::endl;
        return 1;
    }
 
    mosquitto_connect_callback_set(mosq, on_connect);
 
    int ret = mosquitto_connect(mosq, "localhost", 1883, 60);
    if(ret) {
        std::cerr << "Unable to connect to Mosquitto broker." << std::endl;
        return 1;
    }
 
    // mosquitto_loop_start(mosq);
    while(true)
    {
            // 输出文件的每一行
        for (const auto& payload : lines) {
            // std::cout << l << std::endl;

            mosquitto_publish(mosq, NULL, "test_topic", strlen(payload.c_str() ), payload.c_str() , 0, false);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

    }
 
    // ret = mosquitto_loop_forever(mosq, -1, 1);
 
    // mosquitto_destroy(mosq);
    // return ret;
    return 0;

}
