#include "gui_window_skin.hpp"


gui::WindowSkin::WindowSkin(const WindowSkin& other):
                 AbstractWidgetSkin(other.m_source_texture),
                 m_left_edge_location(other.m_left_edge_location),
                 m_left_bottom_angle_location(other.m_left_bottom_angle_location),
                 m_bottom_location(other.m_bottom_location),
                 m_right_bottom_angle_location(other.m_right_bottom_angle_location),
                 m_right_edge_location(other.m_right_edge_location) {}


glib::Vector2i gui::WindowSkin::GetAllSize(const glib::Vector2i& window_size) const {
  glib::Vector2i all_size = window_size;
  all_size.x += m_left_edge_location.m_size.x + m_right_edge_location.m_size.x;
  all_size.y += 2 * m_bottom_location.m_size.y;
  return all_size;
}


void gui::WindowSkin::Render(const glib::Vector2i& window_size,
                             const TitleBarSkin& title_bar_skin) {
  glib::Vector2i all_size = GetAllSize(window_size);
  m_render_texture.Resize(all_size);

  int height_without_title_bar = window_size.y - title_bar_skin.m_left_origin_location.m_size.y;

  glib::Vector2i curr_position(0, title_bar_skin.m_left_all_location.m_size.y);
  for (int i = 0; i < height_without_title_bar; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_left_edge_location);
    ++curr_position.y;
  }
  m_render_texture.CopyTexture(m_source_texture, curr_position, m_left_bottom_angle_location);
  curr_position.x += m_left_bottom_angle_location.m_size.x;
  for (int i = 0; i < window_size.x; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_bottom_location);
    ++curr_position.x;
  }
  m_render_texture.CopyTexture(m_source_texture, curr_position, m_right_bottom_angle_location);
  --curr_position.y;
  for (int i = 0; i < height_without_title_bar; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_right_edge_location);
    --curr_position.y;
  }
  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::WindowSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                                         const glib::Vector2i& window_position) const {
  assert(render_target != nullptr);

  render_target->CopyRenderTexture(m_render_texture, window_position - glib::Vector2i(WINDOW_SHADOW_THICKNESS, WINDOW_SHADOW_THICKNESS));
}
