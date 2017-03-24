# Author: Sunil
cmake_minimum_required(VERSION 2.8)

# activae c++11 features
SET(CMAKE_CXX_FLAGS "-std=c++11")
SET(CMAKE_EXE_LINKER_FLAGS)

SET(TARGET rbtree)
SET(TEST_TARGET rbtree_tests)

# catch all warnings, no optimization and generate debug symbols
add_definitions("-Wall" "-O0 -g")

# file(GLOB TARGET_SRC ${CMAKE_SOURCE_DIR}/*.cpp)

project(${TARGET})

# add_executable(${TARGET} ${TARGET_SRC})
add_executable(${TARGET} main.cpp rbtree.cpp rbtree.hpp rbnode.cpp rbnode.hpp)
# target_link_libraries(${TARGET} gcov)

include_directories(utest/lib/include/)

find_library(
  GTEST googletest
  NAMES gtest
  PATHS ${CMAKE_CURRENT_SOURCE_DIR}/utest/lib/
  NO_DEFAULT_PATH)

find_library(
  GTESTMAIN googletest
  NAMES gtest_main
  PATHS ${CMAKE_CURRENT_SOURCE_DIR}/utest/lib/
  NO_DEFAULT_PATH)

add_executable(${TEST_TARGET} ../utest/rbtree_tests.cpp ../rbtree.cpp ../rbtree.hpp ../rbnode.hpp ../rbnode.cpp)
target_link_libraries(
  ${TEST_TARGET}
  PUBLIC ${GTEST} ${GTESTMAIN} pthread)

# install executable
install(
  TARGETS ${TARGET}
  DESTINATION bin)

# install test
install(
  TARGETS ${TEST_TARGET}
  DESTINATION bin)