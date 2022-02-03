#ifndef GUI_SELECT_PANEL_HPP
#define GUI_SELECT_PANEL_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_select_button.hpp"


namespace gui {
  class SelectPanel: public AbstractContainerWidget {
   protected:
    std::list<SelectButton*> m_select_buttons;
   public:
    SelectPanel() = default;
    SelectPanel(const glib::IntRect& location);
    ~SelectPanel() = default;

    void AddSelectButton(SelectButton* select_button);
    void SetActiveButton(SelectButton* select_button);
  };
}


#endif /* gui_select_panel.hpp */
