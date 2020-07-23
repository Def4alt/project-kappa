set(CORE_FILES imconfig.h
imgui.cpp imgui.h
imgui_demo.cpp
imgui_draw.cpp
imgui_impl_opengl3.cpp imgui_impl_opengl3.h
imgui_impl_sdl.cpp imgui_impl_sdl.h
imgui_internal.h
imgui_widgets.cpp
imstb_rectpack.h
imstb_textedit.h
imstb_truetype.h)

add_library(imgui STATIC ${CORE_FILES})
target_link_libraries(imgui PUBLIC SDL2-static libglew_static)
target_compile_definitions(imgui PUBLIC "-DIMGUI_IMPL_OPENGL_LOADER_GLEW")