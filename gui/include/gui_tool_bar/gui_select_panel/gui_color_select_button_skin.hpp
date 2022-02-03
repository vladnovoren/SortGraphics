#ifndef GUI_COLOR_SELECT_BUTTON_SKIN_HPP
#define GUI_COLOR_SELECT_BUTTON_SKIN_HPP


#include "gui_abstract_button_skin.hpp"


namespace gui {
  struct ColorSelectButtonSkin: AbstractButtonSkin {
    glib::IntRect m_hit_area;
    glib::ColorRGBA m_color;

    ColorSelectButtonSkin() = default;
    ColorSelectButtonSkin(const glib::Texture& source_texture,
                          const glib::IntRect& idle_texture_location,
                          const glib::IntRect& hovered_texture_location,
                          const glib::IntRect& pressed_texture_location,
                          const glib::IntRect& hit_area,
                          const glib::ColorRGBA& color);
    ColorSelectButtonSkin(const ColorSelectButtonSkin& other);
    ~ColorSelectButtonSkin() = default;

    bool IsPointInside(const glib::IntRect& location,
                       glib::Vector2i point) const override;

    void Render() override;

    AbstractButtonSkin* Copy() const override;
  };
}



#endif /* gui_color_select_button_skin.hpp */
