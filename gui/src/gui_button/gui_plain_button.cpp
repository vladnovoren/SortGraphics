#include "gui_plain_button.hpp"
#include "gui_widget_manager.hpp"


gui::PlainButton::PlainButton(const glib::IntRect& location,
                              AbstractWidgetFunctor* functor,
                              AbstractButtonSkin* skin):
                  AbstractButton(location, functor, skin) {}


gui::EventResult gui::PlainButton::OnMouseButtonPressed(glib::Vector2i,
                                                        glib::Vector2i,
                                                        MouseButton button) {
  if (button == MouseButton::LEFT) {
    WidgetManager::GetInstance().AddMouseActiveWidget(this);
    SetPressed();
    return EventResult::PROCESSED;
  }
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::PlainButton::OnMouseMove(glib::Vector2i new_local_mouse_position,
                                               glib::Vector2i) {
  WidgetManager& widget_manager = WidgetManager::GetInstance();
  if (IsPointInside(new_local_mouse_position)) {
    if (widget_manager.GetMouseActiveWidget() != this) {
      SetHovered();
    }
  } else {
    if (m_press_state != ButtonPressState::IDLE) {
      SetIdle();
    }
    if (widget_manager.GetMouseActiveWidget() == this) {
      widget_manager.RemoveMouseActiveWidget(this);
    }
  }
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::PlainButton::OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                                         glib::Vector2i,
                                                         MouseButton button) {
  if (button == MouseButton::LEFT) {
    WidgetManager& widget_manager = WidgetManager::GetInstance();
    if (this == widget_manager.GetMouseActiveWidget()) {
      widget_manager.RemoveMouseActiveWidget(this);
    }
    if (IsPointInside(local_mouse_position)) {
      m_functor->operator()();
      m_skin->SetHovered();
    } else {
      m_skin->SetIdle();
    }
    m_needs_to_render = true;
  }
  return EventResult::PROCESSED;
}
