#ifndef GUI_TITLE_BAR_SKIN_HPP
#define GUI_TITLE_BAR_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"


namespace gui {
  struct TitleBarSkin: AbstractWidgetSkin {
    glib::IntRect       m_left_all_location;
    glib::IntRect       m_left_origin_location;

    glib::IntRect       m_middle_all_location;
    glib::IntRect       m_middle_origin_location;

    glib::IntRect       m_right_all_location;
    glib::IntRect       m_right_origin_location;

    TitleBarSkin() = default;
    TitleBarSkin(const TitleBarSkin& other);
    TitleBarSkin(const glib::Texture& source_texture,
                 const glib::IntRect& left_all_location,
                 const glib::IntRect& left_origin_location,
                 const glib::IntRect& middle_all_location,
                 const glib::IntRect& middle_origin_location,
                 const glib::IntRect& right_all_location,
                 const glib::IntRect& right_origin_location);
    ~TitleBarSkin() override = default;

    glib::Vector2i GetAllSize(glib::Vector2i origin_size);

    void Render(const glib::Vector2i& size);
    void CopyToRenderTarget(glib::RenderTarget* render_target, const glib::Vector2i& position) const;
  };
}


#endif /* gui_title_bar_skin.hpp */
