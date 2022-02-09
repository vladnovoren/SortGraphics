#include "sorting_system.hpp"

SortingSystem::SortingSystem() {
  InitCounters();
  Resize(DEFAULT_ARRAY_SIZE);
}

SortingSystem::SortingSystem(const size_t new_size) {
  InitCounters();
  Resize(new_size);
}

void SortingSystem::Resize(const size_t new_size) {
  array_.resize(new_size);
  ResizeCnts(new_size);
}

SortStatistics SortingSystem::GetSortStatistics(const SortType sort_type) {
//  size_t sort_id = static_cast<size_t>(sort_type);
//  if (!sort_checked_[sort_id]) {
    for (size_t i = 0; i < array_.size(); ++i) {
      OpCountElem<int>::ResetOpCnts();
      SetDefaultValues(0, i);
      ShuffleArray(0, i);
      Sort(sort_type, 0, i);
      UpdateCounters(sort_type, i);
    }
//    printf("1234\n");
//    sort_checked_[sort_id] = true;
//  }
  return GetReadyStatistics(sort_type);
}

void SortingSystem::InitCounters() {
  sort_checked_.assign(static_cast<size_t>(SortType::SORTS_CNT), false);
  assigns_cnt_.resize(static_cast<size_t>(SortType::SORTS_CNT));
  comps_cnt_  .resize(static_cast<size_t>(SortType::SORTS_CNT));
}

void SortingSystem::SetDefaultValues(const size_t left, const size_t right) {
  for (size_t i = left; i <= right; ++i) {
    array_[i] = i;
  }
  OpCountElem<int>::ResetOpCnts();
}

void SortingSystem::ShuffleArray(const size_t left, const size_t right) {
  std::shuffle(array_.begin() + left, array_.begin() + right + 1, std::default_random_engine());
  OpCountElem<int>::ResetOpCnts();
}

void SortingSystem::ResizeCnts(const size_t new_size) {
  for (auto& cnt: assigns_cnt_) {
    cnt.assign(new_size, 0);
  }
  for (auto& cnt: comps_cnt_) {
    cnt.assign(new_size, 0);
  }
}

void SortingSystem::Sort(const SortType sort_type, const size_t left, const size_t right) {
  switch (sort_type) {
    case SortType::BUBBLE:
      BubbleSort(array_.data(), left, array_.size() - 1);
      break;
    case SortType::SELECTION:
      SelectionSort(array_.data(), left, right);
      break;
    case SortType::QUICK:
      QuickSort(array_.data(), left, right);
      break;
    case SortType::MERGE:
      QuickSort(array_.data(), left, right);
      break;
    case SortType::STD_SORT:
      std::sort(array_.begin() + left, array_.begin() + right + 1);
      break;
    case SortType::STD_STABLE_SORT:
      std::stable_sort(array_.begin() + left, array_.begin() + right + 1);
      break;
    default:
      std::cout << "invalid SortType\n";
      break;
  }
}

void SortingSystem::UpdateCounters(const SortType sort_type, const size_t elems_cnt) {
  UpdateAssignsCnt(sort_type, elems_cnt);
  UpdateCompsCnt(sort_type, elems_cnt);
}

void SortingSystem::UpdateAssignsCnt(const SortType sort_type, const size_t elems_cnt) {
  size_t sort_id = static_cast<size_t>(sort_type);
  assert(sort_id < assigns_cnt_.size());
  assert(sort_id < static_cast<size_t>(SortType::SORTS_CNT));

  assigns_cnt_[sort_id][elems_cnt] = OpCountElem<int>::GetAssignsCnt();
}

void SortingSystem::UpdateCompsCnt(const SortType sort_type, const size_t elems_cnt) {
  size_t sort_id = static_cast<size_t>(sort_type);
  assert(sort_id < comps_cnt_.size());
  assert(sort_id < static_cast<size_t>(SortType::SORTS_CNT));

  comps_cnt_[sort_id][elems_cnt] = OpCountElem<int>::GetCompsCnt();
}

SortStatistics SortingSystem::GetReadyStatistics(const SortType sort_type) const {
  size_t sort_id = static_cast<size_t>(sort_type);
  return {&assigns_cnt_[sort_id], &comps_cnt_[sort_id]};
}
