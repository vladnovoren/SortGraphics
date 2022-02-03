#ifndef GUI_COLOR_PICKER_HPP
#define GUI_COLOR_PICKER_HPP


#include "gui_abstract_container_widget.hpp"


namespace gui {
  class ColorPicker: public AbstractContainerWidget {
   private:
    ColorPicker() = default;

    glib::ColorRGBA m_curr_color;
   public:
    ~ColorPicker() override = default;

    static ColorPicker& GetInstance();

    void SetColor(const glib::ColorRGBA& color);
    glib::ColorRGBA GetColor() const;
  };
}


#endif /* gui_color_picker.hpp */
