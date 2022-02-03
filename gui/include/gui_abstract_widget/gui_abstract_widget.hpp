#ifndef GUI_ABSTRACT_WIDGET_HPP
#define GUI_ABSTRACT_WIDGET_HPP


#include "glib.hpp"
#include "gui_abstract_widget_skin.hpp"


namespace gui {
  class AbstractContainerWidget;


  enum class EventResult {
    NO_EVENT,
    PROCESSED,
    NOT_PROCESSED
  };


  enum class MouseButton {
    NO_BUTTON,
    LEFT,
    MIDDLE,
    RIGHT
  };


  class AbstractWidget {
   protected:
    friend class AbstractContainerWidget;
    friend class TitleBar;
    friend class Window;
    friend class ToolBar;

    glib::IntRect m_location;

    AbstractContainerWidget* m_parent_widget = nullptr;

    bool m_should_close    = false;
    bool m_needs_to_render = true;
   public:
    AbstractWidget() = default;
    AbstractWidget(const glib::IntRect& location);
    virtual ~AbstractWidget() = 0;

    virtual void SetLocation(const glib::IntRect& location);

    glib::IntRect Location() const;

    void SetPosition(const glib::Vector2i& position);

    glib::Vector2i Position() const;

    glib::Vector2i Size() const;

    virtual void SetSize(const glib::Vector2i& size);

    virtual bool IsPointInside(glib::Vector2i point) const;

    glib::Vector2i PointRelativeToParent(glib::Vector2i point) const;

    virtual EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                             glib::Vector2i global_mouse_position,
                                             MouseButton button);

    virtual EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                              glib::Vector2i global_mouse_position,
                                              MouseButton button);

    virtual EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                                    glib::Vector2i new_global_mouse_position);

    virtual EventResult OnUnknownEvent();

    EventResult OnClose();

    void MatchForClose();

    bool ShouldClose() const;

    virtual void DeleteMatched();

    virtual void Move(const glib::Vector2i& delta_position);

    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2i& position) = 0;
  };
}


#endif /* gui_abstract_widget.hpp */
