#include "gui_tool_bar.hpp"
#include "gui_brush.hpp"
#include "gui_skin_manager.hpp"


gui::ToolBar::ToolBar() {
  SetSkin(SkinManager::GetInstance().GetToolBarSkin());
}


gui::ToolBar::~ToolBar() {
  delete m_skin;
}


gui::ToolBar* gui::ToolBar::GetInstance() {
  static ToolBar* instance = new ToolBar;
  return instance;
}


bool gui::ToolBar::SetActiveTool(AbstractTool* tool) {
  assert(tool != nullptr);

  m_active_tool = tool;
  return true;
}


gui::AbstractTool* gui::ToolBar::GetActiveTool() const {
  assert(m_active_tool != nullptr);
  return m_active_tool;
}


void gui::ToolBar::SetSkin(ToolBarSkin* skin) {
  assert(skin != nullptr);

  delete m_skin;
  m_skin = new ToolBarSkin(*skin);
}


void gui::ToolBar::Draw(glib::RenderTarget* render_target,
                        const glib::Vector2i& position) {
  assert(render_target != nullptr);

  if (m_needs_to_render) {
    m_skin->Render(m_location.m_size);
    m_needs_to_render = false;
  }
  glib::Vector2i position_to_copy = position + m_location.m_position;
  m_skin->CopyToRenderTarget(render_target, position_to_copy);
  AbstractContainerWidget::Draw(render_target, position);
}


void gui::ToolBar::AddTitle(Title* title) {
  assert(title != nullptr);

  AddChild(title);
}


void gui::ToolBar::AddSelectPanel(SelectPanel* select_panel) {
  assert(select_panel != nullptr);

  AddChild(select_panel);
}
