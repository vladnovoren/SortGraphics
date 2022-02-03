#ifndef GUI_ABSTRACT_WIDGET_FUNCTOR_HPP
#define GUI_ABSTRACT_WIDGET_FUNCTOR_HPP


#include "gui_abstract_widget.hpp"


namespace gui {
  class AbstractWidgetFunctor {
   public:
    AbstractWidgetFunctor() = default;
    virtual ~AbstractWidgetFunctor() = 0;

    virtual void operator()() = 0;
  };


  class CloseWidgetFunctor: public AbstractWidgetFunctor {
   protected:
    AbstractWidget* m_widget = nullptr;
   public:
    CloseWidgetFunctor(AbstractWidget* widget);

    void operator()() override;
  };
}


#endif /* gui_abstract_widget_functor.hpp */
