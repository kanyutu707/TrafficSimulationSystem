#include "trafficLight.hpp"

trafficLight::trafficLight() {
    state = "RED";
}

void trafficLight::changeState() {
    if (state == "RED")
        state = "GREEN";
    else if (state == "GREEN")
        state = "YELLOW";
    else
        state = "RED";
}

std::string trafficLight::getState() {
    return state;
}