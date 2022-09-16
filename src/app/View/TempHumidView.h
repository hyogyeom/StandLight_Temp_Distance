#ifndef __TEMPHUMIDVIEW_H__
#define __TEMPHUMIDVIEW_H__

#pragma once

#include "LCD.h"
#include "Led.h"

class TempHumidView
{

private:
    LCD *lcd;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;

    
public:
    TempHumidView(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5,LCD *lcd);
    ~TempHumidView();
    void setTempHumidData(float temp, float humid);



};

#endif