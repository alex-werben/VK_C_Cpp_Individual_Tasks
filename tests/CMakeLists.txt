cmake_minimum_required(VERSION 3.0.0)
project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

file(GLOB SOURCES *.cpp)

find_package(GTest CONFIG REQUIRED) 

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${VIEW_COMPOSITION_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${VIEW_COMPOSITION_LIBRARIES} GTest::gtest_main)

target_include_directories(${PROJECT_NAME} PUBLIC ${ADD_COMPOSITION_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${ADD_COMPOSITION_LIBRARIES} GTest::gtest_main)

target_include_directories(${PROJECT_NAME} PUBLIC ${STRING_IO_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${STRING_IO_LIBRARIES} GTest::gtest_main)
