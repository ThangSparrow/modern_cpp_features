/*
 *
 * This is an example to demonstrate:
 * 
 * 1. Storing unique_ptr in a container
 * 2. std::for_each with std::unique_ptr. Hint: reference "const auto& person" makes the object "unique"
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class Person {
   public:
	std::string name;
	Person(const std::string& n) : name(n) { std::cout << "Created: " << name << "\n"; }
	~Person() { std::cout << "Destroyed: " << name << "\n"; }
};

int main() {
	std::vector<std::unique_ptr<Person>> people;

	// Add Person objects
	people.push_back(std::make_unique<Person>("A"));
	people.push_back(std::make_unique<Person>("B"));
	people.push_back(std::make_unique<Person>("C"));

	// Print names
	std::cout << "\nPeople:\n";
	for (const auto& person : people) {
		std::cout << person->name << "\n";
	}

	// Print only names starting with "A"
	std::cout << "\nPeople named with A*:\n";
	std::for_each(people.cbegin(), people.cend(), [](const auto& person) {
		if (person->name[0] == 'A') {
			std::cout << person->name << "\n";
		}
	});

  std::cout << "\nSoftware end, release memory!\n";
}