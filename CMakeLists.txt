cmake_minimum_required(VERSION 3.0.0)
project(main)

add_executable(${PROJECT_NAME} src/main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")

add_subdirectory(string_io)
target_include_directories(${PROJECT_NAME} PUBLIC ${STRING_IO_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${STRING_IO_LIBRARIES})

add_subdirectory(view_composition)
target_include_directories(${PROJECT_NAME} PUBLIC ${VIEW_COMPOSITION_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${VIEW_COMPOSITION_LIBRARIES})

add_subdirectory(add_composition)
target_include_directories(${PROJECT_NAME} PUBLIC ${ADD_COMPOSITION_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ADD_COMPOSITION_LIBRARIES})

add_subdirectory(tests)
