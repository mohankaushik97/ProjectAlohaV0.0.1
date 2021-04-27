#ifndef toggle_h
#define toggle_h

class switch1
{

public:
    int input1;

    hw_timer_t *timerS = NULL;
    portMUX_TYPE timerMuxS = portMUX_INITIALIZER_UNLOCKED;


    switch1(int i);

    void switchSetup();

    static void toggle1();

    void handleInterruptS1();
};

#endif