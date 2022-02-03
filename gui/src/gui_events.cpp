#include "gui_events.hpp"


gui::MouseButton gui::SFMLToGUIMouseButton(sf::Mouse::Button sf_button) {
  switch (sf_button) {
    case sf::Mouse::Button::Left:
      return MouseButton::LEFT;

    case sf::Mouse::Button::Middle:
      return MouseButton::MIDDLE;

    case sf::Mouse::Button::Right:
      return MouseButton::RIGHT;

    default:
      return MouseButton::NO_BUTTON;
  }
}


bool gui::IsMouseEvent(const sf::Event& sf_event) {
  switch (sf_event.type) {
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseButtonReleased:
    case sf::Event::MouseMoved:
      return true;
    default:
      return false;
  }
}


bool gui::IsCloseEvent(const sf::Event& sf_event) {
  if (sf_event.type == sf::Event::Closed) {
    return true;
  } else {
    return false;
  }
}


glib::Vector2i gui::GetMousePositionFromSfEvent(const sf::Event& sf_event) {
  glib::Vector2i mouse_position;
  switch (sf_event.type) {
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseButtonReleased:
      mouse_position = glib::Vector2i(sf_event.mouseButton.x, sf_event.mouseButton.y);
      break;
    case sf::Event::MouseMoved:
      mouse_position = glib::Vector2i(sf_event.mouseMove.x, sf_event.mouseMove.y);
      break;
    default:
      break;
  }
  return mouse_position;
}
