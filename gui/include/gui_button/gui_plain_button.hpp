#ifndef GUI_PLAIN_BUTTON_HPP
#define GUI_PLAIN_BUTTON_HPP


#include "gui_abstract_button.hpp"


namespace gui {
  class PlainButton: public AbstractButton {
   protected:
   public:
    PlainButton() = default;
    PlainButton(const glib::IntRect& location,
                AbstractWidgetFunctor* functor,
                AbstractButtonSkin* skin);
    ~PlainButton() = default;

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position) override;
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button) override;
  };
}


#endif /* gui_plain_button.hpp */
