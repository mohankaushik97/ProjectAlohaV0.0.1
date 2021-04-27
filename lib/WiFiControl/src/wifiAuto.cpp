#include <Arduino.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

void autoConnect()
{

    WiFi.mode(WIFI_STA);

    WiFiManager wm;

    // reset settings - wipe credentials for testing
    // wm.resetSettings();

    bool res;
    res = wm.autoConnect("AutoConnectAP"); // anonymous ap

    if (!res)
    {
        Serial.println("Failed to connect");
        // ESP.restart();
    }
    else
    {
        //if you get here you have connected to the WiFi
        Serial.println("connected...yeey :)");
        Serial.print("WiFi SSID: ");
        Serial.println(wm.getWiFiSSID());
    }
}

void manualConnect()
{
    WiFi.mode(WIFI_STA);
}