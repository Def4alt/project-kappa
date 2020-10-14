#include <functional>
#include <iostream>
#include <spdlog/spdlog.h>

#include <docopt/docopt.h>

#include <SDL2/SDL.h>
#include <stdio.h>

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#undef main

#define IMGUI_IMPL_OPENGL_LOADER_GLEW

static constexpr auto USAGE =
    R"(Project Kappa.

    Usage:
        project_kappa [options]

 	Options:
        -h --help         Print help.
        --width=WIDTH     Width of the main window [default: 800].
        --height=HEIGHT   Height of the main window [default: 600].
)";

int main(int argc, const char **argv) {

  std::map<std::string, docopt::value> args =
      docopt::docopt(USAGE, {std::next(argv), std::next(argv, argc)}, true,
                     "Project Kappa 1.0");

  for (auto const &arg : args) {
    if (arg.second.isString()) {
      spdlog::info("Parameter set: {} '{}'", arg.first, arg.second.asString());
    }
  }

  const auto width = args["--width"].asLong();
  const auto height = args["--height"].asLong();

  SDL_Window *window = NULL;
  SDL_Surface *screenSurface = NULL;

  window = SDL_CreateWindow("Project Kappa", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, width, height,
                            SDL_WINDOW_SHOWN);

  if (window == NULL) {
    spdlog::error("Could not create window: {}", SDL_GetError());
    abort();
  }

  screenSurface = SDL_GetWindowSurface(window);

  SDL_FillRect(screenSurface, NULL,
               SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));

  SDL_UpdateWindowSurface(window);

  SDL_Delay(2000);

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
