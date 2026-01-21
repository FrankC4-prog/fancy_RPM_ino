cmake_minimum_required(VERSION 3.5)

project(fancyRPM VERSION 1.0.3 LANGUAGES CXX)

file(GLOB_RECURSE FANCY_RPM_SRC "src/fkc4/fancy_rpm/*.cpp")
add_library(fancyRPM STATIC ${FANCY_RPM_SRC})

target_include_directories(fancyRPM PUBLIC "include/")

target_link_libraries(fancyRPM PUBLIC 
    ELMDuino 
    FastLED
)