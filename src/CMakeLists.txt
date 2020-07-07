cmake_minimum_required(VERSION 3.16)

set(GLEW_USE_STATIC_LIBS TRUE)
add_definitions("-DGLEW_STATIC")

list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/dependencies/GLEW")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(SDL2_DIR "${PROJECT_SOURCE_DIR}/dependencies/SDL2")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(project_kappa
        main.cpp
        logger.cpp logger.h
        index_buffer.cpp index_buffer.h
        error.cpp error.h
        vertex_buffer.cpp vertex_buffer.h
        vertex_array.cpp vertex_array.h
        vertex_buffer_layout.h
        shader.cpp shader.h
        texture.cpp texture.h
        renderer.cpp renderer.h
        game.cpp game.h
        scenes/scene.h
        scenes/scene_menu.cpp scenes/scene_menu.h
        scenes/scene_clear_color.cpp scenes/scene_clear_color.h
        vendor/imgui/imgui.cpp
        vendor/imgui/imgui_demo.cpp
        vendor/imgui/imgui_draw.cpp
        vendor/imgui/imgui_impl_opengl3.cpp
        vendor/imgui/imgui_impl_sdl.cpp
        vendor/imgui/imgui_widgets.cpp
        vendor/stb_image/stb_image.cpp)

include_directories(${SDL2_INCLUDE_DIR} "vendor" ".")
target_link_libraries(project_kappa ${SDL2_LIBRARY} GLEW::GLEW OpenGL::GL)

file(COPY "${PROJECT_SOURCE_DIR}/assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        file(COPY "${SDL2_DIR}/lib/x64/SDL2.dll"
                DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    else()
        file(COPY "${SDL2_DIR}/lib/x86/SDL2.dll"
                DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    endif()
endif()