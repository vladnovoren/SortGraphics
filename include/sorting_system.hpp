#ifndef SORTING_SYSTEM_HPP
#define SORTING_SYSTEM_HPP

#include "sorts.hpp"

enum class SortType {
  BUBBLE,
  SELECTION,
  QUICK,
  MERGE,
  STD_SORT,
  STD_STABLE_SORT,
  SORTS_CNT
};

static const size_t DEFAULT_ARRAY_SIZE = 100;

struct SortStatistics {
  const std::vector<size_t>& assigns_cnt_ = {};
  const std::vector<size_t>& comps_cnt_   = {};
};

class SortingSystem {
 public:
  SortingSystem();
  explicit SortingSystem(const size_t array_size);
  ~SortingSystem() = default;

  void Resize(const size_t new_size);

  SortStatistics GetSortStatistics(const SortType sort_type);
 protected:
  bool sorted_ = false;

  std::vector<OpCountElem<int>> array_;

  std::vector<std::vector<size_t>> assigns_cnt_;
  std::vector<std::vector<size_t>> comps_cnt_;

  std::vector<bool> sort_checked_;

  void InitCounters();

  void SetDefaultValues(const size_t left, const size_t right);
  void ShuffleArray(const size_t left, const size_t right);

  void ResizeCnts(const size_t new_size);

  void Sort(const SortType sort_type, const size_t left, const size_t right);

  void UpdateCounters(const SortType sort_type, const size_t elems_cnt);
  void UpdateAssignsCnt(const SortType sort_type, const size_t elems_cnt);
  void UpdateCompsCnt(const SortType sort_typem, const size_t elems_cnt);

  SortStatistics GetReadyStatistics(const SortType sort_type) const;
};

#endif /* sorting_system.hpp */
