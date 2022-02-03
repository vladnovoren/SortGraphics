#include "gui_tool_select_functor.hpp"


gui::ToolSelectFunctor::ToolSelectFunctor(AbstractTool *tool):
                        m_tool(tool) {
  assert(tool != nullptr);
}


void gui::ToolSelectFunctor::SetTool(AbstractTool *tool) {
  assert(tool != nullptr);

  m_tool = tool;
}


gui::AbstractTool* gui::ToolSelectFunctor::GetTool() const {
  return m_tool;
}


void gui::ToolSelectFunctor::operator()() {
  ToolBar* tool_bar = ToolBar::GetInstance();
  assert(tool_bar != nullptr);

  tool_bar->SetActiveTool(m_tool);
}


void gui::ToolSelectFunctor::operator()(AbstractTool *tool) {
  assert(tool != nullptr);

  SetTool(tool);
  operator()();
}
