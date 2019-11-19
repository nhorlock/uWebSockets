# build uSocket examples
cmake_minimum_required(VERSION 3.7.2)
project(uWebSockets CXX)

file(GLOB UWS_SOURCES src/*)
#message("Using ${SOURCES} for uWebSockets")

include_directories(APPEND ${CMAKE_CURRENT_LIST_DIR}/src)

add_subdirectory(uSockets)
#add_subdirectory(benchmarks)
#add_subdirectory(fuzzing)
add_library(uWebSockets INTERFACE ${UWS_SOURCES} uSockets)
target_sources(uWebSockets PUBLIC ${UWS_SOURCES})
target_include_directories(uWebSockets INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set_target_properties(uWebSockets PROPERTIES LINKER_LANGUAGE CXX)
#add_subdirectory(examples)
