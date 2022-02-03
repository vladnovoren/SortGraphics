#ifndef GUI_EVENTS_HPP
#define GUI_EVENTS_HPP


#include "glib.hpp"
#include "gui_abstract_widget.hpp"


namespace gui {
  MouseButton SFMLToGUIMouseButton(sf::Mouse::Button sf_button);

  bool IsMouseEvent(const sf::Event& sf_event);
  bool IsCloseEvent(const sf::Event& sf_event);

  glib::Vector2i GetMousePositionFromSfEvent(const sf::Event& sf_event);
}


#endif /* gui_events.hpp */
