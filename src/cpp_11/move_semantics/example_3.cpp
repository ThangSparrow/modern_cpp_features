#include <iostream>
#include <utility>

class Resource {
   public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource released\n"; }
};

template <typename T>
void createAndStore(T&& arg) {
	// Perfect forwarding to constructor
	Resource r(std::forward<T>(arg));
}

int main() {
	Resource r1;
	createAndStore(std::move(r1));	// r1 is moved
	createAndStore(Resource());		// Temporary (anonymous/unnamed object) is moved
}