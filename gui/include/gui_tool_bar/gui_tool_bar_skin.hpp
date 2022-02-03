#ifndef GUI_TOOL_BAR_SKIN_HPP
#define GUI_TOOL_BAR_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"


namespace gui {
  struct ToolBarSkin: AbstractWidgetSkin {
    glib::IntRect m_right_edge_location;

    ToolBarSkin() = default;
    ToolBarSkin(const glib::IntRect& right_edge_location);
    ToolBarSkin(const ToolBarSkin& other);
    ~ToolBarSkin() = default;

    void Render(glib::Vector2i size);
    void CopyToRenderTarget(glib::RenderTarget* render_target,
                            const glib::Vector2i& position);
  };
}


#endif /* gui_tool_bar_skin.hpp */
