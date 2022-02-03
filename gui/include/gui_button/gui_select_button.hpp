#ifndef GUI_SELECT_BUTTON_HPP
#define GUI_SELECT_BUTTON_HPP


#include "gui_abstract_button.hpp"
#include "gui_abstract_widget.hpp"
#include "gui_abstract_widget_functor.hpp"


namespace gui {
  class SelectPanel;

  class SelectButton: public AbstractButton {
    friend class SelectPanel;
   protected:
    bool   m_is_selected = false;
    SelectPanel* m_owner = nullptr;
   public:
    SelectButton() = default;
    SelectButton(const glib::IntRect& location);
    SelectButton(const glib::IntRect& location,
                 AbstractButtonSkin* skin);
    SelectButton(const glib::IntRect& location,
                 AbstractWidgetFunctor* functor,
                 AbstractButtonSkin* skin);
    SelectButton(const glib::IntRect& location,
                 AbstractWidgetFunctor* functor,
                 AbstractButtonSkin* skin,
                 SelectPanel* owner);
    ~SelectButton() = default;

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position) override;
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button) override;

    bool IsSelected() const;

    void SetIdle() override;

    void SetOwner(SelectPanel* owner);
  };
}


#endif /* gui_choose_button.hpp */
