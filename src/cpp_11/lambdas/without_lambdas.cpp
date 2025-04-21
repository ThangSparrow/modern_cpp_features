#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Named function
bool compare_length(const std::string &a, const std::string &b)
{
  return a.length() < b.length();
}

double doubling_double(double x)
{
  return x * 2;
}

int doubling_int(int x)
{
  return x * 2;
}

void filter_greater(const int threshold, int x)
{
  if (x > threshold)
  {
    std::cout << x << " ";
  }
}

int main()
{

  // Example 1: Sorting with Custom Criteria - start
  std::vector<std::string> words = {"apple", "banana", "kiwi", "strawberry"};

  // Using named function
  std::cout << "Named function sort:\n";
  std::vector<std::string> words_copy = words;
  std::sort(words_copy.begin(), words_copy.end(), compare_length);
  for (const auto &w : words_copy)
  {
    std::cout << w << " ";
  }
  std::cout << "\n";
  // Example 1: Sorting with Custom Criteria - end

  // Example 2: Capturing Local Variables - start
  std::vector<int> numbers = {10, 15, 20, 25, 30};
  int divisor = 5;
  int count = 0;

  for (auto x : numbers)
  {
    if (x % divisor == 0)
    {
      ++count;
    }
  }
  // Example 2: Capturing Local Variables - end

  // Example 3: Generic Lambda (auto-type lambda) - start
  // Integer vector
  std::vector<int> int_vec = {1, 2, 3, 4};
  std::cout << "Doubled integers: ";
  std::transform(int_vec.begin(), int_vec.end(), int_vec.begin(), doubling_int);
  for (auto x : int_vec)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";

  // Double vector
  std::vector<double> double_vec = {1.2, 3.4, 5.6};
  std::cout << "Doubled doubles: ";
  std::transform(double_vec.begin(), double_vec.end(), double_vec.begin(), doubling_double);
  for (auto x : double_vec)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
  // Example 3: Generic Lambda - end

  // Example 4: Storing Lambdas - start
  int threshold = 10;

  std::vector<int> vec1 = {5, 15, 10, 20, 8};
  std::vector<int> vec2 = {12, 7, 25, 9, 18};

  std::cout << "Filtered vec1 (< " << threshold << "): ";
  for (auto x : vec1)
  {
    filter_greater(threshold, x);
  }
  std::cout << "\n";

  std::cout << "Filtered vec2 (< " << threshold << "): ";
  for (auto x : vec1)
  {
    filter_greater(threshold, x);
  }
  std::cout << "\n";
  // Example 4: Storing Lambdas - end
}