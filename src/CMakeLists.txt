add_executable(project_kappa main.cpp)

add_subdirectory(engine)
add_subdirectory(scenes)

target_include_directories(project_kappa PRIVATE "vendor")

target_link_libraries(
  project_kappa
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          kappa_engine
          project_kappa_scenes)
