#include "sort_plots_clear_functor.hpp"

SortPlotsClearFunctor::SortPlotsClearFunctor(PlotWidget* assigns_plot, PlotWidget* comps_plot):
                       assigns_plot_(assigns_plot), comps_plot_(comps_plot) {
  assert(assigns_plot != nullptr);
  assert(comps_plot   != nullptr);
}

void SortPlotsClearFunctor::operator()() {
  assigns_plot_->Clear();
  comps_plot_->Clear();
}
