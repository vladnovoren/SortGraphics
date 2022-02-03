#include "gui_color_picker.hpp"


gui::ColorPicker& gui::ColorPicker::GetInstance() {
  static ColorPicker instance;
  return instance;
}


void gui::ColorPicker::SetColor(const glib::ColorRGBA& color) {
  m_curr_color = color;
}


glib::ColorRGBA gui::ColorPicker::GetColor() const {
  return m_curr_color;
}
