add_library(project_kappa_scenes STATIC 
    ColorScene.cpp ColorScene.hpp)

target_link_libraries(project_kappa_scenes PRIVATE kappa_engine)