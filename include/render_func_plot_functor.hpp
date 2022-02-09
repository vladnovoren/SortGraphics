#ifndef RENDER_FUNC_PLOT_FUNCTOR_HPP
#define RENDER_FUNC_PLOT_FUNCTOR_HPP

#include "i_plot_functor.hpp"
#include <vector>

template<typename ArgT, typename ValueT>
class RenderFuncPlotFunctor: public IPlotFunctor {
 public:
  RenderFuncPlotFunctor() = default;

  RenderFuncPlotFunctor(PlotWidget* plot_widget): IPlotFunctor(plot_widget) {}

  ~RenderFuncPlotFunctor() override = default;


  void operator()(const std::vector<FuncArgValue<ArgT, ValueT>>* function) {
    SetFunction(function);
    operator()();
  }

  void operator()() override {
    assert(function_ != nullptr);

    plot_widget_->RenderFunction(*function_);
  }

  void SetFunction(const std::vector<FuncArgValue<ArgT, ValueT>>* function) {
    assert(function != nullptr);

    function_ = function;
  }

 protected:
  const std::vector<FuncArgValue<ArgT, ValueT>>* function_ = nullptr;
};

#endif /* render_func_plot_functor.hpp */
