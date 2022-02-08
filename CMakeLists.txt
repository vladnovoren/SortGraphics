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

set(APP_SOURCE src/app.cpp
               src/plot_widget.cpp
               src/main.cpp
               src/sorting_system.cpp
               src/sort_plots_widget.cpp
               src/clear_plot_functor.cpp
               src/draw_func_plot_functor.cpp
)

add_subdirectory(gui/)

add_executable(SortGraphics ${APP_SOURCE})

target_include_directories(SortGraphics PUBLIC include/ glib/include)
target_link_libraries(SortGraphics PUBLIC gui)
