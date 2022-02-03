#include "gui_abstract_container_widget.hpp"


gui::AbstractContainerWidget::AbstractContainerWidget(const glib::IntRect& location):
                              AbstractWidget(location) {}


void gui::AbstractContainerWidget::DeleteMatched() {
  auto child_it = m_children.begin();
  while (child_it != m_children.end()) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    if (child_ptr->ShouldClose()) {
      delete child_ptr;
      m_children.erase(child_it++);
    } else {
      child_ptr->DeleteMatched();
      ++child_it;
    }
  }
}


gui::AbstractContainerWidget::~AbstractContainerWidget() {
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    delete child_ptr;
  }
}


glib::IntRect gui::AbstractContainerWidget::GetValidBoundsForContent() const {
  return glib::IntRect(glib::Vector2i(), m_location.m_size);
}


void gui::AbstractContainerWidget::AddChild(AbstractWidget* child) {
  assert(child != nullptr);

  child->m_parent_widget = this;
  m_children.push_front(child);
}


gui::EventResult gui::AbstractContainerWidget::OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                                                    glib::Vector2i global_mouse_position,
                                                                    MouseButton button) {
  EventResult result = EventResult::NOT_PROCESSED;
  glib::Vector2i mouse_position_inside = local_mouse_position -
                                         m_location.m_position;
  if (button == MouseButton::LEFT) {
    for (auto child_it =  m_children.begin();
              child_it != m_children.end();
              ++child_it) {
      auto child_ptr = *child_it;
      assert(child_ptr != nullptr);
      if (child_ptr->IsPointInside(mouse_position_inside)) {
        m_children.erase(child_it);
        m_children.push_front(child_ptr);
        result = child_ptr->OnMouseButtonPressed(mouse_position_inside,
                                                global_mouse_position,
                                                button);
        return result;
      }
    }
  }
  return result;
}


gui::EventResult gui::AbstractContainerWidget::OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                                                     glib::Vector2i global_mouse_position,
                                                                     MouseButton button) {
  EventResult result = EventResult::NOT_PROCESSED;
  glib::Vector2i mouse_position_inside = local_mouse_position -
                                         m_location.m_position;
  if (button == MouseButton::LEFT) {
    for (auto child_it =  m_children.begin();
              child_it != m_children.end();
              ++child_it) {
      auto child_ptr = *child_it;
      assert(child_ptr != nullptr);
      if (child_ptr->IsPointInside(mouse_position_inside)) {
        result = child_ptr->OnMouseButtonReleased(mouse_position_inside,
                                                  global_mouse_position,
                                                  button);
      }
      if (result == EventResult::PROCESSED) {
        break;
      }
    }
  }
  return result;
}


gui::EventResult gui::AbstractContainerWidget::OnMouseMove(glib::Vector2i new_local_mouse_position,
                                                           glib::Vector2i new_global_mouse_position) {
  EventResult result = EventResult::NOT_PROCESSED;
  glib::Vector2i mouse_position_inside = new_local_mouse_position -
                                         m_location.m_position;
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    child_ptr->OnMouseMove(mouse_position_inside, new_global_mouse_position);
  }
  return result;
}


void gui::AbstractContainerWidget::Draw(glib::RenderTarget* render_target,
                                        const glib::Vector2i& position) {
  assert(render_target != nullptr);

  for (auto child_it =  m_children.rbegin();
            child_it != m_children.rend();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    child_ptr->Draw(render_target, position + m_location.m_position);
  }
}

