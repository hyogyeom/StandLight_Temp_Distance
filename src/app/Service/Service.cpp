#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton" ) 
            {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton" ) 
            {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton" ) 
            {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }    
            else  //범위 밖 
            {
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_2:
            if (strState == "modeButton" ) 
            {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton" ) 
            {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }    
            else  //범위 밖 
            {
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_3:
            if (strState == "modeButton" ) 
            {
                lightState = LIGHT_4;  
            }
            if (strState == "powerButton" ) 
            {
                lightState = LIGHT_OFF;
            }

            if(bDistanceLight)
            {
                view->setState(lightState);
            }    
            else  //범위 밖 
            {
                view->setState(LIGHT_OFF);
            }


            
        break;
        case LIGHT_4:
            if (strState == "modeButton" ) 
            {
                lightState = LIGHT_5; 
            }
            if (strState == "powerButton" ) 
            {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)
            {
                view->setState(lightState);
            }    
            else  //범위 밖 
            {
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_5:
            if (strState == "modeButton" ) 
            {
                lightState = LIGHT_OFF;  
            }
            if (strState == "powerButton" ) 
            {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight)  // 범위 안 
            {
                view->setState(lightState);
            }    
            else  //범위 밖 
            {
                view->setState(LIGHT_OFF);
            }
        break;
    }
}

void Service::updateDistance(int distance)
{
    printf("distance : %d, %d\n" , distance,bDistanceLight);  // 카운트 변수 주고 count가 10이면 꺼지게 

    static int distancecount = 0;
    if(distance < 0 || distance >100 ) //light off
    {
        distancecount++;
        if(distancecount >10 )
        {
        bDistanceLight = false;
        view -> setState(LIGHT_OFF);
        }
        
    }
    else  //light on
    {
        distancecount = 0;
        bDistanceLight = true;
        view -> setState(lightState);
    }
}