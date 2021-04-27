#include <Arduino.h>
#include "timerControlFromLib.h"
#define PRESCALER 80

// int timerNumber = 0;

int secCount = 0;
int minCount = 0;


portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTime1()
{
    Serial.print("Number of seconds: ");
    Serial.print(secCount);
    Serial.println("\t in timer: 0");
    secCount++;
}

void IRAM_ATTR onTime2()
{
    Serial.print("Number of seconds: ");
    Serial.print(secCount);
    Serial.println("\t in timer: 1");
    secCount++;
}

timerControl::timerControl(int control, int zero, int interrupt)
{
    this->outputPin1 = control;
    this->zeroCrossingPin1 = zero;
    this->interruptAt1 = interrupt;
}

// Runs the timer in the library
void timerControl::runTimer()
{
    setCpuFrequencyMhz(80);

    timer = timerBegin(TIMER0, PRESCALER, true);
    timerAttachInterrupt(timer, &onTime1, true);
    timerAlarmWrite(timer, interruptAt1, true);
    timerAlarmEnable(timer);
}

timerControl2::timerControl2(int control, int zero, int interrupt)
{
    this->outputPin2 = control;
    this->zeroCrossingPin2 = zero;
    this->interruptAt2 = interrupt;
}

// Runs the timer in the library
void timerControl2::runTimer2()
{
    setCpuFrequencyMhz(80);

    timer1 = timerBegin(TIMER1, PRESCALER, true);
    timerAttachInterrupt(timer1, &onTime2, true);
    timerAlarmWrite(timer1, interruptAt2, true);
    timerAlarmEnable(timer1);
}