#include "app.hpp"

App::App():
     m_render_window(glib::Vector2i(APP_WIDTH, APP_HEIGHT), "SortGraphics") {
  gui::DummyContainerWidget* root = new gui::DummyContainerWidget;
  m_widget_manager.SetRoot(root);
  CoordSys* test = new CoordSys(glib::IntRect(50, 50, 500, 500),
                                Ranges(0, 0, 500, 500));
  root->AddChild(test);
}

App::~App() = default;

App& App::GetInstance() {
  static App instance;
  return instance;
}

void App::Exec() {
  while (m_widget_manager.IsOpen()) {
    bool is_polled = true;
    while (is_polled) {
      m_widget_manager.GetAndProcessEvent(&m_render_window, is_polled);
    }
    m_widget_manager.DeleteMatched();
    m_widget_manager.Draw(&m_render_window);
  }
}

glib::RenderWindow* App::GetRenderWindow() {
  return &m_render_window;
}
