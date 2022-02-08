#ifndef DRAW_FUNC_PLOT_FUNCTOR_HPP
#define DRAW_FUNC_PLOT_FUNCTOR_HPP

#include "i_plot_functor.hpp"
#include <vector>

class DrawFuncPlotFunctor: public IPlotFunctor {
 public:
  DrawFuncPlotFunctor() = default;
  DrawFuncPlotFunctor(PlotWidget* plot_widget);
  ~DrawFuncPlotFunctor() override = default;

  template<typename ArgT, typename ValueT>
  void operator()(const std::vector<FuncArgValue<ArgT, ValueT>>& function);
 protected:
};

#endif /* draw_func_plot_functor.hpp */
