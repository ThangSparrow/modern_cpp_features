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
  // Example 1: Auto with container - start
  std::cout << "Container: vector" << "\n";
  std::vector<int> vec = {1, 2, 3};
  for (auto cit = vec.cbegin(); cit != vec.cend(); ++cit)
  {
    std::cout << *cit << "\n";
  }

  std::cout << "Container: list" << "\n";
  std::list<int> list = {1, 2, 3, 4, 5};
  for (auto cit = list.cbegin(); cit != list.cend(); ++cit)
  {
    std::cout << *cit << "\n";
  }
  // Example 1: Auto with container - end

  // Example 2: Auto with lambda - start
  std::cout << "Use lambda to compute the square of numbers in a container" << "\n";
  auto square = [](int x)
  { std::cout << x * x << "\n"; }; // Lambda has unique, unnamable type, so auto is necessary to store it

  std::for_each(vec.cbegin(), vec.cend(), square);
  // Example 2: Auto with lambda - end

  // Example 3: Auto with template functions - start
  auto max_int = max(1, 2);     // int
  auto max_double = max(1.2, 3.4); // double

  std::cout << "Max int: " << max_int << "\n";
  std::cout << "Max double: " << max_double << "\n";
  // Example 3: Auto with template functions - end

    // Example 4: Range-Based For Loop - start
  std::cout << "Use range-based for loop to sum elems of vector" << "\n";
  double sum = 0.0;

  // Version 1: Copies elem
  for (auto x : vec)
  {
    sum += x;
  }
  std::cout << "Sum (auto): " << sum << "\n";

  // Version 2: References elems
  sum = 0.0;
  for (auto &x : vec)
  {
    sum += x;
  }
  std::cout << "Sum (auto): " << sum << "\n";
  // Example 4: Range-Based For Loop - end
}