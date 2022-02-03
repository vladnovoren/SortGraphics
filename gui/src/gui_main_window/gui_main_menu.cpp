#include "gui_main_menu.hpp"


gui::MainMenu::MainMenu(int height) {
  m_location.m_size.x = APP_WIDTH;
  m_location.m_size.y = height;
}


gui::MainMenu::~MainMenu() {
  delete m_skin;
}


gui::MainMenu* gui::MainMenu::GetInstance() {
  SkinManager& skin_manager = SkinManager::GetInstance();
  static MainMenu* instance = new MainMenu(skin_manager.GetMainMenuSkin()->m_location.m_size.y);
  return instance;
}


void gui::MainMenu::SetSkin(MainMenuSkin* skin) {
  assert(skin != nullptr);

  delete m_skin;
  m_skin = new MainMenuSkin(*skin);
}


void gui::MainMenu::Draw(glib::RenderTarget* render_target,
                         const glib::Vector2i& position) {
  assert(render_target != nullptr);

  if (m_needs_to_render) {
    m_skin->Render(m_location.m_size.x);
    m_needs_to_render = false;
  }
  
  render_target->CopyTexture(m_skin->m_texture, position);

  AbstractContainerWidget::Draw(render_target, position);
}
