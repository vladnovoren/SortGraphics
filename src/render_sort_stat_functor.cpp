#include "render_sort_stat_functor.hpp"

RenderSortStatFunctor::RenderSortStatFunctor(const SortType sort_type,
                                             SortingSystem* sort_system,
                                             const glib::ColorRGBA& color,
                                             PlotWidget* assigns_plot,
                                             PlotWidget* comps_plot):
                       sort_type_(sort_type),
                       sorting_system_(sort_system),
                       assigns_plot_functor_(assigns_plot, color),
                       comps_plot_functor_(comps_plot, color) {
  assert(sort_system  != nullptr);
  assert(assigns_plot != nullptr);
  assert(comps_plot   != nullptr);
}

void RenderSortStatFunctor::SetSortType(const SortType sort_type) {
  sort_type_ = sort_type;
}

void RenderSortStatFunctor::SetSortingSystem(SortingSystem* sort_system) {
  assert(sort_system != nullptr);

  sorting_system_ = sort_system;
}

void RenderSortStatFunctor::SetAssignsPlotWidget(PlotWidget* assigns_plot) {
  assert(assigns_plot != nullptr);

  assigns_plot_functor_.SetPlotWidget(assigns_plot);
}

void RenderSortStatFunctor::SetCompsPlotWidget(PlotWidget* comps_plot) {
  assert(comps_plot != nullptr);

  comps_plot_functor_.SetPlotWidget(comps_plot);
}

void RenderSortStatFunctor::SetColor(const glib::ColorRGBA& color) {
  assigns_plot_functor_.SetColor(color);
  comps_plot_functor_.SetColor(color);
}

void RenderSortStatFunctor::operator()() {
  assert(sorting_system_ != nullptr);

  SortStatistics sort_stat = sorting_system_->GetSortStatistics(sort_type_);

  assigns_plot_functor_(sort_stat.assigns_cnt_);
  comps_plot_functor_(sort_stat.comps_cnt_);
}
