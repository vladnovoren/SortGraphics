#ifndef GUI_MAIN_WINDOW_HPP
#define GUI_MAIN_WINDOW_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_window.hpp"
#include "gui_main_menu.hpp"
#include "gui_app_config.hpp"
#include "gui_tool_bar.hpp"
#include "gui_content_window.hpp"


namespace gui {
  class MainWindow: public AbstractContainerWidget {
   protected:
    MainWindow();
    ~MainWindow() = default;
   public:
    static MainWindow* GetInstance();

    glib::IntRect GetValidBoundsForContent() const override;

    void AddContentWindow();
    void AddMainMenu();
    void AddToolBar();
  };
}


#endif /* gui_main_window.hpp */
