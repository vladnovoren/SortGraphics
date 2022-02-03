#include "sorts.hpp"

bool CheckAlloc(void* ptr) {
  if (ptr == nullptr) {
    std::cout << "bad alloc\n";
    return false;
  } else {
    return true;
  }
}

int Medium(int first, int second, int third) {
  int max = Max(Max(first, second), third);
  int min = Min(Min(first, second), third);

  return first + second + third - min - max;
}

void BubbleSort(int* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size - 1; ++i) {
    for (size_t j = 0; j < size - 1; ++j) {
      if (array[j] > array[j + 1]) {
        Swap(array[j], array[j + 1]);
      }
    }
  }
}

void SelectionSort(int* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size; ++i) {
    size_t min_id = i;
    for (size_t j = i; j < size; ++j) {
      if (array[j] < array[min_id]) {
        min_id = j;
      }
    }
    Swap(array[i], array[min_id]);
  }
}

void QuickSort(int* array, size_t left, size_t right) {
  assert(array != nullptr);

  int pivot = Medium(array[left], array[right], array[(left + right) / 2]);

  size_t left_id = left, right_id = right;

  while (left_id <= right_id && right_id <= right) {
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

  if (left < right_id && right_id <= right) {
    QuickSort(array, left, right_id);
  }
  if (left_id < right) {
    QuickSort(array, left_id, right);
  }
}

void Merge(int* array, size_t left, size_t mid, size_t right, int* tmp_buffer) {
  assert(array != nullptr);
  assert(tmp_buffer != nullptr);

  size_t left_id = left,
         right_id = mid,
         tmp_buffer_id = 0;

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

  for (size_t i = left; i < right; ++i) {
    array[i] = tmp_buffer[i - left];
  }
}

void MergeSortRecursive(int* array, size_t left, size_t right, int* tmp_buffer) {
  assert(array != nullptr);
  assert(tmp_buffer != nullptr);

  if (left + 1 >= right) {
    return;
  }

  size_t mid = (left + right) / 2;

  MergeSortRecursive(array, left, mid, tmp_buffer);
  MergeSortRecursive(array, mid, right, tmp_buffer);

  Merge(array, left, mid, right, tmp_buffer);
}

void MergeSort(int* array, size_t size) {
  assert(array != nullptr);

  int* tmp_buffer = new int[size];
  if (!CheckAlloc(tmp_buffer)) {
    return;
  }

  MergeSortRecursive(array, 0, size, tmp_buffer);

  delete[] tmp_buffer;
}

bool CheckIncrease(const int* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size - 1; ++i) {
    if (array[i] > array[i + 1]) {
      return false;
    }
  }

  return true;
}

void EnterArray(int* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
}

void SetRandomArray(int* array, size_t size) {
  assert(array != nullptr);

  srand(time(NULL));
  for (size_t i = 0; i < size; ++i) {
    array[i] = rand();
  }
}

void PrintArray(const int* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
  printf("\n");
}
