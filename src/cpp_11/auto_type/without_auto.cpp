#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
T max(T a, T b)
{
  return (a > b) ? a : b;
}

int main()
{
  // Example 1: Print elems in a container - start
  std::cout << "Container: vector" << "\n";
  std::vector<int> vec = {1, 2, 3};
  for (std::vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); ++cit)
  {
    std::cout << *cit << "\n";
  }

  std::cout << "Container: list" << "\n";
  std::list<int> list = {1, 2, 3, 4, 5};
  for (std::list<int>::const_iterator cit = list.cbegin(); cit != list.cend(); ++cit)
  {
    std::cout << *cit << "\n";
  }
  // Example 1: Print elems in a container - end

  // Example 2: Use lambda to compute the square of numbers in a container - start
  std::cout << "Use lambda to compute the square of numbers in a container";
  std::for_each(vec.cbegin(), vec.cend(), [](int x)
                { std::cout << x * x << "\n"; });
  // Example 2: Use lambda to compute the square of numbers in a container - end

  // Example 3: Template Functions - start
  int max_int = max(1, 2);           // int
  double max_double = max(1.2, 3.4); // double

  std::cout << "Max int: " << max_int << "\n";
  std::cout << "Max double: " << max_double << "\n";
  // Example 3: Template Functions - end

  // Example 4: Range-Based For Loop - start
  std::cout << "Use range-based for loop to sum elems of vector" << "\n";
  double sum = 0.0;

  // Version 1: Copies elem
  for (double x : vec) // copies elem in vec and assign to double x
  {
    sum += x;
  }
  std::cout << "Sum (auto): " << sum << "\n";

  // Version 2: References elems
  sum = 0.0;
  for (int &x : vec) // x refer to elem in vec
  {
    sum += x;
  }
  std::cout << "Sum (auto): " << sum << "\n";
  // Example 4: Range-Based For Loop - end
}