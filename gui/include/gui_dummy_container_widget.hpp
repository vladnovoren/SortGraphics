#ifndef GUI_DUMMY_CONTAINER_WIDGET_HPP
#define GUI_DUMMY_CONTAINER_WIDGET_HPP

#include "gui_abstract_container_widget.hpp"

namespace gui {
  class DummyContainerWidget: public AbstractContainerWidget {
   public:
    DummyContainerWidget() = default;
    DummyContainerWidget(const glib::IntRect& location);
    ~DummyContainerWidget() = default;
  };
}

#endif /* gui_dummy_container_widget.hpp */
