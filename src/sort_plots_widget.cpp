#include "sort_plots_widget.hpp"

SortPlotsWidget::SortPlotsWidget(): gui::DummyContainerWidget(DEFAULT_PLOTS_WIDGET_LOCATION) {
  assigns_plot_ = AddPlot(DEFAULT_ASSIGNS_PLOT_LOCATION);
  comps_plot_   = AddPlot(DEFAULT_COMPS_PLOT_LOCATION);
  InitButtons();
}

SortPlotsWidget::SortPlotsWidget(const glib::IntRect &location,
                                 const glib::IntRect &assigns_plot_location,
                                 const glib::IntRect &comps_plot_location):
                 gui::DummyContainerWidget(location) {
  assigns_plot_ = AddPlot(assigns_plot_location);
  comps_plot_   = AddPlot(comps_plot_location);
  InitButtons();
}

PlotWidget* SortPlotsWidget::AddPlot(const glib::IntRect &location) {
  PlotWidget* plot_widget_ = new PlotWidget(location);
  if (!CheckAlloc(plot_widget_)) {
    return nullptr;
  }
  AddChild(plot_widget_);
  return plot_widget_;
}

void SortPlotsWidget::InitButtons() {
  gui::RectButtonSkin* bubble_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/bubble"));
  assert(bubble_skin != nullptr);

  RenderSortStatFunctor* bubble_functor = new RenderSortStatFunctor(SortType::BUBBLE, &sorting_system_, glib::RED, assigns_plot_, comps_plot_);
  assert(bubble_functor != nullptr);

  gui::PlainButton* bubble_button = new gui::PlainButton(glib::IntRect(50, 570, 81, 40), bubble_functor, bubble_skin);
  assert(bubble_button != nullptr);

  AddChild(bubble_button);
}