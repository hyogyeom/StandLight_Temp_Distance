#include "TempHumidView.h"

TempHumidView::TempHumidView(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd)
{
    this -> lcd = lcd;
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff[30];

    if(temp >= 26)
    {
        sprintf(buff, "                ");
        lcd->WriteStringXY(0, 0, buff);
        sprintf(buff,"                 ");
        lcd->WriteStringXY(1, 0, buff);
        light1->Off();
        light2->Off();
        light3->Off();
        light4->Off();
        light5->Off();   
        sprintf(buff,"TEMP HIGH!!");
        lcd->WriteStringXY(0,0,buff);
        sprintf(buff,"WARNING!!");
        lcd->WriteStringXY(1,0,buff);   
    }
    else if(temp < 26)
    {
        char buff[30];
        sprintf(buff, "      ");
        lcd->WriteStringXY(0, 10, buff);
        sprintf(buff,"       ");
        lcd->WriteStringXY(1, 10, buff);
        sprintf(buff, " %.1fC",temp);
        lcd->WriteStringXY(0, 9, buff);
        sprintf(buff,"  %.1f%%",humid);
        lcd->WriteStringXY(1, 8, buff); 
        
    }
     lcd->backLightOn();

       
}