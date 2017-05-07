# Author: Sunil
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# activae c++11 features
SET(CMAKE_CXX_FLAGS "-std=c++11")
SET(CMAKE_EXE_LINKER_FLAGS)
SET(TARGET hashtable)
SET(SOURCE Chaining.cpp Hashing.cpp PlayerInfo.cpp HashTable.cpp LinearProbing.cpp main.cpp)

# catch all warnings, no optimization and generate debug symbols
add_definitions("-Wall" "-O0 -g")

project(${TARGET})

add_executable(${TARGET} ${SOURCE})

# install executable
install(
  TARGETS ${TARGET}
  DESTINATION bin)
