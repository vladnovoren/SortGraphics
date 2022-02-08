#include "draw_func_plot_functor.hpp"

DrawFuncPlotFunctor::DrawFuncPlotFunctor(PlotWidget* plot_widget):
                     IPlotFunctor(plot_widget) {}


template<typename ArgT, typename ValueT>
void DrawFuncPlotFunctor::operator()(const std::vector<FuncArgValue<ArgT, ValueT>>& function) {
  plot_widget_->RenderFunction();
}
