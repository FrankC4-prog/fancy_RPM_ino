cmake_minimum_required(VERSION 3.5)

project(fancy_RPM VERSION 1.0.0 LANGUAGES CXX)

file(GLOB_RECURSE FANCY_RPM_SRC "src/*.cpp")
add_library(fancy_RPM STATIC ${FANCY_RPM_SRC})

target_include_directories(fancy_RPM PUBLIC ".")

target_link_libraries(fancy_RPM PUBLIC 
    ELMDuino 
    FastLED
)