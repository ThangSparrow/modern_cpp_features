/*
 *
 * This is an example to demonstrate:
 * 
 * 1. shared_ptr
 * 2. shared_ptr.use_count()
 * 3. std::weak_ptr
 *
 */

#include <iostream>
#include <memory>
#include <string>

class Resource {
   public:
	std::string id;
	Resource(const std::string& i) : id(i) { std::cout << "Resource created: " << id << "\n"; }
	~Resource() { std::cout << "Resource destroyed: " << id << "\n"; }
};

void use_resource(std::shared_ptr<Resource> res) {
	// use count shall increase
	// new shared_ptr created on stack, point to the same object
	std::cout << "Using resource " << res->id << ", use count: " << res.use_count() << "\n";
}

int main() {
	// Scope 1
	std::weak_ptr<Resource> scope_1_weak_ptr;
	{
		auto res = std::make_shared<Resource>("Data");
		std::cout << "Initial use count: " << res.use_count() << "\n";

		use_resource(res);
		// After the function call, pointer on the stack has been deleted automatically (out of scope)
		std::cout << "After use_resource, use count: " << res.use_count() << "\n";

		// Scope 2
		{
			auto res2 = res;  // share ownership
			std::cout << "Inside scope 2, use count: " << res.use_count() << "\n";
		}
		std::cout << "After scope 2, use count: " << res.use_count() << "\n";

		// weak pointer to resource
		scope_1_weak_ptr = res;	 // non-owning reference to the *same object (resource)*
		res.reset(); // destroy object
    std::cout << "Weak pointer to res, res.use_count: " << res.use_count() << "\n";
		std::cout << "Weak pointer to res, scope_1_weak_ptr.use_count: " << scope_1_weak_ptr.use_count() << "\n";

    // What weak pointer does is purely "observe"
	}
}