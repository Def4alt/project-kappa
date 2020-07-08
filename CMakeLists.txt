cmake_minimum_required(VERSION 3.16)
project(project_kappa)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_VERBOSE_MAKEFILE on)

add_subdirectory("src")
