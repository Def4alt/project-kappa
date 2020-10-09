cmake_minimum_required(VERSION 3.15)

add_subdirectory("engine")

add_executable(project_kappa
    main.cpp
    game.h game.cpp
    scenes/scene_texture_2d.cpp scenes/scene_texture_2d.h 
    scenes/scene_batch_rendering.cpp scenes/scene_batch_rendering.h
    scenes/scene.h
    scenes/scene_menu.cpp scenes/scene_menu.h
    scenes/scene_clear_color.cpp scenes/scene_clear_color.h
    scenes/scene_astronomy.cpp scenes/scene_astronomy.h)

target_link_libraries(project_kappa PRIVATE project_kappa_engine)

file(COPY "${PROJECT_SOURCE_DIR}/assets" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
