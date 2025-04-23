/*
 *
 * This is an example to demonstrate:
 * 
 * 1. raw pointers and risks a memory leak during exception
 * 2. unique_ptr ensure safety in above case
 * 3. shared_ptr ensure safety
 */

#include <iostream>
#include <memory>
#include <stdexcept>

class Gadget {
   public:
	Gadget() { std::cout << "Gadget created\n"; }
	~Gadget() { std::cout << "Gadget destroyed\n"; }
};

void useGadget(const std::shared_ptr<Gadget>& g) {
  std::cout << "Gadget is being used\n";
}

void raw_pointer_risky() {
  std::cout << "Raw pointer:\n";
  Gadget* raw_ptr_g = new Gadget();
  throw std::runtime_error("Error occurred!");
  delete raw_ptr_g; // Never reached -> Leak
}

void unique_ptr_safe() {
  std::cout << "\nunique_ptr:\n";
  std::unique_ptr<Gadget> uni_ptr_g = std::make_unique<Gadget>();
  useGadget(std::move(uni_ptr_g)); // ownership is transferred from uni_ptr_g to useGadget's copy, uni_ptr_g becomes null pointer
  throw std::runtime_error("Error occurred!");
  // No delete needed; uni_ptr_g is automatically destoyed
}

void shared_ptr_safe() {
  std::cout << "\nshared_ptr:\n";
  std::shared_ptr<Gadget> shared_ptr_g = std::make_shared<Gadget>();
  useGadget(shared_ptr_g); // both shared_ptr_g and useGadget's copy can use gadget
  // useGadget's copy is destroyed but object is still available
  throw std::runtime_error("Error occurred!");
  // After this function, shared_ptr_g & object are destroyed
}

int main() {
  try {
    raw_pointer_risky();
  } catch (const std::exception& e) {
    std::cout << "Caught: " << e.what() << "\n";
  }
  // raw_pointer is not deleted

  try {
    unique_ptr_safe();
  } catch (const std::exception& e) {
    std::cout << "Caught: " << e.what() << "\n";
  }
  // unique_ptr is deleted automatically after out of scope
}