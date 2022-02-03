#include "gui_eraser.hpp"


gui::Eraser* gui::Eraser::GetInstance() {
  static Eraser* instance = new Eraser;
  return instance;
}


void gui::Eraser::Apply(Canvas* canvas) {
  assert(canvas != nullptr);

  glib::Vector2i prev_draw_point = canvas->GetPrevDrawPoint();
  glib::Vector2i curr_draw_point = canvas->GetCurrDrawPoint();

  if (prev_draw_point == curr_draw_point) {
    canvas->DrawCircle(glib::IntCircle(curr_draw_point, m_thickness),
                       glib::ColorRGBA(0, 0, 0, 0), glib::BlendMode::COPY);
  } else {
    canvas->DrawLine(glib::IntLine(curr_draw_point, prev_draw_point, m_thickness),
                     glib::ColorRGBA(0, 0, 0, 0), glib::BlendMode::COPY);
  }
}
