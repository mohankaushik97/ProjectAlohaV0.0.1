#ifndef timerControlFromLib_h
#define timerControlFromLib_h
class timerControl
{
public:
    int outputPin1;
    int zeroCrossingPin1;
    int outputPin2;
    int zeroCrossingPin2;
    int interruptAt1;
    int interruptAt2;

    int secCount = 0;
    int minCount = 0;
    const int TIMER0 = 0;

    hw_timer_t *timer;
    hw_timer_t *timer1;

public:
    timerControl(int o1, int z1, int i1);
    // void setValues(int controlPin, int xerocrossPin, int timerNo, int interrupt);
    void runTimer();
};

class timerControl2
{
public:
    int outputPin2 = 10;
    int zeroCrossingPin2 = 12;
    int interruptAt2 = 0;

    int secCount = 0;
    int minCount = 0;
    const int TIMER1 = 1;

    hw_timer_t *timer;
    hw_timer_t *timer1;

public:
    timerControl2(int o1, int z1, int i1);
    // void setValues(int controlPin, int xerocrossPin, int timerNo, int interrupt);
    void runTimer2();
};

#endif