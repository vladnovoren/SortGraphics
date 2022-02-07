#ifndef SORTING_SYSTEM_HPP
#define SORTING_SYSTEM_HPP

#include "sorts.hpp"

enum class Sorts {
  BUBBLE,
  SELECTION,
  QUICK_SORT,
  MERGE,
  STD_SORT,
  STD_STABLE_SORT,
  N_SORTS
};

static const size_t ARRAY_SIZE = 500;

class SortingSystem {
 public:
  SortingSystem();

  size_t assigns_cnt_[size_t(Sorts::N_SORTS)][ARRAY_SIZE] = {};
  size_t comps_cnt_[size_t(Sorts::N_SORTS)][ARRAY_SIZE]   = {};

  void ShuffleArray();

  void BubbleSort();
  void SelectionSort();
  void QuickSort();
  void MergeSort();
  void STDQuickSort();
  void STDStableSort();
 protected:
  int array_[ARRAY_SIZE] = {};
};

#endif /* sorting_system.hpp */
