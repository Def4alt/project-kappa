cmake_minimum_required(VERSION 3.15)

add_subdirectory("vendor/imgui")
add_subdirectory("vendor/stb_image")

add_library(project_kappa_engine STATIC
    logger.cpp logger.h
    index_buffer.cpp index_buffer.h
    debug.cpp debug.h
    vertex_buffer.cpp vertex_buffer.h
    vertex_array.cpp vertex_array.h
    vertex_buffer_layout.h
    shader.cpp shader.h
    texture.cpp texture.h
    renderer.cpp renderer.h
    vertex.cpp vertex.h
    batch_renderer.cpp batch_renderer.h
    camera.cpp camera.h
    camera_controller.cpp camera_controller.h
    event.cpp event.h)

target_include_directories(project_kappa_engine PUBLIC "." "vendor")

target_link_libraries(project_kappa_engine PUBLIC 
    SDL2-static spdlog::spdlog libglew_static glm::glm imgui stb_image)