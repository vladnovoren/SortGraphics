#ifndef GUI_CONTENT_MAIN_WINDOW_HPP
#define GUI_CONTENT_MAIN_WINDOW_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_window.hpp"
#include "gui_tool_bar.hpp"


namespace gui {
  class ContentMainWindow: public AbstractContainerWidget {
   protected:
    ContentMainWindow() = default;
   public:
    ~ContentMainWindow() override = default;

    static ContentMainWindow* GetInstance();

    void AddWindow(Window* window);
  };
}


#endif /* gui_content_main_window.hpp */
