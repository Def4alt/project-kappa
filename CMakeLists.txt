cmake_minimum_required(VERSION 3.15)

project(project_kappa LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE on)

set(glew-cmake_BUILD_SHARED OFF CACHE BOOL "Build the shared glew library" FORCE)
set(ONLY_LIBS ON CACHE BOOL "Do not build executables" FORCE)
set(SDL_SHARED OFF)
set(BUILD_STATIC_LIBS TRUE)

add_subdirectory("dependencies/glew")
add_subdirectory("dependencies/sdl2")
add_subdirectory("dependencies/spdlog")
add_subdirectory("dependencies/glm")
add_subdirectory("src")

if (MSVC)
	target_compile_options(project_kappa PRIVATE /W4)
else()
	target_compile_options(project_kappa PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_compile_features(project_kappa PRIVATE cxx_std_11 cxx_nonstatic_member_init cxx_auto_type cxx_nullptr)
