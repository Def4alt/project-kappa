cmake_minimum_required(VERSION 3.15)

project(project_kappa LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_VERBOSE_MAKEFILE on)

list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/dependencies/GLEW")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory("dependencies/spdlog")
add_subdirectory("src")

if (MSVC)
	target_compile_options(project_kappa PRIVATE /W4)
else()
	target_compile_options(project_kappa PRIVATE -Wall -Wextra -Wpedantic)
endif()
