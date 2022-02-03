#include "gui_abstract_button.hpp"
#include "gui_widget_manager.hpp"


gui::AbstractButton::AbstractButton(const glib::IntRect& location):
                     AbstractWidget(location) {}


gui::AbstractButton::AbstractButton(const glib::IntRect& location,
                                    AbstractButtonSkin* skin):
                     AbstractWidget(location) {
  assert(skin != nullptr);
  
  SetSkin(skin);
}


gui::AbstractButton::AbstractButton(const glib::IntRect& location,
                                    AbstractWidgetFunctor* functor,
                                    AbstractButtonSkin* skin):
                                    AbstractWidget(location),
                                    m_functor(functor) {
  assert(functor != nullptr);
  assert(skin    != nullptr);

  SetSkin(skin);
}


gui::AbstractButton::~AbstractButton() {
  delete m_skin;
  delete m_functor;
}


bool gui::AbstractButton::IsPointInside(glib::Vector2i point) const {
  return m_skin->IsPointInside(m_location, point);
}


void gui::AbstractButton::SetSkin(AbstractButtonSkin* skin) {
  assert(skin);

  delete(m_skin);
  m_skin = skin->Copy();
  m_skin->SetIdle();
}


void gui::AbstractButton::SetFunctor(AbstractWidgetFunctor* functor) {
  assert(functor);

  m_functor = functor;
}


void gui::AbstractButton::Draw(glib::RenderTarget* render_target,
                               const glib::Vector2i& position) {
  assert(render_target);

  if (m_needs_to_render) {
    m_skin->Render();
    m_needs_to_render = false;
  }
  glib::Vector2i position_to_copy = position + m_location.m_position;
  m_skin->CopyToRenderTarget(render_target, position_to_copy);
}


void gui::AbstractButton::SetIdle() {
  m_skin->SetIdle();
  m_needs_to_render = true;
  m_press_state = ButtonPressState::IDLE;
}


void gui::AbstractButton::SetHovered() {
  m_skin->SetHovered();
  m_needs_to_render = true;
  m_press_state = ButtonPressState::HOVERED;
}


void gui::AbstractButton::SetPressed() {
  m_skin->SetPressed();
  m_needs_to_render = true;
  m_press_state = ButtonPressState::PRESSED;
}
