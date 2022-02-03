#ifndef GUI_COLOR_SELECT_FUNCTOR_HPP
#define GUI_COLOR_SELECT_FUNCTOR_HPP


#include "gui_abstract_widget_functor.hpp"
#include "gui_color_picker.hpp"


namespace gui {
  class ColorSelectFunctor: public AbstractWidgetFunctor {
   protected:
    glib::ColorRGBA m_color;
   public:
    ColorSelectFunctor() = default;
    ColorSelectFunctor(const glib::ColorRGBA& color);
    ~ColorSelectFunctor() = default;

    void operator()() override;
    void operator()(const glib::ColorRGBA& color);

    void SetColor(const glib::ColorRGBA& color);
    glib::ColorRGBA GetColor() const;
  };
}


#endif /* gui_color_select_functor.hpp */
