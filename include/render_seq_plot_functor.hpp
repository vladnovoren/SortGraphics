#ifndef RENDER_SEQ_PLOT_FUNCTOR_HPP
#define RENDER_SEQ_PLOT_FUNCTOR_HPP

#include "i_plot_functor.hpp"
#include <vector>

template<typename ValueT>
class RenderSeqPlotFunctor: public IPlotFunctor {
 public:
  RenderSeqPlotFunctor() = default;
  RenderSeqPlotFunctor(PlotWidget* plot_widget, const glib::ColorRGBA& color): IPlotFunctor(plot_widget), color_(color) {}
  ~RenderSeqPlotFunctor() override = default;


  void operator()(const std::vector<ValueT>* sequence) {
    SetSequence(sequence);
    operator()();
  }

  void operator()() override {
    assert(sequence_ != nullptr);

    plot_widget_->RenderSequence(*sequence_, color_);
  }

  void SetSequence(const std::vector<ValueT>* sequence) {
    assert(sequence != nullptr);

    sequence_ = sequence;
  }

  void SetColor(const glib::ColorRGBA& color) {
    color_ = color;
  }

 protected:
  const std::vector<ValueT>* sequence_ = nullptr;
  glib::ColorRGBA color_;
};

#endif /* render_seq_plot_functor.hpp */
