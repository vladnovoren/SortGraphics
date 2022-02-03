#include "gui_abstract_widget.hpp"
#include "gui_abstract_container_widget.hpp"


gui::AbstractWidget::AbstractWidget(const glib::IntRect& location):
                     m_location(location) {}


gui::AbstractWidget::~AbstractWidget() = default;


void gui::AbstractWidget::SetLocation(const glib::IntRect& location) {
  m_location = location;
}


glib::IntRect gui::AbstractWidget::Location() const {
  return m_location;
}


void gui::AbstractWidget::SetPosition(const glib::Vector2i& position) {
  m_location.m_position = position;
}


glib::Vector2i gui::AbstractWidget::Position() const {
  return m_location.m_position;
}


void gui::AbstractWidget::SetSize(const glib::Vector2i& size) {
  m_location.m_size = size;
}


glib::Vector2i gui::AbstractWidget::Size() const {
  return m_location.m_size;
}


bool gui::AbstractWidget::IsPointInside(glib::Vector2i point) const {
  return m_location.IsPointInRect(point);
}


glib::Vector2i gui::AbstractWidget::PointRelativeToParent(glib::Vector2i point) const {
  AbstractWidget* parent = m_parent_widget;
  while (parent != nullptr) {
    point -= parent->m_location.m_position;
    parent = parent->m_parent_widget;
  }
  return point;
}


gui::EventResult gui::AbstractWidget::OnMouseButtonPressed(glib::Vector2i,
                                                           glib::Vector2i,
                                                           MouseButton) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractWidget::OnMouseButtonReleased(glib::Vector2i,
                                                            glib::Vector2i,
                                                            MouseButton) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractWidget::OnMouseMove(glib::Vector2i, glib::Vector2i) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractWidget::OnClose() {
  MatchForClose();
  return EventResult::PROCESSED;
}


void gui::AbstractWidget::MatchForClose() {
  m_should_close = true;
}


bool gui::AbstractWidget::ShouldClose() const {
  return m_should_close;
}


void gui::AbstractWidget::DeleteMatched() {}


void gui::AbstractWidget::Move(const glib::Vector2i& delta_position) {
  m_location.m_position += delta_position;
}


gui::EventResult gui::AbstractWidget::OnUnknownEvent() {
  return gui::EventResult::PROCESSED;
}
