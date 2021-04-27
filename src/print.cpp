#include <Arduino.h>


void print(){
    Serial.println("Hello from other side");
}

int getInterruptAt(int brightness){
    int interruptAt = map(brightness,0,4095,240,5600);
    return interruptAt;
}