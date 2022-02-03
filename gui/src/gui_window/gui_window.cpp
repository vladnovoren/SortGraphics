#include "gui_window.hpp"


gui::Window::Window(const glib::IntRect& location):
             AbstractContainerWidget(location) {
}


gui::Window::~Window() {
  delete m_skin;
}


void gui::Window::SetSkin(WindowSkin* skin) {
  assert(skin != nullptr);

  delete m_skin;
  m_skin = new WindowSkin(*skin);
}


void gui::Window::AddTitleBar(TitleBar* title_bar) {
  assert(title_bar != nullptr);

  m_title_bar = title_bar;
  AddChild(title_bar);
}


void gui::Window::AddContent(AbstractWidget* content_widget) {
  assert(content_widget != nullptr);

  m_content_widget = content_widget;
  AddChild(content_widget);
}


void gui::Window::Move(const glib::Vector2i& delta_position) {
  glib::Vector2i left_up_corner = m_location.m_position + delta_position;
  glib::Vector2i right_down_corner = left_up_corner + m_location.m_size;

  glib::IntRect bounds = m_parent_widget->GetValidBoundsForContent();
  glib::Vector2i delta(2 * m_title_bar->m_skin->m_left_all_location.m_size.x,
                       m_title_bar->m_location.m_size.y);
  bounds.m_size -= delta;

  if (bounds.IsPointInRect(left_up_corner) && bounds.IsPointInRect(right_down_corner)) {
    m_location.m_position = m_location.m_position + delta_position;
  } else {
    glib::Vector2i good_left_up_corner = bounds.m_position;
    glib::Vector2i good_right_down_corner = good_left_up_corner + bounds.m_size + m_location.m_size;
    if (left_up_corner.x < good_left_up_corner.x) {
      left_up_corner.x = good_left_up_corner.x;
      right_down_corner = left_up_corner + m_location.m_size;
    }
    if (left_up_corner.y < good_left_up_corner.y) {
      left_up_corner.y = good_left_up_corner.y;
      right_down_corner = left_up_corner + m_location.m_size;
    }
    if (right_down_corner.x > good_right_down_corner.x) {
      right_down_corner.x = good_right_down_corner.x;
      left_up_corner = right_down_corner - m_location.m_size;
    }
    if (right_down_corner.y > good_right_down_corner.y) {
      right_down_corner.y = good_right_down_corner.y;
      left_up_corner = right_down_corner - m_location.m_size;
    }
    m_location.m_position = left_up_corner;
  }
}


void gui::Window::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i& position) {
  assert(render_target != nullptr);
  assert(m_title_bar != nullptr);
  TitleBarSkin* title_bar_skin = m_title_bar->m_skin;
  assert(title_bar_skin != nullptr);
  assert(m_skin != nullptr);

  if (m_needs_to_render) {
    m_skin->Render(m_location.m_size, *title_bar_skin);
    m_needs_to_render = false;
  }
  glib::Vector2i position_to_copy = m_location.m_position + position + title_bar_skin->m_left_all_location.m_position - title_bar_skin->m_left_origin_location.m_position;
  render_target->CopyTexture(m_skin->m_texture, position_to_copy);

  AbstractContainerWidget::Draw(render_target, position);
}
