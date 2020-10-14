add_executable(project_kappa main.cpp)
target_link_libraries(
  project_kappa
  PRIVATE project_options
          project_warnings
	        CONAN_PKG::sdl2
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
