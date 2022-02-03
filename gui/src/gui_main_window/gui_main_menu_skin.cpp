#include "gui_main_menu_skin.hpp"


gui::MainMenuSkin::MainMenuSkin(const MainMenuSkin& other):
                   AbstractWidgetSkin(other.m_source_texture),
                   m_location(other.m_location) {}


void gui::MainMenuSkin::Render(int length) {
  m_render_texture.Resize(glib::Vector2i(length, m_location.m_size.y));
  glib::Vector2i curr_position;
  for (int i = 0; i < length; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_location);
    ++curr_position.x;
  }
  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::MainMenuSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                                           const glib::Vector2i& position) const {
  assert(render_target != nullptr);

  render_target->CopyTexture(m_texture, position);
}
