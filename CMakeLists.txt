
cmake_minimum_required(VERSION 3.5)
project(blocker LANGUAGES CXX VERSION 0.1.0)



set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")



find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)



add_executable(blocker
	src/Input.cpp
	src/main.cpp
	src/Window.cpp
	src/Vec2.cpp
)



target_link_libraries(blocker PRIVATE SDL2::SDL2 ${SDL2_TTF_LIBRARIES})



target_include_directories(blocker PRIVATE src)



# For warnings with different compilers. See here: https://codingnest.com/basic-cmake/

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options(blocker PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    target_compile_options(blocker PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn )
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options(blocker PRIVATE /W4 /w44265 /w44061 /w44062 )
endif()
