#ifndef __DHT11_H__
#define __DHT11_H__

#include "DHT_Data.h"


class DHT11
{
private:
    int pinNumber;
    int data[5];
    

    void startTrigger();
    void waitResponse();
    void clearData();

public:
    DHT11(int pin);
    virtual ~DHT11();
    DHT_Data readData();
    DHT_Data dhtData;
};

#endif /* __DHT11_H__ */