add_subdirectory(vendor/imgui)
add_subdirectory(vendor/stb_image)

add_library(kappa_engine STATIC 
    Game.cpp Game.hpp 
    Scene.hpp
    SceneMenu.cpp SceneMenu.hpp)

target_include_directories(kappa_engine PUBLIC "vendor" ".")

target_link_libraries(kappa_engine PUBLIC
    project_options
    project_warnings
    CONAN_PKG::spdlog
    CONAN_PKG::glew
    CONAN_PKG::fmt
    CONAN_PKG::sdl2
    imgui
    stb_image)
