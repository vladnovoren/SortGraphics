#include "gui_title_bar_skin.hpp"


gui::TitleBarSkin::TitleBarSkin(const glib::Texture& source_texture,
                                const glib::IntRect& left_all_location,
                                const glib::IntRect& left_origin_location,
                                const glib::IntRect& middle_all_location,
                                const glib::IntRect& middle_origin_location,
                                const glib::IntRect& right_all_location,
                                const glib::IntRect& right_origin_location):
                   AbstractWidgetSkin(source_texture),
                   m_left_all_location(left_all_location),
                   m_left_origin_location(left_origin_location),
                   m_middle_all_location(middle_all_location),
                   m_middle_origin_location(middle_origin_location),
                   m_right_all_location(right_all_location),
                   m_right_origin_location(right_origin_location) {}


gui::TitleBarSkin::TitleBarSkin(const TitleBarSkin& other):
                   AbstractWidgetSkin(other.m_source_texture),
                   m_left_all_location(other.m_left_all_location),
                   m_left_origin_location(other.m_left_origin_location),
                   m_middle_all_location(other.m_middle_all_location),
                   m_middle_origin_location(other.m_middle_origin_location),
                   m_right_all_location(other.m_right_all_location),
                   m_right_origin_location(other.m_right_origin_location) {}


glib::Vector2i gui::TitleBarSkin::GetAllSize(glib::Vector2i origin_size) {
  origin_size.x += m_left_all_location.m_size.x - m_left_origin_location.m_size.x;
  origin_size.x += m_right_all_location.m_size.x - m_right_origin_location.m_size.x;

  origin_size.y += m_middle_all_location.m_size.y - m_middle_origin_location.m_size.y;

  return origin_size;
}


void gui::TitleBarSkin::Render(const glib::Vector2i& size) {
  glib::Vector2i all_size = GetAllSize(size);

  m_render_texture.Resize(all_size);

  int n_middle = size.x - m_right_origin_location.m_size.x - m_left_origin_location.m_size.x;
  glib::Vector2i curr_position = m_left_all_location.m_position;
  m_render_texture.CopyTexture(m_source_texture, curr_position, m_left_all_location);
  curr_position.x += m_left_all_location.m_size.x;
  for (int i = 0; i < n_middle; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_middle_all_location);
    curr_position += glib::Vector2i(1, 0);
  }
  m_render_texture.CopyTexture(m_source_texture, curr_position, m_right_all_location);

  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::TitleBarSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                                           const glib::Vector2i& position) const {
  assert(render_target != nullptr);

  render_target->CopyTexture(m_texture, position + m_left_all_location.m_position - m_left_origin_location.m_position);
}
