#include <string>
#include <iostream>
#include <utility>

class IntWrapper {
	int* ptr;
	std::string name;

   public:
	//    Default constructor
	IntWrapper() : ptr(nullptr), name("") { std::cout << "Default constructor for " << name << std::endl; };

	// Parameterized constructor
	IntWrapper(int value, std::string name) : name(name) {
		ptr = new int(value);
		std::cout << "Parameterized constructor for " << name << " with value " << *ptr << std::endl;
	};

	// Copy constructor
	IntWrapper(const IntWrapper& other) = delete;

	// Move constructor
	IntWrapper(IntWrapper&& other) noexcept : ptr(other.ptr), name(std::move(other.name)) {
		other.ptr = nullptr;
		other.name = "moved_from_" + name;
		std::cout << "Move constructor from " << other.name << " to " << name << std::endl;
	};

	// Destructor: Cleans up the dynamically allocated integer
	~IntWrapper() {
		delete ptr;
		std::cout << "Destructor for " << name << std::endl;
	};

	// Copy assignment operator: Deleted to prevent copying
	IntWrapper& operator=(const IntWrapper& other) = delete;

	// Move assignment operator: Transfers resources from an rvalue
	IntWrapper& operator=(IntWrapper&& other) noexcept {
		if (this != &other) {
			delete ptr;
			ptr = other.ptr;
			name = other.name;

			other.ptr = nullptr;
			other.name = "moved_from_" + std::move(other.name);
            std::cout << "Move assignment from " << other.name << " to " << name << std::endl;
		}
		return *this;
	};

	// Get the wrapped value
	int getValue() const { return ptr ? *ptr : 0; };

	// Get the address of value
	int* getAddress() const { return ptr ? ptr : nullptr; }

	// Get the object name
	std::string getName() const { return name; };
};

int main() {
	// Create object using parameterized constructor
	IntWrapper w1(42, "w1");

	// Test move constructor
	IntWrapper w2 = std::move(w1);	// w1 becomes moved_from_w1, w2 is w1 
	std::cout << w1.getName() << " value: " << w1.getValue() << std::endl;
	std::cout << w1.getName() << " address: " << w1.getAddress() << std::endl;
	std::cout << w2.getName() << " value: " << w2.getValue() << std::endl;
	std::cout << w2.getName() << " address: " << w2.getAddress() << std::endl;

	// Test move assignment
	IntWrapper w3(100, "w3");
	IntWrapper w4(200, "w4");
	w4 = std::move(w3);	 // w3 becomes moved_from_w3, w4 is w3
	std::cout << w3.getName() << " value: " << w3.getValue() << std::endl;
	std::cout << w4.getName() << " value: " << w4.getValue() << std::endl;

	// Try copy constructor - failed while compiling
	// IntWrapper w4 = w3;

	// Try copy assignment - failed while compiling
	// w1 = w3;
}