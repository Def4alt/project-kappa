cmake_minimum_required(VERSION 3.15)

project(project_kappa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_VERBOSE_MAKEFILE on)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(GLEW_VERBOSE TRUE)

set(glew-cmake_BUILD_SHARED OFF CACHE BOOL "Build the shared glew library" FORCE)
set(ONLY_LIBS ON CACHE BOOL "Do not build executables" FORCE)

add_subdirectory("dependencies/glew")
add_subdirectory("dependencies/spdlog")
add_subdirectory("src")

if (MSVC)
	target_compile_options(project_kappa PRIVATE /W4)
else()
	target_compile_options(project_kappa PRIVATE -Wall -Wextra -Wpedantic)
endif()
