#include "Arduino.h"
#include <controlInClass.h>
#include <mqttClient.h>

char *oldTopic;
int oldMessage;
static control1 *instance1;

char *getTopic()
{
    if (oldTopic != getTopic1())
    {
        // Serial.print("Topic: ");
        // Serial.println(getTopic1());
        oldTopic = getTopic1();
        ;
        return oldTopic;
    }
    return NULL;
}

int getMessage()
{
    if (oldMessage != getMessage1())
    {
            Serial.print("Topic: ");
            Serial.print(getTopic());
            Serial.print("\t Message: ");
            Serial.println(getMessage());
        oldMessage = getMessage1();
        return oldMessage;
    }
    return NULL;
}

control1::control1(int o, int z, int s)
{
    output1 = o;
    zeroCross1 = z;
    switch1 = s;
    instance1 = this;
}

void IRAM_ATTR control1::onTime1()
{
    // Serial.println("Inside onTime1");
    // timer interrupt
    instance1->handleTimerInterrupt1();
}

void IRAM_ATTR control1::handleTimerInterrupt1()
{
    // Serial.println("inside HandleTimerInterrupt(Timer)");
    if (powerOn1)
    {
        // Serial.println("Power is on!!");
        digitalWrite(output1, LOW);
        powerOn1 = false;
        // Serial.print("1 ");
    }
}

void IRAM_ATTR control1::crossing1()
{
    // Serial.println("Inside crossing1");
    // zerocrossing interrupt
    instance1->handleInterrupt1();
}

void IRAM_ATTR control1::handleInterrupt1()
{
    // Serial.println("Inside handleInterrupt(Crossing)");
    if (!powerOn1)
    {

        timerRestart(timer1);
        digitalWrite(output1, HIGH);
        char *topicLocal = getTopic1();
        // Serial.print("got topic from getTopic: ");
        // Serial.print("topic right now is: ");
        // Serial.println(topicLocal);
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
}

void control1::setupControl1()
{
    setCpuFrequencyMhz(80);

    // Serial.println(zeroCross1);
    pinMode(zeroCross1, INPUT_PULLUP);
    pinMode(output1, OUTPUT);
    // Serial.print("Output pin is: ");
    // Serial.print(output1);
    // Serial.print("\t Zerocrossing pin is: ");
    // Serial.print(zeroCross1);
    timer1 = timerBegin(TIMER0, PRESCALER, true);
    timerAttachInterrupt(timer1, &onTime1, true);
    timerAlarmWrite(timer1, interrupt1, true);
    Serial.print("Interrupt Value: ");
    Serial.println(interrupt1);
    timerAlarmEnable(timer1);
    attachInterrupt(zeroCross1, crossing1, FALLING);
    Serial.println("setupControl Reached");
}


