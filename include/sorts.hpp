#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <iostream>
#include <cstring>
#include <cassert>
#include <ctime>

bool CheckAlloc(void* ptr);

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

int Medium(int first, int second, int third);

void BubbleSort(int* array, size_t size);

void SelectionSort(int* array, size_t size);

void QuickSort(int* array, size_t left, size_t right);

void Merge(int* array, size_t left, size_t mid, size_t right, int* tmp_buffer);

void MergeSortRecursive(int* array, size_t left, size_t right, int* tmp_buffer);

void MergeSort(int* array, size_t size);

bool CheckIncrease(const int* array, size_t size);

void EnterArray(int* array, size_t size);

void SetRandomArray(int* array, size_t size);

void PrintArray(const int* array, size_t size);

#endif /* sorts.hpp */
