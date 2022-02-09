#ifndef SORT_GRAPHICS_WIDGET_HPP
#define SORT_GRAPHICS_WIDGET_HPP

#include "gui.hpp"
#include "sorting_system.hpp"
#include "plot_widget.hpp"
#include "render_sort_stat_functor.hpp"

static const glib::IntRect DEFAULT_PLOTS_WIDGET_LOCATION(0, 0, 1150, 600);
static const glib::IntRect DEFAULT_ASSIGNS_PLOT_LOCATION(50, 50, 500, 500);
static const glib::IntRect DEFAULT_COMPS_PLOT_LOCATION(600, 50, 500, 500);

class SortPlotsWidget: public gui::DummyContainerWidget {
 public:
  SortPlotsWidget();
  SortPlotsWidget(const glib::IntRect& location,
                  const glib::IntRect& assigns_plot_location,
                  const glib::IntRect& comps_plot_location);
  ~SortPlotsWidget() = default;
 protected:
  SortingSystem sorting_system_;

  PlotWidget* assigns_plot_ = nullptr;
  PlotWidget* comps_plot_   = nullptr;

  PlotWidget* AddPlot(const glib::IntRect& location);
  void InitButtons();
};

#endif /* sort_plots_widget.hpp */
