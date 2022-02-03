#ifndef GUI_ABSTRACT_BUTTON_SKIN_HPP
#define GUI_ABSTRACT_BUTTON_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"


namespace gui {
  enum class ButtonType {
    CIRCLE,
    RECT
  };


  struct AbstractButtonSkin: AbstractWidgetSkin {
    glib::IntRect m_curr_texture_location;
    glib::IntRect m_idle_texture_location;
    glib::IntRect m_hovered_texture_location;
    glib::IntRect m_pressed_texture_location;

    AbstractButtonSkin() = default;
    AbstractButtonSkin(const AbstractButtonSkin& other);
    AbstractButtonSkin(const glib::Texture& source_texture,
                       const glib::IntRect& idle_texture_location,
                       const glib::IntRect& hovered_texture_location,
                       const glib::IntRect& pressed_texture_location);
    ~AbstractButtonSkin() override = 0;

    virtual bool IsPointInside(const glib::IntRect& location,
                               glib::Vector2i point) const = 0;

    virtual void Render();
    virtual void CopyToRenderTarget(glib::RenderTarget* render_target,
                                    const glib::Vector2i& position) const;

    virtual AbstractButtonSkin* Copy() const = 0;

    void SetIdle();
    void SetHovered();
    void SetPressed();
  };


  struct RectButtonSkin: AbstractButtonSkin {
    RectButtonSkin() = default;
    RectButtonSkin(const glib::Texture& source_texture,
                   const glib::IntRect& idle_texture_location,
                   const glib::IntRect& hovered_texture_location,
                   const glib::IntRect& pressed_texture_location);
    ~RectButtonSkin() override = default;

    bool IsPointInside(const glib::IntRect& location,
                       glib::Vector2i point) const override;

    AbstractButtonSkin* Copy() const override;
  };


  struct CircleButtonSkin: AbstractButtonSkin {
    CircleButtonSkin() = default;
    CircleButtonSkin(const glib::Texture& source_texture,
                     const glib::IntRect& idle_texture_location,
                     const glib::IntRect& hovered_texture_location,
                     const glib::IntRect& pressed_texture_location);
    ~CircleButtonSkin() override = default;

    bool IsPointInside(const glib::IntRect& location,
                       glib::Vector2i point) const override;

    AbstractButtonSkin* Copy() const override;
  };
}


#endif /* gui_abstract_button_skin.hpp */
