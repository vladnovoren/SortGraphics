#ifndef RENDER_SORT_STAT_FUNCTOR
#define RENDER_SORT_STAT_FUNCTOR

#include "render_seq_plot_functor.hpp"
#include "sorting_system.hpp"

class RenderSortStatFunctor: public gui::AbstractWidgetFunctor {
 public:
  RenderSortStatFunctor() = default;
  RenderSortStatFunctor(const SortType sort_type,
                        SortingSystem* sort_system,
                        const glib::ColorRGBA& color,
                        PlotWidget* assigns_plot,
                        PlotWidget* comps_plot);
  ~RenderSortStatFunctor() override = default;

  void SetSortType(const SortType sort_type);
  void SetSortingSystem(SortingSystem* sort_system);
  void SetAssignsPlotWidget(PlotWidget* assigns_plot);
  void SetCompsPlotWidget(PlotWidget* comps_plot);
  void SetColor(const glib::ColorRGBA& color);

  void operator()() override;

 protected:
  SortType sort_type_ = SortType::QUICK;
  SortingSystem* sorting_system_ = nullptr;

  RenderSeqPlotFunctor<size_t> assigns_plot_functor_;
  RenderSeqPlotFunctor<size_t> comps_plot_functor_;
};

#endif /* render_sort_stat_functor.hpp */
