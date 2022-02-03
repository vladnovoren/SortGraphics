#ifndef GUI_MAIN_MENU_SKIN_HPP
#define GUI_MAIN_MENU_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"


namespace gui {
  struct MainMenuSkin: AbstractWidgetSkin {
    glib::IntRect       m_location;

    MainMenuSkin() = default;
    MainMenuSkin(const MainMenuSkin& other);
    ~MainMenuSkin() override = default;

    void Render(int length);
    void CopyToRenderTarget(glib::RenderTarget* render_target,
                            const glib::Vector2i& position) const;
  };
}


#endif /* gui_main_menu_skin.hpp */
