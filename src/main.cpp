#include "sorting_system.hpp"
#include "app.hpp"

int main() {
  size_t size = 0;
  std::cin >> size;

  SortingSystem sortingSystem(100);
  SortStatistics statistics = sortingSystem.GetSortStatistics(SortType::BUBBLE);

  std::cout << statistics.assigns_cnt_.back() << ' ' << statistics.comps_cnt_.back() << '\n';

  App& app = App::GetInstance();
  app.Exec();

  return 0;
}
