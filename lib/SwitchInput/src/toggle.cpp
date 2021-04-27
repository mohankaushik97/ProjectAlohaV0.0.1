

#include "Arduino.h"
#include "controlInClass.h"
#include "toggle.h"
#include "mqttClient.h"

static switch1 *instanceS1;

switch1::switch1(int input)
{
    input1 = input;
}

void switch1::toggle1()
{
    instanceS1->handleInterruptS1();
}

void switch1::handleInterruptS1()
{
    if (topicLocal != NULL)
    {
        // Serial.println("topicLogic is not null");
        if (!strcmp(topicLocal, "switch/s1"))
        {
            int messageLocal = getMessage1();
            Serial.print("Topic: ");
            Serial.print(topicLocal);
            Serial.print("\t Message: ");
            Serial.print(messageLocal);
            interrupt1 = map(messageLocal, 0, 100, 250, 5000);
            Serial.print("\t Interrupt: ");
            Serial.println(interrupt1);
            timerAlarmWrite(timer1, interrupt1, true);
            timerAlarmEnable(timer1);
            powerOn1 = true;
        }
        else
        {

            Serial.println("there is something wrong");
        }
    }
    else
    {
        Serial.println("topicLocal is null");
    }
}

void switch1::switchSetup()
{
    setCpuFrequencyMhz(80);

    attachInterrupt(input1, toggle1, CHANGE);
    Serial.println("setupControl Reached");
}
