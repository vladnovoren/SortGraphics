#ifndef CLEAR_PLOT_FUNCTOR_HPP
#define CLEAR_PLOT_FUNCTOR_HPP

#include "plot_widget.hpp"
#include "i_plot_functor.hpp"

class ClearPlotFunctor: public IPlotFunctor {
 public:
  ClearPlotFunctor() = default;
  ClearPlotFunctor(PlotWidget* plot_widget);
  ~ClearPlotFunctor() override = default;

  void operator()();
};

#endif /* clear_plot_functor.hpp */
