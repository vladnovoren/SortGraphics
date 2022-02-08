#ifndef CLEAR_PLOT_FUNCTOR_HPP
#define CLEAR_PLOT_FUNCTOR_HPP

#include "plot_widget.hpp"
#include "gui_abstract_widget_functor.hpp"

class ClearPlotFunctor: gui::AbstractWidgetFunctor {
 public:
  ClearPlotFunctor();
  ClearPlotFunctor(PlotWidget* plot_widget);

  void SetPlotWidget(PlotWidget);
 private:
};

#endif /* clear_plot_functor.hpp */
