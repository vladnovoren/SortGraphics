#ifndef GUI_MOVE_FUNCTOR_HPP
#define GUI_MOVE_FUNCTOR_HPP


#include "gui_abstract_widget_functor.hpp"


namespace gui {
  class MoveFunctor: public AbstractWidgetFunctor {
   protected:
    AbstractWidget* m_owner = nullptr;
    glib::Vector2i  m_delta_position;
   public:
    MoveFunctor() = default;
    MoveFunctor(AbstractWidget* owner);
    ~MoveFunctor() = default;

    void SetDeltaPosition(const glib::Vector2i& delta_position);

    void operator()() override;
    void operator()(const glib::Vector2i& delta_position);
  };
}


#endif /* gui_move_functor.hpp */
