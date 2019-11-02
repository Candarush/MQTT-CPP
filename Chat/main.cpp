#include "MyMQTTWrapper.h"
#include "MyMQTTWrapper.cpp"
#include <string>
#include <iostream>
#include <thread>

using namespace std;

MyMqttWrapper * MyMQTT;

void MQTTloop(string nickname) {
    
    string cin_buffer;
    while (1)
    {
        while (cin>>cin_buffer)
        {
            cin_buffer = nickname + ": " + cin_buffer;
            if (MyMQTT->send_message(cin_buffer.c_str())) break;;
        }
    }
    
}

int main() {
    
    printf("Запуск!\n");
    
    printf("Введите логин: ");
    string nickname;
    cin>>nickname;
    
    mosqpp::lib_init();
    MyMQTT = new MyMqttWrapper(nickname.c_str(), "test.mosquitto.org", 1883);
    
    thread t = thread(MQTTloop, nickname);
    t.detach();
    
    MyMQTT->loop_forever();
    
    mosqpp::lib_cleanup();
    return 0;
}
