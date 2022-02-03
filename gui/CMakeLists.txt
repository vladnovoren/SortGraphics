cmake_minimum_required(VERSION 3.16.3)

add_subdirectory(glib/)

set(GUI_SOURCE src/open_file.cpp
               src/gui_abstract_widget/gui_abstract_widget_functor.cpp
               src/gui_abstract_widget/gui_abstract_widget_skin.cpp

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

               src/gui_canvas/gui_canvas.cpp
               src/gui_events.cpp
               src/gui_abstract_container_widget.cpp
               src/gui_move_functor.cpp
               src/gui_main_window/gui_main_window.cpp
               src/gui_main_window/gui_main_menu.cpp
               src/gui_main_window/gui_content_window.cpp
               src/gui_main_window/gui_main_menu_skin.cpp
               src/gui_window/gui_window_skin.cpp

               src/gui_tools/gui_abstract_tool.cpp

               src/gui_tools/gui_brush.cpp
               src/gui_tools/gui_fill_bucket.cpp
               src/gui_tools/gui_tool_select_functor.cpp

               src/gui_tool_bar/gui_tool_bar.cpp
               src/gui_tool_bar/gui_tool_bar_skin.cpp

               src/gui_tool_bar/gui_color_picker/gui_color_picker.cpp
               src/gui_tool_bar/gui_color_picker/gui_color_select_functor.cpp

               src/gui_tool_bar/gui_select_panel/gui_select_panel.cpp

               src/gui_tool_bar/gui_select_panel/gui_color_select_button_skin.cpp
               src/gui_canvas/gui_canvas_skin.cpp

               src/gui_tools/gui_eraser.cpp
)


add_library(gui STATIC ${GUI_SOURCE})
target_include_directories(gui PUBLIC glib/include/
                                      include/
                                      include/gui_abstract_widget/
                                      include/gui_button/
                                      include/gui_button/gui_abstract_button/
                                      include/gui_canvas/
                                      include/gui_main_window/
                                      include/gui_tool_bar/
                                      include/gui_tool_bar/gui_color_picker/
                                      include/gui_tool_bar/gui_select_panel/
                                      include/gui_tools/
                                      include/gui_window
                                      include/gui_window/gui_title_bar
)
target_link_libraries(gui PUBLIC glib)
