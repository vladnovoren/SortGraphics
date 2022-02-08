#include "clear_plot_functor.hpp"

ClearPlotFunctor::ClearPlotFunctor(PlotWidget *plot_widget):
                  IPlotFunctor(plot_widget) {}

void ClearPlotFunctor::operator()() {
  assert(plot_widget_ != nullptr);

  plot_widget_->Clear();
}
