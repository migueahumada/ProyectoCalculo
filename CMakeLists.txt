cmake_minimum_required(VERSION 3.11) 

project(Calculo LANGUAGES C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(README_FILE README.md)

set(HEADERS inc/CMath.h
            inc/Utils.h
            inc/Player.h)

set(SOURCES main.c
            src/Player.c
            src/Utils.c)

set(RESOURCES rsc/Panther.png)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${README_FILE} ${RESOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC inc)

if(APPLE)
  target_include_directories(${PROJECT_NAME} PUBLIC /Users/miko/Downloads/raylib-6.0_macos/include)
  target_link_libraries(${PROJECT_NAME}
    /Users/miko/Downloads/raylib-6.0_macos/lib/libraylib.a
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit")
endif(APPLE)

if(WIN32)
  target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/libs/raylib-6.0_win64_msvc16/include)
  
  target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/raylib-6.0_win64_msvc16/lib/raylib.lib winmm)
endif(WIN32)




