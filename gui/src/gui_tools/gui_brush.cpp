#include "gui_brush.hpp"


gui::Brush* gui::Brush::GetInstance() {
  static Brush* instance = new Brush;
  return instance;
}


void gui::Brush::Apply(Canvas* canvas) {
  assert(canvas != nullptr);

  glib::Vector2i prev_draw_point = canvas->GetPrevDrawPoint();
  glib::Vector2i curr_draw_point = canvas->GetCurrDrawPoint();

  glib::ColorRGBA color = ColorPicker::GetInstance().GetColor();

  if (prev_draw_point == curr_draw_point) {
    canvas->DrawCircle(glib::IntCircle(curr_draw_point, m_thickness), color);
  } else {
    canvas->DrawLine(glib::IntLine(curr_draw_point, prev_draw_point, m_thickness),
                     color);
  }
}
