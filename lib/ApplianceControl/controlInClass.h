#ifndef controlInClass_h
#define controlInClass_h

#include "Arduino.h"
#define PRESCALER 128

char *getTopic();

int getMessage();

class control1
{
public:
    int abc;

    char *oldTopic;
    String oldMessage;

    int zeroCross1;
    int output1;
    int switch1;

    int brightness1;
    int interrupt1 = 1000;
    int oldBrightness1 = 0;

    #define TIMER0 0
    bool powerOn1 = false;


    hw_timer_t *timer1 = NULL;
    portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

    static void onTime1();

    control1(int o, int z, int s);

    static void crossing1();

    void handleInterrupt1();

    void handleTimerInterrupt1();

    void setupControl1();

    void switchToggle();

};

#endif