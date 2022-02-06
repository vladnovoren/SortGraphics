#include "sorting_system.hpp"

SortingSystem::SortingSystem() {
  for (size_t i = 0; i < ARRAY_SIZE; ++i) {
    array_[i] = i + 1;
  }
}

void SortingSystem::ShuffleArray() {
  assert(array_ != nullptr);

  srand(time(NULL));
  for (size_t i = 0; i < ARRAY_SIZE; ++i) {
    std::swap(array_[i], array_[rand() % (i + 1)]);
  }
}

void SortingSystem::BubbleSort() {
  ShuffleArray();
  
  
}
