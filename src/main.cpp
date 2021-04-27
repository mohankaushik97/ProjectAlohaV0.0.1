#include <Arduino.h>

#include <PubSubClient.h>
#include <WiFi.h>

#include <print.h>
#include <wifiAuto.h>
#include <mqttClient.h>
#include <timerControlFromLib.h>
#include <controlInClass.h>

const int potentiometerPin = 12;

// char message_buff[100];

// int interruptAt = 500;
int brightness = 0;
int oldBrightness = 0;

TaskHandle_t Task1;
TaskHandle_t Task2;

//Task1code: runs the mqttclient loop
void Task1code(void *pvParameters)
{
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());
  for (;;)
  {
    clientloop();
    vTaskDelay(10);
  }
}

void setup()
{
  Serial.begin(115200);
  // WiFi connection
  autoConnect();

  // // Mqtt Connection
  setClientData();
  MQTTconnection();

  subscribeTo("s1");
  subscribeTo("s2");
  subscribeTo("s3");
  subscribeTo("s4");
  publishTo("switch/s1", "50");
  Serial.println("publishing done");
  publishTo("switch/s2/state", "testing");

  // pinMode(potentiometerPin, INPUT);
  // brightness = analogRead(potentiometerPin);

  // TODO: Only one instance of timerConrtolFromLib code is running at once.

  // test test1 = test(10, 5);
  // test test2 = test(10, 20);
  // test1.addValues();
  // test2.addValues();

  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(

      Task1code, /* Task function. */
      "Task1",   /* name of task. */
      10000,     /* Stack size of task */
      NULL,      /* parameter of the task */
      1,         /* priority of the task */
      &Task1,    /* Task handle to keep track of created task */
      0);        /* pin task to core 0 */
  delay(500);

  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
  delayMicroseconds(500);
  control1 *cntrl = new control1(14, 13, 12);
  cntrl->setupControl1();
}

void loop()
{
  brightness = analogRead(potentiometerPin);
  if (brightness - oldBrightness >= 30 || oldBrightness - brightness >= 30)
  {
    oldBrightness = brightness;
  }
  // Serial.println("in loop");
  // interruptAt = getInterruptAt(oldBrightness);
  // Serial.println(interruptAt);
}

