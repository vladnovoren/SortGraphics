#include "gui_content_window.hpp"


gui::ContentMainWindow* gui::ContentMainWindow::GetInstance() {
  static ContentMainWindow* instance = new ContentMainWindow;
  return instance;
}


void gui::ContentMainWindow::AddWindow(Window* window) {
  assert(window != nullptr);

  AddChild(window);
}
