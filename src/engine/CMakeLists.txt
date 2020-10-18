add_subdirectory(vendor/imgui)
add_subdirectory(vendor/stb_image)

add_library(kappa_engine STATIC 
    Game.cpp Game.hpp 
    Scene.hpp
    SceneMenu.cpp SceneMenu.hpp
    Renderer.cpp Renderer.hpp
    Sprite.cpp Sprite.hpp
    Texture.cpp Texture.hpp
    BatchRenderer.cpp BatchRenderer.hpp
    DefaultTypes.hpp
    VertexArray.cpp VertexArray.hpp
    VertexBuffer.cpp VertexBuffer.hpp
    IndexBuffer.cpp IndexBuffer.hpp
    VertexBufferLayout.hpp
    Vertex.cpp Vertex.hpp)

target_include_directories(kappa_engine PUBLIC "vendor" ".")

target_link_libraries(kappa_engine PUBLIC
    project_options
    project_warnings
    CONAN_PKG::spdlog
    CONAN_PKG::glew
    CONAN_PKG::fmt
    CONAN_PKG::sdl2
    CONAN_PKG::glm
    imgui
    stb_image)
