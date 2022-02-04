#ifndef GUI_ABSTRACT_WIDGET_SKIN_HPP
#define GUI_ABSTRACT_WIDGET_SKIN_HPP


#include "glib.hpp"
#include <cstring>


namespace gui {
  struct AbstractWidgetSkin {
    AbstractWidgetSkin() = default;
    AbstractWidgetSkin(const glib::Texture& source_texture);
    virtual ~AbstractWidgetSkin() = default;

    glib::Texture       m_texture;
    glib::RenderTexture m_render_texture;

    glib::Texture       m_source_texture;
  };
}


#endif /* gui_abstract_widget_skin.hpp */
