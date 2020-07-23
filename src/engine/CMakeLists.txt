cmake_minimum_required(VERSION 3.15)

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
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui_demo.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_impl_opengl3.cpp
    vendor/imgui/imgui_impl_sdl.cpp
    vendor/imgui/imgui_widgets.cpp
    vendor/stb_image/stb_image.cpp 
    vertex.cpp vertex.h
    batch_renderer.cpp batch_renderer.h
    camera.cpp camera.h
    camera_controller.cpp camera_controller.h
    event.cpp event.h)

target_include_directories(project_kappa_engine PUBLIC "vendor" ".")
target_link_libraries(project_kappa_engine PUBLIC SDL2-static spdlog::spdlog libglew_static)

# if(WIN32)
#     target_compile_definitions(project_kappa_engine PUBLIC "-DGLEW_STATIC")

#     if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#         file(COPY "${SDL2_DIR}/lib/x64/SDL2.dll"
#                 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#     else()
#         file(COPY "${SDL2_DIR}/lib/x86/SDL2.dll"
#                 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#     endif()
# endif()
