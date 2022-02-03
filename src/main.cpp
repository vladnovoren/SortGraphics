#include "sorts.hpp"

int main() {
  size_t size = 0;
  std::cin >> size;
  CountSortElem<int>* array = new CountSortElem<int>[size];

  CheckAlloc(array);
  // SetRandomArray(array, size);
  // BubbleSort(array, size);
  MergeSort(array, size);
  QuickSort(array, 0, size - 1);

  size_t n_assign = NAssigns(array, size) - size;
  size_t n_comp   = NComp(array, size);

  if (CheckIncrease(array, size)) {
    std::cout << "success!\n";
  } else {
    std::cout << "failure!\n";
  }

  std::cout << "n_assign: " << n_assign << '\n';
  std::cout << "n_comp: " << n_comp << '\n';

  delete[] array;

  return 0;
}
