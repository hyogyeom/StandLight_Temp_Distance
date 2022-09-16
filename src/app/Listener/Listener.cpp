#include "Listener.h"
#include <wiringPi.h>

Listener::Listener(Button *modeButton,Button *powerButton, Controller *control, ClockCheck *clock, DHT11 *dht11)
{
    this -> modeButton = modeButton;
    this -> powerButton = powerButton;
    this -> controller = control;
    this -> clockCheck = clock;
    this -> dht11 = dht11;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if(dht11 -> dhtData.Temp < 26)
    {
        if (modeButton->getState() == RELEASE_ACTIVE)
        {
            controller->updateEvent("modeButton");
        }

        if (powerButton->getState() == RELEASE_ACTIVE)
        {
            controller->updateEvent("powerButton");
        }

        if (clockCheck->isUpdate())
        {
            controller->updateEvent("clockUpdate");
        }
    }

    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11 -> readData();
        if(!dhtData.error)  // true
        {
            controller -> updateTempHumid(dhtData);
        }
    }

}