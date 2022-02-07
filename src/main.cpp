#include "sorts.hpp"
#include "app.hpp"

int main() {
  size_t size = 0;
  std::cin >> size;
  OpCountElem<int>* array = new OpCountElem<int>[size];
  CheckAlloc(array);

  SetRandomValues(array, 0, size - 1);
  // BubbleSort(array, 0, size - 1);
  SelectionSort(array, 0, size - 1);
  // MergeSort(array, 0, size - 1);
  // QuickSort(array, 0, size - 1);

  if (CheckIncrease(array, 0, size - 1)) {
    std::cout << "success!\n";
  } else {
    std::cout << "failure!\n";
  }

  delete[] array;

  return 0;
}
