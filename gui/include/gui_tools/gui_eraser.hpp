#ifndef GUI_ERASER_HPP
#define GUI_ERASER_HPP


#include "gui_abstract_tool.hpp"


namespace gui {
  class Eraser: public AbstractTool {
    Eraser() = default;

    int m_thickness = 1;
   public:
    ~Eraser() = default;

    static Eraser* GetInstance();

    void Apply(Canvas* canvas) override;
  };
}


#endif /* gui_eraser */
