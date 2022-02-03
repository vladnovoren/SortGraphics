#ifndef GUI_ABSTRACT_CONTAINER_WIDGET_HPP
#define GUI_ABSTRACT_CONTAINER_WIDGET_HPP


#include "gui_abstract_widget.hpp"
#include <list>
#include <algorithm>


namespace gui {
  class AbstractContainerWidget: public AbstractWidget {
   protected:
    std::list<AbstractWidget*> m_children;

    void AddChild(AbstractWidget* child);
   public:
    AbstractContainerWidget() = default;
    AbstractContainerWidget(const glib::IntRect& location);
    virtual ~AbstractContainerWidget() = 0;

    void DeleteMatched() override;

    virtual glib::IntRect GetValidBoundsForContent() const;

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position) override;

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;
  };
}


#endif /* gui_abstract_container_widget.hpp */
