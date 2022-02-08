#include "sort_plots_widget.hpp"

SortPlotsWidget::SortPlotsWidget(): gui::DummyContainerWidget(DEFAULT_PLOTS_WIDGET_LOCATION) {
  assigns_plot_ = AddPlot(DEFAULT_ASSIGNS_PLOT_LOCATION);
  comps_plot_   = AddPlot(DEFAULT_COMPS_PLOT_LOCATION);
}

SortPlotsWidget::SortPlotsWidget(const glib::IntRect &location,
                                 const glib::IntRect &assigns_plot_location,
                                 const glib::IntRect &comps_plot_location):
                 gui::DummyContainerWidget(location) {
  assigns_plot_ = AddPlot(assigns_plot_location);
  comps_plot_   = AddPlot(comps_plot_location);
}

PlotWidget* SortPlotsWidget::AddPlot(const glib::IntRect &location) {
  PlotWidget* plot_widget_ = new PlotWidget(location);
  if (!CheckAlloc(plot_widget_)) {
    return nullptr;
  }
  AddChild(plot_widget_);
  return plot_widget_;
}
