#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <cstdio>

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

void BubbleSort(std::vector<int>& array);


#endif /* sorts.hpp */
