#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data original;
	original.str = "Hello, world!";
	original.x = 42;

	// Serialize pointer
	uintptr_t raw = Serializer::serialize(&original);

	// Deserialize back to pointer
	Data *restored = Serializer::deserialize(raw);

	std::cout << "Original address: " << &original << '\n';
	std::cout << "Serialized value: " << raw << '\n';
	std::cout << "Restored address: " << restored << '\n';
	std::cout << "Restored str: " << restored->str << '\n';
	std::cout << "Restored x: " << restored->x << '\n';

}