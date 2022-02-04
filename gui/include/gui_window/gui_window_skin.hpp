#ifndef GUI_WINDOW_SKIN_HPP
#define GUI_WINDOW_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"
#include "gui_title_bar_skin.hpp"
#include "glib.hpp"


namespace gui {
  static const int WINDOW_SHADOW_THICKNESS = 3;

  struct WindowSkin: AbstractWidgetSkin {
    glib::IntRect m_left_edge_location;
    glib::IntRect m_left_bottom_angle_location;
    glib::IntRect m_bottom_location;
    glib::IntRect m_right_bottom_angle_location;
    glib::IntRect m_right_edge_location;

    WindowSkin() = default;
    WindowSkin(const WindowSkin& other);

    glib::Vector2i GetAllSize(const glib::Vector2i& window_size) const;

    void Render(const glib::Vector2i& window_size,
                const TitleBarSkin& title_bar_skin);
    void CopyToRenderTarget(glib::RenderTarget* render_target,
                            const glib::Vector2i& window_position) const;
  };
}


#endif /* gui_window_skin.hpp */
