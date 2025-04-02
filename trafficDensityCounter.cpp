#include "trafficDensityCounter.hpp"

trafficDensityCounter::trafficDensityCounter() {
    count = 0;
}

void trafficDensityCounter::increaseCount() {
    count++;
}

void trafficDensityCounter::decreaseCount() {
    if (count > 0) {
        count--;
    }
}

int trafficDensityCounter::getCount() {
    return count;
}