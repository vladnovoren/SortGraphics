#include "app.hpp"

App::App():
     m_render_window(glib::Vector2i(APP_WIDTH, APP_HEIGHT), "SortGraphics") {
}

App::~App() = default;

App& App::GetInstance() {
  static App instance;
  return instance;
}

void App::Init() {
  gui::DummyContainerWidget* root = new gui::DummyContainerWidget(glib::IntRect (0, 0, APP_HEIGHT, APP_WIDTH));
  m_widget_manager.SetRoot(root);

  SortPlotsWidget* sort_plots_widget = new SortPlotsWidget;
  root->AddChild(sort_plots_widget);
}

void App::Exec() {
  Init();
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
