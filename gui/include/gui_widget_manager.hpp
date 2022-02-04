#ifndef GUI_WIDGET_MANAGER_HPP
#define GUI_WIDGET_MANAGER_HPP

#include "gui_abstract_widget.hpp"
#include "gui_events.hpp"

namespace gui {
  class WidgetManager {
   protected:
    WidgetManager() = default;

    bool m_is_open = true;

    AbstractWidget* m_root = nullptr;
    AbstractWidget* m_mouse_active_widget = nullptr;
   public:
    ~WidgetManager();

    void Draw(glib::RenderWindow* render_window);

    static WidgetManager& GetInstance();

    void SetRoot(AbstractWidget* widget);

    AbstractWidget* GetRoot();
    AbstractWidget* GetMouseActiveWidget();

    void AddMouseActiveWidget(AbstractWidget* widget);
    void RemoveMouseActiveWidget(AbstractWidget* widget);

    void DeleteMatched();

    EventResult ProcessEvent(AbstractWidget* widget, const sf::Event& sf_event,
                             bool force = false);
    EventResult GetAndProcessEvent(glib::RenderWindow* render_window,
                                   bool& is_pooled);
    EventResult ProcessMouseEventOnSignedWidget(glib::RenderWindow* render_window,
                                                const sf::Event& sf_event);

    bool IsOpen() const;
  };
}


#endif /* gui_widget_manager.hpp */
