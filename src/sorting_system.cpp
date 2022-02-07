#include "sorting_system.hpp"

SortingSystem::SortingSystem() {
  SetDefaultValues();
  ShuffleArray();
}

SortingSystem::SortingSystem(const size_t new_size) {
  Resize(new_size);
}

void SortingSystem::ShuffleArray() {
  std::shuffle(array_.begin(), array_.end(), std::default_random_engine());
}

void SortingSystem::SetDefaultValues() {
  for (size_t i = 0; i < array_.size(); ++i) {
    array_[i] = i;
  }
}

void SortingSystem::Resize(const size_t new_size) {
  ResizeArray(new_size);
  ResizeCnts(new_size);
}

void SortingSystem::ResizeArray(const size_t new_size) {
  array_.resize(new_size);
  SetDefaultValues();
  ShuffleArray();
}

void SortingSystem::ResizeCnts(const size_t new_size) {
  for (auto& cnt: assigns_cnt_) {
    cnt.assign(new_size, 0);
  }
  for (auto& cnt: comps_cnt_) {
    cnt.assign(new_size, 0);
  }
}
