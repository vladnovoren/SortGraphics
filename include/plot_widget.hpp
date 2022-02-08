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

static const int GRAPHICS_THICKNESS = 1;

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
  void RenderFunction(const std::vector<FuncArgValue<ArgT, ValueT>>& function);
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
void PlotWidget::RenderFunction(const FuncArgValue<ArgT, ValueT>* array, size_t size) {
  assert(array != nullptr);

  glib::Vector2i curr(array[0].arg_, -array[0].value_);
  glib::Vector2i prev = curr;

  std::cout << "center: ";
  center_.Print();
  std::cout << '\n';

  glib::IntLine line;
  for (size_t i = 1; i < size; ++i) {
    prev = curr;
    curr = glib::Vector2i(array[i].arg_, -array[i].value_);
    line = glib::IntLine(center_ + ppu_ * prev, center_ + ppu_ * curr, GRAPHICS_THICKNESS);
    line.m_begin.Print();
    std::cout << '\n';
    line.m_end.Print();
    render_texture_.RenderLine(line, glib::ColorRGBA());
  }

  line = glib::IntLine(center_ + ppu_ * prev, center_ + ppu_ * curr, GRAPHICS_THICKNESS);
  render_texture_.RenderLine(line, glib::ColorRGBA());
}

#endif /* plot_widget.hpp */
