#include "sorts.hpp"

int main() {
  size_t size = 0;
  std::cin >> size;
  int* array = new int[size];
  CheckAlloc(array);

  SetRandomArray(array, size);
  SelectionSort(array, size);
  PrintArray(array, size);
  if (CheckIncrease(array, size)) {
    std::cout << "success!\n";
  } else {
    std::cout << "failure!\n";
  }

  delete[] array;

  return 0;
}
