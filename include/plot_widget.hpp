#ifndef PLOT_WIDGET_HPP
#define PLOT_WIDGET_HPP

#include "gui_abstract_widget.hpp"

struct Ranges {
  double min_x_ = 0;
  double min_y_ = 0;
  double max_x_ = 0;
  double max_y_ = 0;

  Ranges() = default;
  Ranges(const double min_x, const double min_y,
         const double max_x, const double max_y);

  glib::Vector2d GetSize() const;
  double GetWidth() const;
  double GetHeight() const;
};

static const int GRAPHICS_BOUNDING_THICKNESS = 2;
static const int GRAPHICS_THICKNESS = 2;

template<typename ArgT, typename ValueT>
struct FuncArgValue {
  ArgT arg_;
  ValueT value_;
};

class PlotWidget: public gui::AbstractWidget {
 public:
  PlotWidget() = default;
  PlotWidget(const glib::IntRect& location);
  PlotWidget(const glib::IntRect& location, const Ranges& ranges);
  ~PlotWidget() = default;

  void SetPPU(const double ppu);
  void SetRanges(const Ranges& ranges);

  double GetPPU() const;
  const Ranges& GetRanges() const;

  void Clear();

  template<typename ArgT, typename ValueT>
  void RenderFunction(const std::vector<FuncArgValue<ArgT, ValueT>>& function, const glib::ColorRGBA& color);

  template<typename ValueT>
  void RenderSequence(const std::vector<ValueT>& sequence, const glib::ColorRGBA& color);
 protected:
  double ppu_ = 1;
  Ranges ranges_;
  glib::Vector2i center_;

  glib::RenderTexture render_texture_;

  void CountCenter();

  void RenderBoundingbox();
  void RenderAxes();

  void Draw(glib::RenderTarget* render_target, const glib::Vector2i& position);
};

template<typename ArgT, typename ValueT>
void PlotWidget::RenderFunction(const std::vector<FuncArgValue<ArgT, ValueT>>& function, const glib::ColorRGBA& color) {
  glib::Vector2i curr(function[0].arg_, -function[0].value_);
  glib::Vector2i prev = curr;

  glib::IntLine line;
  for (size_t i = 1; i < function.size(); ++i) {
    prev = curr;
    curr = glib::Vector2i(function[i].arg_, -function[i].value_);
    line = glib::IntLine(center_ + ppu_ * prev, center_ + ppu_ * curr, GRAPHICS_THICKNESS);
    render_texture_.RenderLine(line, color);
  }

  line = glib::IntLine(center_ + ppu_ * prev, center_ + ppu_ * curr, GRAPHICS_THICKNESS);
  render_texture_.RenderLine(line, color);
  RenderBoundingbox();
}

template<typename ValueT>
void PlotWidget::RenderSequence(const std::vector<ValueT>& sequence, const glib::ColorRGBA& color) {
  glib::Vector2i curr(1, - (sequence[0] * 0.1));
  glib::Vector2i prev = curr;

  glib::IntLine line;
  for (size_t i = 1; i < sequence.size(); i += 2) {
    prev = curr;
    curr = glib::Vector2i(i + 1, -(sequence[i] * 0.1));
    line = glib::IntLine(center_ + ppu_ * prev, center_ + curr, GRAPHICS_THICKNESS);
    render_texture_.RenderLine(line, color);
  }

  line = glib::IntLine(center_ + ppu_ * prev, center_ + curr, GRAPHICS_THICKNESS);
  render_texture_.RenderLine(line, color);
  RenderBoundingbox();
}

#endif /* plot_widget.hpp */
