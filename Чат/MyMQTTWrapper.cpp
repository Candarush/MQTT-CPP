#include "/usr/local/include/mosquittopp.h"
#include "MyMQTTWrapper.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <locale>

 
using namespace std;

MyMqttWrapper::MyMqttWrapper(const char *id, const char *host, int port) : mosquittopp(id)
{
    int keepalive = 60;
    connect(host, port, keepalive);
    printf("Создал MQTTwrapper.\n");
};

void MyMqttWrapper::on_connect(int rc)
{
    if (rc == 0)
    {
        subscribe(NULL, "M30-212B-18/Game");
    }
}
void MyMqttWrapper::on_message(const struct mosquitto_message *message){
    setlocale(LC_CTYPE, "rus");
    if(!strcmp(message->topic, "M30-212B-18/Game")){
        printf("%s\n",message->payload);
    }
};

bool MyMqttWrapper::send_message(const  char * message)
{
int ret = publish(NULL,"M30-212B-18/Game",(int)strlen(message),message,2,false);
return ( ret == MOSQ_ERR_SUCCESS );
}

void MyMqttWrapper::on_subcribe(int mid, int qos_count, const int *granted_qos)
{
    printf("Подключение успешно.\n");
}
