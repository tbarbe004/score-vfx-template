cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(NOT TARGET score_lib_base)
  include("${SCORE_SOURCE_DIR}/cmake/ScoreExternalAddon.cmake")
endif()

if(NOT TARGET score_plugin_gfx)
  message("Requires gfx plug-in")
  return()
endif()

project(score_addon_videomapping LANGUAGES CXX)

# General initialization
score_common_setup()

# Creation of the library
add_library(score_addon_videomapping
  Videomapping/Executor.hpp
  Videomapping/Metadata.hpp
  Videomapping/Process.hpp
  Videomapping/Layer.hpp
  Videomapping/Executor.cpp
  Videomapping/Process.cpp
  Videomapping/Node.hpp
  Videomapping/Node.cpp

  score_addon_videomapping.hpp
  score_addon_videomapping.cpp
)

# Link
target_link_libraries(score_addon_videomapping PUBLIC
  score_plugin_gfx
)

# Target-specific options
setup_score_plugin(score_addon_videomapping)

