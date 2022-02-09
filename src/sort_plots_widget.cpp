#include "sort_plots_widget.hpp"

SortPlotsWidget::SortPlotsWidget(): gui::DummyContainerWidget(DEFAULT_PLOTS_WIDGET_LOCATION) {
  assigns_plot_ = AddPlot(DEFAULT_ASSIGNS_PLOT_LOCATION);
  comps_plot_   = AddPlot(DEFAULT_COMPS_PLOT_LOCATION);
  Init();
}

SortPlotsWidget::SortPlotsWidget(const glib::IntRect &location,
                                 const glib::IntRect &assigns_plot_location,
                                 const glib::IntRect &comps_plot_location):
                 gui::DummyContainerWidget(location) {
  assigns_plot_ = AddPlot(assigns_plot_location);
  comps_plot_   = AddPlot(comps_plot_location);
  Init();
}

PlotWidget* SortPlotsWidget::AddPlot(const glib::IntRect &location) {
  PlotWidget* plot_widget_ = new PlotWidget(location);
  if (!CheckAlloc(plot_widget_)) {
    return nullptr;
  }
  AddChild(plot_widget_);
  return plot_widget_;
}

void SortPlotsWidget::Init() {
  InitLabels();
  InitButtons();
}

void SortPlotsWidget::InitLabels() {
  glib::Text assigns_text("Assigments", gui::SkinManager::GetInstance().GetSanFranciscoFont());
  assigns_text.SetFontSize(12);
  assigns_text.SetColor(glib::BLACK);
  assigns_text.SetAlign(glib::TextAlign::CENTER);

  gui::Title* assigns = new gui::Title;
  assigns->SetLocation(glib::IntRect(300, 35, 0, 0));
  assigns->SetText(assigns_text);

  AddChild(assigns);

  glib::Text comps_text("Comparisons", gui::SkinManager::GetInstance().GetSanFranciscoFont());
  comps_text.SetFontSize(12);
  comps_text.SetColor(glib::BLACK);
  comps_text.SetAlign(glib::TextAlign::CENTER);

  gui::Title* comps = new gui::Title;
  comps->SetLocation(glib::IntRect(850, 35, 0, 0));
  comps->SetText(comps_text);
  AddChild(comps);
}

void SortPlotsWidget::InitButtons() {
  gui::RectButtonSkin* bubble_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/bubble"));
  RenderSortStatFunctor* bubble_functor = new RenderSortStatFunctor(SortType::BUBBLE, &sorting_system_, glib::RED, assigns_plot_, comps_plot_);
  gui::PlainButton* bubble_button = new gui::PlainButton(glib::IntRect(50, 570, 81, 40), bubble_functor, bubble_skin);
  AddChild(bubble_button);

  gui::RectButtonSkin* merge_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/merge"));
  RenderSortStatFunctor* merge_functor = new RenderSortStatFunctor(SortType::MERGE, &sorting_system_, glib::BLUE, assigns_plot_, comps_plot_);
  gui::PlainButton* merge_button = new gui::PlainButton(glib::IntRect(150, 570, 81, 40), merge_functor, merge_skin);
  AddChild(merge_button);

  gui::RectButtonSkin* quick_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/quick"));
  RenderSortStatFunctor* quick_functor = new RenderSortStatFunctor(SortType::QUICK, &sorting_system_, glib::GREEN, assigns_plot_, comps_plot_);
  gui::PlainButton* quick_button = new gui::PlainButton(glib::IntRect(250, 570, 81, 40), quick_functor, quick_skin);
  AddChild(quick_button);

  gui::RectButtonSkin* selection_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/selection"));
  RenderSortStatFunctor* selection_functor = new RenderSortStatFunctor(SortType::SELECTION, &sorting_system_, glib::YELLOW, assigns_plot_, comps_plot_);
  gui::PlainButton* selection_button = new gui::PlainButton(glib::IntRect(350, 570, 81, 40), selection_functor, selection_skin);
  AddChild(selection_button);

  gui::RectButtonSkin* stdsort_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/stdsort"));
  RenderSortStatFunctor* stdsort_functor = new RenderSortStatFunctor(SortType::STD_SORT, &sorting_system_, glib::PINK, assigns_plot_, comps_plot_);
  gui::PlainButton* stdsort_button = new gui::PlainButton(glib::IntRect(450, 570, 81, 40), stdsort_functor, stdsort_skin);
  AddChild(stdsort_button);

  gui::RectButtonSkin* stdstable_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/stdstable"));
  RenderSortStatFunctor* stdstable_functor = new RenderSortStatFunctor(SortType::STD_STABLE_SORT, &sorting_system_, glib::PURPLE, assigns_plot_, comps_plot_);
  gui::PlainButton* stdstable_button = new gui::PlainButton(glib::IntRect(550, 570, 81, 40), stdstable_functor, stdstable_skin);
  AddChild(stdstable_button);

  gui::RectButtonSkin* clear_skin = dynamic_cast<gui::RectButtonSkin*>(gui::SkinManager::GetInstance().LoadButtonSkinFromFolder("Skins/sort/clear"));
  SortPlotsClearFunctor* clear_functor = new SortPlotsClearFunctor(assigns_plot_, comps_plot_);
  gui::PlainButton* clear_button = new gui::PlainButton(glib::IntRect(650, 570, 81, 40), clear_functor, clear_skin);
  AddChild(clear_button);

  delete bubble_skin;
  delete merge_skin;
  delete quick_skin;
  delete selection_skin;
  delete stdsort_skin;
  delete stdstable_skin;
  delete clear_skin;
}