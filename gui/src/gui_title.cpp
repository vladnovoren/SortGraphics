#include "gui_title.hpp"


gui::Title::Title(const char* label, const glib::Vector2i& center_position,
                  unsigned int font_size) {
  assert(label != nullptr);

  m_location.m_position = center_position;
  SetLabel(label);
  SetFontSize(font_size);
}


void gui::Title::SetText(const glib::Text& text) {
  m_text = text;
}


void gui::Title::SetLabel(const char* label) {
  assert(label != nullptr);

  m_text.SetLabel(label);
}


void gui::Title::SetFontSize(unsigned int font_size) {
  m_text.SetFontSize(font_size);
}


void gui::Title::Draw(glib::RenderTarget* render_target, const glib::Vector2i& position) {
  assert(render_target != nullptr);

  render_target->RenderText(&m_text, position);
}
