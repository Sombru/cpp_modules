#ifndef Serializer_HPP
# define Serializer_HPP

#include <stdint.h>
#include <string>

struct Data
{
	std::string str;
	int x;
};


class Serializer
{
private:
public:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif