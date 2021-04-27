#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <mqttClient.h>

//MQTT Credentials
const char *mqttServer = "hairdresser.cloudmqtt.com";
const int mqttPort = 15558;
const char *mqttUser = "trsuglpr";
const char *mqttPassword = "BHiAhqppjzqf";

char message_buff[100];

char *topic1;

int message1;

WiFiClient espClient;
PubSubClient client(espClient);

void setTopic1(char *t)
{
    topic1 = t;
}

char *getTopic1()
{
    return topic1;
}

void setMessage1(int m)
{
    message1 = m;
}

int getMessage1()
{
    return message1;
}

String byteToString(byte *payload, unsigned int length)
{
    unsigned int i;
    for (i = 0; i < length; i++)
    {
        message_buff[i] = char(payload[i]);
    }
    message_buff[i] = '\0';

    String message = String(message_buff);
    return message;
}

void callback(char *topic, byte *payload, unsigned int length)
{
    // Serial.print("Message arrived in topic: ");
    // Serial.println(topic);
    setTopic1(topic);
    Serial.print("topic in callback: ");
    Serial.println(topic);
    String message = byteToString(payload, length);

    int msg = message.toInt();
    Serial.print("Percent of brightness is: ");
    setMessage1(msg);
    Serial.println(msg);
}

void setClientData()
{
    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
}

void MQTTconnection()
{
    while (!client.connected())
    {
        // Serial.println("Connecting to MQTT...");
        if (client.connect("ESP32Client", mqttUser, mqttPassword))
        {
            Serial.println("connected to MQTT client");
            // Serial.println(client.state());
        }
        else
        {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    // return client;
}

char *strToChar(String text)
{
    char *textS;
    text.toCharArray(textS, 100);
    // return textS;

    int n = text.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, text.c_str());
    return char_array;
}

void publishTo(String topic, String message)
{
    // Serial.println("Trying to publish");

    char topicChar[topic.length()];
    char messageChar[message.length()];

    int i;
    for (i = 0; i < sizeof(topicChar); i++)
    {
        topicChar[i] = topic[i];
        // Serial.print(topicChar[i]);
    }

    int j;
    for (j = 0; j < sizeof(messageChar); j++)
    {
        messageChar[j] = message[j];
    }
    topicChar[i] = '\0';
    messageChar[j] = '\0';
    Serial.println("Size of TopicChar: ");
    Serial.println(sizeof(topicChar));
    Serial.println("Trying to pulish to: ");
    Serial.println(topicChar);

    client.publish(topicChar, messageChar);
    // Serial.println("Successfully published");
}

void subscribeTo(String topic)
{
    // Serial.println("Trying to Subscribe");
    if (topic == "all")
    {
        client.subscribe("switch/+");
    }
    else
    {
        String final = "switch/" + topic;
        char *finalV1;
        // final.toCharArray(finalV1,100);

        // declaring character array : p
        char p[final.length()];

        int i;
        for (i = 0; i < sizeof(p); i++)
        {
            p[i] = final[i];
        }
        p[i] = '\0';

        // Serial.println(final);
        Serial.print("Subscribing to: ");
        Serial.println(p);

        client.subscribe(p);
    }
    // Serial.println("Successfully Subscribed");
}

void clientloop()
{
    client.loop();
}