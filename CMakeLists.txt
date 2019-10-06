cmake_minimum_required(VERSION 3.14)
project(PSO_Absolute)

set(CMAKE_CXX_STANDARD 14)

add_executable(PSO_Absolute main.cpp Particle.h Particle.cpp PSO_Absolute.h PSO_Absolute.cpp)