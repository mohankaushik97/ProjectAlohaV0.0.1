// #include <Arduino.h>

// #define PRESCALER 128
// #define TIMER_NUMBER 0

// int zeroCrossingPin = 13; // Interrupt Pin Input Pullup!
// int outputPin = 14;       // Output Dimming control.
// // const int zeroCrossingPin2 = 13;  // Need to change the pins numbers
// // const int outputPin2 = 14;
// const int powerPin = 25;
// const int groundPin = 33;


// int brightness;
// int interruptAt = 5200;
// int oldBrightness = 0;
// bool powerOn = false;

// hw_timer_t *timer = NULL;
// portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

// void setConsts(int controlPin, int zerocrossPin){
//     outputPin = controlPin;
//     zerocrossPin = zerocrossPin;
// }

// void IRAM_ATTR onTime()
// {
    // if (powerOn)
    // {
    //     digitalWrite(outputPin, LOW);
    //     powerOn = false;
    // }
// }

// void crossing()
// {
//     // Serial.println("Zerocrossing");
//     if (!powerOn)
//     {
//         timerRestart(timer);
//         digitalWrite(outputPin, HIGH);
//         interruptAt = map(oldBrightness, 0, 4096, 240, 5600);
//         timerAlarmWrite(timer, interruptAt, true);
//         timerAlarmEnable(timer);
//         powerOn = true;
//         // Serial.println(interruptAt);
//         // Serial.println("Zerocrossing");
//     }
// }

// void setupControl()
// {
//     setCpuFrequencyMhz(80);
//     Serial.println(getCpuFrequencyMhz());

//     Serial.println(zeroCrossingPin);

//     pinMode(zeroCrossingPin, INPUT_PULLUP);
//     pinMode(outputPin, OUTPUT);
//     pinMode(powerPin, OUTPUT);
//     pinMode(groundPin, OUTPUT);

//     digitalWrite(powerPin, HIGH);
//     digitalWrite(groundPin, LOW);

//     timer = timerBegin(TIMER_NUMBER, PRESCALER, true);
//     timerAttachInterrupt(timer, &onTime, true);
//     timerAlarmWrite(timer, interruptAt, true);
//     timerAlarmEnable(timer);
//     attachInterrupt(zeroCrossingPin, crossing, FALLING);

//     digitalWrite(outputPin, LOW);
//     // TODO: get the brightness values from mqtt

// }


// hw_timer_t *timer = NULL;
// portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
