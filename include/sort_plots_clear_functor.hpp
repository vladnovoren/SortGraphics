#ifndef SORT_PLOTS_CLEAR_FUNCTOR_HPP
#define SORT_PLOTS_CLEAR_FUNCTOR_HPP

#include "clear_plot_functor.hpp"

class SortPlotsClearFunctor: public gui::AbstractWidgetFunctor {
 public:
  SortPlotsClearFunctor(PlotWidget* assigns_plot, PlotWidget* comps_plot);

  void operator()() override;

 protected:
  PlotWidget* assigns_plot_ = nullptr;
  PlotWidget* comps_plot_   = nullptr;
};

#endif /* sort_plots_clear_functor.hpp */
