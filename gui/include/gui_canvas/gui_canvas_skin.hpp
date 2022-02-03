#ifndef GUI_CANVAS_SKIN_HPP
#define GUI_CANVAS_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"


namespace gui {
  struct CanvasSkin: AbstractWidgetSkin {
    glib::IntRect m_location;

    CanvasSkin() = default;
    CanvasSkin(const CanvasSkin& other);
    ~CanvasSkin() = default;

    void Render(const glib::Vector2i& size);
  };
}


#endif /* gui_canvas_skin.hpp */
