#include "gui_move_functor.hpp"
#include "gui_window.hpp"


gui::MoveFunctor::MoveFunctor(AbstractWidget* owner): m_owner(owner) {
  assert(owner != nullptr);
}


void gui::MoveFunctor::SetDeltaPosition(const glib::Vector2i& delta_position) {
  m_delta_position = delta_position;
}


void gui::MoveFunctor::operator()() {
  m_owner->Move(m_delta_position);
}


void gui::MoveFunctor::operator()(const glib::Vector2i& delta_position) {
  SetDeltaPosition(delta_position);
  this->operator()();
}
