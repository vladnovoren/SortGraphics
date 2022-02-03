#include "gui_color_select_functor.hpp"


gui::ColorSelectFunctor::ColorSelectFunctor(const glib::ColorRGBA& color):
                         m_color(color) {}


void gui::ColorSelectFunctor::operator()() {
  ColorPicker::GetInstance().SetColor(m_color);
}


void gui::ColorSelectFunctor::operator()(const glib::ColorRGBA& color) {
  m_color = color;
  operator()();
}


void gui::ColorSelectFunctor::SetColor(const glib::ColorRGBA& color) {
  m_color = color;
}


glib::ColorRGBA gui::ColorSelectFunctor::GetColor() const {
  return m_color;
}
