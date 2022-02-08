#include "i_plot_functor.hpp"

IPlotFunctor::IPlotFunctor(PlotWidget* plot_widget):
              plot_widget_(plot_widget) {
  assert(plot_widget != nullptr);
}

void IPlotFunctor::SetPlotWidget(PlotWidget* plot_widget) {
  assert(plot_widget != nullptr);

  plot_widget_ = plot_widget;
}

PlotWidget* IPlotFunctor::GetPlotWidget() const {
  return plot_widget_;
}
