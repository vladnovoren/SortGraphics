cmake_minimum_required(VERSION 3.16.3)

project(SortGraphics)

add_compile_options(
  -Wall
  -Wextra
  -Werror
  -Wpedantic

  -g
  -Og
  -fsanitize=address
)

add_link_options(
  -fsanitize=address
)

add_subdirectory(gui/)

add_executable(SortGraphics src/main.cpp)

target_include_directories(SortGraphics PUBLIC include/ glib/include)
