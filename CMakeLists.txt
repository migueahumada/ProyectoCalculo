cmake_minimum_required(VERSION 4.2) 

project(Calculo LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(README_FILE README.md)

set(HEADERS inc/Player.h)

set(SOURCES main.c
            src/Player.c)

set(RSC rsc/)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${README_FILE})

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




