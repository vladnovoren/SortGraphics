#ifndef GUI_ABSTRACT_BUTTON_HPP
#define GUI_ABSTRACT_BUTTON_HPP


#include "gui_abstract_widget.hpp"
#include "gui_abstract_widget_functor.hpp"
#include "gui_abstract_button_skin.hpp"


namespace gui {
  enum ButtonPressState {
    IDLE,
    HOVERED,
    PRESSED
  };


  class AbstractButton: public AbstractWidget {
   protected:
    glib::Vector2i m_curr_mouse_position;

    AbstractWidgetFunctor* m_functor = nullptr;
    AbstractButtonSkin* m_skin       = nullptr;

    ButtonPressState m_press_state = ButtonPressState::IDLE;
   public:
    AbstractButton() = default;
    AbstractButton(const glib::IntRect& location);
    AbstractButton(const glib::IntRect& location,
                   AbstractButtonSkin* skin);
    AbstractButton(const glib::IntRect& location,
                   AbstractWidgetFunctor* functor,
                   AbstractButtonSkin* skin);
    ~AbstractButton() override;

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;

    bool IsPointInside(glib::Vector2i point) const override;

    void SetFunctor(AbstractWidgetFunctor* functor);
    virtual void SetSkin(AbstractButtonSkin* skin);

    virtual void SetIdle();
    virtual void SetHovered();
    virtual void SetPressed();
  };
}


#endif /* gui_button.hpp */
