#ifndef GUI_TOOL_SELECT_FUNCTOR_HPP
#define GUI_TOOL_SELECT_FUNCTOR_HPP


#include "gui_tool_bar.hpp"
#include "gui_abstract_widget_functor.hpp"


namespace gui {
  class ToolSelectFunctor: public AbstractWidgetFunctor {
   protected:
    AbstractTool* m_tool = nullptr;
   public:
    ToolSelectFunctor() = default;
    ToolSelectFunctor(AbstractTool* tool);
    ~ToolSelectFunctor() = default;

    void SetTool(AbstractTool* tool);
    AbstractTool* GetTool() const;

    void operator()(AbstractTool* tool);
    void operator()() override;
  };
}


#endif /* gui_tool_select_functor.hpp */
