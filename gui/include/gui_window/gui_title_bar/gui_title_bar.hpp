#ifndef GUI_TITLE_BAR_HPP
#define GUI_TITLE_BAR_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_plain_button.hpp"
#include "gui_title.hpp"
#include "gui_title_bar_skin.hpp"
#include "gui_move_functor.hpp"


namespace gui {
  class TitleBar: public AbstractContainerWidget {
    friend class Window;
   protected:
    TitleBarSkin* m_skin = nullptr;

    MoveFunctor* m_move_functor = nullptr;

    glib::Vector2i m_old_global_mouse_position;

    bool m_is_dragging = false;
   public:
    TitleBar() = default;
    TitleBar(TitleBarSkin* skin);
    ~TitleBar();

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position) override;

    void SetSkin(TitleBarSkin* skin);
    void SetMoveFunctor(MoveFunctor* move_functor);

    void AddMinimizeButton(PlainButton* minimize_button);
    void AddMaximizeButton(PlainButton* maximize_button);
    void AddCloseButton   (PlainButton* close_button);
    void AddTitle         (Title* title);
  };
}


#endif /* gui_title_bar.hpp */
