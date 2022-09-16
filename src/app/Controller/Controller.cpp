#include "Controller.h"
#include "DHT11.h"

Controller::Controller(Service *serv, ClockService *clockServ,TempHumidService *tempHumidService)
{
    this -> service = serv;
    this -> clockService = clockServ;
    this -> tempHumidService = tempHumidService;
    this -> lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }


    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
}

void Controller::updateTempHumid(DHT_Data DHT_Data)
{
    tempHumidService -> updateEvent(DHT_Data);
}