#ifndef GUI_BRUSH_HPP
#define GUI_BRUSH_HPP


#include "glib_color.hpp"
#include "gui_abstract_tool.hpp"
#include "gui_canvas.hpp"
#include "gui_color_picker.hpp"


namespace gui {
  class Brush: public AbstractTool {
   protected:
    Brush() = default;

    int m_thickness = 1;
   public:
    ~Brush() = default;

    static Brush* GetInstance();

    void Apply(Canvas* canvas) override;
  };
}


#endif /* gui_brush.hpp */
