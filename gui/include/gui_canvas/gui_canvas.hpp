#ifndef GUI_CANVAS_HPP
#define GUI_CANVAS_HPP


#include "glib.hpp"
#include "gui_abstract_widget.hpp"
#include "gui_canvas_skin.hpp"


namespace gui {
  class Canvas: public AbstractWidget {
   protected:
    glib::Texture       m_texture;
    glib::RenderTexture m_render_texture;
    glib::RenderTexture m_canvas_texture;

    CanvasSkin* m_skin = nullptr;

    bool m_is_drawing = false;
    bool m_needs_to_render_background = true;

    int m_thickness = 10;

    glib::Vector2i m_prev_draw_point = glib::Vector2i(-1, -1);
    glib::Vector2i m_curr_draw_point = glib::Vector2i(-1, -1);
   public:
    Canvas() = default;
    Canvas(const glib::IntRect& location);
    ~Canvas();

    void SetLocation(const glib::IntRect& location) override;
    void SetSize(const glib::Vector2i& size) override;
    void SetSkin(CanvasSkin* skin);

    bool IsDrawing() const;
    glib::Vector2i GetPrevDrawPoint() const;
    glib::Vector2i GetCurrDrawPoint() const;

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position) override;

    void DrawCircle(glib::IntCircle circle, glib::ColorRGBA color,
                   glib::BlendMode blend_mode = glib::BlendMode::ADD);
    void DrawLine(glib::IntLine line, glib::ColorRGBA color,
                  glib::BlendMode blend_mode = glib::BlendMode::ADD);
    void Clear(glib::ColorRGBA color);

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;
  };
}


#endif /* gui_canvas.hpp */
