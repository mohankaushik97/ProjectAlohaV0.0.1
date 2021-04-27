#ifndef mqttClient_h
#define mqttClient_h

#include <PubSubClient.h>


void setTopic1(char* t);

char* getTopic1();

void setMessage1(int m);

int getMessage1();

// Sets server data and callback function
void setClientData();

// Establishes the connection to the mqtt server
void MQTTconnection();

void publishTo(String topic, String message);

void subscribeTo(String topic);

void callback(char *topic, byte *payload, unsigned int length);

void clientloop();

#endif