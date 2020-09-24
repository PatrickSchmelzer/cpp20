#include <vector>
#include <iostream>
#include <bit>
#include <numbers>
#include <cstdint>
#include <string>
#include <map>
#include <set>
#include <array>
#include <unordered_map>
//#include <syncstream> // not yet implemented on visual studio??




/*****************************************************************************************/
/// THE BIG FOUR
/// - CONCEPTS
/// - MODULES
/// - RANGE LIBRARY
/// - COROUTINES
/*****************************************************************************************/

// ranges allow to i.e. sort containers without using iterators but the container i.e. 
//std::ranges::sort(std::views::reverse(v)); // sorts the vector v in reverse order
// piping with view
//std::vector vec{ 1, 2, 3, 4, 5, 6 };
//auto v = vec | std::views::reverse | std::views::drop(2);
//
//std::cout << *v.begin() << '\n';

// jthreads (new threading with the possibliity of stopping a thread and coroutines)	


struct Point {
	int x = 0;
	int y = 0;
};

//// simplified usage of scoped enumerations within a switch case
//enum class rgba_color_channel { red, green, blue, alpha };
//std::string_view to_string(rgba_color_channel my_channel) {
//	switch (my_channel) {
//	using enum rgba_color_channel;
//	case red:   return "red";
//	case green: return "green";
//	case blue:  return "blue";
//	case alpha: return "alpha";
//	default: return "";
//	}
//}

int main() {
	/*****************************************************************************************/
	// C++ 20 features
	/*****************************************************************************************/
	// Designated Initialzers
	Point firstPoint{ .x = 20, .y = 11 };
	Point secondPoint{ .y = 11 }; // Also works with default values

	// Range based loop with initializer
	for (std::vector<int> v{ 2, 4, 5 }; const auto & e : v) {
		std::cout << e << "\n";
	}


	/// new features without example
	// template syntax for lambdas
	auto f = []<typename T>(std::vector<T> v) {};

	// [[likely]] [[unlikely]] attributes for compiler optimizations (branch prediction)

	/*****************************************************************************************/
	// C++ 20 Library features
	/*****************************************************************************************/
	// multiple conects (checking for requriements  i.e. boolean, same_as, copyable...)
	//Synchronized buffered outputstream
	//std::osyncstream{ std::cout } << "The value of x is:" << x << std::endl; // not yet implemented on visual studio??
	// std::span (non owning access to stl algorithms (basically pointer + size but compared to std::array no memory allocation only pointer and size is stored
	// bit operation, many new algorithms in <bit>
	// std::cout << std::popcount(7U); // pop count is not yet implemented in visual studio <--> especially useful for big/little endian switching
	
	// Finally math constants
	std::cout << std::numbers::pi << "\n";
	std::cout << std::numbers::e << "\n";
	
	// functions for strings
	std::string str = "foobar";
	std::cout << str.starts_with("foo"); // true
	std::cout << str.ends_with("baz"); // false

	// functions for sets / maps
	std::map<int, char> map{ {1, 'a'}, {2, 'b'} };
	std::cout << map.contains(2); // true
	std::cout << map.contains(123); // false

	std::set<int> set{ 1, 2, 3 };
	std::cout << set.contains(2); // true

	// bit cast
	float f = 123.0;
	//int i = std::bit_cast<int>(f); //safer way then reinterpret cast

	//std::midpoint
	//Calculate the midpoint of two integers safely(without overflow).
	//std::midpoint(1, 3); // == 2
	// std::to_array
	std::to_array("foo"); // returns `std::array<char, 4>`
	std::to_array<int>({ 1, 2, 3 }); // returns `std::array<int, 3>`

	int a[] = { 1, 2, 3 };
	std::to_array(a); // returns `std::array<int, 3>`

	return 0;
}