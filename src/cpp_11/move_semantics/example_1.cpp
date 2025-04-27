#include <iostream>
#include <cstring>

class MyString {
	char* data;
	size_t length;

   public:
	// Constructor
	MyString(const char* str = "") {
		length = std::strlen(str);
		data = new char[length + 1];
		strcpy(data, str);
		std::cout << "Constructor called for: " << data << std::endl;
	}

	// Copy Constructor
	MyString(const MyString& other) {
		length = other.length;
		data = new char[length + 1];
		strcpy(data, other.data);
		std::cout << "Copy Constructor called for: " << data << std::endl;
	}

	// Move Constructor
	MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
		other.data = nullptr;  // Leave the moved-from object in a valid state
		other.length = 0;
		std::cout << "Move Constructor called for: " << data << std::endl;
	}

	// Copy Assignment Operator
	MyString& operator=(const MyString& other) {
		if (this != &other) {
			delete[] data;
			length = other.length;
			data = new char[length + 1];
			std::strcpy(data, other.data);
			std::cout << "Copy Assignment called for: " << data << std::endl;
		}
		return *this;
	}

	// Move Assignment Operator
	MyString& operator=(MyString&& other) noexcept {
		if (this != &other) {
			delete[] data;
			data = other.data;
			length = other.length;
			other.data = nullptr;
			other.length = 0;
			std::cout << "Move Assignment called for: " << data << std::endl;
		}
		return *this;
	}

	// Destructor
	~MyString() {
		delete[] data;
		std::cout << "Destructor called for: " << (data ? data : "null") << std::endl;
	}

	const char* getData() const { return data; }
};

int main() {
	MyString s1("Hello");		  // Constructor
	MyString s2 = s1;			  // Copy Constructor
	MyString s3 = std::move(s1);  // Move Constructor
	s2 = MyString("World");		  // Move Assignment (temporary object)
	s1 = s2;					  //Copy Assignment
    return 0;
}