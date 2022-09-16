#ifndef __SERVICE_H__
#define __SERVICE_H__

#include <string>
#include "View.h"
#include "LightState.h"

//enum {LIGHT_OFF, LIGHT_1, LIGHT_2, LIGHT_3, LIGHT_4, LIGHT_5};

class Service
{
private:
    int lightState;
    View *view;
    bool bDistanceLight;
    

public:
    Service(View *viewer);
    virtual ~Service();
    void updateState(std::string strState);
    void updateDistance(int distance);
};

#endif /* __SERVICE_H__ */