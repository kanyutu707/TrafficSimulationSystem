#ifndef TRAFFIC_DENSITY_COUNTER_H
#define TRAFFIC_DENSITY_COUNTER_H

class trafficDensityCounter {
private:
    int count;
public:
    trafficDensityCounter();
    void increaseCount();
    void decreaseCount();
    int getCount();
};

#endif 