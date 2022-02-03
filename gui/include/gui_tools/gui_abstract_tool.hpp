#ifndef GUI_ABSTRACT_TOOL_HPP
#define GUI_ABSTRACT_TOOL_HPP


#include "gui_canvas.hpp"


namespace gui {
  class AbstractTool {
   public:
    virtual ~AbstractTool() = 0;

    virtual void Apply(Canvas* canvas) = 0;
  };
}


#endif /* gui_abstract_tool.hpp */
