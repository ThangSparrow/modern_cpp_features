//------------------------------------------------------------------------------
// Requirements:
//      1. Create a class UniqueBuffer that manages a dynamically allocated array of integers
//      2. Make it move-only by disabling the copy constructor and copy assignment operator (= delete)
//      3. Implement a move constructor and move assignment operator.
//      4. Test it by moving a UniqueBuffer object into another and verify that original object is in a valid but empty state
//      5. Add a method to print the contents of the buffer for debugging
//-----------------------------------------------------------

#include <iostream>
#include <cstring>

class UniqueBuffer {
   public:
	int* data;
	size_t size;
	// Constructor
	UniqueBuffer(size_t s) {
		if (s > 0) {
			data = new int[s]();
            size = s;
			std::cout << "Allocated buffer of size " << s << std::endl;
		}
	};

	// Delete copy constructor and copy assignment
	UniqueBuffer(const UniqueBuffer&) = delete;
	UniqueBuffer& operator=(const UniqueBuffer&) = delete;

	// Move constructor
	UniqueBuffer(UniqueBuffer&& other) noexcept : data(other.data), size(other.size) {
		other.data = nullptr;
		other.size = 0;
		std::cout << "Move Constructor called for: " << data << std::endl;
	}

	// Move assignment operator
	UniqueBuffer& operator=(UniqueBuffer&& other) noexcept {
		if (this != &other) {
			delete[] data;
			data = other.data;
			size = other.size;
			other.data = nullptr;
			other.size = 0;
			std::cout << "Move Assignment called for: " << data << std::endl;
		}
		return *this;
	}

	// Destructor
	~UniqueBuffer() {
		delete[] data;
		std::cout << "Destructor called!" << std::endl;
	}

	// Print buffer contents
	void print() const {
		if (data == nullptr || size == 0) {
			std::cout << "Empty buffer" << std::endl;
			return;
		}
		std::cout << "Buffer contents: ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	// Get size
	int getSize() const { return size; };
};

int main() {
	// Create a buffer and initialize some values
	UniqueBuffer buf1(5);
	for (size_t i = 0; i < 5; i++) {
		buf1.data[i] = static_cast<int>(i + 1);
	}
	buf1.print();

	// Test move constructor
	UniqueBuffer buf2 = std::move(buf1);
	std::cout << "After move constructor: " << std::endl;
	buf1.print();  // Should be empty
	buf2.print();  // Should contain 1, 2, 3, 4, 5
	std::cout << "buf1 size: " << buf1.getSize() << ", buf2 size: " << buf2.getSize() << std::endl;

	// Test move assignment
	UniqueBuffer buf3(3);
	buf3 = std::move(buf2);
	std::cout << "After move assignment:" << std::endl;
	buf2.print();  // Should be empty
	buf3.print();  // Should contain 1, 2, 3, 4, 5
	std::cout << "buf2 size: " << buf2.getSize() << ", buf3 size: " << buf3.getSize() << std::endl;
}