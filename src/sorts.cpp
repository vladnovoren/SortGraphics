#include "sorts.hpp"

int Medium(int first, int second, int third) {
  int max = Max(Max(first, second), third);
  int min = Min(Min(first, second), third);

  return first + second + third - min - max;
}

void BubbleSort(std::vector<int>& array) {
  for (size_t i = 0; i < n - 1; ++i) {
    for (size_t j = 0; j < n - 1; ++j) {
      if (array[j] > array[j + 1]) {
        Swap(array[j], array[j + 1]);
      }
    }
  }
}

void QuickSort(std::vector<int>& array, size_t left, size_t right) {
  int pivot = Medium(array[left], array[right], array[(left + right) / 2]);

  size_t left_id = left, right_id = right;

  while (left_id <= right_id) {
    while (array[left_id] < pivot) {
      ++left_id;
    }
    while (array[right_id] > pivot) {
      --right_id;
    }
    if (left_id <= right_id) {
      Swap(array[left_id], array[right_id]);
      ++left_id;
      --right_id;
    }
  }

  if (left < right_id) {
    QuickSort(array, left, right_id);
  }
  if (left_id < right) {
    QuickSort(array, left_id, right);
  }
}

void Merge(std::vector<int>& array, size_t left, size_t mid, size_t right, std::vector<int>& tmp_buffer) {
  size_t left_id = left, right_id = mid, tmp_buffer_id = 0;
  while (left_id < mid && right_id < right) {
    if (array[left_id] < array[right_id]) {
      tmp_buffer[tmp_buffer_id] = array[left_id++];
    } else {
      tmp_buffer[tmp_buffer_id] = array[right_id++];
    }
    tmp_buffer_id++;
  }

  while (left_id < mid) {
    tmp_buffer[tmp_buffer_id++] = array[left_id++];
  }
  while (right_id < right) {
    tmp_buffer[tmp_buffer_id++] = array[right_id++];
  }

  for (size_t i = 0; i < )
}

void MergeSort(std::sort<int>& array, size_t left, size_t right)
