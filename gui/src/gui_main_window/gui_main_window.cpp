#include "gui_main_window.hpp"


gui::MainWindow::MainWindow() {
  SetLocation(glib::IntRect(0, 0, APP_WIDTH, APP_HEIGHT));
}


gui::MainWindow* gui::MainWindow::GetInstance() {
  static MainWindow* instance = new MainWindow;
  return instance;
}


glib::IntRect gui::MainWindow::GetValidBoundsForContent() const {
  glib::IntRect bounds;
  MainMenu* main_menu = MainMenu::GetInstance();
  bounds.m_position.y = main_menu->m_location.m_size.y;
  bounds.m_size = m_location.m_size;
  bounds.m_size.y -= main_menu->m_location.m_size.y;
  return bounds;
}


void gui::MainWindow::AddContentWindow() {
  ContentMainWindow* content = ContentMainWindow::GetInstance();
  assert(content != nullptr);

  AddChild(content);
}


void gui::MainWindow::AddMainMenu() {
  MainMenu* main_menu = MainMenu::GetInstance();
  assert(main_menu != nullptr);

  AddChild(main_menu);
}


void gui::MainWindow::AddToolBar() {
  ToolBar* tool_bar = ToolBar::GetInstance();
  assert(tool_bar != nullptr);

  AddChild(tool_bar);
}
