#include "gui_select_panel.hpp"


gui::SelectPanel::SelectPanel(const glib::IntRect& location):
                  AbstractContainerWidget(location) {}


void gui::SelectPanel::AddSelectButton(SelectButton* select_button) {
  assert(select_button != nullptr);

  AddChild(select_button);
  m_select_buttons.push_front(select_button);
  select_button->SetOwner(this);
}


void gui::SelectPanel::SetActiveButton(SelectButton *select_button) {
  assert(select_button != nullptr);

  auto found_it = std::find(m_select_buttons.begin(), m_select_buttons.end(), select_button);
  if (found_it == m_select_buttons.end()) {
    PRINT_LINE_LOCATION
    printf("Bad select button!\n");
    return;
  }

  for (auto button_ptr: m_select_buttons) {
    assert(button_ptr != nullptr);
    if (button_ptr != select_button) {
      button_ptr->SetIdle();
    } else {
      button_ptr->SetPressed();
      button_ptr->m_is_selected = true;
    }
  }
}
