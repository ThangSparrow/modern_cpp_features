#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Person
{
public:
  std::string name;
  Person(const std::string &n) : name(n)
  {
    std::cout << "Created " << name << "\n";
  }
  ~Person()
  {
    std::cout << "Destroyed " << name << "\n";
  }
};

void raw_pointer()
{
  std::cout << "Raw pointer example: \n";
  Person *p1 = new Person("A");
  Person *p2 = new Person("B");
  // Use p1, p2 ......

  // Forgot to delete p1 & p2 -> Memory leak!
  std::cout << "End of raw pointer example\n";
}

void unique_ptr()
{
  std::cout << "\nunique_ptr example:\n";
  std::unique_ptr<Person> p1 = std::make_unique<Person>("C");
  std::unique_ptr<Person> p2 = std::make_unique<Person>("D");
  // No delete needed, p1 & p2 are automatically destroyed when out of scope
  std::cout << "End of unique_ptr example\n";
}

void shared_ptr()
{
  std::cout << "\nshared_ptr example:\n";
  std::shared_ptr<Person> p1 = std::make_shared<Person>("Eve");
  {
    std::shared_ptr<Person> p2 = p1; // Share ownership
    std::cout << "p1 use count: " << p1.use_count() << "\n";
  } // p2 goes out of scope, but p1 still owns the object
  std::cout << "p1 use count after p2 destroyed: " << p1.use_count() << "\n";
  // p1 destroyed when function ends
}

int main()
{
  raw_pointer();
  unique_ptr();
  shared_ptr();
}