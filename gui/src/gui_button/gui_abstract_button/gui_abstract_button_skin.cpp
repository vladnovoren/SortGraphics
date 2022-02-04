#include "gui_abstract_button_skin.hpp"


gui::AbstractButtonSkin::AbstractButtonSkin(const glib::Texture& source_texture,
                                            const glib::IntRect& idle_texture_location,
                                            const glib::IntRect& hovered_texture_location,
                                            const glib::IntRect& pressed_texture_location):
                         AbstractWidgetSkin(source_texture),
                         m_curr_texture_location(idle_texture_location),
                         m_idle_texture_location(idle_texture_location),
                         m_hovered_texture_location(hovered_texture_location),
                         m_pressed_texture_location(pressed_texture_location) {}


gui::AbstractButtonSkin::AbstractButtonSkin(const AbstractButtonSkin& other):
                         AbstractWidgetSkin(other.m_source_texture),
                         m_curr_texture_location(other.m_curr_texture_location),
                         m_idle_texture_location(other.m_idle_texture_location),
                         m_hovered_texture_location(other.m_hovered_texture_location),
                         m_pressed_texture_location(other.m_pressed_texture_location) {}


gui::AbstractButtonSkin::~AbstractButtonSkin() = default;


void gui::AbstractButtonSkin::Render() {
  m_render_texture.Resize(m_curr_texture_location.m_size);
  m_render_texture.Clear(glib::ColorRGBA(0, 0, 0, 0));
  m_render_texture.CopyTexture(m_source_texture, glib::Vector2i(), m_curr_texture_location);
  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::AbstractButtonSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                                                 const glib::Vector2i& position) const {
  assert(render_target != nullptr);

  render_target->CopyTexture(m_texture, position);
}


void gui::AbstractButtonSkin::SetIdle() {
  m_curr_texture_location = m_idle_texture_location;
}


void gui::AbstractButtonSkin::SetHovered() {
  m_curr_texture_location = m_hovered_texture_location;
}


void gui::AbstractButtonSkin::SetPressed() {
  m_curr_texture_location = m_pressed_texture_location;
}


gui::RectButtonSkin::RectButtonSkin(const glib::Texture& source_texture,
                                    const glib::IntRect& idle_texture_location,
                                    const glib::IntRect& hovered_texture_location,
                                    const glib::IntRect& pressed_texture_location):
                     AbstractButtonSkin(source_texture, idle_texture_location,
                                        hovered_texture_location,
                                        pressed_texture_location) {}


bool gui::RectButtonSkin::IsPointInside(const glib::IntRect& location,
                                        glib::Vector2i point) const {
  return location.IsPointInRect(point);
}


gui::AbstractButtonSkin* gui::RectButtonSkin::Copy() const {
  return new RectButtonSkin(*this);
}


gui::CircleButtonSkin::CircleButtonSkin(const glib::Texture& source_texture,
                                        const glib::IntRect& idle_texture_location,
                                        const glib::IntRect& hovered_texture_location,
                                        const glib::IntRect& pressed_texture_location):
                       AbstractButtonSkin(source_texture, idle_texture_location,
                                          hovered_texture_location,
                                          pressed_texture_location) {}


bool gui::CircleButtonSkin::IsPointInside(const glib::IntRect& location,
                                          glib::Vector2i point) const {
  glib::IntCircle circle(location.m_position + 0.5 * location.m_size, 0.5 * location.m_size.x);
  return circle.IsPointInside(point);
}


gui::AbstractButtonSkin* gui::CircleButtonSkin::Copy() const {
  return new CircleButtonSkin(*this);
}
