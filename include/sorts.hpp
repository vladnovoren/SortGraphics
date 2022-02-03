#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <iostream>
#include <cstring>
#include <cassert>
#include <ctime>

template<typename T>
class CountSortElem {
 public:
  T value_ = 0;

  CountSortElem() = default;

  CountSortElem(T value): value_(value) {}

  CountSortElem(const CountSortElem& other): value_(other.value_) {
    ++n_assign_;
  }

  CountSortElem& operator=(const CountSortElem& other) {
    value_ = other.value_;
    ++n_assign_;
    return *this;
  }

  ~CountSortElem() = default;

  bool operator<(const CountSortElem& right) {
    ++n_comp_;
    return value_ < right.value_;
  }

  bool operator>(const CountSortElem& right) {
    ++n_comp_;
    return value_ > right.value_;
  }

  bool operator<=(const CountSortElem& right) {
    ++n_comp_;
    return value_ <= right.value_;
  }

  bool operator>=(const CountSortElem& right) {
    ++n_comp_;
    return value_ >= right.value_;
  }

  size_t GetNComp() const {
    return n_comp_;
  }

  size_t GetNAssign() const {
    return n_assign_;
  }

 protected:
  size_t n_comp_ = 0;
  size_t n_assign_ = 0;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const CountSortElem<T>& elem) {
  os << elem.value_;
  return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, const CountSortElem<T>& elem) {
  is >> elem.value_;
  return is;
}

template<typename T>
T Max(const T& first, const T& second) {
  return (first > second ? first : second);
}

template<typename T>
T Min(const T& first, const T& second) {
  return (first < second ? first : second);
}

template<typename T>
void Swap(T& first, T& second) {
  T tmp = first;
  first = second;
  second = tmp;
}

template<typename T>
bool CheckAlloc(T* ptr) {
  if (ptr == nullptr) {
    std::cout << "bad alloc\n";
    return false;
  } else {
    return true;
  }
}

template<typename T>
void BubbleSort(T* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size - 1; ++i) {
    for (size_t j = 0; j < size - 1; ++j) {
      if (array[j] > array[j + 1]) {
        Swap(array[j], array[j + 1]);
      }
    }
  }
}

template<typename T>
void SelectionSort(T* array, size_t size) {
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

template<typename T>
void QuickSort(CountSortElem<T>* array, size_t left, size_t right) {
  assert(array != nullptr);

  CountSortElem<T> pivot = array[(left + right) / 2];

  size_t left_id = left, right_id = right;

  while (left_id <= right_id && right_id <= right) {
    while (array[left_id] < pivot) {
      ++left_id;
    }
    while (pivot < array[right_id]) {
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

template<typename T>
void Merge(T* array, size_t left, size_t mid, size_t right, T* tmp_buffer) {
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

template<typename T>
void MergeSortRecursive(T* array, size_t left, size_t right, T* tmp_buffer) {
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

template<typename T>
void MergeSort(T* array, size_t size) {
  assert(array != nullptr);

  T* tmp_buffer = new T[size];
  if (!CheckAlloc(tmp_buffer)) {
    return;
  }

  MergeSortRecursive(array, 0, size, tmp_buffer);

  delete[] tmp_buffer;
}

template<typename T>
bool CheckIncrease(T* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size - 1; ++i) {
    if (array[i + 1] < array[i]) {
      return false;
    }
  }

  return true;
}

template<typename T>
void EnterArray(T* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
}

template<typename T>
void SetRandomArray(CountSortElem<T>* array, size_t size) {
  assert(array != nullptr);

  srand(time(NULL));
  for (size_t i = 0; i < size; ++i) {
    array[i] = rand();
  }
}

template<typename T>
void PrintArray(const T* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
}

template<typename T>
size_t NAssigns(const CountSortElem<T>* array, size_t size) {
  assert(array != nullptr);

  size_t result = 0;
  for (size_t i = 0; i < size; ++i) {
    result += array[i].GetNAssign();
  }
  return result;
}

template<typename T>
size_t NComp(const CountSortElem<T>* array, size_t size) {
  assert(array != nullptr);

  size_t result = 0;
  for (size_t i = 0; i < size; ++i) {
    result += array[i].GetNComp();
  }
  return result;
}

#endif /* sorst.hpp */
