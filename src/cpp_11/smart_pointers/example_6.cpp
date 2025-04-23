/*
 *
 * This is an example to demonstrate:
 * 
 * 1. lambda with vector of unique pointers
 * 2. *auto* for type deduction
 * 
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class Person {
   public:
	std::string name;
	int age;
	Person(const std::string& n, int a) : name(n), age(a) { std::cout << "Created: " << name << "\n"; }
	~Person() { std::cout << "Destroyed: " << name << "\n"; }
};

int main() {
	// Using unique pointers
	{
		std::vector<std::unique_ptr<Person>> unique_people;
		unique_people.push_back(std::make_unique<Person>("A", 25));
		unique_people.push_back(std::make_unique<Person>("B", 30));
		unique_people.push_back(std::make_unique<Person>("C", 20));

		int age_threshold = 22;
    int person_count = 0;
		std::cout << "\nPeople older than " << age_threshold << ":\n";
		std::for_each(unique_people.cbegin(), unique_people.cend(), [age_threshold, &person_count](const auto& person) {
			if (person->age > age_threshold) {
				std::cout << person->name << " (" << person->age << ")\n";
        person_count++;
			}
		});
    std::cout << "person_count: " << person_count << "\n";
	}
}