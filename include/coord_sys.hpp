#ifndef COORD_SYS_HPP
#define COORD_SYS_HPP

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

template<typename T>
struct FunctionValue {
  T arg_;
  T value_;
};

class CoordSys: public gui::AbstractWidget {
 public:
  CoordSys() = default;
  CoordSys(const glib::IntRect& location, const Ranges& ranges);
  ~CoordSys() = default;

  void SetPPU(const double ppu);
  void SetRanges(const Ranges& ranges);

  double GetPPU() const;
  const Ranges& GetRanges() const;

  void Clear();

  template<typename T>
  void RenderFunction(const FunctionValue<T>* array, size_t size);
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

template<typename T>
void CoordSys::RenderFunction(const FunctionValue<T>* array, size_t size) {
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

#endif /* coord_sys.hpp */
