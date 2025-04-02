#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <string>

class trafficLight {
private:
    std::string state;
public:
    trafficLight();
    void changeState();
    std::string getState();
};

#endif 