/*
 *
 * This is an example to demonstrate:
 * 
 * 1. Memory leakage when forgot to "delete" raw pointer
 * 2. Improve above point by std::unique_ptr
 * 3. Usage of std::move
 *
 */

#include <iostream>
#include <memory>
#include <string>

class Book {
   public:
	std::string title;
	Book(const std::string& t) : title(t) { std::cout << "Book created: " << title << "\n"; }
	~Book() { std::cout << "Book destroyed: " << title << "\n"; }
};

void raw_pointer_book() {
	std::cout << "Raw pointer: \n";
	Book* book_raw_ptr = new Book("A");

	// use book_raw_ptr - start
	std::cout << "Title " << book_raw_ptr->title << "\n";
	// ...
	// use book_raw_ptr - end

	// delete book_raw_ptr;
	// Forgot to delete book_raw_ptr -> memory leak
}

void unique_ptr_book() {
	std::cout << "\nunique_ptr:\n";
	std::unique_ptr<Book> book_uni_ptr = std::make_unique<Book>("B");

	// use book_uni_ptr - start
	std::cout << "Title: " << book_uni_ptr->title << "\n";
	// use book_uni_ptr - stop

	// move ownership of book_uni_ptr to book_uni_ptr_2 - start
	auto book_uni_ptr_2 = std::move(book_uni_ptr);

  // book_uni_ptr is now nullptr; don't access it!
  if (book_uni_ptr) {
    std::cout << "Title book_uni_ptr: " <<book_uni_ptr->title << "\n";
  } else {
    std::cout << "book_uni_ptr is not null.\n";
  }

	std::cout << "Title book_uni_ptr_2: " << book_uni_ptr->title << "\n";
	// move ownership of book_uni_ptr to book_uni_ptr_2 - stop

	// book_uni_ptr is automatically destroyed
  // book_uni_ptr_2 is automatically destroyed
}

int main() {
	raw_pointer_book();
	unique_ptr_book();
}
