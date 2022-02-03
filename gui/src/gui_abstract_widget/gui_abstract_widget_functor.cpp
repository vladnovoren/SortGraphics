#include "gui_abstract_widget_functor.hpp"


gui::AbstractWidgetFunctor::~AbstractWidgetFunctor() = default;


gui::CloseWidgetFunctor::CloseWidgetFunctor(AbstractWidget* widget): m_widget(widget) {
  assert(m_widget != nullptr);
}


void gui::CloseWidgetFunctor::operator()() {
  assert(m_widget != nullptr);

  m_widget->OnClose();
}
