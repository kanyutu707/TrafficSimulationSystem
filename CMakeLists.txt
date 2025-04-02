cmake_minimum_required(VERSION 3.10)
project(TrafficSimulation)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(traffic_simulation
    main.cpp
    trafficLight.cpp
    trafficDensityCounter.cpp
)


target_include_directories(traffic_simulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


find_package(Threads REQUIRED)
target_link_libraries(traffic_simulation PRIVATE Threads::Threads)


if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(traffic_simulation PRIVATE -Wall -Wextra -pedantic)
endif()

install(TARGETS traffic_simulation DESTINATION bin)