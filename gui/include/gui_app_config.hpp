#ifndef GUI_APP_CONFIG_HPP
#define GUI_APP_CONFIG_HPP


#include "glib_tools.hpp"


namespace gui {
  static const int APP_WIDTH             = 1200;
  static const int APP_HEIGHT            = 800;
  static const int CANVAS_DEFAULT_WIDTH  = 800;
  static const int CANVAS_DEFAULT_HEIGHT = 600;
  static const int DELTA_BUTTON_X        = 5;

  static const int TOOL_BAR_WIDTH        = 135;

  static const int FONT_SIZE             = 14;

  static const char* const AQUA_SKIN_FOLDER_PATH = "Skins/aqua";

  static const int WINDOW_SHADOW_THICKNESS = 2;
  static const glib::Vector2i WINDOW_SHADOW_SIZE(WINDOW_SHADOW_THICKNESS,
                                                 WINDOW_SHADOW_THICKNESS);

  const size_t N_COLORS = 10;
  const glib::ColorRGBA COLORS[N_COLORS] = {
    {0, 0, 0, 1},
    {1, 1, 1, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {0, 0, 1, 1},
    {1, 1, 0, 1},
    {0.5546875, 0.26171875, 0.12890625, 1},
    {0.5, 0.5, 0.5, 1},
    {0, 1, 1, 1},
    {1, 0, 1, 1}
  };
}


#endif /* gui_app_config.hpp */
