#ifndef SORTING_SYSTEM_HPP
#define SORTING_SYSTEM_HPP

#include "sorts.hpp"

enum class SortType {
  BUBBLE,
  SELECTION,
  QUICK_SORT,
  MERGE,
  STD_SORT,
  STD_STABLE_SORT,
  SORTS_CNT
};

static const DEFAULT_ARRAY_SIZE = 100;


class SortingSystem {
 public:
  SortingSystem();
  SortingSystem(const size_t array_size);
  SortingSystem() = default;

  void Resize(const size_t new_size);

  const std::vector<size_t>& GetSortStatistics(const Sort sort_type);

 protected:
  bool sorted_ = false;

  std::vector<OpCountElem<int>> array_;

  std::vector<vector<size_t>> assigns_cnt_(static_cast<size_t>(SortType::SORTS_CNT), std::vector<size_t>(DEFAULT_ARRAY_SIZE));
  std::vector<vector<size_t>> comps_cnt_  (static_cast<size_t>(SortType::SORTS_CNT), std::vector<size_t>(DEFAULT_ARRAY_SIZE));

  std::vector<bool> sort_checked_(static_cast<size_t>(SortType::SORTS_CNT), false);

  void SetDefaultValues();
  void ShuffleArray();

  void ResizeArray(const size_t new_size);
  void ResizeCnts(const size_t new_size);

  void Sort(const Sort)
};

#endif /* sorting_system.hpp */
