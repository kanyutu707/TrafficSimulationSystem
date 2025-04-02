#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "trafficLight.hpp"
#include "trafficDensityCounter.hpp"

std::string getCurrentTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
    return std::string(buf);
}

int main() {
  
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    trafficLight t;
    trafficDensityCounter c;

    for (int i = 0; i < 15; i++) {
        c.increaseCount();
    }
    
    std::cout << "Traffic Simulation Started\n";
    std::cout << "Initial traffic count: " << c.getCount() << "\n";
    std::cout << "----------------------------------------\n";
    
    int cycleCount = 0;
    
    while (cycleCount < 10) {
        std::string currentState = t.getState();
        std::cout << getCurrentTime() << " - Light is: " << currentState 
                  << " | Traffic count: " << c.getCount() << std::endl;
        
        if (currentState == "RED") {
            int waitTime = 30;
            if (c.getCount() < 10) { 
                waitTime = 30;
                std::cout << "Traffic is low. Waiting for " << waitTime << " seconds...\n";
                std::this_thread::sleep_for(std::chrono::seconds(waitTime));
            } else if (c.getCount() >= 10 && c.getCount() < 50) { 
                waitTime = 60;
                std::cout << "Traffic is moderate. Waiting for " << waitTime << " seconds...\n";
                std::this_thread::sleep_for(std::chrono::seconds(waitTime));
            } else { 
                waitTime = 120;
                std::cout << "Traffic is high. Waiting for " << waitTime << " seconds...\n";
                std::this_thread::sleep_for(std::chrono::seconds(waitTime));
            }
            
            int newCars = rand() % 5 + 1;
            for (int i = 0; i < newCars; i++) {
                c.increaseCount();
            }
            std::cout << newCars << " new cars arrived during RED light\n";
            
        } else if (currentState == "YELLOW") {
            std::cout << "Yellow light. Waiting for 10 seconds...\n";
            std::this_thread::sleep_for(std::chrono::seconds(10));
            
            int newCars = rand() % 3;
            for (int i = 0; i < newCars; i++) {
                c.increaseCount();
            }
            std::cout << newCars << " new cars arrived during YELLOW light\n";
            
        } else { 
            std::cout << "Green light. Cars are passing...\n";
            
            int passingCars = std::min(c.getCount(), rand() % 5 + 1);
            for (int i = 0; i < passingCars; i++) {
                c.decreaseCount();
            }
            std::cout << passingCars << " cars passed during GREEN light\n";
            
            std::this_thread::sleep_for(std::chrono::seconds(5)); 
        }
        
        t.changeState();
        cycleCount++;
        std::cout << "----------------------------------------\n";
    }
    
    std::cout << "Simulation completed after " << cycleCount << " cycles.\n";
    std::cout << "Final traffic count: " << c.getCount() << "\n";
    
    return 0;
}