#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    // v1 is an object on the stack
    // v1 contains a pointer that points to integer memory on the heap
    std::cout << "v1 size before move: " << v1.size() << std::endl;

    // Move v1 to v2
    std::vector<int> v2 = std::move(v1);
    // After move assignment, pointer in v1 becomes nullptr, v2's pointer point to the heap memory above
    std::cout << "v1 size after move: " << v1.size() << std::endl;
    std::cout << "v2 size after move: " << v2.size() << std::endl;

    // v1 is in a valid but unspecified state (usually empty)
    // v1's pointer point to other integer memory on heap
    v1.push_back(10); // Safe to use v1 again
    std::cout << "v1 size after push_back: " << v1.size() << std::endl;
    return 0;
}