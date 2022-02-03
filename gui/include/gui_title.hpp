#ifndef GUI_TITLE_HPP
#define GUI_TITLE_HPP


#include "gui_abstract_widget.hpp"


namespace gui {
  class Title: public AbstractWidget {
   protected:
    glib::Text m_text;
   public:
    Title() = default;
    Title(const char* label, const glib::Vector2i& center_position,
          unsigned int font_size);
    ~Title() = default;

    void SetText(const glib::Text& text);
    void SetLabel(const char* label);
    void SetFontSize(unsigned int font_size);

    void Draw(glib::RenderTarget* render_target, const glib::Vector2i& position) override;
  };
}


#endif /* gui_title.hpp */
