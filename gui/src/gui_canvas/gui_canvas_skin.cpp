#include "gui_canvas_skin.hpp"


gui::CanvasSkin::CanvasSkin(const CanvasSkin& other):
                 AbstractWidgetSkin(other.m_source_texture),
                 m_location(other.m_location) {}


void gui::CanvasSkin::Render(const glib::Vector2i& size) {
  m_render_texture.Resize(size);
  m_render_texture.Clear(glib::ColorRGBA(0, 0, 0, 0));
  size_t n_x = (size.x + m_location.m_size.x - 1) / m_location.m_size.x;
  size_t n_y = (size.y + m_location.m_size.y - 1) / m_location.m_size.y;
  glib::Vector2i curr_position;
  for (size_t i_y = 0; i_y < n_y; ++i_y) {
    curr_position.x = 0;
    for (size_t i_x = 0; i_x < n_x; ++i_x) {
      m_render_texture.CopyTexture(m_source_texture, curr_position);
      curr_position.x += m_location.m_size.x;
    }
    curr_position.y += m_location.m_size.y;
  }
  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}
