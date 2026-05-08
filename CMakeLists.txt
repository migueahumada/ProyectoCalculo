cmake_minimum_required(VERSION 3.11) 




project(Calculo)

set(CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} main.c)

if(APPLE)
  target_include_directories(${PROJECT_NAME} PUBLIC /Users/miko/Downloads/raylib-6.0_macos/include)
  target_link_libraries(${PROJECT_NAME}
    /Users/miko/Downloads/raylib-6.0_macos/lib/libraylib.a
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit")
endif(APPLE)

if(WIN32)
  
endif(WIN32)




