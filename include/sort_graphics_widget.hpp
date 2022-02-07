#ifndef SORT_GRAPHICS_WIDGET_HPP
#define SORT_GRAPHICS_WIDGET_HPP

#include "gui.hpp"
#include "sorting_system.hpp"
#include "plot_widget.hpp"

class SortGraphicsWidget: public gui::DummyContainerWidget {
 public:
  SortGraphicsWidget();
  SortGraphicsWidget(const glib::IntRect& location);
  ~SortGraphicsWidget() = default;

  void AddAssignsPlot(PlotWidget* assigns_plot);
  void AddCompsPlot(PlotWidget* comps_plot);
 protected:
  SortingSystem sorting_system;

  PlotWidget* assigns_plot = nullptr;
  PlotWidget* comps_plot   = nullptr;
};

#endif /* sort_graphics_widget.hpp */
