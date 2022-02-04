cmake_minimum_required(VERSION 3.16.3)

add_subdirectory(glib/)

set(GUI_SOURCE src/open_file.cpp
               src/gui_abstract_widget/gui_abstract_widget.cpp
               src/gui_abstract_widget/gui_abstract_widget_functor.cpp
               src/gui_abstract_widget/gui_abstract_widget_skin.cpp
               src/gui_dummy_container_widget.cpp

               src/gui_button/gui_abstract_button/gui_abstract_button.cpp
               src/gui_button/gui_abstract_button/gui_abstract_button_skin.cpp
               src/gui_button/gui_select_button.cpp
               src/gui_button/gui_plain_button.cpp

               src/gui_skin_manager.cpp
               src/gui_widget_manager.cpp

               src/gui_title.cpp

               src/gui_window/gui_title_bar/gui_title_bar.cpp
               src/gui_window/gui_title_bar/gui_title_bar_skin.cpp
               src/gui_window/gui_window.cpp

               src/gui_events.cpp
               src/gui_abstract_container_widget.cpp
               src/gui_move_functor.cpp
               src/gui_window/gui_window_skin.cpp
)


add_library(gui STATIC ${GUI_SOURCE})
target_include_directories(gui PUBLIC glib/include/
                                      include/
                                      include/gui_abstract_widget/
                                      include/gui_button/
                                      include/gui_button/gui_abstract_button/
                                      include/gui_window
                                      include/gui_window/gui_title_bar
)
target_link_libraries(gui PUBLIC glib)
