#ifndef __TEMPHUMIDSERVICE_H__
#define __TEMPHUMIDSERVICE_H__

#include "DHT_Data.h"
#include "TempHumidView.h"

#pragma once

class TempHumidService
{
private:
    TempHumidView *tempHumidView;

public:
    TempHumidService(TempHumidView *tempHumidView);
    ~TempHumidService();
    void updateEvent(DHT_Data dhtData);
};

#endif