# TrafficSimulationSystem

## Overview
**TrafficSimulationSystem** is a C++ project that simulates traffic light control and traffic flow at an intersection. The system uses random traffic density and light timing to model real-world traffic behavior. It operates in a command-line interface, simulating cycles of red, yellow, and green traffic lights while adjusting the flow based on the current traffic count.

## Features

- **Traffic Light Simulation**: Simulates the three traffic light states (RED, YELLOW, GREEN).
- **Traffic Flow Estimation**: Traffic density is randomly adjusted, with new cars arriving based on traffic light state.
- **Randomized Traffic Count**: Simulated traffic flow increases or decreases depending on the state of the traffic light.
- **Command-line Interface**: Interact with the system via terminal/command-line for simulation output.
- **Customizable Simulation Cycles**: The system simulates 10 cycles of traffic light changes by default.

## Technologies Used

- **C++**: The main programming language for implementing the simulation.
- **C++ Standard Library**: Used for input/output, random number generation, and time handling.
- **CMake**: For building the project.

## Installation

To run the **TrafficSimulationSystem**, you need to build it using **CMake**.

### Prerequisites

- A C++ compiler (e.g., GCC, Clang).
- CMake (for building the project).

### Steps

1. **Clone the repository**:
    ```bash
    git clone https://github.com/kanyutu707/TrafficSimulationSystem.git
    ```

2. **Navigate into the project directory**:
    ```bash
    cd TrafficSimulationSystem
    ```

3. **Create a build directory**:
    ```bash
    mkdir build
    cd build
    ```

4. **Generate the build system using CMake**:
    ```bash
    cmake ..
    ```

5. **Build the project**:
    ```bash
    cmake --build .
    ```

6. **Run the simulation**:
    ```bash
    ./TrafficSimulationSystem
    ```

## Usage

The system simulates 10 traffic light cycles, outputting traffic light states and traffic counts to the command line. You can adjust the number of cycles and observe the traffic flow during each state of the light (RED, YELLOW, GREEN).

### Example Output

```
Traffic Simulation Started
Initial traffic count: 15
----------------------------------------
14:32:12 - Light is: RED | Traffic count: 15
Traffic is moderate. Waiting for 60 seconds...
3 new cars arrived during RED light
----------------------------------------
14:33:12 - Light is: YELLOW | Traffic count: 18
Yellow light. Waiting for 10 seconds...
2 new cars arrived during YELLOW light
----------------------------------------
14:33:22 - Light is: GREEN | Traffic count: 20
Green light. Cars are passing...
3 cars passed during GREEN light
----------------------------------------
...
Simulation completed after 10 cycles.
Final traffic count: 8
```

### How the Simulation Works:

- **RED Light**: The system waits for a duration (30, 60, or 120 seconds) based on the current traffic count, and new cars are added to the traffic density.
- **YELLOW Light**: A brief wait (10 seconds), with a smaller number of new cars added to the traffic.
- **GREEN Light**: Vehicles pass through the intersection, decreasing the traffic count. The number of passing cars is randomized but cannot exceed the current traffic count.

## Code Breakdown

- **trafficLight.hpp**: Contains the `trafficLight` class, which manages the traffic light states (RED, YELLOW, GREEN) and handles state transitions.
- **trafficDensityCounter.hpp**: Contains the `trafficDensityCounter` class, which tracks the number of cars at the intersection and updates the count as cars arrive or leave.

## Contributing

If you would like to contribute to the development of this project, please fork the repository, create a new branch, and submit a pull request. Contributions are always welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
