#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidService.h"
#include "TempHumidView.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Button modebutton(27);
    Button powerbutton(28);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView temphumidView(&led1, &led2, &led3, &led4, &led5,&lcd);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockSerivce(&clockView);
    TempHumidService tempHumidService(&temphumidView);
    Controller control(&service, &clockSerivce,&tempHumidService);
    Listener listener(&modebutton,&powerbutton, &control, &clockCheck, &dht);
    

    while (1)
    {
        listener.checkEvent();
        if(dht.dhtData.Temp < 26)
        {
            view.lightView();
        }
        delay(100);
    }

    return 0;
}